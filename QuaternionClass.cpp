#include "headers/QuaternionClass.h"

//Quaternion assignment
Quaternion Quaternion::operator=(const Quaternion& other)
{
	double s = other.s;
	Vec<double, 3> v = other.v;
	return	Quaternion(s,v);
}	

//Quaternion additon
Quaternion Quaternion::operator+(const Quaternion& other)
{
	double qans_s = s + other.s;		
	Vec <double, 3> qans_v = v + other.v;
	return Quaternion( qans_s, qans_v);	
}

//Quaternion multiplication
Quaternion Quaternion::operator*(const Quaternion& other)
{
	double qans_s = s * other.s - v.dot(other.v);
	Vec <double, 3> qans_v = s * other.v + other.s * v + v.cross(other.v);
	return Quaternion( qans_s, qans_v);;
}

//Quaternion print function
ostream& operator<<(ostream& out, Quaternion& q)
{
	out << q.s << ",  <";
	for (int i = 0; i < 2; ++i)
	{
		cout << q.v[i] << ",  ";
	}
	out << q.v[2] << "> ";	
	return out;
}

//Inverse Function
Quaternion Quaternion::inv()		
{
	Vec <double, 3 > vinv = -v;
	return Quaternion(s,vinv);	
}

//Get s component of Quaternion	
double Quaternion::scomp()
{
	return s;
}

//Get v component of Quaternion
Vec <double, 3> Quaternion::vcomp()
{
	return v;
}
/*
   Get equivalent rotation parameters of Quaternion
   Rotation Vector <R11 R12 R13 0 R21 R22 R23 0 R31 R32 R33 0>
*/
Vec<double, 12> Quaternion::GetR()
{
	Vec<double, 12> Rq;
	for (int i = 0; i < 12; ++i)
	{
		if(((i + 1) % 4) == 0)
			Rq[i] = 0;
	}
	Rq[0]  = 1.0 - 2.0 * (pow((v[1]), 2.0) + pow((v[2]), 2.0));
	Rq[1]  = 2.0 * (v[0] * v[1] - s * v[2]);
	Rq[2]  = 2.0 * (v[0] * v[2] + s * v[1]);
	Rq[4]  = 2.0 * (v[0] * v[1] + s * v[2]);
	Rq[5]  = 1.0 - 2.0 * (pow((v[0]), 2.0) + pow((v[2]), 2.0));
	Rq[6]  = 2.0 * (v[1] * v[2] - s * v[0]);
	Rq[8]  = 2.0 * (v[0] * v[2] - s * v[1]);
	Rq[9]  = 2.0 * (v[1] * v[2] + s * v[0]);
	Rq[10] = 1.0 - 2.0 * (pow((v[0]), 2.0) + pow((v[1]), 2.0));
	return Rq;
}
