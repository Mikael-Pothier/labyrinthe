#pragma once
#include "Personnage.h"
#include "TorcheUpgrade.h"
#include "LifeUpgrade.h"
#include <iosfwd>
#include <vector>
#include <string>
#include <memory>
#include <map>

using std::ostream;
using std::vector;
using std::string;
using std::unique_ptr;
using std::map;

class CCommande;
class CJeu
{
	const int NBTORCH_DEFAUT = 50;
	const int NBLIFE_DEFAUT = 50;

	CPersonnage perso_;
	vector<unique_ptr<CItem>> items_;
	map<unique_ptr<CItem>, short> objets_actifs_;
	CPosition objectif_;
	string espace_jeu_;
	bool partie_gagne_ = false;

	static const CPosition
		POS_PERSO_DEFAUT, POS_ITEMS_DEFAUT, POS_OBJECTIF_DEFAUT;
	static const char
		VIDE;
	static const string ESPACE_JEU_DEFAUT;

	bool Gagne();
	bool Perd();

	bool DirectionAccessible(Orientation direction);

	void PlacerTorchesHasard(int nbTorch);
	void PlacerViesHasard(int nbLife);

	void RamasserItem();
	int EtablirPosItem(CPosition pos);
	void DiminuerEffetsItem();
public:
	CJeu() throw();

	bool Fini();
	bool PartieGagne() const { return partie_gagne_; };

	void AfficherEtat(ostream &) const;
	void AfficherResultats(ostream &) const;

	void Executer(const CCommande &);
	void PlacerItems(int nbTorch, int nbLife);
};