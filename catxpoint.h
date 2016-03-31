#ifndef __CATX_POINT__
#define __CATX_POINT__

class CatXPoint
{
	private:
		double x_;
		double y_;
		double z_;
	public:
		CatXPoint (double x = 0, double y = 0, double z = 0);
		void setX (double x);
		void setY (double y);
		void setZ (double z);
		double x () const;
		double y () const;
		double z () const;
};

#endif
