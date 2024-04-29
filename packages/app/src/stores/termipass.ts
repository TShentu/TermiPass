import { defineStore } from 'pinia';
import {
	TermiPassState as TermiPassStateI,
	TermiPassStatus
} from '../utils/termipassState';
import { useUserStore } from './user';
import { useScaleStore } from './scale';
import { UserStatusActive } from 'src/utils/checkTerminusState';
import { i18n } from '../boot/i18n';
import { useDeviceStore } from './device';
import { notifyFailed } from 'src/utils/notifyRedefinedUtil';

export interface TermiPassState {
	state: TermiPassStateI;
	reactivation: boolean;
	srpInvalid: boolean;
	ssoInvalid: boolean;
	tokenRefreshing: boolean;
}

export interface TermiPassStateInfo {
	status: TermiPassStatus;
	isError: UserStatusActive;
	icon: string;
	title: string;
	description?: string;
	descriptionEx?: string;
}

export const useTermipassStore = defineStore('termipass', {
	state: () => {
		return {
			state: new TermiPassStateI()
		} as TermiPassState;
	},

	getters: {
		isLocal(): boolean {
			const userStore = useUserStore();
			return userStore.current_user?.isLocal || false;
		},
		isP2P(): boolean {
			const vpnStore = useScaleStore();
			return vpnStore.isDirect;
		},
		isDER(): boolean {
			const vpnStore = useScaleStore();
			return !vpnStore.isDirect;
		},
		isDirect(): boolean {
			const userStore = useUserStore();
			return !userStore.current_user?.isLocal || true;
		},
		totalStatus(): TermiPassStateInfo | undefined {
			// return UserStatus
			const userStore = useUserStore();
			if (!userStore.current_user) {
				return undefined;
			}

			if (userStore.current_user.offline_mode) {
				return {
					status: TermiPassStatus.OfflineMode,
					isError: UserStatusActive.normal,
					title: i18n.global.t('user_current_status.offline_mode.title'),
					icon: 'public_off'
				};
			}

			const deviceStore = useDeviceStore();

			if (!deviceStore.networkOnLine) {
				return {
					status: TermiPassStatus.Offline,
					isError: UserStatusActive.error,
					title: i18n.global.t('user_current_status.networkOnLine.title'),
					icon: 'wifi_tethering_error',
					description: i18n.global.t(
						'user_current_status.networkOnLine.description'
					),
					descriptionEx: ''
				};
			}

			if (this.reactivation) {
				return {
					status: TermiPassStatus.Reactivation,
					isError: UserStatusActive.error,
					title: i18n.global.t('user_current_status.reactivation.title'),
					icon: 'devices_off',
					description: i18n.global.t(
						'user_current_status.reactivation.description'
					),
					descriptionEx: i18n.global.t(
						'user_current_status.reactivation.description_ex'
					)
				};
			}

			if (this.ssoInvalid) {
				return {
					status: TermiPassStatus.TokenInvalid,
					isError: UserStatusActive.error,
					title: i18n.global.t('user_current_status.token_invalid.title'),
					icon: 'account_circle_off',
					description: i18n.global.t(
						'user_current_status.token_invalid.description'
					),
					descriptionEx: i18n.global.t(
						'user_current_status.token_invalid.description_ex'
					)
				};
			}

			if (this.srpInvalid) {
				return {
					status: TermiPassStatus.VaultTokenInvalid,
					isError: UserStatusActive.error,
					title: i18n.global.t('user_current_status.srp_invalid.title'),
					icon: 'account_circle_off',
					description: i18n.global.t(
						'user_current_status.srp_invalid.description'
					),
					descriptionEx: i18n.global.t(
						'user_current_status.srp_invalid.description_ex'
					)
				};
			}

			const scaleStore = useScaleStore();

			if (userStore.current_user.tailscale_activated && !scaleStore.isOn) {
				return {
					status: TermiPassStatus.RequiresVpn,
					isError: UserStatusActive.error,
					title: i18n.global.t('user_current_status.requires_vpn.title'),
					icon: 'public_off',
					description: i18n.global.t(
						'user_current_status.requires_vpn.description'
					),
					descriptionEx: i18n.global.t(
						'user_current_status.requires_vpn.description_ex'
					)
				};
			}

			if (scaleStore.isConnecting) {
				return {
					status: TermiPassStatus.VPNConnecting,
					isError: UserStatusActive.active,
					title: i18n.global.t('user_current_status.connecting.title'),
					icon: ''
				};
			}

			if (scaleStore.isOn) {
				if (this.isP2P) {
					return {
						status: TermiPassStatus.P2P,
						isError: UserStatusActive.active,
						title: i18n.global.t('user_current_status.p2p.title'),
						icon: 'vpn_lock'
					};
				}
				return {
					status: TermiPassStatus.DERP,
					isError: UserStatusActive.active,
					title: i18n.global.t('user_current_status.derp.title'),
					icon: 'vpn_lock'
				};
			}

			return {
				status: TermiPassStatus.Internet,
				isError: UserStatusActive.active,
				title: i18n.global.t(
					userStore.current_user.isLocal
						? 'user_current_status.intranet.title'
						: 'user_current_status.internet.title'
				),
				icon: userStore.current_user.isLocal ? 'signal_wifi_0_bar' : 'public'
			};
		}
	},

	actions: {
		notifyUserCannotCorrespondMethod() {
			if (this.totalStatus?.isError != UserStatusActive.active) {
				notifyFailed(
					i18n.global.t('the_current_status_this_module_cannot_be_accessed', {
						status: this.totalStatus?.title
					})
				);
				return false;
			}
			return true;
		}
	}
});
