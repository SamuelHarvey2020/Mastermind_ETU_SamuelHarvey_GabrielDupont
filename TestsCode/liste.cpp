#include "stdafx.h"
#include "CppUnitTest.h"
#include "ListeDouble.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
namespace Tests_Liste
{		
	//TEST DE CRÉATION DE LISTE
	TEST_METHOD(UneListeDevraitEtreCrééeAvecPremierNoeudNull)
	{
		ListeDouble<int> liste;

		Assert::IsTrue(l.getPremierNoeud() == NULL);
	}

	//====================================TESTS DE LA MÉTHODE AJOUTER============================================================

	TEST_METHOD(OnDevraitPouvoirAjouterUnLivreEtUnNoeudAUneListeVide)
	{
		Liste l;
		Livre* _livre = new Livre(1, "test", 2000);

		Assert::IsTrue(l.ajouter(_livre));
		Assert::IsTrue(l.getPremierNoeud() != NULL);
	}

	TEST_METHOD(OnDevraitPouvoirAjouterUnLivreEtUnNoeudAUneListeNonVide)
	{
		Liste l;
		Livre* _livre = new Livre(1, "test", 2001);
		Livre* _livre2 = new Livre(2, "test", 2002);
		l.ajouter(_livre);

		Assert::IsTrue(l.ajouter(_livre2));
	}


	TEST_METHOD(OnNeDevraitPasPouvoirAjouterUnLivreSiLeLivreEstDéjaPrésent)
	{
		Liste l;
		Livre* _livre = new Livre(1, "test", 2000);
		Livre* _livre2 = new Livre(1, "test", 2000);
		l.ajouter(_livre);

		Assert::IsFalse(l.ajouter(_livre2));
	}


	TEST_METHOD(OnDevraitPouvoirEffectuerUnChainageCorrect)
	{
		Liste l;
		Livre* _livre = new Livre(10, "test", 2000);
		Livre* _livre2 = new Livre(5, "test", 2000);
		Livre* _livre3 = new Livre(7, "test", 2000);
		l.ajouter(_livre);
		l.ajouter(_livre2);
		l.ajouter(_livre3);

		Assert::IsTrue(l.getPremierNoeud()->getLivre() == _livre2);
		Assert::IsTrue(l.getPremierNoeud()->getSuivant()->getLivre() == _livre3);
	}

}
*/