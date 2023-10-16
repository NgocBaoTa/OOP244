#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "load.h"
#include "mapping.h"

void clearInputBuffer()
{

	while (getchar() != '\n')
	{
		;
	}
}
int validateWeight(int weight)
{
	int ok = 1;
	if (weight > 1000 || weight < 1) {
		printf("Invalid weight (must be 1-1000 Kg.)\n");
		ok = 0;
	}
	return ok;
}

int validateBoxSize(double size)
{
	int ok = 1;
	if (!(size == 0.25 || size == 0.5 || size == 1))
	{
		printf("Invalid Size\n");
		ok = 0;
	}

	return ok;
}

int validateDestination(int row, char col)
{
	int ok = 1;
	if (ok && (row < 0 || row > MAP_ROWS)) {
		printf("Invalid destination(row)\n");
		ok = 0;
	}
	if (ok && ((((int)toupper(col)) - 65) < 0 || (((int)toupper(col)) - 65) > MAP_COLS)) {
		printf("Invalid destination(column) \n");
		ok = 0;
	}
	// if(ok && !validateDestinationPoint(row,col)){
	// 	printf("its not a building\n");
	// 	ok =0;
	// }
	return ok;
}

// int validateDestinationPoint(int row, int col)
// {
// 	int ok =0;
//     int deliveryArea[25][25] = {
//         {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
//         {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
//         {1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
//         {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
//         {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//         {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//         {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//         {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
//         {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
//         {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
//         {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
//         {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
//     };

//     int colInt = ((int)toupper(col)) - 'A';
//     int rowInt = row - 1;

//     if (rowInt >= 0 && rowInt <= 24 && colInt >= 0 && colInt <= 24)
//     {
//         if (deliveryArea[rowInt][colInt] == 1)
//         {
//             ok = 1;
//         }
//     }
// 	return ok;
// }

int getInput(struct Shipment* box, int* flagOk) {
	int weight = 0, row = 0, ok = 1;
	double size = 0.0;
	char col;

	printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
	scanf("%d %lf", &weight, &size);
	if (weight == 0 && size == 0)
	{
		scanf(" %c", &col);
		if (weight == 0 && size == 0 && col == 'x')
		{
			ok = 0;
		}
		clearInputBuffer();
	}
	else
	{
		scanf("%d%c", &row, &col);
		*flagOk = validateWeight(weight) && validateBoxSize(size) && validateDestination(row, col);
		if (*flagOk)
		{
			box->box_weight = weight;
			box->box_size = size;
			box->destination.row = row - 1;
			box->destination.col = ((int)toupper(col)) - 65;
		}
		clearInputBuffer();
	}
	return !ok;
}

void loadTruck(struct Truck* truck, const struct Shipment* box) {
	truck->truck_weight += box->box_weight;
	truck->truck_volume += box->box_size;
	truck->shipment[truck->num_box] = *box;
	truck->num_box++;
}

int validateTruck(struct Truck* truck, int weight, double size) {
	int ok = 1, totalWeight;
	double totalSize;
	totalWeight = truck->truck_weight + weight;
	totalSize = truck->truck_volume + size;

	if (totalWeight > MAX_BOX_WEIGHT || totalSize > MAX_LOAD_SIZE) {
		ok = 0;
	}
	return ok;

}

struct Truck* assignTruck(struct Truck* truck, struct Shipment box, int numTrucks, double* index) {
	double minDistance = 100000, dist = 0;
	struct Truck* closeTruck = NULL;

	for (int i = 0; i < numTrucks; i++) {
		if (validateTruck(&truck[i], box.box_weight, box.box_size)) {
			for (int j = 0; j < truck[i].route.numPoints; j++) {
				struct Point stt = truck[i].route.points[j];
				dist = distance(&box.destination, &stt);
				if (dist < minDistance) {
					minDistance = dist;
					closeTruck = &truck[i];
				}
			}
		}
		else {
			if (validateTruck(&truck[i], box.box_weight, box.box_size)) {
				closeTruck = &truck[i];
			}
		}
	}

	*index = minDistance;

	return closeTruck;

}

void loadingTruck(const struct Shipment* box, struct Truck* truck, int numTrucks) {
	struct Truck* assignedTruck = NULL;
	double index = 0;

	assignedTruck = assignTruck(truck, *box, numTrucks, &index);
	if (truck) {
		loadTruck(assignedTruck, box);

		printf("Ship on ");
		if (assignedTruck->colorTruck == 2) {
			printf("BLUE LINE, ");
		}
		else if (assignedTruck->colorTruck == 4) {
			printf("GREEN LINE, ");
		}
		else if (assignedTruck->colorTruck == 8) {
			printf("YELLOW LINE, ");
		}

		if (index <= 1) {
			printf("no diversion\n");
		}
		else if (index > 1) {
			printf("diversion: ");
			divertPath(&assignedTruck->route, box->destination);
			printf("\n");
		}
	}
}

void divertPath(struct Route* route, struct Point des) {
	struct Map baseMap = populateMap();
	struct Point basePoint = { 0 };
	struct Route shortestRoute = { {0} };

	struct Map routeMap = addRoute(&baseMap, route);

	int closestIdx = getClosestPoint(route, des);
	basePoint = route->points[closestIdx];
	shortestRoute = shortestPath(&routeMap, basePoint, des);

	for (int i = 1; i < shortestRoute.numPoints; i++) {
		printf("%d%c", shortestRoute.points[i - 1].row + 1, shortestRoute.points[i - 1].col + 65);
		printf(", ");
	}
	printf("%d%c", des.row + 1, des.col + 65);
}