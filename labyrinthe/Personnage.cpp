#include "Personnage.h";
#include <iostream>
using std::ostream;

CPersonnage::CPersonnage()
{
	nb_pas_ = NB_PAS_DEFAUT;
	vision_ = VISION_DEFAUT;
	direction_ = Orientation::Nord;
}

CPersonnage::CPersonnage(CPosition pos, unsigned short pasDepart, 
						unsigned short visionDepart, unsigned short vitesse)
{
	SetNbPas(pasDepart);
	SetVision(visionDepart);
	pos_personnage_ = pos;
	SetDirection(Orientation::Nord);
	SetVitesse(vitesse);
}

CPersonnage::CPersonnage(unsigned short x, unsigned short y, 
						unsigned short pasDepart, unsigned short visionDepart, 
						unsigned short vitesse)
{
	SetNbPas(pasDepart);
	SetVision(visionDepart);
	pos_personnage_ = CPosition(x, y);
	SetDirection(Orientation::Nord);
	SetVitesse(vitesse);
}

short CPersonnage::GetNbPas()
{
	return nb_pas_;
}

void CPersonnage::SetNbPas(unsigned short pas)
{
	nb_pas_ = pas;
}

short CPersonnage::GetVision() const
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

Orientation CPersonnage::GetDirectionInverse() const
{
	Orientation Inverse;
	switch (GetDirection())
	{
	case Nord:
		Inverse = Sud;
		break;
	case Sud:
		Inverse = Nord;
		break;
	case Est:
		Inverse = Ouest;
		break;
	case Ouest:
		Inverse = Est;
		break;
	}
	return Inverse;
}

void CPersonnage::SetDirection(const Orientation ori)
{
	direction_ = ori;
}

void CPersonnage::DescendrePas()
{
	--nb_pas_;
}

CPosition CPersonnage::GetPosition() const
{
	return pos_personnage_;
}

unsigned short CPersonnage::GetVitesse() const
{
	return vitesse_;
}

void CPersonnage::SetVitesse(const unsigned short vitesse)
{
	vitesse_ = vitesse;
}

void CPersonnage::Avancer()
{
	Marcher(GetVitesse());
}

void CPersonnage::Reculer()
{
	Marcher( -GetVitesse()  );
}

void CPersonnage::Marcher(const short vitesse)
{
	switch (GetDirection())
	{
	case Nord:
		pos_personnage_ = CPosition(pos_personnage_.GetX(), 
						  pos_personnage_.GetY() - vitesse);
		break;
	case Sud:
		pos_personnage_ = CPosition(pos_personnage_.GetX(), 
						  pos_personnage_.GetY() + vitesse);
		break;
	case Est:
		pos_personnage_ = CPosition(pos_personnage_.GetX() + vitesse, 
						  pos_personnage_.GetY());
		break;
	case Ouest:
		pos_personnage_ = CPosition(pos_personnage_.GetX() - vitesse,
						  pos_personnage_.GetY());
		break;
	}
	DescendrePas();
}

void CPersonnage::Gauche()
{
	SetDirection(PivoterGauche(GetDirection()));
}

void CPersonnage::Droite()
{
	SetDirection(PivoterDroite(GetDirection()));
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

void CPersonnage::SetPosition(CPosition pos)
{
	pos_personnage_ = pos;
}