#include "Item.h";

CItem::CItem(CPosition pos, char symbole, unsigned short duree, unsigned short bonus)
{
	SetPosItem(pos);
	symbole_ = symbole;
	duree_ = duree;
	bonus_ = bonus;
}

CItem::CItem(short x, short y, char symbole, unsigned short duree, unsigned short bonus) :
		CItem(CPosition(x,y), symbole, duree, bonus)
{

}

CItem::CItem(CPosition pos, char symbole)
{
	SetPosItem(pos);
	symbole_ = symbole;
	duree_ = 0;
}

CItem::CItem(short x, short y, char symbole) : CItem(CPosition(x, y), symbole)
{

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

unsigned short CItem::GetDuree() const
{
	return duree_;
}

unsigned short CItem::GetBonus() const
{
	return bonus_;
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