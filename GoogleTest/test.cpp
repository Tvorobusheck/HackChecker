#include "pch.h"
#include "../HackChecker/VirusChecker.h"

const string ie_path = "../test_files/iexplore.exe";
const string non_existing = "../non/existing.exe";


TEST(SuspectedFileCase, Existing) {
	SuspectedFile file = SuspectedFile(ie_path);
	EXPECT_EQ(file.get_path(), ie_path);
}

TEST(SuspectedFileCase, FullCheck) {

	SuspectedFile file = SuspectedFile(ie_path);
	EXPECT_EQ(file.get_path(), ie_path);
	EXPECT_TRUE(file.checkFile());
}

TEST(SuspectedFileCase, NonExisting) {

	SuspectedFile file = SuspectedFile(ie_path);
	EXPECT_FALSE(file.load(non_existing));
}