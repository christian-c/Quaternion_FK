#include <cv.hpp>		
#include <iostream>							
#include <cmath>	
#include "QuaternionClass.h"

using namespace std;	
using namespace cv;
// Dual Quaternion Class Q(q,p)

class DualQuat
{
	private:
		Quaternion q;
		Quaternion p; 
	public:
		DualQuat(Quaternion qcomp, Quaternion pcomp): q(qcomp), p(pcomp) {}
		// Operator Overloading
		DualQuat operator=(const DualQuat& other);
		DualQuat operator*(const DualQuat& other);
		friend ostream& operator<<(ostream&, DualQuat&);

		//Function Prototypes
		Quaternion qcomp();
		Quaternion pcomp();
		
};

