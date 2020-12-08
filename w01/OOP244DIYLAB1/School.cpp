#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "File.h"
#include "School.h"
using namespace std;
namespace dir {
	School tele[24];
	//function that used to read file, and load information into struct tele.
	bool loadSchool() {
		School tl;
		int tnum = 0;
		bool ok = true;
		if (openFile("schools.dat")) {
			while (ok && tnum < 24) {
				ok = readCode(tl.s_code) &&
					readExt(&tl.s_ext);
				if (ok) tele[tnum++] = tl;
			}
			closeFile();
		}
		return tnum == 24;
	}
	//function that used to find the required information and display.
	void DisplayExt(const char scode[]) {
		int p, found = 0;
		for (int i = 0; i < 24; i++) {
			if (strstr(tele[i].s_code, scode)) {
				p = i;
				found = 1;
			}
		}
		if (found)
		{
			cout << "416 491 5050 x " << tele[p].s_ext << endl;
		}
		else if(!found)
		{
			cout << scode << " School code not found!" << endl;
		}
	}

}
