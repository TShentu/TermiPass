<template>
	<div class="row items-center">
		<q-avatar :icon="SETTING_MENU.tools.icon" @click="toggleDrawer" />
		<q-toolbar-title>{{ SETTING_MENU.tools.name }}</q-toolbar-title>
	</div>

	<q-list class="q-ma-md sItem" separator>
		<q-item class="titleBg">
			<q-item-section>{{
				t('web.settings.tools.import') + ' / ' + t('web.settings.tools.export')
			}}</q-item-section>
		</q-item>
		<q-item class="row items-center justify-center">
			<q-avatar icon="upload" />
			{{ t('web.settings.tools.import') }}...
		</q-item>
		<q-item class="row items-center justify-center">
			<q-avatar icon="download" />
			{{ t('web.settings.tools.export') }}...
		</q-item>
	</q-list>
</template>

<script lang="ts">
import { defineComponent, ref } from 'vue';
import { SETTING_MENU } from '../../../utils/constants';
import { useMenuStore } from '../../../stores/menu';
import { useI18n } from 'vue-i18n';

export default defineComponent({
	name: 'ToolsPage',
	components: {},
	setup() {
		const themeModel = ref();
		const themeOption = ref(['auto', 'light', 'dark']);
		const meunStore = useMenuStore();

		const toggleDrawer = () => {
			meunStore.rightDrawerOpen = false;
		};

		const { t } = useI18n();

		return {
			SETTING_MENU,
			themeModel,
			themeOption,
			toggleDrawer,
			t
		};
	}
});
</script>

<style scoped lang="scss">
.sItem {
	border: 1px solid $grey-2;
	border-radius: 10px;
}
</style>
