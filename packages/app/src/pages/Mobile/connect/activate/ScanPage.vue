<template>
	<div class="row items-center justify-evenly">
		<q-icon
			name="sym_r_chevron_left"
			size="32px"
			@click="goBack"
			color="white"
			class="back-icon"
		/>
		<span class="text-white text-h5 scan-title">{{ t('scan_qr_code') }}</span>
		<div class="img-box" />
		<!-- <span class="text-white text-h6 scan-label">{{
			t('scan_qr_code_to_activate')
		}}</span> -->
		<canvas id="myCanvas" />

		<q-btn
			flat
			style="position: absolute; bottom: 77px; right: 50px"
			@click="toPhotoAlbum"
		>
			<div class="column justify-between items-center content-center">
				<div
					class="row justify-center items-center content-center photo-album-img-bg"
				>
					<q-icon name="sym_r_imagesmode" size="20px" />
				</div>
				<div class="text-white text-body3 album_title">
					{{ t('photo_album') }}
				</div>
			</div>
		</q-btn>
	</div>
</template>

<script lang="ts" setup>
import { onMounted, onUnmounted } from 'vue';
import { useRouter } from 'vue-router';
import { useQuasar } from 'quasar';
import { useUserStore } from '../../../../stores/user';
import { useMenuStore } from '../../../../stores/menu';
import { getNativeAppPlatform } from '../../../../platform/capacitor/capacitorPlatform';
import { useI18n } from 'vue-i18n';
import { WizardInfo } from './wizard';
import { userBindTerminus } from '../BindTerminusBusiness';
import { base64ToString, UserItem } from '@didvault/sdk/src/core';
import { notifyFailed } from '../../../../utils/notifyRedefinedUtil';
const $q = useQuasar();
const userStore = useUserStore();
const menuStore = useMenuStore();
const { t } = useI18n();

const router = useRouter();

let canvas: any;
let ctx: any;

const startScan = async () => {
	try {
		const result = await getNativeAppPlatform().scanQR();
		await getNativeAppPlatform().stopScanQR();
		if (result && result.length) {
			resoleScanResult(result, () => {
				setTimeout(() => {
					startScan();
				}, 1000);
			});
		} else {
			setTimeout(() => {
				startScan();
			}, 1000);
		}
	} catch (error) {
		setTimeout(() => {
			startScan();
		}, 1000);
	}
};

onMounted(async () => {
	menuStore.changeSafeArea(false);
	document.body.classList.add('qrscanner');
	initCanvas();
	window.addEventListener('onresize', initCanvas);

	setTimeout(() => {
		getNativeAppPlatform()
			.scanQRDidUserGrantPermission()
			.then((permission) => {
				if (permission) {
					startScan();
				} else {
					getNativeAppPlatform().scanQrCheckPermission();
				}
			});
	}, 500);
});

onUnmounted(() => {
	getNativeAppPlatform().stopScanQR();
	menuStore.changeSafeArea(true);
	document.body.classList.remove('qrscanner');
	window.removeEventListener('onresize', initCanvas);
});

const toPhotoAlbum = async () => {
	const qrcodeContent =
		await getNativeAppPlatform().getQRCodeImageFromPhotoAlbum();
	if (!qrcodeContent || qrcodeContent.length === 0) {
		notifyFailed(t('read_fail_try_again'));
		return;
	}
	resoleScanResult(qrcodeContent, () => {
		// startScan()
	});
	$q.loading.hide();
};

const goBack = () => {
	router.back();
};

