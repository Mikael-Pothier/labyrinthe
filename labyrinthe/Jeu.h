#pragma once
#include "Personnage.h"
#include "TorcheUpgrade.h"
#include "LifeUpgrade.h"
#include <iosfwd>
#include <vector>
#include <string>

using std::ostream;
using std::vector;
using std::string;

class CCommande;
class CJeu
{
	const int NBTORCH_DEFAUT = 5;
	const int NBLIFE_DEFAUT = 5;
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
	bool IsWalkable(Orientation direction);
	void FillTorchRandom(int nbTorch);
	void FillLifeRandom(int nbLife);
public:
	CJeu() throw();
	bool Fini();
	void AfficherEtat(ostream &) const;
	void Executer(const CCommande &);
	void PlaceItem(int nbTorch, int nbLife);
};