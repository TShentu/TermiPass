<template>
	<div class="bottom-root">
		<div class="content">
			<div class="row justify-center items-center">
				<q-btn
					class="bg-blue text-title text-subtitle1 confirm-btn"
					flat
					:label="btnTitle.length > 0 ? btnTitle : 'Confirm'"
					@click="confirmAction()"
					:disable="btnDisableRef"
				>
				</q-btn>
			</div>
		</div>
	</div>
</template>

<script setup lang="ts">
import { ref } from 'vue';

const props = withDefaults(
	defineProps<{
		btnTitle: string;
		btnDisable?: boolean;
	}>(),
	{
		btnTitle: '',
		btnDisable: false
	}
);

const confirmAction = () => {
	emit('confirmAction');
};

const btnDisableRef = ref(props.btnDisable);

function setBtnDisable(disable: boolean) {
	btnDisableRef.value = disable;
}

defineExpose({ setBtnDisable });
const emit = defineEmits(['confirmAction']);
</script>

<style lang="scss" scoped>
.bottom-root {
	height: 74px;

	.content {
		height: 100%;
		padding-top: 10px;
		margin-left: 20px;
		margin-right: 20px;

		.confirm-btn {
			width: 100%;
			height: 56px;
			border-radius: 10px;
			text-transform: capitalize;
		}
	}
}
</style>
