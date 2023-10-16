#pragma once
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
	struct Population {
		char* postalCode;
		int population;
	};

	void sort();
	bool load(Population& population);
	bool load(const char filename[]);
	void display(const Population& population);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_