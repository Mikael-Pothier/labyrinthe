#pragma once

class CItem
{
public:
	CItem();
	CItem(CPosition pos);
	CItem(short x, short y);
	~CItem();

	Cposition getPosItem();
	void setPosItem(CPosition pos);
	void setPosItem(short x, short y);

private:
	CPosition positem_;/*changer int pour class position*/ 

};