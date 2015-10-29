#include "headers/DualQuaternionClass.h"

//Dual Quaternion Assignment
DualQuat DualQuat::operator=(const DualQuat& other)
{
	Quaternion q = other.q;
	Quaternion p = other.p;
	return	DualQuat(q,p);
}	
#include <cv.hpp>		
#include <iostream>										
#include <vector>
//Dual Quaternion Multiplication
DualQuat DualQuat::operator*(const DualQuat& other)
{
	Quaternion q_ans = q * other.q;
	Quaternion p_ans = q * other.p * q.inv() + p;
	return DualQuat( q_ans, p_ans);;
}

//Dual Quaternion Print Function
ostream& operator<<(ostream& out, DualQuat& Q)
{
	out << "([ " << Q.q << "], <";
	Vec <double, 3> pos = Q.p.scomp();
	for (int i = 0; i < 2; ++i)
	{
		cout << pos[i] << ",  ";
	}
	out << pos[2] << ">) " << endl;	
	return out;
}

//Get q component of Dual Quaternion
Quaternion DualQuat::qcomp()
{
	return q;
}

//Get p component of Dual Quaternion
Quaternion DualQuat::pcomp()
{
	return p;
}

