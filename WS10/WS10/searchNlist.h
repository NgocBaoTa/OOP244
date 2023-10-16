// Final Project Milestone 1 
// searchNList Module
// File	searchNList.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Bao Ngoc Ta               
// Date: 08/04/2023              
// Authenticity Declaration :
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////


#pragma once
#include <iostream>
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include "ReadWrite.h"
#include "Collection.h"

namespace sdds {
    template <typename type1, typename type2>
    bool search(Collection<type1> & collect, type1* arr, int num, const type2& key) {
        bool result = false;
        for (int i = 0; i < num; i++) {
            if (arr[i] == key) {
                collect.add(arr[i]);
                result = true;
            }
        }
        return result;
    }


    template <typename type>
    void listArrayElements(const char* title, const type* arr, int num) {
        std::cout << title << '\n';
        for (int i = 0; i < num; i++) {
            std::cout << i + 1 << ": " << arr[i] << '\n';

        }
    }
}
#endif // !SDDS_SEARCHNLIST_H_