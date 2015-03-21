#pragma once

#include <iosfwd>
using std::ostream;

class CCommande;
class CJeu
{
public:
	CJeu() throw()
	{

	}
	bool Fini();
	void AfficherEtat(ostream &) const;
	void Executer(const CCommande &);
};