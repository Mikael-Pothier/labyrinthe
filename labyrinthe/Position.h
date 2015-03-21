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

	CPosition VoisineEst() const throw()
	{
		return CPosition(GetX() + 1, GetY());
	}

	CPosition VoisineNord() const throw()
	{
		return CPosition(GetX(), GetY() - 1);
	}

	CPosition VoisineOuest() const throw()
	{
		return CPosition(GetX() - 1, GetY());
	}

	CPosition VoisineSud() const throw()
	{
		return CPosition(GetX(), GetY() + 1);
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