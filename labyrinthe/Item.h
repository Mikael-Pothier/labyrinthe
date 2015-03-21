#include "position.h";
#pragma once

class CItem
{
public:
	CItem(CPosition pos);
	CItem(short x, short y);

	CPosition getPosItem() const;
	void setPosItem(CPosition pos);

	bool getIsActive() const;
	void Activate();
	void disable();
	
	bool operator==(CItem const& a); 

private:
	CPosition positem_;
	bool isActive;

};