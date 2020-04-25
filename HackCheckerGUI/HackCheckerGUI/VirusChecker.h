#pragma once
#include <string>
#include "Hash.h"

using namespace std;

#define MAX_FILE_SIZE 300 * 1024
#define PATH_TO_SIGNATURES "D:/Data/HackChecker/HackCheckerGUI/HackCheckerGUI/signatures.txt"

struct signature {
	unsigned int offset;
	unsigned int size;
	unsigned int hash;
};


// STATE pattern - шаблон состояния, базовый класс - File, поведение - SuspectedFile
class File {
protected:
	string path;
	wstring wpath;
	FILE * file;
public:
	File(string);
	File(wstring);
	bool load(string);
	bool wload(wstring);
	bool close();
	string get_path();
	wstring wget_path();
};

class SuspectedFile : public File{
public:
	bool checkFile();
	SuspectedFile(string);
	SuspectedFile(wstring);
};