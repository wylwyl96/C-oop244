#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(char studentname[]);
	bool read(int& studentnumber);
	bool read(double& studentGPA);
}
#endif // !SDDS_FILE_H_
