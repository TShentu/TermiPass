<template>
	<div class="input-mnemonic-page column justify-start items-center">
		<terminus-page-title
			:center="true"
			class="page-title"
			:label="t('password_title')"
			desc=""
			imgSrc="/vault-logo.svg"
		/>
		<terminus-edit
			v-model="userStore.terminusInfo().terminusName"
			:label="t('terminus_name')"
			:show-password-img="false"
			:is-read-only="true"
			class="input-mnemonic-page__edit"
		/>
		<terminus-mnemonics-component
			ref="mnemonicRef"
			:lager-title="false"
			class="input-mnemonic-page__mnemonic"
			@on-mnemonic-change="mnemonicUpdate"
			@keyup.enter="onConfirm"
		/>
		<confirm-button
			class="input-mnemonic-page__button"
			:btn-title="t('next')"
			@onConfirm="onConfirm"
			:btn-status="btnStatusRef"
		/>
	</div>
</template>

<script lang="ts" setup>
import { ref } from 'vue';
import { useRouter } from 'vue-router';
import { useQuasar } from 'quasar';
import TerminusMnemonicsComponent from '../../components/common/TerminusMnemonicsComponent.vue';
import ConfirmButton from '../../components/common/ConfirmButton.vue';
import { ConfirmButtonStatus } from '../../utils/constants';
import { useI18n } from 'vue-i18n';
import TerminusPageTitle from '../../components/common/TerminusPageTitle.vue';
import TerminusEdit from '../../components/common/TerminusEdit.vue';
import { useUserStore } from '../../stores/user';
import { UserItem } from '@didvault/sdk/src/core';
import {
	connectTerminus,
	importUser
} from '../Mobile/connect/BindTerminusBusiness';
import { notifyFailed } from '../../utils/notifyRedefinedUtil';

const $q = useQuasar();
const router = useRouter();
const mnemonic = ref<string>('');
const { t } = useI18n();
const userStore = useUserStore();

async function onConfirm() {
	btnStatusRef.value = ConfirmButtonStatus.disable;
	$q.loading.show();
	try {
		await importUser(userStore.terminusInfo().terminusName, mnemonic.value);
	} catch (e) {
		btnStatusRef.value = ConfirmButtonStatus.normal;
		$q.loading.hide();
		notifyFailed(e.message);
		return;
	}

	const user: UserItem = userStore.users!.items.get(userStore.current_id!)!;
	try {
		await connectTerminus(user, '');
		router.push({ path: '/items' });
	} catch (e) {
		notifyFailed(e.message);
	} finally {
		btnStatusRef.value = ConfirmButtonStatus.normal;
		$q.loading.hide();
	}
}

const btnStatusRef = ref<ConfirmButtonStatus>(ConfirmButtonStatus.disable);

const mnemonicUpdate = (value: string) => {
	mnemonic.value = value;
	const masterPasswordArray = mnemonic.value.split(' ');
	if (
		masterPasswordArray.length !== 12 ||
		masterPasswordArray.find((e) => e.length === 0) !== undefined
	) {
		btnStatusRef.value = ConfirmButtonStatus.disable;
		return;
	}
	btnStatusRef.value = ConfirmButtonStatus.normal;
};
</script>

<style lang="scss" scoped>
.input-mnemonic-page {
	width: 100%;
	height: 100%;
	background: $background;
	padding-left: 20px;
	padding-right: 20px;
	position: relative;
	border: 1px solid $grey-2;

	&__edit {
		width: 100%;
		margin-top: 20px;
	}

	&__mnemonic {
		margin-top: 20px;
	}

	&__button {
		position: absolute;
		bottom: 20px;
		width: calc(100% - 40px);
		left: 20px;
		right: 20px;
	}
}
</style>
