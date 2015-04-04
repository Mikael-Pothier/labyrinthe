#pragma once
#include "Personnage.h"
#include "Item.h"
#include <iosfwd>
#include <vector>
#include <string>
using std::ostream;
using std::vector;
using std::string;

class CCommande;
class CJeu
{
	CPersonnage perso_;
	vector<CItem> items_;
	CPosition objectif_;
	string espace_jeu_;

	static const CPosition
		POS_PERSO_DEFAUT, POS_ITEMS_DEFAUT, POS_OBJECTIF_DEFAUT;
	static const char
		VIDE;
	static const string ESPACE_JEU_DEFAUT;

	bool Gagne();
	bool Perd();
public:
	CJeu() throw();
	bool Fini();
	void AfficherEtat(ostream &) const;
	void Executer(const CCommande &);
};