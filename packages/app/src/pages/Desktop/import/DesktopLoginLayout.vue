<template>
	<div class="login-layout-root">
		<DesktopDefaultHeaderView />
		<div
			style="width: 100%; height: calc(100% - 38px)"
			class="row items-center justify-center"
		>
			<div class="login-layout-box row justify-between items-center">
				<div class="login-layout-welcome row justify-start items-start">
					<q-carousel
						class="login-layout-carousel"
						animated
						v-model="slide"
						infinite
						:autoplay="autoplay"
						swipeable
						transition-prev="slide-right"
						transition-next="slide-left"
						@mouseenter="autoplay = false"
						@mouseleave="autoplay = true"
					>
						<q-carousel-slide
							:name="1"
							img-src="../../../assets/login/termipass_slide_img.svg"
						/>
						<q-carousel-slide
							:name="2"
							img-src="../../../assets/login/termipass_slide_img.svg"
						/>
						<q-carousel-slide
							:name="3"
							img-src="../../../assets/login/termipass_slide_img.svg"
						/>
						<q-carousel-slide
							:name="4"
							img-src="../../../assets/login/termipass_slide_img.svg"
						/>
					</q-carousel>
					<div class="login-layout-data text-h4">{{ carouselData }}</div>
					<div class="login-layout-navigation row justify-center items-center">
						<template v-for="index in 4" :key="index">
							<div
								:class="
									index === slide ? 'navigation-active' : 'navigation-normal'
								"
								@click="changeActive(index)"
							/>
						</template>
					</div>
				</div>
				<router-view class="login-layout-page" />
			</div>
		</div>
	</div>
</template>

<script setup lang="ts">
import { computed, ref } from 'vue';
import { useI18n } from 'vue-i18n';
import DesktopDefaultHeaderView from '../../../components/DesktopDefaultHeaderView.vue';

const slide = ref(1);
const autoplay = ref(true);
const { t } = useI18n();
const carouselData = computed(() => {
	switch (slide.value) {
		case 1:
			return t('welcome_words_first');
		case 2:
			return t('welcome_words_second');
		case 3:
			return t('welcome_words_third');
		case 4:
			return t('welcome_words_fourth');
		default:
			return '';
	}
});

const changeActive = (index: number) => {
	slide.value = index;
};
</script>

<style scoped lang="scss">
.login-layout-root {
	height: 100vh;
	width: 100vw;
	background: $desktop-background;

	.login-layout-box {
		height: 692px;
		min-width: 1096px;
		padding-left: 52px;
		padding-right: 52px;
		padding-bottom: 38px;

		.login-layout-welcome {
			height: 100%;
			width: 480px;
			background: $desktop-background;
			position: relative;

			.login-layout-carousel {
				width: 100%;
				height: calc(100% - 78px);
				background: $desktop-background;
			}

			.login-layout-data {
				height: 64px;
				text-align: center;
				color: $title;
				position: absolute;
				bottom: 68px;
				width: 316px;
				left: calc(50% - 158px);
				right: calc(50% - 158px);
			}

			.login-layout-navigation {
				width: 100%;
				height: 78px;

				.navigation-base {
					height: 4px;
					border-radius: 20px;
					margin-right: 8px;
				}

				.navigation-active {
					@extend .navigation-base;
					width: 20px;
					background: $grey-10;
				}

				.navigation-normal {
					@extend .navigation-base;
					width: 4px;
					background: $grey-5;
				}
			}
		}

		.login-layout-page {
			height: 100%;
			border-radius: 12px;
			width: 480px;
			border: 1px solid $grey-2;
		}
	}
}
</style>
