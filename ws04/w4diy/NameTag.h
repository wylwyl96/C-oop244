//name:yuelin wen    email:ywen26@myseneca.ca
#pragma once
#ifndef NAMETAG_H_
#define NAMETAG_H_
namespace sdds{
	class NameTag {
		char* m_nametag;
		int m_extnum;

		void setName(const char* Cstr);
		void setUnusable();
		bool isUnusable()const;

	public:
		NameTag();
		NameTag(const char* nametag);
		NameTag(const char* nametag, int extnum);
		~NameTag();
		NameTag& read();
		std::ostream& print()const;

	};
}
#endif