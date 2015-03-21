#include "Personnage.h";

CPersonnage::CPersonnage()
{
	NbPas_ = NbPasDefaut;
	Vision_ = VisionDefaut;
	direction_ = Orientation::Nord;

}

CPersonnage::CPersonnage(CPosition pos,unsigned short pasDepart,unsigned short visionDepart)
{
	NbPas_ = pasDepart;
	Vision_ = visionDepart;
	posPersonnage_ = pos;
	direction_ = Orientation::Nord;
}

CPersonnage::CPersonnage(unsigned short x,unsigned short y,unsigned short pasDepart,unsigned short visionDepart)
{
	NbPas_ = pasDepart;
	visionDepart = visionDepart;
	posPersonnage_= CPosition(x,y);
	direction_ = Orientation::Nord;
}

short CPersonnage::GetNbPas()
{
	return NbPas_;
}

void CPersonnage::SetNbPas(unsigned short pas)
{
	NbPas_=pas;
}

short CPersonnage::GetVision()
{
	return Vision_;
}

void CPersonnage::SetVision(unsigned short vision)
{
	Vision_=vision;
}

Orientation CPersonnage::GetDirection()
{
	return direction_;
}

void CPersonnage::DescendrePas()
{
	--NbPas_;
}

void CPersonnage::Marcher()
{
	switch (GetDirection())
	{
	case Nord:
		posPersonnage_ = CPosition(posPersonnage_.GetX(),posPersonnage_.GetY()-1);
		break;
	case Sud:
		posPersonnage_ = CPosition(posPersonnage_.GetX(),posPersonnage_.GetY()+1);
		break;
	case Est:
		posPersonnage_ = CPosition(posPersonnage_.GetX()+1,posPersonnage_.GetY());
		break;
	case Ouest:
		posPersonnage_ = CPosition(posPersonnage_.GetX()-1,posPersonnage_.GetY());
		break;
	}
	DescendrePas();
}

bool CPersonnage::estMort()
{
	return GetNbPas() ==0;
}