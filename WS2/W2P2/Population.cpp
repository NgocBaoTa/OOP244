#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    int noOfAreas;
    Population* population;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfAreas - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].population > population[j + 1].population) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& population) {
        bool ok = false;
        char code[128];

        if (read(code) && read(population.population)) {
            int len = strLen(code) + 1;
            population.postalCode = new char[len];
            strCpy(population.postalCode, code);
            ok = true;
        }
        return ok;
    }

	bool load(const char filename[]) {
        bool ok = false;
        int i = 0;
        if (openFile(filename)) {
            noOfAreas = noOfRecords();
            population = new Population[noOfAreas];

            for (i = 0; i < noOfAreas; i++) {
                if (load(population[i])) {
                    ok = true;
                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted.";
                }
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
	}

    void display(const Population& population) {
        cout << population.postalCode << ":  " << population.population << endl;
    }

    void display() {
        int sum = 0;
        cout << "Postal Code: population" << endl <<
         "-------------------------" << endl;

        sort();

        for (int i = 0; i < noOfAreas; i++) {
            sum += population[i].population;
            cout << i + 1 << "- ";
            display(population[i]);
        }

        cout << "-------------------------" << endl <<
            "Population of Canada: " << sum << endl;
    }

    void deallocateMemory() {
        for (int i = 0; i < noOfAreas; i++) {
            delete[] population[i].postalCode;
        }

        delete population;
    }
}