#pragma once;
#include "Position.h"
#include "Orientation.h"
#include <map>

using std::map;

class CPersonnage
{
public:
	CPersonnage();

	CPersonnage(CPosition pos, unsigned short pasDepart = NB_PAS_DEFAUT, 
				unsigned short visionDepart = VISION_DEFAUT, unsigned short vitesse = VITESSE_DEFAUT);

	CPersonnage(unsigned short x, unsigned short y, unsigned short pasDepart = NB_PAS_DEFAUT,
				unsigned short visionDepart = VISION_DEFAUT, unsigned short vitesse = VITESSE_DEFAUT);

	void SetNbPas(unsigned short pas);
	short GetNbPas() const;

	void SetVision(unsigned short vision);
	short GetVision() const;

	void SetVitesse(const unsigned short vitesse);
	unsigned short GetVitesse() const;

	unsigned short GetItem(char symbole);
	void SetItem(char symbole, unsigned short nb);
	void AjouterDuree(char symbole, unsigned short nb);

	Orientation GetDirection() const;
	Orientation GetDirectionInverse() const;
	void SetDirection(const Orientation);
	CPosition GetPosition() const;
	void SetPosition(CPosition pos);

	void Avancer();
	void Reculer();
	void Gauche();
	void Droite();
	bool EstMort();
	void ReduireAllItem();
private:

	static const unsigned short NB_PAS_DEFAUT = 100;
	static const unsigned short VISION_DEFAUT = 5;
	static const unsigned short VITESSE_DEFAUT = 1;

	unsigned short nb_pas_;
	unsigned short vision_;
	unsigned short vitesse_;

	CPosition pos_personnage_;
	Orientation direction_;
	map<char, int> DureeItem_;

	void Marcher(const short vitesse);
	void DescendrePas();
	void reduireItem(char symbole);
};
#include <iosfwd>
using std::ostream;
ostream& operator<<(ostream &, const CPersonnage &);