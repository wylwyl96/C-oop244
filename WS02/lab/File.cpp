#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	bool read(char studentname[]) {
		return fscanf(fptr, "%[^,],", studentname) == 1;
	}
	bool read(int& studentnumber) {
		return fscanf(fptr, "%d,", &studentnumber) == 1;
	}
	bool read(double& studentGPA) {
		return fscanf(fptr, "%lf\n", &studentGPA) == 1;
	}

}