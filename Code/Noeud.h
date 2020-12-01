#pragma once

template <class T>
class Noeud
{
public:
	Noeud();
	~Noeud();
	Noeud<T>* getSuivant();
	void setSuivant(Noeud<T>* _suivant);
	Noeud<T>* getPrecedent();
	void setPrecedent(Noeud<T>* _precedent);
	T* getElement();
	void setElement(T* _element);
private:
	Noeud<T>* suivant;
	Noeud<T>* precedent;
	T* element;
};

template<class T>
Noeud<T>::Noeud()
{

}

template<class T>
inline Noeud<T>::~Noeud()
{
}

template<class T>
Noeud<T>* Noeud<T>::getSuivant()
{
	return suivant;
}

template<class T>
void Noeud<T>::setSuivant(Noeud<T>* _suivant)
{
	suivant = _suivant;
}

template<class T>
Noeud<T>* Noeud<T>::getPrecedent()
{
	return precedent;
}

template<class T>
void Noeud<T>::setPrecedent(Noeud<T>* _precedent)
{
	precedent = _precedent;
}

template<class T>
T* Noeud<T>::getElement()
{
	return element;
}

template<class T>
void Noeud<T>::setElement(T* _element)
{
	element = _element;
}
