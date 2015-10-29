#include "headers/QuaternionFK.h"	

// Quaternion declaration using joint angle and axis of revolution
Quaternion Getq(const double &theta, const char &axis)
{
	double s = cos(theta/2.0);
	Vec <double, 3> v; 
	for(int i = 0; i<3; ++i)
	{
		v[i] = 0;
	}
	switch (axis)
	{
		case 'x':
			v[0] = sin(theta/2.0);
		break;

		case 'y':
			v[1] = sin(theta/2.0);
		break;

		case 'z':
			v[2] = sin(theta/2.0);
		break;
	}


	return Quaternion(s,v);
}

// Function to Declare Dual Quaternion
DualQuat GetQ(Quaternion &Q_q, const char &axis, const double &trans,
		 const double &radius,const double &theta, const bool &rev)
/*
   axis - axis of revolution
   trans - translation of q(n) with respect to q(n-1) along the axis of revolution 
   radius - define translation of q(n) with respect to q(n-1) when rotation is involved 
   theta - joint angle 
   rev = '1' - translation is within the plane perpendicular to axis of revolution 
*/
{
	double p_s= 0.0;
	Vec <double,3> p_v;
	for(int i = 0; i < 3; ++i)
	{
		p_v[i] = 0.0;
	}
	switch (axis)
	{
		case 'x':
			p_v[0] = trans;
			if (rev == 1)
			{
				p_v[1] = radius * sin(theta);
				p_v[2] = radius * cos(theta);
			}
			else
			{
				p_v[1] = 0.0;
				p_v[2] = 0.0;
			}
		break;

		case 'y':
			p_v[1] = trans;
			if (rev == 1)
			{
				p_v[0] = radius * sin(theta);
				p_v[2] = radius * cos(theta);
			}
			else
			{
				p_v[0] = 0.0;
				p_v[2] = 0.0;
			}
		break;

		case 'z':
			p_v[2] = trans;
			if(rev ==1)
			{
				p_v[0] = radius * sin(theta);
				p_v[1] = radius * cos(theta);
			}
			else
			{
				p_v[0] = 0.0;
				p_v[1] = 0.0;
			}		
	break;
	}
	Quaternion Q_p = Quaternion(p_s,p_v);
	return DualQuat(Q_q,Q_p);
}

// Function to Display Rotation Parameters
void PrintR(Vec<double,12> &R)
{
	int i = 0;
	while (i < 12)
	{
		cout << R[i] << "  ";
		if(((i + 1) % 4) == 0)
		cout << endl;
		i++;
	}
}

// Main Function
int main (int argc, char **argv) 
{
	//Temporary storage for rotation parameters 
	Vec<double, 12> rot; 

	//position parameters for ODE
	double position[3];

 	float J1 = 0;
 	float J2 = 0;
 	float J3 = 0;

	//joint angle 1 revolves around the z axis
	Quaternion q1 = Getq(J1, 'z'); 

	//joint angle 2 revolves around the y axis
	Quaternion q2 = Getq(J2, 'y');
 
	//joint angle 3 revolves around the y axis
	Quaternion q3 = Getq(J3, 'y');
 
	//joint angle 1 translation about z-axis
	DualQuat Q1 = GetQ(q1, 'z', length1+length2, 0,J1,0); 

	//joint angle 2 translation on xz-plane
	DualQuat Q2 = GetQ(q2, 'y', 0, length3,J2,1); 

	//joint angle 3 translation on xz-plane
	DualQuat Q3 = GetQ(q3, 'y', 0, length4,J3,1); 

	//Get Resultant Dual Quaternion
	DualQuat QAns = Q1*Q2*Q3;

	Quaternion pos = QAns.pcomp();
	Vec <double, 3> loc = pos.vcomp();
	
	Quaternion Q_r = QAns.qcomp();

	//Display Resultant Dual Quaterion
	cout << "Dual Quaternion:  " << QAns << endl;


	//Display End-Effector Position 
	cout << "End Effector Position:  ";
	for(int i = 0; i < 3; ++i)
	{
		position[i] = loc[i];
		cout << position[i] << "   ";
	}
	cout << endl << endl;

}




