import { boot } from 'quasar/wrappers';
import axios, { AxiosInstance, AxiosRequestConfig, AxiosResponse } from 'axios';
import { useUserStore } from '../stores/user';
import { useCloudStore } from '../stores/cloud';
import { NetworkErrorMode, busEmit } from '../utils/bus';
import qs from 'qs';

declare module '@vue/runtime-core' {
	interface ComponentCustomProperties {
		$axios: AxiosInstance;
	}
}

// Be careful when using SSR for cross-request state pollution
// due to creating a Singleton instance here;
// If any client changes this (global) instance, it might be a
// good idea to move this instance creation inside of the
// "export default () => {}" function below (which runs individually
// for each client)
const api = axios.create({ baseURL: 'https://api.example.com' });
//const notifaction_timeout = 1;

export default boot(({ app, router }) => {
	// for use inside Vue files (Options API) through this.$axios and this.$api

	app.config.globalProperties.$axios = axios;
	// ^ ^ ^ this will allow you to use this.$axios (for Vue Options API form)
	//       so you won't necessarily have to import axios in each vue file
	app.config.globalProperties.$api = api;

	// app.config.globalProperties.$axios.interceptors.request.use(
	// 	(request: AxiosRequestConfig) => {
	// 		const cloudStore = useCloudStore();
	// 		if (
	// 			!request.url ||
	// 			(request.url.indexOf(cloudStore.url) !== -1 &&
	// 				request.method === 'post')
	// 		) {
	// 			const data = request.data || {};
	// 			request.data = qs.stringify(data);

	// 			return request;
	// 		}
	// 		return request;
	// 	}
	// );

	app.config.globalProperties.$axios.interceptors.request.use(
		(config: AxiosRequestConfig) => {
			const cloudStore = useCloudStore();
			console.log('config ' + config.url);
			console.log(cloudStore.url);
			if (
				config.url &&
				config.url.indexOf(cloudStore.url) !== -1 &&
				config.method === 'post'
			) {
				const data = config.data || {};
				config.data = qs.stringify(data);
				return config;
			}

			// if (
			// 	config.url &&
			// 	config.url.indexOf('/api/cloud/sig') >= 0 &&
			// 	config.method === 'post'
			// ) {
			// 	const data = config.data || {};
			// 	config.data = qs.stringify(data);
			// 	return config;
			// }

			const userStore = useUserStore();

			if (config.headers) {
				// config.headers['Access-Control-Allow-Origin'] = '*';
				// config.headers['Access-Control-Allow-Headers'] = 'Content-Type';
				// config.headers['Access-Control-Allow-Methods'] =
				// 	'PUT,POST,GET,DELETE,OPTIONS';

				// if (tokenStore.$state.token?.access_token) {
				// 	config.headers['X-Authorization'] =
				// 		tokenStore.$state.token?.access_token;
				// 	return config;
				// } else {
				if (!userStore.current_id) {
					return config;
				}
				const user = userStore.users!.items.get(userStore.current_id);
				if (!user) {
					return config;
				}
				if (!user.access_token) {
					return config;
				}
				config.headers['X-Authorization'] = user.access_token;

				return config;
			}
			// } else {
			// 	return config;
			// }
		}
	);

	app.config.globalProperties.$axios.interceptors.response.use(
		(response: AxiosResponse) => {
			//console.log("response " + JSON.stringify(response));
			console.log('response ==>');
			console.log(response);

			if (!response || response.status != 200 || !response.data) {
				throw Error('Network error, please try again later');
			}

			const cloudStore = useCloudStore();
			if (
				response.config.url &&
				response.config.url.indexOf(cloudStore.url) !== -1 &&
				response.config.method === 'post'
			) {
				const data = response.data;

				if (data.code === 506) {
					//cloudStore.removeToken();

					router.push({ path: '/login' });
					return response;
				}

				if (data && data.code === 401) {
					return response;
				}

				if (data.code == 200 || data.code == 0) {
					return data;
				}

				throw new Error(data.message);
			} else {
				const data = response.data;
				if (data.code == 100001) {
					busEmit('network_error', {
						type: NetworkErrorMode.axois,
						error: 'token expired'
					});
					//store.commit("account/remove");

					// router.push({ path: '/login' });
					throw Error(data.message);
					//return response;
				}

				if (data.code != 0) {
					throw Error(data.message);
				}

				return data.data;
			}
		},
		(error: any) => {
			console.error(error);
			busEmit('network_error', {
				type: NetworkErrorMode.axois,
				error: error.message
			});
			throw error;
		}
	);
});

export { api };
