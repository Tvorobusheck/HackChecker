#pragma once
#include <Windows.h>
#include "SignatureVersionSeter.h"

#define NEW_SIGNATURE L"D:\\Data\\new_signature.txt"
#define OLD_SIGNATURE L"D:/Data/HackChecker/HackCheckerGUI/HackCheckerGUI/signatures.txt"

void update() {
	update_version();
	CopyFile(NEW_SIGNATURE, OLD_SIGNATURE, 0);
}