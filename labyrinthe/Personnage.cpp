#include "Personnage.h";
#include <iostream>
using std::ostream;

CPersonnage::CPersonnage()
{
	nb_pas_ = NB_PAS_DEFAUT;
	vision_ = VISION_DEFAUT;
	direction_ = Orientation::Nord;

}

CPersonnage::CPersonnage(CPosition pos, unsigned short pasDepart, unsigned short visionDepart)
{
	nb_pas_ = pasDepart;
	vision_ = visionDepart;
	pos_personnage_ = pos;
	direction_ = Orientation::Nord;
}

CPersonnage::CPersonnage(unsigned short x, unsigned short y, unsigned short pasDepart, unsigned short visionDepart)
{
	nb_pas_ = pasDepart;
	visionDepart = visionDepart;
	pos_personnage_ = CPosition(x, y);
	direction_ = Orientation::Nord;
}

short CPersonnage::GetNbPas()
{
	return nb_pas_;
}

void CPersonnage::SetNbPas(unsigned short pas)
{
	nb_pas_ = pas;
}

short CPersonnage::GetVision()
{
	return vision_;
}

void CPersonnage::SetVision(unsigned short vision)
{
	vision_ = vision;
}

Orientation CPersonnage::GetDirection() const
{
	return direction_;
}

void CPersonnage::DescendrePas()
{
	--nb_pas_;
}

CPosition CPersonnage::GetPosition() const
{
	return pos_personnage_;
}

void CPersonnage::Marcher()
{
	switch (GetDirection())
	{
	case Nord:
		pos_personnage_ = CPosition(pos_personnage_.GetX(), pos_personnage_.GetY() - 1);
		break;
	case Sud:
		pos_personnage_ = CPosition(pos_personnage_.GetX(), pos_personnage_.GetY() + 1);
		break;
	case Est:
		pos_personnage_ = CPosition(pos_personnage_.GetX() + 1, pos_personnage_.GetY());
		break;
	case Ouest:
		pos_personnage_ = CPosition(pos_personnage_.GetX() - 1, pos_personnage_.GetY());
		break;
	}
	DescendrePas();
}

bool CPersonnage::EstMort()
{
	return GetNbPas() == 0;
}

ostream & operator<<(ostream &os, const CPersonnage &p)
{
	switch (p.GetDirection())
	{
	case Est:
		os << '>'; break;
	case Nord:
		os << 'A'; break;
	case Ouest:
		os << '<'; break;
	case Sud:
		os << 'V'; break;
	}
	return os;
}