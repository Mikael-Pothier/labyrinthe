#pragma once

class CPosition
{
	short x_, y_;
public:
	CPosition() throw()
		:x_(0), y_(0)
	{
	}
	CPosition(const short x, const short y) 
		throw() 
		:x_(x), y_(y)
	{
	}
	short GetX() const throw()
	{
		return x_;
	}
	short GetY() const throw()
	{
		return y_;
	}
	bool operator==(const CPosition &p) const throw()
	{
		return GetX() == p.GetX() &&
			   GetY() == p.GetY();
	}
	bool operator!=(const CPosition &p) const throw()
	{
		return !(*this == p);
	}
};