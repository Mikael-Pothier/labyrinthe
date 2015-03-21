#include "Item.h";

CItem::CItem()
{
	setPosItem(-1,-1);
}

CItem::CItem(Cposition pos)
{
	setPosItem(pos);
}

CItem::CItem(short x, short y)
{
	setPosItem(x,y);
}

Cposition CItem::getPosItem()
{
	return positem_;
}

void CItem::setPosItem(Cposition pos)
{
	
}