//name:yuelin wen  email:ywen26@myseneca.ca
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();
      
      Numbers(const Numbers& N);
      Numbers& operator=(const Numbers& N);
      int numberCount()const;
      bool load();
      void save();
      Numbers& operator+=(double d);
      std::ostream& display(std::ostream& ostr)const;
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

