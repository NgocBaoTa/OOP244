#pragma once
#include "mapping.h"

#define MAX_BOX_WEIGHT 1000
#define MAX_BOX_SIZE 1
#define MAX_LOAD_SIZE 36
#define MAX_NUM_BOX 144
#define NUM_TRUCKS 3

struct Shipment {
	int box_weight;
	double box_size;
	struct Point destination;
};

struct Truck {
	int truck_weight;
	double truck_volume;
	struct Route route;
	struct Shipment shipment[MAX_NUM_BOX];
	int num_box;
	int colorTruck;
};



void clearInputBuffer();
int validateWeight(int weight);
int validateBoxSize(double size);
int validateDestination(int row, char col);
int validateDestinationPoint(int row, int col);
int getInput(struct Shipment* box, int* flagOk);
void loadTruck(struct Truck* truck, const struct Shipment* box);
int validateTruck(struct Truck* truck, int weight, double size);
struct Truck* assignTruck(struct Truck* truck, struct Shipment box, int numTrucks, double* index);
void loadingTruck(const struct Shipment* box, struct Truck* truck, int numTrucks);
void divertPath(struct Route* route, struct Point des);




