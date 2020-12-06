#include "stdafx.h"
#include "CppUnitTest.h"
#include "Mastermind.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_Mastermind
{

	TEST_CLASS(mastermind)
	{
		public:
		//TEST DU CONSTRUCTEUR DE MASTERMIND
		TEST_METHOD(LorsDeLINstanciationDeLaClasseMastermind4096CombinaisonsDevraientÊtreCréé) 
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

			Assert::IsTrue(liste->getNbElements() == 4096);
		}

		//====================================TESTS DE LA MÉTHODE NETTOYER LISTE============================================================

		TEST_METHOD(LorsquUneCombinaisonEstValideLaFonctionDevraitRetournerTrue) 
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);
			int nombreAleatoire = rand() % mastermind.getNbElements();
			Combinaison* tabCouleursRef = mastermind.getElement(nombreAleatoire);

			//les couleur de la combinaison que HAl porpose
			short c1 = 3;
			Couleur* couleur1 = new Couleur(c1);

			short c2 = 3;
			Couleur* couleur2 = new Couleur(c2);

			short c3 = 5;
			Couleur* couleur3 = new Couleur(c3);

			short c4 = 8;
			Couleur* couleur4 = new Couleur(c4);

			Combinaison* ref = new Combinaison(*couleur1, *couleur2, *couleur3, *couleur4);

			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 1;
			tabVerdict[1] = 1;
			tabVerdict[2] = 1;
			tabVerdict[3] = 1;

		


		
		}




	};
}