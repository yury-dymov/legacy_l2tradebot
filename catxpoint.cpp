#include "catxpoint.h"

CatXPoint::CatXPoint (double x, double y, double z) : x_ (x), y_ (y), z_ (z) 
{
}

void CatXPoint::setX (double x) 
{
	x_ = x;
}

void CatXPoint::setY (double y) 
{
	y_ = y;
}

void CatXPoint::setZ (double z)
{
	z_ = z;
}

double CatXPoint::x () const 
{
	return x_;
}

double CatXPoint::y () const 
{
	return y_;
}

double CatXPoint::z () const 
{
	return z_;
}

