#include "Espace.h"

vector<vector<char>> CEspace::Map_ = {};
vector<CPosition> CEspace::Visibles_ = {};

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
	for (short i = 0; i < diam; ++i)
	{
		for (short j = 0; j < diam; ++j)
		{
			AjouterVisible(CPosition(depart.GetX() + j, depart.GetY() + i));
		}
	}
}

void CEspace::Afficher(ostream &os, const CPosition &pos)
{
	os << Map_[pos.GetY()][pos.GetX()];
}