#pragma once;
#include "Position.h";
#include "Orientation.h";

class CPersonnage
{
public:
	CPersonnage();

	CPersonnage(CPosition pos, unsigned short pasDepart = NB_PAS_DEFAUT, 
				unsigned short visionDepart = VISION_DEFAUT);

	CPersonnage(unsigned short x, unsigned short y, unsigned short pasDepart = NB_PAS_DEFAUT,
				unsigned short visionDepart = VISION_DEFAUT);

	void SetNbPas(unsigned short pas);
	short GetNbPas();

	void SetVision(unsigned short vision);
	short GetVision();

	Orientation GetDirection() const;
	CPosition GetPosition() const;

	void Marcher();
	bool EstMort();
private:
	unsigned short nb_pas_;
	unsigned short vision_;

	CPosition pos_personnage_;
	Orientation direction_;

	static const short NB_PAS_DEFAUT = 50;
	static const short VISION_DEFAUT = 3;

	void DescendrePas();
};
#include <iosfwd>
using std::ostream;
ostream& operator<<(ostream &, const CPersonnage &);