//name:Yuelin Wen    stduent id:114379209
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      void InEmpty();
      bool isNew();
      bool isValid();

      operator bool()const;
      operator int()const;
      operator double()const;
      
      bool operator~()const;

      Account& operator=(int account);
      Account& operator=(Account& account);
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      
   };
   double operator+(const Account& LO, const Account& RO);
   double operator+=(double& LO, const Account& RO);
   
}
#endif // SDDS_ACCOUNT_H_