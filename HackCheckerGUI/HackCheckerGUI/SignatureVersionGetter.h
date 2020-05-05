#pragma once

#include <string>


#define OLD_VERSION_PATH "D:\\Data\\HackChecker\\HackCheckerGUI\\HackCheckerGUI\\SignatureVersion.txt"
#define NEW_VERSION_PATH "D:\\Data\\new_version.txt"

std::string get_version_local() {
	std::string version;
	FILE * f = fopen(OLD_VERSION_PATH, "r");
	char buffer[1024];
	fscanf(f, "%s", buffer);
	version = buffer;
	fclose(f);
	return version;
}

std::string get_version_online() {
	std::string version;
	FILE * f = fopen(NEW_VERSION_PATH, "r");
	char buffer[1024];
	fscanf(f, "%s", buffer);
	version = buffer;
	fclose(f);
	return version;
}