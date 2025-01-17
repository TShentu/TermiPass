import { useFilesUploadStore } from '../stores/files-upload';
import url from '../utils/url';

export function checkConflict(files, items) {
	if (typeof items === 'undefined' || items === null) {
		items = [];
	}

	let folder_upload = files[0].fullPath !== undefined;

	let conflict = false;
	for (let i = 0; i < files.length; i++) {
		let file = files[i];
		let name = file.name;

		if (folder_upload) {
			let dirs = file.fullPath.split('/');
			if (dirs.length > 1) {
				name = dirs[0];
			}
		}

		let res = items.findIndex(function hasConflict(element) {
			return element.name === this;
		}, name);

		if (res >= 0) {
			conflict = true;
			break;
		}
	}

	return conflict;
}

function checkSameName(file, items, index = 0) {
	let hasSameName = items.findIndex((item) => {
		return item.name === file.name;
	});

	if (hasSameName > -1) {
		let suffix = '';
		if (file.name.split('.').length > 1) {
			suffix = '.' + file.name.split('.')[file.name.split('.').length - 1];
		}

		let prefix = file.name.slice(0, file.name.indexOf(suffix));
		if (index > 0) {
			prefix = file.name.slice(0, file.name.indexOf(`(${index})`));
		}

		const filename = `${prefix}(${index + 1})${suffix}`;

		const newFile = new File([file.slice()], filename, {
			type: file.type,
			lastModified: file.lastModified
		});

		return checkSameName(newFile, items, index + 1);
	} else {
		return file;
	}
}

export async function createCopiedFile(files, items) {
	if (typeof items === 'undefined' || items === null) {
		items = [];
	}

	const newFiles = [];
	for (let i = 0; i < files.length; i++) {
		let file = files[i];
		const newFile = await checkSameName(file, items);
		newFiles.push(newFile);
	}

	return newFiles;
}

export function scanFiles(dt) {
	return new Promise((resolve) => {
		let reading = 0;
		const contents = [];

		if (dt.items !== undefined) {
			for (let item of dt.items) {
				if (
					item.kind === 'file' &&
					typeof item.webkitGetAsEntry === 'function'
				) {
					const entry = item.webkitGetAsEntry();
					readEntry(entry);
				}
			}
		} else {
			resolve(dt.files);
		}

		function readEntry(entry, directory = '') {
			if (entry.isFile) {
				reading++;
				entry.file((file) => {
					reading--;

					file.fullPath = `${directory}${file.name}`;
					contents.push(file);

					if (reading === 0) {
						resolve(contents);
					}
				});
			} else if (entry.isDirectory) {
				const dir = {
					isDir: true,
					size: 0,
					fullPath: `${directory}${entry.name}`,
					name: entry.name
				};

				contents.push(dir);

				readReaderContent(entry.createReader(), `${directory}${entry.name}`);
			}
		}

		function readReaderContent(reader, directory) {
			reading++;

			reader.readEntries(function (entries) {
				reading--;
				if (entries.length > 0) {
					for (const entry of entries) {
						readEntry(entry, `${directory}/`);
					}

					readReaderContent(reader, `${directory}/`);
				}

				if (reading === 0) {
					resolve(contents);
				}
			});
		}
	});
}

function detectType(mimetype) {
	if (mimetype.startsWith('video')) return 'video';
	if (mimetype.startsWith('audio')) return 'audio';
	if (mimetype.startsWith('image')) return 'image';
	if (mimetype.startsWith('pdf')) return 'pdf';
	if (mimetype.startsWith('text')) return 'text';
	return 'blob';
}

export async function handleFiles(files, base, overwrite = false) {
	const upload = useFilesUploadStore();
	for (let i = 0; i < files.length; i++) {
		let id = upload.id;
		let path = base;
		let file = files[i];

		if (file.fullPath !== undefined) {
			path += url.encodePath(file.fullPath);
		} else {
			path += url.encodeRFC5987ValueChars(file.name);
		}

		if (file.isDir) {
			path += '/';
		}

		const item = {
			id,
			path,
			file,
			overwrite,
			...(!file.isDir && { type: detectType(file.type) })
		};

		await (function () {
			return new Promise(async function (res) {
				await upload.upload(item);
				res();
			});
		})();
	}
}
