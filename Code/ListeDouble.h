#pragma once
#include "ListeBase.h"
#include "EmptyListException.h"
#include "Iterateur.h"


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

	const int getNbElements();
	Noeud<T>* getPremierNoeud();
	const bool isEmpty();

	typedef Iterateur<T> iterateur;
	Iterateur<T> begin();
	Iterateur<T> end();

private:
	Noeud* premierNoeud;
	void retirer();
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
}

template<class T>
inline bool ListeDouble<T>::ajouter(T* element)
{
	Noeud<T>* nouveauNoeud = new Noeud;
	nouveauNoeud->setElement(element);
	bool canBeAdded = true;

	if (this->premierNoeud == NULL) {
		this->premierNoeud = nouveauNoeud;
		this->premierNoeud->setSuivant(NULL);
	}
	else {

		if (*element < *(premierNoeud->getElement())) {
			nouveauNoeud->setSuivant(premierNoeud);
			this->premierNoeud = nouveauNoeud;
		}
		else {

			Noeud<T>* noeudTemporaire = this->premierNoeud;
			//Iterateur<T> iter(noeudTemporaire);
			bool solved = false;

			if (*element != *(noeudTemporaire->getElement())) {

				while (solved != true) {

					if (noeudTemporaire->getSuivant() == NULL) {
						noeudTemporaire->setSuivant(nouveauNoeud);
						noeudTemporaire->getSuivant()->setSuivant(NULL);
						solved = true;
					}
					else if (*element == *(noeudTemporaire->getSuivant()->getElement())) {

						canBeAdded = false;
						break;
					}
					else if (*element < *(noeudTemporaire->getSuivant()->getElement())) {

						nouveauNoeud->setSuivant(noeudTemporaire->getSuivant());
						noeudTemporaire->setSuivant(nouveauNoeud);
						solved = true;
					}
					else {
						iterateur++;
					}
				}
			}
			else {
				canBeAdded = false;
			}

		}

	}
	return canBeAdded;
}

template<class T>
inline void ListeDouble<T>::retirer(Noeud <T>* noeudCourant)
{
	Noeud<T>* noeudTemporaire = noeudCourant;
	noeudTemporaire->getPrecedent()->setSuivant(noeudTemporaire->getSuivant());
	noeudTemporaire->getSuivant()->setPrecedent(noeudTemporaire->getPrecedent());
	delete noeudTemporaire;
}

template<class T>
inline const int ListeDouble<T>::getNbElements()
{
	return 0;
}

template<class T>
inline Noeud<T>* ListeDouble<T>::getPremierNoeud()
{
	return this->premierNoeud;
}

template<class T>
inline const bool ListeDouble<T>::isEmpty()
{
	if (this->premierNoeud == NULL;) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
inline Iterateur<T> ListeDouble<T>::begin()
{
	return Iterateur<T>(premierNoeud);
}

template<class T>
inline Iterateur<T> ListeDouble<T>::end()
{
	return Iterateur<T>(NULL);
}

template<class T>
inline void ListeDouble<T>::retirer()
{
}
