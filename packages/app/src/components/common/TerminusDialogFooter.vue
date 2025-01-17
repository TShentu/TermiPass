<template>
	<div v-if="isMobile" class="card-action row justify-between items-center">
		<confirm-button
			v-if="showCancel"
			class="cancel-button"
			btn-title="cancel"
			bg-classes="bg-white"
			@onConfirm="mobileCancel()"
		/>
		<confirm-button
			class="confirm-button"
			btn-title="confirm"
			@onConfirm="onOK"
			:style="{ width: showCancel ? '48%' : '100%' }"
			v-if="!loading"
		/>
		<confirm-button
			class="confirm-button"
			btn-title="Loading"
			:style="{ width: showCancel ? '48%' : '100%' }"
			v-else
		/>
	</div>

	<q-card-actions v-else class="row justify-end items-center q-mt-md q-mb-sm">
		<q-item
			v-if="showCancel"
			clickable
			dense
			class="but-cancel text-subtitle3 row justify-center items-center q-px-md q-mr-md"
			@click="onCancel"
		>
			{{ cancelText }}
		</q-item>
		<q-item
			clickable
			dense
			class="but-creat text-subtitle3 row justify-center items-center q-px-md q-mr-sm"
			@click="onOK"
			v-if="!loading"
		>
			{{ okText }}
		</q-item>
		<q-item
			v-else
			dense
			class="but-creat row justify-center items-center q-px-md q-mr-sm"
		>
			Loading
		</q-item>
	</q-card-actions>
</template>

<script lang="ts" setup>
import { ref } from 'vue';
import { useQuasar } from 'quasar';

import ConfirmButton from './ConfirmButton.vue';
import { useDataStore } from '../../stores/data';

defineProps({
	okText: {
		type: String,
		default: 'Sumbit',
		required: false
	},
	cancelText: {
		type: String,
		default: 'Cancel',
		required: false
	},
	showCancel: {
		type: Boolean,
		default: true,
		required: false
	},
	loading: {
		type: Boolean,
		default: false,
		required: false
	}
});

const $q = useQuasar();
const emit = defineEmits(['close', 'submit']);
const isMobile = ref(process.env.PLATFORM == 'MOBILE' || $q.platform.is.mobile);
const store = useDataStore();

const onCancel = () => {
	emit('close');
};

const onOK = (e: any) => {
	emit('submit', e);
};

const mobileCancel = () => {
	store.closeHovers();
	emit('close');
};
</script>

<style scoped lang="scss">
.but-creat {
	border-radius: 8px;
	background: $yellow;
	color: $title;
}
.but-cancel {
	border-radius: 8px;
	border: 1px solid $grey-2;
	color: $title;
}

.card-action {
	margin: 20px;
	.cancel-button {
		width: 48%;
		border: 1px solid $grey-2;
	}
}
</style>
