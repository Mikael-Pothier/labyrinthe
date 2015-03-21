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
	SetPosItem(CPosition(x,y));
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
	return EstActive_;
}

void CItem::Activate()
{
	EstActive_=true;
}

void CItem::Disable()
{
	EstActive_=false;
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