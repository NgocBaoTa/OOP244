#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "load.h"

int main(void)
{
	int ok = 1, flagOk = 0;
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	struct Shipment boxes = { 0,0,{0,0} };

	struct Truck trucks[NUM_TRUCKS] = { 0,0,{0},{0},0,0 };
	trucks[0].route = blueRoute;
	trucks[1].route = greenRoute;
	trucks[2].route = yellowRoute;



	printf("=================\n");
	printf("Seneca Deliveries\n");
	printf("=================\n");
	trucks[0].colorTruck = 2;
	trucks[1].colorTruck = 4;
	trucks[2].colorTruck = 8;

	do {
		ok = getInput(&boxes, &flagOk);
		if (flagOk) {
			loadingTruck(&boxes, trucks, NUM_TRUCKS);

		}

	} while (!ok);

	//   struct Point stt = {0,0};

	   //struct Point des = {8,6};  	//its not a building
	   ////struct Point des = {8,7}; 	//its a building

	   //struct Map baseMap = populateMap();

	   //struct Route shortest = shortestPath(&baseMap, stt, des);
	   //struct Map routeMap = addRoute(&baseMap, &shortest);
	   //printMap(&routeMap, 1, 1);
	   //divertPath(&shortest, des);


	return 0;
}