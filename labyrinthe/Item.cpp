#include "Item.h";

CItem::CItem(CPosition pos)
{
	setPosItem(pos);
	Activate();
}

CItem::CItem(short x, short y)
{
	CPosition pos(x,y);
	setPosItem(pos);
	
	Activate();
}

CPosition CItem::getPosItem() const
{
	return positem_;
}

void CItem::setPosItem(CPosition pos)
{
	positem_ = pos;
}

bool CItem::getIsActive() const
{
	return isActive;
}

void CItem::Activate()
{
	isActive=true;
}

void CItem::disable()
{
	isActive=false;
}

bool CItem::operator==(CItem const& a)
{
	//vu qu'il ne peut pas avoir 2 items a la meme position nous pouvons donc vérifier la position pour savoir si on vérifie le meme item
	if(a.getPosItem() == getPosItem())
		return true;

	return false;
}