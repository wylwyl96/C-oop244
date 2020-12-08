//name:Yuelin Wen  email:ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Account.h"
#include "File.h"
using namespace std;
namespace sdds {
	int noOfInfo;
	Info* infos;

	void sort() {
		int i, j;
		Info temp;
		for (i = noOfInfo - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (infos[j].balance > infos[j + 1].balance) {
					temp = infos[j];
					infos[j] = infos[j + 1];
					infos[j + 1] = temp;
				}
			}
		}
	}

	bool load(Info& infos) {
		bool ok = false;
		ok = read(infos.accountnum) &&
			read(infos.balance);
		return ok;
	}

	bool load(const char filename[]) {
		bool ok = false;
		bool ko = true;
		int i = 0;
		if (openFile(filename)) {
			noOfInfo = noOfRecords();
			infos = new Info[noOfInfo];
			for (i = 0; ko && i < noOfInfo; i++) {
				ko = load(infos[i]);
			}
			if (noOfInfo != i) {
				cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
			}
			else {
				ok = true;
			}
			closeFile();
		}
		else {
			cout << "Could not open data file: " << filename << endl;
		}
		return ok;
	}

	void display(const Info& infos) {
		cout << infos.accountnum << ":  " << infos.balance << endl;
	}

	void display() {
		sort();
		cout << "Account#: Balance" << endl;
		for (int i = 0; i < noOfInfo; i++) {
			cout << i+1 <<": ";
			display(infos[i]);
		}
	}

	void deallocateMemory() {
		delete infos;
	}
}

