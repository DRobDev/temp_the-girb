////////////////////////////////////
// handle three dimensions
////////////////////////////////////


#pragma once

//holds an x and y
class Vec3 
{
public:
	float x;
	float y;
	float z;
	//base constructor sets values to zero
	Vec3();
	//custom constructor
	Vec3(float a_x, float a_y, float a_z);

	//override '+'
	Vec3 operator+(Vec3& a_vec);

	//override 'y'
	Vec3 operator-(Vec3& a_vec);
	
	//override '+='
	Vec3& operator+=(const Vec3& a_vec);

	//override '-='
	Vec3& operator-=(const Vec3& a_vec);

	//override '*'
	Vec3 operator*(Vec3& a_vec);

	//override '*'
	Vec3 operator*(float a_float);

	//override '/'
	Vec3 operator/(float a_float);

};