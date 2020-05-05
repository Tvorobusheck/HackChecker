#pragma once
#include <windows.h>

#define NEW_VERSION_PATH L"D:\\Data\\new_version.txt"
#define OLD_VERSION_PATH L"D:\\Data\\HackChecker\\HackCheckerGUI\\HackCheckerGUI\\SignatureVersion.txt"

void update_version() {
	CopyFile(NEW_VERSION_PATH, OLD_VERSION_PATH, 0);
}