const resoleScanResult = async (result: string, failCallBack?: any) => {
	if (result.startsWith('http')) {
		notifyFailed(t('qr_code_error'));
		if (failCallBack) {
			failCallBack();
		}
		return;
	}

	if (result.startsWith('https://file.bttcdn.com')) {
		notifyFailed(t('qr_code_error'));
		if (failCallBack) {
			failCallBack();
		}
		return;
	}

	if (!userStore.current_id) {
		notifyFailed(t('please_choose_user'));
		if (failCallBack) {
			failCallBack();
		}
		return;
	}

	if (
		!result.startsWith('active-vault' + '://') &&
		!result.startsWith('active_vault' + '://')
	) {
		const item = getNativeAppPlatform().scanQRProtocolList.find((e) =>
			result.startsWith(e.protocol)
		);
		if (item && (await item.canResponseQRContent(result))) {
			const scanResult = await item.method(result);
			if (!scanResult) {
				if (failCallBack) {
					failCallBack();
				}
				return;
			}
			goBack();
			if (item.success) {
				item.success();
			}
			return;
		}

		notifyFailed(t('qr_code_error'));
		if (failCallBack) {
			failCallBack();
		}
		return;
	}

	const content = result.split('://')[1];

	try {
		getNativeAppPlatform().hookServerHttp = false;
		const obj: WizardInfo = JSON.parse(base64ToString(content));
		console.log('obj ===>');
		console.log(obj);

		if (obj.username?.split('@').length != 2) {
			notifyFailed(
				t('errors.username_is_error_please_retry_scan', {
					username: obj.username
				})
			);
			if (failCallBack) {
				failCallBack();
			}
			return;
		}
		console.log(obj.username);
		console.log(userStore.current_user?.name);
		console.log(obj.username !== userStore.current_user?.name);

		if (obj.username !== userStore.current_user?.name) {
			notifyFailed(
				t('errors.username_is_error_please_retry_scan', {
					username: obj.username
				})
			);
			if (failCallBack) {
				failCallBack();
			}
			return;
		}

		// if (returnV.value) {
		// 	return;
		// }

		$q.loading.show();

		const user: UserItem = userStore.users!.items.get(userStore.current_id!)!;

		await userBindTerminus(user, obj.url, obj.password!, {
			async onSuccess() {
				const new_user: UserItem = userStore.users!.items.get(
					userStore.current_id!
				)!;
				new_user.wizard = JSON.stringify(obj);
				new_user.terminus_activate_status = 'wait_activate_system';
				new_user.setup_finished = false;
				await userStore.users!.items.update(new_user);
				await userStore.save();

				router.push({ path: '/ActivateWizard' });
			},
			onFailure(message: string) {
				getNativeAppPlatform().hookServerHttp = true;
				$q.loading.hide();
				notifyFailed(message);
				if (failCallBack) {
					failCallBack();
				}
			}
		});
	} catch (error) {
		notifyFailed(error.message);
	}

	$q.loading.hide();
};

function initCanvas() {
	canvas = document.getElementById('myCanvas');
	ctx = canvas.getContext('2d');
	canvas.width = window.innerWidth;
	canvas.height = window.innerHeight;
	drawCanvas();
}
function drawCanvas() {
	ctx.moveTo(0, 0);
	ctx.lineTo(window.innerWidth, 0);
	ctx.lineTo(window.innerWidth, window.innerHeight);
	ctx.lineTo(0, window.innerHeight);
	ctx.closePath();
	const height = 290;
	const width = 290;
	const top = 200.5;
	const left = (window.innerWidth - 290) / 2;
	const cornerRadius = 16;
	ctx.moveTo(left + cornerRadius, top);
	ctx.arcTo(left, top, left, top + cornerRadius, cornerRadius);
	ctx.lineTo(left, top + height - cornerRadius);
	ctx.arcTo(
		left,
		top + height,
		left + cornerRadius,
		top + height,
		cornerRadius
	);
	ctx.lineTo(left + width - cornerRadius, top + height);
	ctx.arcTo(
		left + width,
		top + height,
		left + width,
		top + height - cornerRadius,
		cornerRadius
	);
	ctx.lineTo(left + width, top + cornerRadius);
	ctx.arcTo(left + width, top, left + width - cornerRadius, top, cornerRadius);
	ctx.closePath();
	ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
	ctx.fill();
}
</script>

<style lang="scss" scoped>
.back-icon {
	position: absolute;
	left: 20px;
	top: 39px;
}

.scan-title {
	position: absolute;
	width: 200px;
	height: 30px;
	left: calc(50% - 60px);
	right: calc(50% - 60px);
	top: 39px;
	text-align: left;
}

.img-box {
	position: absolute;
	background: linear-gradient($yellow, $yellow) left top,
		linear-gradient($yellow, $yellow) left top,
		linear-gradient($yellow, $yellow) right top,
		linear-gradient($yellow, $yellow) right top,
		linear-gradient($yellow, $yellow) right bottom,
		linear-gradient($yellow, $yellow) right bottom,
		linear-gradient($yellow, $yellow) left bottom,
		linear-gradient($yellow, $yellow) left bottom;
	background-repeat: no-repeat;
	background-size: 2px 40px, 40px 2px;
	border-radius: 16px;
	top: 197px;
	height: 296px;
	width: 296px;
}

.scan-label {
	position: absolute;
	width: auto;
	height: 12px;
	top: 509px;
}

.photo-album-img-bg {
	width: 32px;
	height: 32px;
	background: white;
	border-radius: 50%;
}

.album_title {
	margin-top: 10px;
	text-align: center;
	text-transform: capitalize;
}
</style>
