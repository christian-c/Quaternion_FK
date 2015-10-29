#include <cv.hpp>		
#include <iostream>							
#include <cmath>					

using namespace std;	
using namespace cv;

// Quaternion Class q(s,v)

class Quaternion 
{
	private:
		double s;
		Vec < double, 3 >  v; 
	public:
		Quaternion(double qs, Vec <double, 3> qv): s(qs), v(qv) {}
		//Operator Overloading
		Quaternion operator=(const Quaternion& other);
		Quaternion operator+(const Quaternion& other);
		Quaternion operator*(const Quaternion& other);
		friend ostream& operator<<(ostream&, Quaternion&);
		
		//Fuction Prototypes
		Quaternion inv();
		double scomp();
		Vec <double, 3> vcomp();
		Vec<double, 12> GetR();
		
};
