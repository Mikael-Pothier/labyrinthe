#include "Item.h";

CItem::CItem(CPosition pos, char symbole, unsigned short duree)
{
	SetPosItem(pos);
	symbole_ = symbole;
	duree_ = duree;
}

CItem::CItem(short x, short y, char symbole, unsigned short duree)
{
	CPosition pos(x, y);
	SetPosItem(pos);
	symbole_ = symbole;
	duree_ = duree;
}

CItem::CItem(CPosition pos, char symbole)
{
	SetPosItem(pos);
	symbole_ = symbole;
	duree_ = 0;
}

CItem::CItem(short x, short y, char symbole)
{
	CPosition pos(x, y);
	SetPosItem(pos);
	symbole_ = symbole;
	duree_ = 0;
}

CPosition CItem::GetPosItem() const
{
	return pos_item_;
}

void CItem::SetPosItem(CPosition pos)
{
	pos_item_ = pos;
}

char CItem::GetSymbole() const
{
	return symbole_;
}

unsigned short CItem::getduree() const
{
	return duree_;
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