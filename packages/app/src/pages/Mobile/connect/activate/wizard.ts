export interface SystemOption {
	location: string;
	language: string;
}

export interface CloudflareNetworkOption {
	enable_tunnel: boolean;
	external_ip: string | null;
}

export interface WizardInfo {
	username: string;
	password: string;
	url: string;
	system: SystemOption;
	network: CloudflareNetworkOption;
}
