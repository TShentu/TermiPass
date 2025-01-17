<template>
	<div class="set-unlock-pwd-root column justify-start items-center">
		<terminus-scroll-area
			class="set-unlock-pwd-scroll"
			:class="
				isBex
					? 'bex-scroll-area-conf'
					: keyboardOpen
					? 'scroll-area-conf-open'
					: 'scroll-area-conf-close'
			"
		>
			<template v-slot:content>
				<div
					class="set-unlock-pwd-page column justify-start items-center q-mb-lg"
				>
					<q-img
						class="set-unlock-pwd-page__img"
						:src="getRequireImage('login/mobile_login_background.svg')"
					>
					</q-img>
					<terminus-page-title
						style="margin-top: 79px"
						:label="t('create_a_password')"
						:desc="t('create_a_password_desc')"
					/>
					<terminus-password-validator
						:edt-transaction="true"
						ref="passwordValidator"
						v-model:button-status="btnStatusRef"
						v-model:button-text="btnTextRef"
					/>
				</div>
			</template>
		</terminus-scroll-area>
		<confirm-button
			class="set-unlock-pwd-root-button"
			:btn-title="btnTextRef"
			@onConfirm="verifyPassword"
			@onError="clearData"
			:btn-status="btnStatusRef"
		/>
		<q-inner-loading :showing="loading" dark color="white" size="64px">
		</q-inner-loading>
	</div>
</template>

<script setup lang="ts">
import { onBeforeUnmount, onMounted, ref } from 'vue';
import { useRouter } from 'vue-router';
import { useQuasar } from 'quasar';
import MonitorKeyboard from '../../../../utils/monitorKeyboard';
import ConfirmButton from '../../../../components/common/ConfirmButton.vue';
import { ConfirmButtonStatus } from '../../../../utils/constants';
import { getPlatform } from '@didvault/sdk/src/core';
import '../../../../css/terminus.scss';
import { useI18n } from 'vue-i18n';
import { getNativeAppPlatform } from '../../../../platform/capacitor/capacitorPlatform';
import { savePassword } from './UnlockBusiness';
import TerminusPageTitle from '../../../../components/common/TerminusPageTitle.vue';
import TerminusPasswordValidator from '../../../../components/common/TerminusPasswordValidator.vue';
import TerminusScrollArea from '../../../../components/common/TerminusScrollArea.vue';
import TerminusTipDialog from '../../../../components/dialog/TerminusTipDialog.vue';
import { getRequireImage } from '../../../../utils/imageUtils';
import { StatusBar } from '@capacitor/status-bar';
import { notifyFailed } from '../../../../utils/notifyRedefinedUtil';

const $router = useRouter();
const $q = useQuasar();
const { t } = useI18n();
const loading = ref(false);
let monitorKeyboard: MonitorKeyboard | undefined = undefined;
const keyboardOpen = ref(false);

const btnTextRef = ref(t('next'));
const btnStatusRef = ref<ConfirmButtonStatus>(ConfirmButtonStatus.disable);
const passwordValidator = ref();
const isBex = ref(process.env.IS_BEX);

onMounted(() => {
	if ($q.platform.is.android) {
		StatusBar.setOverlaysWebView({ overlay: true });
		monitorKeyboard = new MonitorKeyboard();
		monitorKeyboard.onStart();
		monitorKeyboard.onShow(() => (keyboardOpen.value = true));
		monitorKeyboard.onHidden(() => (keyboardOpen.value = false));
	}
});

onBeforeUnmount(() => {
	if ($q.platform.is.android) {
		StatusBar.setOverlaysWebView({ overlay: false });
	}
});

const clearData = () => {
	passwordValidator.value.clearPassword();
};

const verifyPassword = async () => {
	const password = passwordValidator.value.getValidPassword();
	if (!password) {
		notifyFailed(t('password_not_meet_rules'));
		return;
	}

	loading.value = true;
	await savePassword(password, {
		async onSuccess() {
			const jumpToRegisterDid = () => {
				if (process.env.IS_BEX) {
					$router.replace({ path: '/import_mnemonic' });
					return;
				}

				$router.replace({
					name: 'setupSuccess'
				});
			};

			if (await getPlatform().biometricKeyStore.isSupported()) {
				$q.dialog({
					component: TerminusTipDialog,
					componentProps: {
						title: t('biometric_unlock'),
						message: t('biometric_unlock_desc'),
						navigation: t('skip')
					}
				})
					.onOk(async () => {
						const result = await getNativeAppPlatform().openBiometric();
						if (!result.status) {
							notifyFailed(t('errors.set_biometry_failure'));
							return;
						}
						jumpToRegisterDid();
					})
					.onCancel(() => {
						jumpToRegisterDid();
					});
				return;
			}

			jumpToRegisterDid();
		},
		onFailure(message: string) {
			notifyFailed(message);
		}
	});
};
</script>

<style lang="scss" scoped>
.set-unlock-pwd-root {
	width: 100%;
	height: 100%;
	background: $background;

	.bex-scroll-area-conf {
		width: 100%;
		height: calc(100% - 48px - 60px);
	}

	.set-unlock-pwd-scroll {
		width: 100%;

		.set-unlock-pwd-page {
			width: 100%;
			height: 100%;
			padding-left: 20px;
			padding-right: 20px;
			position: relative;

			&__img {
				width: 276px;
				height: 322px;
				position: absolute;
				left: 0;
			}
		}
	}

	.set-unlock-pwd-root-button {
		width: calc(100% - 40px);
	}
}
</style>
