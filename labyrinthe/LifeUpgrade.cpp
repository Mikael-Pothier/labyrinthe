#include "LifeUpgrade.h";

CLifeUpgrade::CLifeUpgrade(CPosition pos, char Symbole, unsigned short augmentation) : CItem(pos, Symbole, 0, augmentation)
{

}

CLifeUpgrade::CLifeUpgrade(short x, short y, char Symbole, unsigned short augmentation) : CItem(CPosition(x, y), Symbole, 0, augmentation)
{

}