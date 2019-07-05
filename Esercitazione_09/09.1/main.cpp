#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "random.h"
#include "DataBlocking.h"
#include "TravelingSalesman.h"
#include <algorithm>

using namespace std;

int main (){

    int numberOfCities = 30;
    int numberOfParents = 600;
    int numberOfGenerations = 500;
    double probabilityOfMutation = 0.08;
    double probabilityOfCrossover = 0.9;

    double ray = 1.;
    TravelingSalesman Walker1(numberOfCities,numberOfParents,numberOfGenerations); 
    Walker1.CheckBounds();
    cout << endl << "Citta su una circonferenza di raggio 1" << endl;
    Walker1.Circle(ray);
    Walker1.RunGA(probabilityOfMutation, probabilityOfCrossover);
    Walker1.BestPath("../Results/Circle/path_circle.out");
    Walker1.BestDistance("../Results/Circle/distance_circle.out");
    Walker1.BestDistance50("../Results/Circle/distance50_circle.out");
  
    TravelingSalesman Walker2(numberOfCities,numberOfParents,numberOfGenerations);
    Walker2.CheckBounds();
    double side = 1.;
    cout << endl << "Città dentro ad un quadrato di lato 1" << endl;
    Walker2.Square(side);
    Walker2.RunGA(probabilityOfMutation, probabilityOfCrossover);
    Walker2.BestPath("../Results/Square/path_square.out");
    Walker2.BestDistance("../Results/Square/distance_square.out");
    Walker2.BestDistance50("../Results/Square/distance50_square.out");

  return 0;
}