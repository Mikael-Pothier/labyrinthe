#include "Item.h";

CItem::CItem(CPosition pos, char symbole, unsigned short duree)
{
	SetPosItem(pos);
	duree_ = duree;
	symbole_ = symbole;
	Activate();
}

CItem::CItem(short x, short y, char symbole, unsigned short duree)
{
	CPosition pos(x, y);
	SetPosItem(pos);
	duree_ = duree;
	symbole_ = symbole;
	Activate();
}

CPosition CItem::GetPosItem() const
{
	return pos_item_;
}

void CItem::SetPosItem(CPosition pos)
{
	pos_item_ = pos;
}

bool CItem::GetIsActive() const
{
	return is_active_;
}

void CItem::Activate()
{
	is_active_ = true;
}

void CItem::Disable()
{
	is_active_ = false;
}

short CItem::GetDuree()
{
	return duree_;
}

char CItem::GetSymbole() const
{
	return symbole_;
}

bool CItem::operator==(CItem const& a)
{
	//vu qu'il ne peut pas avoir 2 items a la meme position nous pouvons 
	//donc vérifier la position pour savoir si on vérifie le meme item
	return a.GetPosItem() == GetPosItem();
}
#include <iostream>
using std::ostream;

ostream & operator<<(ostream &os, const CItem &it)
{
	return os << it.GetSymbole();
}