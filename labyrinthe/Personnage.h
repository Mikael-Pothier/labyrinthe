#include "Position.h";
#include "Orientation.h";
#pragma once;

class CPersonnage
{
public:
	CPersonnage();
	CPersonnage(CPosition pos,unsigned short pasDepart,unsigned short visionDepart);
	CPersonnage(unsigned short x,unsigned short y,unsigned short pasDepart,unsigned short visionDepart);

	void SetNbPas(unsigned short pas);
	short GetNbPas();

	void SetVision(unsigned short vision);
	short GetVision();

	Orientation GetDirection();

	void Marcher();
	bool estMort();
private:
	unsigned short NbPas_;
	unsigned short Vision_;

	CPosition posPersonnage_;
	Orientation direction_;

	const short NbPasDefaut=50;
	const short VisionDefaut=3;

	void DescendrePas();
};