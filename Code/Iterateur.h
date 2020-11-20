
#include "Noeud.h"

#pragma once
template <class T>
class Iterateur {
public:
	Iterateur();
	Iterateur(Noeud<T>* courant);
	~Iterateur();

	void operator++();
	void operator--();
	T* operator->();
	T operator*();
	bool operator==(Iterateur<T> iter);
	bool operator !=(Iterateur<T> iter);
	Noeud<T>* getCourant();

private:
	Noeud<T>* courant;
};
//TODO : Implémentez votre itérateur (toutes les méthodes de la classe mère)

template<class T>
Iterateur<T>::Iterateur()
{
}

template<class T>
Iterateur<T>::Iterateur(Noeud<T>* courant)
{
	this->courant = courant;
}

template<class T>
Iterateur<T>::~Iterateur()
{
}

template<class T>
void Iterateur<T>::operator++()
{
	this->courant = this->courant->getSuivant();
}

template<class T>
void Iterateur<T>::operator--()
{
	this->courant = this->courant->getPrecedent();
}

template<class T>
T* Iterateur<T>::operator->()
{
	return this->courant->getElement();
}

template<class T>
T Iterateur<T>::operator*()
{
	return *this->courant->getElement();
}

template<class T>
bool Iterateur<T>::operator==(Iterateur<T> iter)
{
	return this->courant == iter.courant;
}

template<class T>
bool Iterateur<T>::operator!=(Iterateur<T> iter)
{
	return this->courant != iter.courant;
}

template<class T>
inline Noeud<T>* Iterateur<T>::getCourant()
{
	return courant;
}
