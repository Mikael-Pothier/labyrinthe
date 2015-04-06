#include "Espace.h"
#include <cstdlib>
#include <ctime> 

vector<vector<char>> CEspace::Map_ = {};
vector<CPosition> CEspace::Visibles_ = {};
vector<CPosition> CEspace::Libre_ = {};

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
				Libre_.push_back(CPosition(Map_[i].size()-1, i));
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

CPosition CEspace::TakeSpace()
{

	if (Libre_.size() == 0)
	{
		throw MapPleine();
	}

	int posTable = rand() % Libre_.size();

	CPosition posSpace(Libre_[posTable].GetX(), Libre_[posTable].GetY());

	Libre_.erase(Libre_.begin() + posTable, Libre_.begin() + posTable + 1);

	return posSpace;
}

void CEspace::AddSpace(CPosition pos)
{
	Libre_.push_back(pos);
}

void CEspace::PlaceInMap(CPosition pos, char symbol)
{
	Map_[pos.GetY()][pos.GetX()]= symbol;
}

void CEspace::RemoveFromMap(CPosition pos)
{
	Map_[pos.GetY()][pos.GetX()] = ' ';
}