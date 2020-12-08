#pragma once
#ifndef SCHOOL_H // replace with relevant names
#define SCHOOL_H

// Your header file content goes here

namespace dir {
	struct School {
		char s_code[10];
		int s_ext;
	};
	bool loadSchool();
	void DisplayExt(const char scode[]);
}
#endif