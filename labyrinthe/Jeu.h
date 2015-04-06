#pragma once
#include "Personnage.h"
#include "TorcheUpgrade.h"
#include "LifeUpgrade.h"
#include <iosfwd>
#include <vector>
#include <string>
#include <memory>
using std::ostream;
using std::vector;
using std::string;
using std::unique_ptr;

class CCommande;
class CJeu
{
	const int NBTORCH_DEFAUT = 5;
	const int NBLIFE_DEFAUT = 5;
	CPersonnage perso_;
	vector<unique_ptr<CItem>> items_;
	CPosition objectif_;
	string espace_jeu_;
	bool partie_gagne = false;

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
	void TakeItem();
	int FindPosItem(CPosition pos);
public:
	CJeu() throw();
	bool Fini();
	bool PartieGagne() const { return partie_gagne; };
	void AfficherEtat(ostream &) const;
	void AfficherResultats(ostream &) const;
	void Executer(const CCommande &);
	void PlaceItem(int nbTorch, int nbLife);
};