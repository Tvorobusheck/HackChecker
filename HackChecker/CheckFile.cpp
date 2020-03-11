#include "pch.h"
#include "VirusChecker.h"
#include <iostream>
using namespace std;

SuspectedFile::SuspectedFile(string path) {
	this->load(path);
}

string SuspectedFile::get_path() {
	return this->path;
}

bool SuspectedFile::load(string path) {
	FILE * file = fopen(path.c_str(), "rb");
	if (file == NULL) {
		cerr << "Error! Can't open file at: " << path << endl;
		return false;
	}
	this->file = file;
	this->path = path;
	return true;
}

bool SuspectedFile::close() {
	return fclose(file);
}

bool SuspectedFile::checkFile() {
	FILE * file = this->file;
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