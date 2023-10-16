/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/013/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
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

        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator ~() const;
        Account& operator=(const int num);
        Account& operator=(Account& rightAcc);
        Account& operator+=(const double amount);
        Account& operator-=(const double amount);
        Account& operator<<(Account& rightAcc);
        Account& operator>>(Account& rightAcc);
    };

    double operator+(Account& leftAcc, Account& rightAcc);
    double operator+=(double& amount, Account& rightAcc);
}
#endif // SDDS_ACCOUNT_H_