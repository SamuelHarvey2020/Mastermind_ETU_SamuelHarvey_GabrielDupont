#pragma once
#include "ListeBase.h"
#include "EmptyListException.h"
#include "Iterateur.h"
#include "Noeud.h"


using namespace std;

template <class T>
//On hérite de la liste de base
//TODO : Décommenter pour activer l'héritage
class ListeDouble : public ListeBase<T>
{
//TODO : Définissez votre liste double, TOUTES les méthodes à surcharger sont dans ListeBase<T>
public :
	ListeDouble();
	~ListeDouble();
	void vider();

	bool ajouter(T* element);
	void retirer(Noeud <T>* noeudCourant);

	int getNbElements() const;
	Noeud<T>* getPremierNoeud();
	bool isEmpty() const;

	typedef Iterateur<T> iterateur;
	Iterateur<T> begin();
	Iterateur<T> end();

private:
	Noeud<T>* premierNoeud;
	void retirer();
	int nbElements = 0;
};

//TODO : Implémentez votre liste double (toutes les méthodes de la classe mère)
template <class T>
ListeDouble<T>::ListeDouble()
{
	premierNoeud = NULL;
}

template <class T>
ListeDouble<T>::~ListeDouble()
{
}

template <class T>
void ListeDouble<T>::vider()
{
	while (this->premierNoeud != NULL) {
		retirer();
	}
}

template<class T>
bool ListeDouble<T>::ajouter(T* element)
{
	Noeud<T>* nouveauNoeud = new Noeud<T>();
	nouveauNoeud->setElement(element);
	bool canBeAdded = true;

	if (this->premierNoeud == NULL) {
		this->premierNoeud = nouveauNoeud;
		this->premierNoeud->setSuivant(NULL);
		this->premierNoeud->setPrecedent(NULL);
	}
	else {

		if (*element < *(premierNoeud->getElement())) {
			this->premierNoeud->setPrecedent(nouveauNoeud);
			nouveauNoeud->setSuivant(premierNoeud);
			this->premierNoeud = nouveauNoeud;
		}
		else {

			iterateur iter = this->begin();
			bool solved = false;

			while (solved != true) {

				if (*element == *(iter.getCourant()->getElement())) {
					canBeAdded = false;
					break;
				}
				else if (*element < *(iter.getCourant()->getElement())) {

					iter.getCourant()->getPrecedent()->setSuivant(nouveauNoeud);
					nouveauNoeud->setPrecedent(iter.getCourant()->getPrecedent());
					nouveauNoeud->setSuivant(iter.getCourant());
					iter.getCourant()->setPrecedent(nouveauNoeud);
					
					solved = true;
				}
				else if (iter.getCourant()->getSuivant() == NULL) {

					nouveauNoeud->setPrecedent(iter.getCourant());
					iter.getCourant()->setSuivant(nouveauNoeud);
					iter.getCourant()->getSuivant()->setSuivant(NULL);
					solved = true;
				}
				else {
					++iter;
				}
			}
		}
	}
	if (canBeAdded == true) {
		this->nbElements++;
	}
	return canBeAdded;
}

template<class T>
void ListeDouble<T>::retirer(Noeud <T>* noeudCourant)
{

	if (this->premierNoeud != NULL) {

		if (noeudCourant != NULL) {

			Noeud<T>* noeudTemporaire = noeudCourant;

			if (noeudTemporaire == premierNoeud) {

				if(noeudTemporaire->getSuivant() != NULL){
					this->premierNoeud = noeudTemporaire->getSuivant();
					noeudTemporaire->getSuivant()->setPrecedent(NULL);
				}
				else {
					this->premierNoeud = NULL;
				}
			}
			else if (noeudTemporaire->getSuivant() == NULL) {
				noeudTemporaire->getPrecedent()->setSuivant(NULL);
			}
			else {
				noeudTemporaire->getPrecedent()->setSuivant(noeudTemporaire->getSuivant());
				noeudTemporaire->getSuivant()->setPrecedent(noeudTemporaire->getPrecedent());
			}
			delete noeudTemporaire;
			this->nbElements--;

		}
	}
}

template<class T>
int ListeDouble<T>::getNbElements() const
{
	return this->nbElements;
}

template<class T>
Noeud<T>* ListeDouble<T>::getPremierNoeud()
{
	return this->premierNoeud;
}

template<class T>
bool ListeDouble<T>::isEmpty() const
{
	if(this->premierNoeud == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
Iterateur<T> ListeDouble<T>::begin()
{
	return Iterateur<T>(premierNoeud);
}

template<class T>
Iterateur<T> ListeDouble<T>::end()
{
	return Iterateur<T>(NULL);
}

template<class T>
void ListeDouble<T>::retirer()
{
	this->retirer(this->premierNoeud);
}
