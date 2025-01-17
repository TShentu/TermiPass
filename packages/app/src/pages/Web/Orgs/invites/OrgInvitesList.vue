<template>
	<div
		class="row justify-between items-center bg-white"
		style="width: 100%; height: 60px"
	>
		<div class="row justify-between items-center">
			<div class="row items-center q-pl-md">
				<q-icon
					v-if="isMobile"
					name="sym_r_chevron_left"
					size="24px"
					@click="goBack"
				/>
				<q-icon :name="heading.icon" size="24px" />

				<div class="column q-pl-md" v-if="!isMobile">
					<div class="text-grey-8 text-caption">
						{{ org?.name }}
					</div>
					<div class="text-body2 text-weight-bold">
						{{ heading.title }}
					</div>
				</div>
			</div>

			<div class="column" v-if="isMobile">
				<div class="text-grey-8 text-caption">
					{{ org?.name }}
				</div>
				<div class="text-body2 text-weight-bold">
					{{ heading.title }}
				</div>
			</div>
		</div>
	</div>

	<q-list
		class="bg-white"
		style="width: 100%; height: calc(100% - 60px); overflow: hidden"
	>
		<q-scroll-area
			v-if="itemList.length > 0"
			style="height: 100%"
			:thumb-style="scrollBarStyle.thumbStyle"
		>
			<template v-for="(item, index) in itemList" :key="index">
				<div class="card-wrap full-width">
					<q-card
						clickable
						v-ripple
						@click="selectItem(item as Invite)"
						:active="isSelected(item as Invite)"
						active-class="text-blue"
						flat
						class="vaultsCard row items-center justify-start q-my-sm q-pa-md"
						:class="isSelected(item as Invite) ? 'vaultCardActive' : ''"
					>
						<q-card-section class="row items-center justify-between q-pa-none">
							<OrgInviteItem :invite="(item as Invite)" />
							<q-separator v-if="index < itemList.length - 1" />
						</q-card-section>
					</q-card>
				</div>
			</template>
		</q-scroll-area>

		<div
			class="column text-color-sub-title items-center justify-center full-height"
			v-else
		>
			<img src="../../../../assets/layout/nodata.svg" />
			<span style="margin-top: 32px; margin-bottom: 70px; color: $grey-8">
				{{ t('do_not_have_any_invitees_yet') }}
			</span>
		</div>
	</q-list>
</template>

<script lang="ts">
import { defineComponent, ref, onMounted, onUnmounted, computed } from 'vue';
import { useRouter, useRoute } from 'vue-router';
import { useQuasar } from 'quasar';
import { app } from '../../../../globals';
import { debounce, Invite } from '@didvault/sdk/src/core';
import { scrollBarStyle } from '../../../../utils/contact';
import { useMenuStore } from '../../../../stores/menu';
import OrgInviteItem from './OrgInviteItem.vue';
import { busOn, busOff } from '../../../../utils/bus';
import { useI18n } from 'vue-i18n';

export default defineComponent({
	name: 'OrgInvitesIndex',
	components: {
		OrgInviteItem
	},
	setup() {
		const $q = useQuasar();
		const router = useRouter();
		const route = useRoute();
		const meunStore = useMenuStore();
		const isMobile = ref(
			process.env.PLATFORM == 'MOBILE' ||
				process.env.PLATFORM == 'BEX' ||
				$q.platform.is.mobile
		);
		const org = ref();

		const initOrg = () => {
			org.value = app.orgs.find((org) => org.id == meunStore.org_id);
			console.log('initOrginitOrg', org.value);
		};

		const heading = computed(function () {
			return {
				icon: 'sym_r_share_reviews',
				title: 'Invites'
			};
		});

		function _getItems() {
			initOrg();
			const invites = org.value!.invites;
			return invites;
		}

		async function selectItem(item: Invite) {
			router.push({
				path: '/org/Invites/' + (item.id ? item.id : '')
			});
		}

		function isSelected(item: Invite): boolean {
			return route.params.org_type == item.id;
		}
		let itemList = ref<Invite[]>(_getItems());

		function stateUpdate() {
			itemList.value = _getItems();
		}

		async function search() {
			updateItems();
		}

		const goBack = () => {
			router.go(-1);
		};

		//let unsubscribe : any;
		onMounted(() => {
			busOn('orgSubscribe', stateUpdate);

			meunStore.$subscribe(() => {
				updateItems();
			});
		});
		onUnmounted(() => {
			busOff('orgSubscribe', stateUpdate);
		});

		let updateItems = debounce(() => {
			itemList.value = _getItems();
		}, 50);

		const { t } = useI18n();

		return {
			itemList,
			selectItem,
			isSelected,
			heading,
			org,
			search,
			isMobile,
			goBack,
			scrollBarStyle,
			t
		};
	}
});
</script>

<style lang="scss" scoped>
.searchWrap {
	height: 56px;
	line-height: 56px;
	text-align: center;

	.searchInput {
		width: 90%;
		height: 40px;
		line-height: 40px;
		border: 1px solid $blue;
		border-radius: 10px;
		margin: 17px auto;
		display: inline-block;
	}
}

.checkOperate {
	border-radius: 4px;
	padding: 4px;
}

.item-unit {
	border-radius: 5px;
	padding: 4px 20px;
	white-space: nowrap;
	position: relative;

	.item-unit-content {
		white-space: nowrap;
	}

	.hideCopied {
		position: absolute;
		width: 100%;
		height: 100%;
		opacity: 0;
		left: 0;
		top: 0;
	}
}

.card-wrap {
	display: flex;
	align-items: center;
	justify-content: center;
	border-bottom: 1px solid #e0e0e0;

	.vaultsCard {
		width: 90%;
		border: 0;
		border-radius: 0;
		box-sizing: border-box;
		position: relative;
		border-radius: 8px;
		cursor: pointer;

		&:hover {
			background: $grey-1;
		}
	}
}
</style>
