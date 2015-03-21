#include "TorcheUpgrade.h";

CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole,unsigned short duree) : CItem(pos,Symbole,duree)
{
	Portee_= PorteeDefaut;
}

CTorcheUpgrade::CTorcheUpgrade(CPosition pos, char Symbole,unsigned short duree,unsigned short augmentation) : CItem(pos,Symbole,duree)
{
	if(augmentation >0)
		Portee_=augmentation;
	else
		Portee_= PorteeDefaut;
}

CTorcheUpgrade::CTorcheUpgrade(short x,short y, char Symbole,unsigned short duree,unsigned short augmentation) : CItem(x,y,Symbole,duree) 
{
	if(augmentation >0)
		Portee_=augmentation;
	else
		Portee_= PorteeDefaut;
}

CTorcheUpgrade::CTorcheUpgrade(short x,short y, char Symbole,unsigned short duree): CItem(x,y,Symbole,duree)
{
	Portee_= PorteeDefaut;
}

unsigned short CTorcheUpgrade::getPortee()
{
	return Portee_;
}