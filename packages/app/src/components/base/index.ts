import { App } from 'vue';
import Button from './Button.vue';
import Search from './Search.vue';
import BtIcon from './BtIcon.vue';
import BtDialog from './BtDialog.vue';
import BtMonthPicker from './BtMonthPicker.vue';
import BtCheckBox from './BtCheckBox.vue';
import BtRadio from './BtRadio.vue';
import BtCheckButton from './BtCheckButton.vue';

const install = function (app: App<Element>): void {
	app.component('BtButton', Button);
	app.component('BtSearch', Search);
	app.component('BtIcon', BtIcon);
	app.component('BtDialog', BtDialog);
	app.component('BtMonthPicker', BtMonthPicker);
	app.component('BtCheckBox', BtCheckBox);
	app.component('BtRadio', BtRadio);
	app.component('BtCheckButton', BtCheckButton);
};

export default install;
