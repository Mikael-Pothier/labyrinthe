#pragma once
#include "Personnage.h"
#include "Item.h"
#include <iosfwd>
#include <vector>
using std::ostream;
using std::vector;
class CCommande;
class CJeu
{
	CPersonnage perso_;
	vector<CItem> items_;
	CPosition objectif_;
	static const CPosition
		POS_PERSO_DEFAUT, POS_ITEMS_DEFAUT, POS_OBJECTIF_DEFAUT;
	static const char
		ESPACE_VIDE;

	bool Gagne();
	bool Perd();
public:
	CJeu() throw() : perso_(POS_PERSO_DEFAUT)
	{
		//dfgsdghdfg
	}
	bool Fini();
	void AfficherEtat(ostream &) const;
	void Executer(const CCommande &);
};