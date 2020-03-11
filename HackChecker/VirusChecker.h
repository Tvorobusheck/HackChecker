#pragma once
#include <string>
#include "Hash.h"

using namespace std;

#define MAX_FILE_SIZE 300 * 1024 * 1024
#define PATH_TO_SIGNATURES "../HackChecker/signatures.txt"

struct signature {
	unsigned int offset;
	unsigned int size;
	unsigned int hash;
};
class SuspectedFile {
public:
	SuspectedFile(string);
	bool load(string);
	bool close();
	bool checkFile();
	string get_path();
private:
	string path;
	FILE * file;
};