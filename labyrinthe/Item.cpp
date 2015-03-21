#include "Item.h";

CItem::CItem(CPosition pos, char Symbole, unsigned short durée)
{
	SetPosItem(pos);
	Duree_=durée;
	Symbole_=Symbole;
	Activate();
}

CItem::CItem(short x, short y, char Symbole, unsigned short durée)
{
	CPosition pos(x,y);
	SetPosItem(pos);
	Duree_=durée;
	Symbole_=Symbole;
	Activate();
}

CPosition CItem::GetPosItem() const
{
	return positem_;
}

void CItem::SetPosItem(CPosition pos)
{
	positem_ = pos;
}

bool CItem::GetIsActive() const
{
	return isActive_;
}

void CItem::Activate()
{
	isActive_=true;
}

void CItem::Disable()
{
	isActive_=false;
}

bool CItem::operator==(CItem const& a)
{
	//vu qu'il ne peut pas avoir 2 items a la meme position nous pouvons donc vérifier la position pour savoir si on vérifie le meme item
	if(a.GetPosItem() == GetPosItem())
		return true;

	return false;
}

short CItem::GetDuree()
{
	return Duree_;
}

char CItem::GetSymbole()
{
	return Symbole_;
}