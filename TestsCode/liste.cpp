#include "stdafx.h"
#include "CppUnitTest.h"
#include "ListeDouble.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Tests_Liste
{		

	TEST_CLASS(TestsListe)
	{
		public:
		//TEST DE CRÉATION DE LISTE
		TEST_METHOD(UneListeDevraitEtreCrééeAvecPremierNoeudNull)
		{
			ListeDouble<int> liste;

			Assert::IsTrue(liste.getPremierNoeud() == NULL);
		}

		//====================================TESTS DE LA MÉTHODE AJOUTER============================================================

		TEST_METHOD(OnDevraitPouvoirAjouterUnLivreEtUnNoeudAUneListeVide)
		{
			ListeDouble<int> liste;
			int* nb = new int(1);

			Assert::IsTrue(liste.ajouter(nb));
			Assert::IsTrue(liste.getPremierNoeud() != NULL);
		}

		TEST_METHOD(OnDevraitPouvoirAjouterUnLivreEtUnNoeudAUneListeNonVide)
		{
			ListeDouble<int> liste;
			int* nb = new int(1);
			int* nb2 = new int(2);
			liste.ajouter(nb);

			Assert::IsTrue(liste.ajouter(nb2));
		}


		TEST_METHOD(OnNeDevraitPasPouvoirAjouterUnLivreSiLeLivreEstDéjaPrésent)
		{
			ListeDouble<int> liste;
			int* nb = new int(1);
			int* nb2 = new int(1);
			liste.ajouter(nb);

			Assert::IsFalse(liste.ajouter(nb2));
		}


		TEST_METHOD(OnDevraitPouvoirEffectuerUnChainageCorrect)
		{
			ListeDouble<int> liste;
			int* nb = new int(8);
			int* nb2 = new int(2);
			int* nb3 = new int(6);
			liste.ajouter(nb);
			liste.ajouter(nb2);
			liste.ajouter(nb3);

			Assert::IsTrue(liste.getPremierNoeud()->getElement() == nb2);
			Assert::IsTrue(liste.getPremierNoeud()->getSuivant()->getElement() == nb3);
		}

		//====================================TESTS DE LA MÉTHODE RETIRER============================================================
		/*
		TEST_METHOD(EffectuerUnRetirerSurUneListeVideDevraitRienFaire)
		{
			ListeDouble<int> liste;
			Noeud<int> * ndNb;
			int* nb = new int(1);
			ndNb->setElement(nb);
	
			liste.retirer(ndNb);

			Assert::IsTrue(liste.getPremierNoeud() == NULL);
		}

		TEST_METHOD(RetirerDevraisNeRienFaireSiContenuNonPrésent)
		{
			ListeDouble<int> liste;

			Noeud<int>* ndNb;
			int* nb = new int(1);
			ndNb->setElement(nb);
			liste.ajouter(nb);

			Noeud<int>* ndNb2;
			int* nb2 = new int(2);
			ndNb2->setElement(nb2);
			liste.ajouter(nb2);

			liste.retirer(ndNb2);

			Assert::IsTrue(liste.getPremierNoeud()->getSuivant() == NULL);
		}

		TEST_METHOD(OnDevraitPouvoirRetirerLePremierNoeud)
		{
			ListeDouble<int> liste;

			Noeud<int>* ndNb;
			int* nb = new int(1);
			ndNb->setElement(nb);
			liste.ajouter(nb);

			liste.retirer(ndNb);

			Assert::IsTrue(liste.getPremierNoeud() == NULL);
		}


		TEST_METHOD(OnDevraitPouvoirRetirerPremierNoeudEnEffectuantUnNouveauChainage)
		{
			ListeDouble<int> liste;

			Noeud<int>* ndNb;
			int* nb = new int(1);
			ndNb->setElement(nb);
			liste.ajouter(nb);

			Noeud<int>* ndNb2;
			int* nb2 = new int(2);
			ndNb2->setElement(nb2);
			liste.ajouter(nb2);

			liste.retirer(ndNb);

			Assert::IsTrue(liste.getPremierNoeud()->getElement() == nb2);
		}

		TEST_METHOD(OnDevraitPouvoirRetirerLeDernierNoeud)
		{
			ListeDouble<int> liste;

			Noeud<int>* ndNb;
			int* nb = new int(1);
			ndNb->setElement(nb);
			liste.ajouter(nb);

			Noeud<int>* ndNb2;
			int* nb2 = new int(2);
			ndNb2->setElement(nb2);
			liste.ajouter(nb2);

			Noeud<int>* ndNb3;
			int* nb3 = new int(3);
			ndNb3->setElement(nb3);
			liste.ajouter(nb3);

			liste.retirer(ndNb3);

			Assert::IsTrue(liste.getPremierNoeud()->getSuivant()->getSuivant() == NULL);
		}

		TEST_METHOD(OnDevraitPouvoirRetirerNimporteQuelNoeudPrésentEtEffectuerLeChainage)
		{
			ListeDouble<int> liste;

			Noeud<int>* ndNb;
			int* nb = new int(10);
			ndNb->setElement(nb);
			liste.ajouter(nb);

			Noeud<int>* ndNb2;
			int* nb2 = new int(12);
			ndNb2->setElement(nb2);
			liste.ajouter(nb2);

			Noeud<int>* ndNb3;
			int* nb3 = new int(7);
			ndNb3->setElement(nb3);
			liste.ajouter(nb3);

			Noeud<int>* ndNb4;
			int* nb4 = new int(2);
			ndNb4->setElement(nb4);
			liste.ajouter(nb4);

			liste.retirer(ndNb3);

			Assert::IsTrue(liste.getPremierNoeud()->getSuivant()->getElement() == nb);
		}
		*/
	};
}
