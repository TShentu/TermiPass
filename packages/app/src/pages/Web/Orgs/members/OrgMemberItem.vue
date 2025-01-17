<template>
	<div class="member_wrap row items-center justify-center">
		<div class="stretch row items-center justify-start">
			<div class="q-mr-md avator">
				<TerminusAvatar
					:info="userStore.getUserTerminusInfo(member.id || '')"
					:size="28"
				/>
			</div>
			<div class="column justify-between">
				<div class="did text-subtitle2">{{ member.name }}</div>
				<div>
					<!-- TODO: snowning.com error-->
					<span>@{{ userStore.getCurrentDomain() }}</span>
					<span
						class="tag text-3ubtitle3 owner"
						v-if="member.role === OrgRole.Owner"
						>{{ t('owner') }}</span
					>
					<span
						class="tag text-3ubtitle3 admin"
						v-if="member.role === OrgRole.Admin"
						>{{ t('admin') }}</span
					>
					<span
						class="tag text-3ubtitle3 suspended"
						v-if="org?.isSuspended(member)"
						>{{ t('suspend') }}</span
					>
				</div>
			</div>
		</div>
	</div>
</template>

<script lang="ts">
import { defineComponent, computed } from 'vue';
import { OrgMember, OrgRole, OrgMemberStatus } from '@didvault/sdk/src/core';
import { app } from '../../../../globals';
import { useMenuStore } from '../../../../stores/menu';
import { useUserStore } from '../../../../stores/user';
import { useI18n } from 'vue-i18n';

export default defineComponent({
	name: 'MemberItem',
	props: {
		member: {
			type: OrgMember,
			required: true
		},
		isSelected: {
			type: Boolean,
			default: false,
			required: false
		}
	},
	components: {},

	emits: [],
	setup(props: any) {
		const meunStore = useMenuStore();
		const userStore = useUserStore();
		const org = computed(function () {
			return app.orgs.find((org) => org.id == meunStore.org_id);
		});

		const groups = computed(function () {
			return org.value!.getGroupsForMember(props.member) || [];
		});

		const { t } = useI18n();

		return {
			org,
			OrgMemberStatus,
			OrgRole,
			groups,
			userStore,
			t
		};
	}
});
</script>

<style lang="scss" scoped>
.member_wrap {
	width: 94%;

	.stretch {
		width: 96%;
		height: 58px;
		border-radius: 8px;
		.avator {
			width: 28px;
			height: 28px;
			border-radius: 14px;
			overflow: hidden;
		}
		.did {
			width: 90%;
			color: $title;
		}
		.tag {
			padding: 0 4px;
			border-radius: 4px;
			margin-left: 10px;
			&.owner {
				border: 1px solid $deep-orange-5;
				color: $deep-orange-5;
			}
			&.admin {
				border: 1px solid $blue-4;
				color: $blue-4;
			}
			&.provisioned {
				border: 1px solid $grey-8;
				color: $grey-8;
			}
			&.suspended {
				border: 1px solid $grey-8;
				color: $grey-8;
			}
		}
	}
}
</style>
