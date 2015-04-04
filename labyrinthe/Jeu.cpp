#include "Jeu.h"
#include "Commande.h"
#include "Menu.h"
#include "Espace.h"

#include<iostream>
using std::ostream;

const CPosition
CJeu::POS_PERSO_DEFAUT = CPosition(1, 1),
CJeu::POS_ITEMS_DEFAUT = CPosition(5, 5),
CJeu::POS_OBJECTIF_DEFAUT = CPosition(10, 10);

const char CJeu::VIDE = ' ';
const string CJeu::ESPACE_JEU_DEFAUT = "Map.txt";

CJeu::CJeu() throw() : perso_(POS_PERSO_DEFAUT), 
					   espace_jeu_(ESPACE_JEU_DEFAUT),
					   objectif_(POS_OBJECTIF_DEFAUT)
{
	CEspace::CreerEspace(espace_jeu_);
	PlaceItem(NBTORCH_DEFAUT,NBLIFE_DEFAUT);
	perso_.SetPosition(CEspace::EtablirPosition(CEspace::DEPART));
	objectif_ = CEspace::EtablirPosition(CEspace::FIN);
	CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
}

bool CJeu::Gagne()
{
	return perso_.GetPosition() == objectif_;
}

bool CJeu::Perd()
{
	return perso_.EstMort();
}

bool CJeu::Fini()
{
	return Perd() || Gagne();
}

void CJeu::AfficherEtat(ostream & os) const
{
	system("cls");
	for (int i = CEspace::Y_MIN; i < CEspace::Max_Y(); ++i)
	{
		for (int j = CEspace::X_MIN; j < CEspace::Max_X(); ++j)
		{
			const CPosition pos(j, i);

			if (pos == perso_.GetPosition())
				os << perso_;
			//if (CEspace::EstVisible(pos))		
				CEspace::Afficher(os, pos);
			//else
			//	os << VIDE;
		}
		os << '\n';
	}
}

void CJeu::Executer(const CCommande & c)
{
	if (c == CMenu::AVANCER)
	{
		if (IsWalkable(perso_.GetDirection()))
		{
			perso_.Avancer();

			CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
		}
	}
	else if (c == CMenu::DROITE)
	{
		perso_.Droite();
	}
	else if (c == CMenu::GAUCHE)
	{
		perso_.Gauche();
	}
	else if (c == CMenu::RECULER)
	{
		if(IsWalkable(perso_.GetDirectionInverse()))
		perso_.Reculer();
		CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
	}
}

bool CJeu::IsWalkable(Orientation direction)
{
	bool walkable = false;
	switch (direction)
	{
	case Nord:
		walkable = CEspace::EstAccessible(perso_.GetPosition().VoisineNord());
		break;
	case Sud:
		walkable = CEspace::EstAccessible(perso_.GetPosition().VoisineSud());
		break;
	case Est:
		walkable = CEspace::EstAccessible(perso_.GetPosition().VoisineEst());
		break;
	case Ouest:
		walkable = CEspace::EstAccessible(perso_.GetPosition().VoisineOuest());
		break;
	}
	return walkable;
}

void CJeu::FillTorchRandom(int nbTorch)
{
	try
	{
		for (int i = 0; i < nbTorch; ++i)
		{
			CPosition pos = CEspace::TakeSpace();
			items_.push_back(CTorcheUpgrade(pos.GetX(), pos.GetY(), CTorcheUpgrade::SYMBOLE_DEFAUT, CTorcheUpgrade::PORTEE_DEFAUT));
		}
	}
	catch (CEspace::MapPleine) 
	{}
}

void CJeu::FillLifeRandom(int nbLife)
{
	try
	{
		for (int i = 0; i < nbLife; ++i)
		{
			CPosition pos = CEspace::TakeSpace();
			items_.push_back(CLifeUpgrade(pos.GetX(), pos.GetY(), CLifeUpgrade::SYMBOLE_DEFAUT, CLifeUpgrade::NB_PAS_DEFAUT));
		}
	}
	catch (CEspace::MapPleine)
	{}
}

void CJeu::PlaceItem(int nbTorch, int nbLife)
{
	FillTorchRandom(nbTorch);
	FillLifeRandom(nbLife);
	for (int i = 0; i < items_.size(); ++i)
	{
		CEspace::PlaceInMap(items_[i].GetPosItem(), items_[i].GetSymbole());
	}
}