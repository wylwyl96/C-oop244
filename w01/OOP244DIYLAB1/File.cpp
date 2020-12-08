#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
using namespace std;
namespace dir {
	FILE* fptr;

	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}

	void closeFile() {
		if (fptr) fclose(fptr);
	}

	bool readCode(char scode[]) {
		return fscanf(fptr, "%[^ ]", scode) == 1;
	}

	bool readExt(int* ext) {
		return fscanf(fptr, "%d\n", ext) == 1;
	}
}

