#pragma once

#include "Position.h"
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::ifstream;
using std::ostream;

class CEspace
{
	static vector<vector<char>> Map_;
	static vector<CPosition> Visibles_;
	static CPosition Debut_,
					 Fin_;
public:
	enum 
	{
		X_MIN = 0, Y_MIN = 0,
		X_MAX = 25, Y_MAX = 10
	};

	enum
	{
		DEPART = 'b', FIN = 'e', 
		MUR_VERTI = '|', MUR_HORIZ = '-'
	};

	static bool EstValide(const CPosition &p) throw()
	{
		return X_MIN <= p.GetX() && p.GetX() < Max_X() &&
			   Y_MIN <= p.GetY() && p.GetY() < Max_Y();
	}

	static bool EstAccessible(const CPosition &p)
	{
		return  Map_[p.GetY()][p.GetX()] != MUR_HORIZ &&
				Map_[p.GetY()][p.GetX()] != MUR_VERTI &&
				EstValide(p);
	}

	static void CreerEspace(const string &);

	static void AjouterVisible(const CPosition pos);

	static void EtablirVisibles(const CPosition &, const short &);

	static vector<CPosition> GetZoneVision()
	{
		return Visibles_;
	}

	static bool EstVisible(const CPosition &p)
	{
		vector<CPosition> v = GetZoneVision();
		auto it = std::find(v.begin(), v.end(), p);
		return it != v.end() &&
			   p != EtablirPosition(DEPART) &&
			   p != EtablirPosition(FIN);
	}

	static void Afficher(ostream &os, const CPosition &pos);

	static short Max_X() { return Map_[Y_MIN].size(); } const

	static short Max_Y() { return Map_.size(); } const

	static CPosition EtablirPosition(const char c)
	{
		for (short i = 0; i < Map_.size(); ++i)
		{
			for (short j = 0; j < Map_[i].size(); ++j)
			{
				if (Map_[i][j] == c)
				{
					return CPosition(j, i);
				}
			}
		}
		return CPosition(0,0);
	}
};