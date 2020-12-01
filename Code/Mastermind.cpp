#include "Mastermind.h"


Mastermind::Mastermind(ListeDouble<Combinaison>* _liste)
{
   //Il faut cr�er ici les 4096 combinaisons de couleurs possibles. Bonne r�flexion!
}

Mastermind::~Mastermind()
{

}


int Mastermind::getNbElements() const
{
	return 0;
}

/// <summary>
/// Retourne un �l�ment de la liste en position index
/// </summary>
/// <param name="index">La position de l'�l�ment � retourner</param>
/// <returns>L'�l�ment qui est � la position index</returns>
Combinaison* Mastermind::getElement(int index) const
{
	return nullptr;
}

bool Mastermind::validerCombinaison(Combinaison* _toValidate, Combinaison* _ref, short* _tabVerdicts)
{
	//tab verdict codee deja
	//
	for (int i = 0; i < 4; i++) {
		int verdict = _tabVerdicts[i];
	}
	//A COMPLETER
	//V�rifiez si la combinaison toValidate doit �tre retir�e ou non de la liste, en fonction d'une combinaison de r�f�rence et d'un tableau de 4 verdicts.
	//Pour chacune des couleurs pr�sentes dans toValidate, 3 verdicts possibles doivent �tre pris en consid�ration pour �l�miner ou non la combinaison, 
	//il s'agit de "Bonne couleur, bonne place" (valeur 1), "Bonne couleur, mauvaise place" (valeur 2) et "Mauvaise couleur" (valeur 3).

	//Voici un �bauche d'algorithme qui devrait vous aider � compl�ter cette m�thode:
	//Pour chacune des couleurs de la combinaison toValidate, v�rifiez:
	
	//Si le verdict est 1 (Bonne couleur, bonne place) et que la combinaison de couleurs � valider n'a pas la couleur � la m�me place que 
	//la combinaison de r�f�rence, il faut la retirer de la liste.

	//Si le verdict est 2 (Bonne couleur, mauvaise place) et que la combinaison de couleurs � valider n'a pas la couleur � un autre emplacement que
	//celui de la combinaison de r�f�rence, il faut la retirer de la liste.

	//Si le verdict est 3 (Mauvaise couleur) et que la combinaison de couleurs � valider a la couleur, il faut la retirer de la liste.

	//Retournez true si la combinaison est valide (respecte les verdicts) et false dans le cas contraire.

	//garde ou flush combinaison
	//recoit combinaison a valider, combinaison ref, tabreference
	//tovalidate vient de la liste - change chaque fois
	//autres param changent pas
	//ref - ordinateur a essay� de deviner
	//tabverdict - verdict de la demande ref
	//3-3-3-3 -> retire tout les combinaisons dont les couleurs envoy�s par ref sont pr�sentes
	//1-3-3-3 -> mauve bleu orange orange > entr� -> mauve blanc noir noir > ref -> garde tout les combinaisons dont le 1 est a la bonne place
	//2 -> bonne couleur mais pas a la bonne place-> garde toutes les combinaisons dont la couleur de verdict 2 est pr�sente, flush tout celles ou la couleur de verdict 2 est a la meme place et ceux qui ont pas la couleur

	return 0;
}

short Mastermind::nettoyerListe(Combinaison* _ref, short* _tabVerdicts)
{
	Iterateur<Combinaison> iter = this->liste->begin();

	for (int i = 0; i < this->liste->getNbElements(); i++) {

		Noeud<Combinaison>* noeudAVerifier = iter.getCourant();
		Combinaison* combinaisonAVerifier = noeudAVerifier->getElement();

		bool isCorrect = validerCombinaison(combinaisonAVerifier, _ref, _tabVerdicts);

		if (isCorrect == false) {
			this->liste->retirer(noeudAVerifier);
		}

		++iter;
	}
	//apelle valider combinaison
	//grosse boucle qui fait le tour de la liste avec iterateur - passe a validercombinaison chaque combinaison
	//1,2 ou 3
	//ex tabverdict - 1 1 2 3 - resultats
	// bool de valider - retire ou garde
	// passe au prochain


	//A COMPLETER
	//�pure la liste de combinaisons de couleurs en fonction de la combinaison re�ue et des 4 verdicts (valeurs 1 � 3).
	//Pour chacune des combinaisons de la liste, v�rifier si elle doit �tre retir�e ou non de liste.
	//Le nombre de combinaisons supprim�es doit �tre retourn�.

	return 0;
}
