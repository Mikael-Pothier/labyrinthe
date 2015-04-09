#include "Espace.h"
#include <cstdlib>
#include <ctime> 

vector<vector<char>> CEspace::Map_ = {};
vector<CPosition> CEspace::Visibles_ = {};
vector<CPosition> CEspace::Libres_ = {};

void CEspace::CreerEspace(const string &fileName)
{
	ifstream ifs;
	ifs.open(fileName);
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
			if (c == ' ')
				Libres_.push_back(CPosition(Map_[i].size()-1, i));
		}
	}
	ifs.close();
}

void CEspace::AjouterVisible(const CPosition pos)
{
	if (EstValide(pos))
		Visibles_.push_back(pos);
}

void CEspace::EtablirVisibles(const CPosition & centre, const short & diam)
{
	Visibles_.clear();
	short rayon = (diam - 1) / 2;
	CPosition depart(centre.GetX() - rayon, centre.GetY() - rayon);

	if (diam <= CEspace::Max_Y() && diam <= CEspace::Max_X())
	{
		for (short i = 0; i < diam; ++i)
		{
			for (short j = 0; j < diam; ++j)
			{
				AjouterVisible(CPosition(depart.GetX() + j, depart.GetY() + i));
			}
		}
	}
}

void CEspace::Afficher(ostream &os, const CPosition &pos)
{
	os << Map_[pos.GetY()][pos.GetX()];
}

CPosition CEspace::TrouverEspaceLibre()
{
	if (Libres_.size() == 0)
		throw MapPleine();

	int posTable = rand() % Libres_.size();

	CPosition posSpace(Libres_[posTable].GetX(), Libres_[posTable].GetY());

	Libres_.erase(Libres_.begin() + posTable, Libres_.begin() + posTable + 1);

	return posSpace;
}

void CEspace::AjouterEspaceLibre(CPosition pos)
{
	Libres_.push_back(pos);
}

void CEspace::Placer(CPosition pos, char symbol)
{
	Map_[pos.GetY()][pos.GetX()]= symbol;
}

void CEspace::Retirer(CPosition pos)
{
	Map_[pos.GetY()][pos.GetX()] = ' ';
}