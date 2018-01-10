#include "tools\vec3.h"

Vec3::Vec3() 
{ x = 0; y = 0; z = 0;}

Vec3::Vec3(float a_x, float a_y, float a_z) 
{ x = a_x; y = a_y; z = a_z;}

Vec3 Vec3::operator+(Vec3& a_vec)
{ return Vec3(x + a_vec.x, y + a_vec.y, z + a_vec.z); }

Vec3 Vec3::operator-(Vec3& a_vec)
{ return Vec3(x - a_vec.x, y - a_vec.y, z - a_vec.z); }

Vec3& Vec3::operator+=(const Vec3& a_vec)
{  
	this->x += a_vec.x;
	this->y += a_vec.y;
	this->z += a_vec.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& a_vec)
{
	this->x -= a_vec.x;
	this->y -= a_vec.y;
	this->z -= a_vec.z;
	return *this;
}

Vec3 Vec3::operator*(Vec3& a_vec)
{ return Vec3(x * a_vec.x, y * a_vec.y, z * a_vec.z); }

Vec3 Vec3::operator*(float a_float)
{ return Vec3(x * a_float, y * a_float, z * a_float); }

Vec3 Vec3::operator/(float a_float)
{
	if(a_float == 0) return Vec3();
	return Vec3(x/a_float, y/a_float, z/a_float);
}



