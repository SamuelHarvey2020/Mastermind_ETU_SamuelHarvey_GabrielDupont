#pragma once

#include "ListeDouble.h"

#include "Combinaison.h"
#include "Couleur.h"

class Mastermind
{
public:
  
    Mastermind(ListeDouble<Combinaison>* _liste);
    ~Mastermind();

    int getNbElements() const;
	Combinaison* getElement(int _index) const;

    short nettoyerListe(Combinaison* _ref, short* _tabVerdicts);

private:

	bool validerCombinaison(Combinaison* _toValidate, Combinaison* _ref, short* _tabVerdicts);

    ListeDouble<Combinaison>* liste; //Contient toutes les combinaisons de couleurs possibles, selon le contexte.

	void deleteCouleurs(Couleur* c1, Couleur* c2, Couleur* c3, Couleur* c4);

	void deleteCombinaisons(Combinaison* tabCombinaison[]);


	Combinaison* tabCombinaison[4096];


	int nbOfCreatedCombinaisons = 0;


};
