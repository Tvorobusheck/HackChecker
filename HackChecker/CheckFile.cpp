#include "pch.h"
#include "VirusChecker.h"
#include <iostream>
using namespace std;

// SpecialCase pattern - проверка NULL
// IdentityMap pattern - сохраняю значения вычислений, а потом использую
// PUBSUB pattern - сообщения отправляются в стандартный поток вывода и в поток вывода ошибок

File::File(string path) {
	this->load(path);
}

SuspectedFile::SuspectedFile(string path) : File{ path } {
	
}

string File::get_path() {
	return this->path;
}

bool File::load(string path) {
	FILE * file = fopen(path.c_str(), "rb");
	if (file == NULL) {
		cerr << "Error! Can't open file at: " << path << endl;
		return false;
	}
	this->file = file;
	this->path = path;
	return true;
}

bool File::close() {
	return fclose(file);
}

bool SuspectedFile::checkFile() {
	FILE * file = this->file;
	if (file == NULL) {
		cerr << "Error! Can't open suspected file: " << this->get_path() << endl;
		return false;
	}
	char buffer[MAX_FILE_SIZE];
	int size_of_file = fread(buffer, MAX_FILE_SIZE, 1, file);
	FILE * signatures_file = fopen(PATH_TO_SIGNATURES, "r");
	if (signatures_file == NULL) {
		cerr << "Error! Can't open signature file at: " << PATH_TO_SIGNATURES<< endl;
		return false;
	}
	int amount_of_signatures;
	fscanf(signatures_file, "%d", &amount_of_signatures);
	for (int i = 0; i < amount_of_signatures; i++) {
		signature signat;
		fscanf(signatures_file, "%d%d%d", &signat.offset, &signat.size, &signat.hash);
		ByteHash fileHash;
		fileHash.hash_it(buffer + signat.offset, signat.size);
		if (signat.hash == fileHash.getValue()) {
			return true;
		}
	}

	fclose(signatures_file);
	return false;
}