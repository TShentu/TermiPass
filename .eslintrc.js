module.exports = {
	env: {
		browser: true,
		es2021: true,
		node: true
	},

	extends: [
		'eslint:recommended',
		'plugin:@typescript-eslint/recommended',
		'plugin:vue/vue3-essential',
		'plugin:prettier/recommended'
	],

	parserOptions: {
		ecmaVersion: 'latest',
		parser: '@typescript-eslint/parser',
		sourceType: 'module'
	},

	plugins: ['@typescript-eslint', 'vue'],

	rules: {
		'no-debugger': process.env.NODE_ENV === 'production' ? 'error' : 'off'
	}
};
