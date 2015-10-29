#include <cv.hpp>		
#include <iostream>							
#include <cmath>	
#include "DualQuaternionClass.h"

using namespace std;	
using namespace cv;

// Variable Declaration

const double length1 = 200;
const double length2 = 75;
const double length3 = 280;
const double length4 = 75;	

//Function Prototypes
void PrintR(Vec<double,12> &R);
