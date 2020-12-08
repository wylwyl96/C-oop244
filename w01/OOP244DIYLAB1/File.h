#pragma once
#ifndef FILE_H // replace with relevant names
#define FILE_H

// Your header file content goes here

namespace dir {

	bool openFile(const char filename[]);
	void closeFile();
	bool readCode(char scode[]);
	bool readExt(int* ext);

}
#endif