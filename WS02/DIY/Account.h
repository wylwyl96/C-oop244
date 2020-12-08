#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
namespace sdds {
	struct Info {
		int accountnum;
		double balance;
	};
	void sort();
	bool load(Info& infos);
	bool load(const char filename[]);
	void display(const Info& infos);
	void display();
	void deallocateMemory();
}
#endif // SDDS_ACCOUNT_H_