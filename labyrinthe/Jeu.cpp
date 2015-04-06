#include "Jeu.h"
#include "Commande.h"
#include "Menu.h"
#include "Espace.h"

#include<iostream>
using std::ostream;
using std::move;

const CPosition
CJeu::POS_PERSO_DEFAUT = CPosition(1, 1),
CJeu::POS_ITEMS_DEFAUT = CPosition(5, 5),
CJeu::POS_OBJECTIF_DEFAUT = CPosition(10, 10);

const char CJeu::VIDE = ' ';
const string CJeu::ESPACE_JEU_DEFAUT = "Map.txt";

CJeu::CJeu() throw() : perso_(POS_PERSO_DEFAUT), 
					   espace_jeu_(ESPACE_JEU_DEFAUT)
{
	CEspace::CreerEspace(espace_jeu_);
	PlaceItem(NBTORCH_DEFAUT,NBLIFE_DEFAUT);
	perso_.SetPosition(CEspace::EtablirPosition(CEspace::DEPART));
	CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
	objectif_ = CEspace::EtablirPosition(CEspace::FIN);
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
	partie_gagne = Gagne();
	return partie_gagne || Perd();
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
			else if (CEspace::EstVisible(pos))		
				CEspace::Afficher(os, pos);
			else
				os << VIDE;
		}
		os << '\n';
	}
	os << "Pas restants: " << perso_.GetNbPas() << 
		  " Vision actuelle: " << perso_.GetVision() << 
		  " Torche(" << "): " << CTorcheUpgrade::GetSymbole() <<
		  " Nourriture(" << "): " << CLifeUpgrade::GetSymbole() << '\n';
}

void CJeu::AfficherResultats(ostream & os) const
{
	string msg = PartieGagne() ? "Vous avez gagne!" : "Vous avez perdu...";
	os << msg << '\n';
}

void CJeu::Executer(const CCommande & c)
{
	if (c == CMenu::AVANCER)
	{
		if (IsWalkable(perso_.GetDirection()))
		{
			perso_.Avancer();
			perso_.ReduireAllItem();
			TakeItem();
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
		if (IsWalkable(perso_.GetDirectionInverse()))
		{
			perso_.Reculer();
			perso_.ReduireAllItem();
			TakeItem();
			CEspace::EtablirVisibles(perso_.GetPosition(), perso_.GetVision());
		}
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
			unique_ptr<CTorcheUpgrade>p(new CTorcheUpgrade(pos.GetX(), pos.GetY()));
			items_.push_back(move(p));
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
			unique_ptr<CLifeUpgrade> p(new CLifeUpgrade(pos.GetX(), pos.GetY(), 
									   CLifeUpgrade::SYMBOLE_DEFAUT, CLifeUpgrade::NB_PAS_DEFAUT));
			items_.push_back(move(p));
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
		CEspace::PlaceInMap(items_[i]->GetPosItem(), items_[i]->GetSymbole());
	}
}

int CJeu::FindPosItem(CPosition pos)
{
	for (int i = 0; i < items_.size(); ++i)
	{
		if (pos == items_[i]->GetPosItem())
			return i;
	}
	return -1;
}

void CJeu::TakeItem()
{
	int posItem = FindPosItem(perso_.GetPosition());

	if (posItem != -1)
	{
		items_[posItem]->UseItem(perso_);
		CEspace::RemoveFromMap(items_[posItem]->GetPosItem());
		items_.erase(items_.begin() + posItem, items_.begin() + posItem + 1);
	}
}