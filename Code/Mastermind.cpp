#include "Mastermind.h"


Mastermind::Mastermind(ListeDouble<Combinaison>* _liste)
{
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			for (int k = 1; k < 9; k++)
			{
				for (int l = 1; l < 9; l++)
				{
					short c1 = i;
					Couleur* couleur1 = new Couleur(c1);

					short c2 = j;
					Couleur* couleur2 = new Couleur(c2);

					short c3 = k;
					Couleur* couleur3 = new Couleur(c3);

					short c4 = l;
					Couleur* couleur4 = new Couleur(c4);

					Combinaison* combinaison = new Combinaison(*couleur1, *couleur2, *couleur3, *couleur4);
					_liste->ajouter(combinaison);
					tabCombinaison[nbOfCreatedCombinaisons] = combinaison;
					nbOfCreatedCombinaisons++;
					deleteCouleurs(couleur1, couleur2, couleur3, couleur4);
				}
			}
		}
	}

	this->liste = _liste;
}

Mastermind::~Mastermind()
{
	deleteCombinaisons(this->tabCombinaison);
}


int Mastermind::getNbElements() const
{
	return this->liste->getNbElements();
}

/// <summary>
/// Retourne un �l�ment de la liste en position index
/// </summary>
/// <param name="index">La position de l'�l�ment � retourner</param>
/// <returns>L'�l�ment qui est � la position index</returns>
Combinaison* Mastermind::getElement(int index) const
{
	Iterateur<Combinaison> iter = this->liste->begin();
	int i = 1;
	while (i != index) {
		i++;
		++iter;
	}

	Combinaison* comb = iter.operator->();
	return comb;
}

bool Mastermind::validerCombinaison(Combinaison* _toValidate, Combinaison* _ref, short* _tabVerdicts)
{
	for (int i = 0; i < 4; i++)
	{
		Couleur couleurAValider = _toValidate->getCouleur(i);
		int verdict = _tabVerdicts[i];
		Couleur couleurRef = _ref->getCouleur(i);
		if (verdict == 1 && couleurAValider != couleurRef)
			return false;
		if (verdict == 3 && couleurAValider == couleurRef)
			return false;
		if (verdict == 2)
		{
			bool result = false;
			for (int j = 0; j < 4 && !result; j++)
				if (j != i && _toValidate->getCouleur(j) == couleurRef)
					result = true;
			if (!result)
				return false;
		}
	}
	return true;
	
}

short Mastermind::nettoyerListe(Combinaison* _ref, short* _tabVerdicts)
{
	Iterateur<Combinaison> iter = this->liste->begin();

	Noeud<Combinaison>* noeudAVerifier = NULL;

	short nbOfDeletedCombinaison = 0;

	while ((noeudAVerifier = iter.getCourant()) != NULL) {

		Combinaison* combinaisonAVerifier = noeudAVerifier->getElement();

		bool isCorrect = validerCombinaison(combinaisonAVerifier, _ref, _tabVerdicts);

		++iter;

		if (isCorrect == false) {
			this->liste->retirer(noeudAVerifier);
			nbOfDeletedCombinaison = nbOfDeletedCombinaison + 1;
		}

	}

	return nbOfDeletedCombinaison;
}

void Mastermind::deleteCouleurs(Couleur* couleur1, Couleur* couleur2, Couleur* couleur3, Couleur* couleur4)
{
	delete couleur1;
	delete couleur2;
	delete couleur3;
	delete couleur4;
}

void Mastermind::deleteCombinaisons(Combinaison* tabCombinaison[])
{
	for (int i = 0; i < 4096; i++)
	{
		delete tabCombinaison[i];
	}
}