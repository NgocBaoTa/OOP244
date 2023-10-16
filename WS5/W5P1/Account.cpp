/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/13/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }


    Account::operator bool() const
    {
        return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0);
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    bool Account::operator~() const
    {
        return m_number == 0;
    }

    Account& Account::operator=(const int num)
    {
        if (~*this) {
            if (num >= 10000 && num <= 99999) {
                m_number = num;
            }
            else {
                setEmpty();
            }
        }
        return *this;
    }

    Account& Account::operator=(Account& rightAcc)
    {
        if (~*this && rightAcc.m_number >= 0) {
            this->m_balance = rightAcc.m_balance;
            this->m_number = rightAcc.m_number;
            rightAcc.m_balance = 0.0;
            rightAcc.m_number = 0;
        }
        return *this;
    }

    Account& Account::operator+=(const double amount)
    {
        if (m_number > 0 && m_balance >= 0.0 && amount > 0.0) {
            m_balance += amount;
        }
        return *this;
    }

    Account& Account::operator-=(const double amount)
    {
        if (m_number > 0 && m_balance >= amount && amount > 0) {
            m_balance -= amount;
        }
        return *this;
    }

    Account& Account::operator<<(Account& rightAcc)
    {
        if (this->m_balance >= 0 && rightAcc.m_balance >= 0 && this->m_number != rightAcc.m_number) {
            this->m_balance += rightAcc.m_balance;
            rightAcc.m_balance = 0;
        }

        return *this;
    }

    Account& Account::operator>>(Account& rightAcc)
    {
        if (this->m_balance >= 0 && rightAcc.m_balance >= 0 && this->m_number != rightAcc.m_number) {
            rightAcc.m_balance += this->m_balance;
            this->m_balance = 0;
        }

        return *this;
    }


    double operator+(Account& leftAcc, Account& rightAcc)
    {
        double sum = 0.0;
        if ((bool)leftAcc && (bool)rightAcc) {
            sum = (double)leftAcc + (double)rightAcc;
        }

        return sum;
    }

    double operator+=(double& amount, Account& rightAcc)
    {
        amount += (double)rightAcc;
        return amount;
    }
}