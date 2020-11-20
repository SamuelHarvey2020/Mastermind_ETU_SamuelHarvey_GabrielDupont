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

	bool ajouter(T* _livre);
	bool retirer(T* _livre);
	Noeud<T>* getPremierNoeud();
	void affiche();

	typedef Iterateur<T> iterateur;
	Iterateur<T> begin();
	Iterateur<T> end();

private:
	Noeud* premierNoeud;
private:
	
};

//TODO : Implémentez votre liste double (toutes les méthodes de la classe mère)
template <class T>
ListeDouble<T>::ListeDouble()
{
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
inline bool ListeDouble<T>::ajouter(T* _livre)
{
	return false;
}

template<class T>
inline bool ListeDouble<T>::retirer(T* _livre)
{
	return false;
}

template<class T>
inline Noeud<T>* ListeDouble<T>::getPremierNoeud()
{
	return NULL;
}

template<class T>
inline void ListeDouble<T>::affiche()
{
}

template<class T>
inline Iterateur<T> ListeDouble<T>::begin()
{
	return Iterateur<T>();
}

template<class T>
inline Iterateur<T> ListeDouble<T>::end()
{
	return Iterateur<T>();
}
