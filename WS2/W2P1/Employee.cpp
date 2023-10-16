/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 05/24/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employee) {
        bool ok = false;
        char name[128];
        /* if reading of employee number, salay and name are successful
                allocate memory to the size of the name + 1
                and keep its address in the name of the Employee Reference
                copy the name into the newly allocated memroy
                make sure the "ok" flag is set to true
           end if
        */

        if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) {
            int len = strLen(name) + 1;
            employee.m_name = new char[len];
            strCpy(employee.m_name, name);
            ok = true;
        }
        return ok;
    }


    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            /*
             Set the noOfEmployees to the number of recoreds in the file.
             dyanamically allocated an array of employees into the global
             Employee pointer; "employees" to the size of the noOfEmployees.
             In a loop load the employee records from the file into
             the dynamic array.
             If the number of the records does not match the number of reads
                print the message
               "Error: incorrect number of records read; the data is possibly corrupted"
             Otherwise
                set the ok flag to true
             End if
             close the file
             */

            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            
            for (i = 0; i < noOfEmployees; i++) {
                if (load(employees[i])) {
                ok = true;

                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted.";
                }
            }
            

            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }


    // TODO: Implementation for the display functions go here
    void display(const Employee& employee) {
        cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
    }

    void display() {
        cout << "Employee Salary report, sorted by employee number" << endl <<
            "no- Empno, Name, Salary" << endl <<
            "------------------------------------------------" << endl;

        sort();
        
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here

    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }

        delete employees;
    }

}