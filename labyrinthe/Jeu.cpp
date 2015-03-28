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

const char CJeu::ESPACE_VIDE = ' ';

bool CJeu::Fini()
{
	return perso_.GetPosition() == objectif_;
}

void CJeu::AfficherEtat(ostream & os) const
{
	system("cls");
	AfficherMap(os);
	for (int i = CEspace::Y_MIN; i < CEspace::Y_MAX; ++i)
	{
		for (int j = CEspace::X_MIN; j < CEspace::X_MAX; ++j)
		{
			const CPosition pos(j, i);
			if (pos == perso_.GetPosition())
			{
				os << perso_;
			}
			else
				os << ESPACE_VIDE;
		}
	}
}

void CJeu::Executer(const CCommande & c)
{
	if (c == CMenu::AVANCER)
	{
		perso_.Avancer();
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
		perso_.Reculer();
	}
}

void CJeu::ReadMap(const string FileName)
{
	ifstream ifs;
	ifs.open(FileName);
	char c;
	int i = 0;

	Map_.push_back(vector<char>());
	while (EOF != (c = ifs.get()))
	{
		if (c == '\n')
		{
			Map_.push_back(vector<char>());
			++i;
		}
		else
		{
			Map_[i].push_back(c);
		}
	}

	ifs.close();
}

void CJeu::AfficherMap(ostream & os) const
{
	for (short i = 0; i < Map_.size(); ++i)
	{
		for (short j = 0; j < Map_[i].size(); ++j)
		{
			os << Map_[i][j];
		}
		os << endl;
	}
}

CPosition CJeu::TrouverPosDepart()
{
	for (short i = 0; i < Map_.size(); ++i)
	{
		for (short j = 0; j < Map_[i].size(); ++j)
		{
			if (Map_[i][j] == 'b')
			{
				return CPosition(i, j);
			}
		}
	}
	return CPosition(-1, -1);
}

void CJeu::PlacerPersonnage(CPosition pos)
{
	perso_.SetPosition(pos);
	Map_[pos.GetX()][pos.GetY()] = 'A';
}