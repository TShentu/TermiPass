<template>
	<scan-component ref="scanCt" @cancel="scanCancel" @scan-result="scanResult" />
</template>

<script setup lang="ts">
import { ref } from 'vue';
import ScanComponent from '../../components/common/ScanComponent.vue';
import { useRouter } from 'vue-router';
import { getNativeAppPlatform } from '../../platform/capacitor/capacitorPlatform';
import { notifySuccess } from '../../utils/notifyRedefinedUtil';

const router = useRouter();
const scanCt = ref();

const scanCancel = () => {
	router.back();
};

const scanResult = async (result: string) => {
	const appPlatform = getNativeAppPlatform();
	for (let index = 0; index < appPlatform.scanQRProtocolList.length; index++) {
		const element = appPlatform.scanQRProtocolList[index];
		if (await element.canResponseQRContent(result)) {
			const scanResult = await element.method(result);
			if (!scanResult) {
				scanCt.value.checkScanPermissionAndStart();
				return;
			}
			router.back();
			if (element.success) {
				element.success();
			}
			return;
		}
	}
	scanCt.value.checkScanPermissionAndStart();
	notifySuccess(result);
};
</script>

<style scoped lang="scss"></style>
