#pragma once
#include "Personnage.h"
#include "Item.h"
#include <iosfwd>
#include <fstream>
#include <vector>
#include <string>
using std::ostream;
using std::vector;
using namespace std;

class CCommande;
class CJeu
{
	CPersonnage perso_;
	vector<CItem> items_;
	CPosition objectif_;
	vector<vector<char>> Map_;
	static const CPosition
		POS_PERSO_DEFAUT, POS_ITEMS_DEFAUT, POS_OBJECTIF_DEFAUT;
	static const char
		ESPACE_VIDE;

	bool Gagne();
	bool Perd();
	void AfficherMap(ostream & os) const;
public:
	CJeu() throw() : perso_(POS_PERSO_DEFAUT)
	{

	}
	bool Fini();
	void AfficherEtat(ostream &) const;
	void Executer(const CCommande &);
	void ReadMap(const string fileName);
	CPosition TrouverPosDepart();
	void PlacerPersonnage(CPosition pos);
};