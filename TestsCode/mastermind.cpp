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

		TEST_METHOD(LorsDeLINstanciationDeLaClasseMastermindPlusDe4000CombinaisonsDevraientÊtreCréé)
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

			Assert::IsFalse(liste->getNbElements() == 4000);
		}

		//====================================TESTS DE LA MÉTHODE NETTOYER LISTE============================================================

		TEST_METHOD(LorsquUneCombinaisonEstValideSur4VerdictLaFonctionDevraitRetournerLensembleDesCombiniasonExceptéUne) 
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

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

			//combinaison du joueur(3358)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 1;
			tabVerdict[1] = 1;
			tabVerdict[2] = 1;
			tabVerdict[3] = 1;

			//la fonction devrait retourner 4095 car il n'y a qu'une seule combinaison valide
			Assert::IsTrue(mastermind.nettoyerListe(ref, tabVerdict) == 4095);
			
		}

		TEST_METHOD(LorsqueLaRéponseDuJoueurEst1122LaFonctionDevraitRetournerLesToutesLesCombinaisonsExceptéUne) 
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

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

			//combinaison du joueur(3385)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 1;
			tabVerdict[1] = 1;
			tabVerdict[2] = 2;
			tabVerdict[3] = 2;



			//la fonction devrait retourner 4095 car il n'y a qu'une seule combinaison valide
			Assert::IsTrue(mastermind.nettoyerListe(ref, tabVerdict) == 4095);
		}

		TEST_METHOD(LorsqueLaRéponseDuJoueurEst1222LaFonctionDevraitRetournerLesToutesLesCombinaisonsExceptéCellesQuiOntLesCouleurs358)
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

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

			//combinaison du joueur(3538)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 1;
			tabVerdict[1] = 2;
			tabVerdict[2] = 2;
			tabVerdict[3] = 2;


			//la fonction devrait retourner 4074 car il n'y a que 22 combinaisons valides
			Assert::IsTrue(mastermind.nettoyerListe(ref, tabVerdict) == 4074);
		}

		TEST_METHOD(LorsqueLaRéponseDuJoueurEst2222LaFonctionDevraitRetournerLesToutesLesCombinaisonsExceptéCellesQuiOntLesCouleurs3458)
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

			//les couleur de la combinaison que HAl porpose
			short c1 = 3;
			Couleur* couleur1 = new Couleur(c1);

			short c2 = 4;
			Couleur* couleur2 = new Couleur(c2);

			short c3 = 5;
			Couleur* couleur3 = new Couleur(c3);

			short c4 = 8;
			Couleur* couleur4 = new Couleur(c4);

			Combinaison* ref = new Combinaison(*couleur1, *couleur2, *couleur3, *couleur4);

			//combiniason du joueur(4583)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 2;
			tabVerdict[1] = 2;
			tabVerdict[2] = 2;
			tabVerdict[3] = 2;


			//la fonction devrait retourner 4087 car il n'y a que 9 combinaisons valides (4583,4835,4385,5384,5834,5843,8345,8543,8534)
			Assert::IsTrue(mastermind.nettoyerListe(ref, tabVerdict) == 4087);

		}

		TEST_METHOD(LorsqueLaRéponseDuJoueurEst3333LaFonctionDevraitRetournerLesToutesLesCombinaisonsExceptéCellesQuiNOntPasLesCouleurs3458)
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

			//les couleur de la combinaison que HAl porpose
			short c1 = 3;
			Couleur* couleur1 = new Couleur(c1);

			short c2 = 4;
			Couleur* couleur2 = new Couleur(c2);

			short c3 = 5;
			Couleur* couleur3 = new Couleur(c3);

			short c4 = 8;
			Couleur* couleur4 = new Couleur(c4);

			Combinaison* ref = new Combinaison(*couleur1, *couleur2, *couleur3, *couleur4);

			//combiniason du joueur(1267)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 3;
			tabVerdict[1] = 3;
			tabVerdict[2] = 3;
			tabVerdict[3] = 3;


			//la fonction devrait retourner 1695 car il y a 2401 combinaisons qui n'ont pas les couleurs(3,4,5 et 8)
			Assert::IsTrue(mastermind.nettoyerListe(ref, tabVerdict) == 1695);

		}

		TEST_METHOD(LorsqueLaRéponseDuJoueurEst1313LaFonctionDevraitRetournerLesToutesLesCombinaisonsExceptéCellesQuiNOntPasLesCouleurs48etCellesQueLeurPremièreEtTroisièmeCouleurNeSontPas3et5)
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

			//les couleur de la combinaison que HAl porpose
			short c1 = 3;
			Couleur* couleur1 = new Couleur(c1);

			short c2 = 4;
			Couleur* couleur2 = new Couleur(c2);

			short c3 = 5;
			Couleur* couleur3 = new Couleur(c3);

			short c4 = 8;
			Couleur* couleur4 = new Couleur(c4);

			Combinaison* ref = new Combinaison(*couleur1, *couleur2, *couleur3, *couleur4);

			//combiniason du joueur(3652)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 1;
			tabVerdict[1] = 3;
			tabVerdict[2] = 1;
			tabVerdict[3] = 3;


			//la fonction devrait retourner 4047 car il y a 49 combinaisons qui n'ont pas les couleurs 4 et 8 en plus d'avoir 3 comme première couleur et 5 comme dernière couleur
			Assert::IsTrue(mastermind.nettoyerListe(ref, tabVerdict) == 4047);

		}


		//====================================TESTS DE LA MÉTHODE NETTOYER LISTE POUR TROUVER LA COMBINAISON CHOISIE============================================================

		TEST_METHOD(LorsqueLaRéponseDuJoueurEst1222etEnsuite1111LaFonctionDevraitRetournerLesCombinaisonsRestantesAprèsLePremierNettoyageExceptéUne)
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

			//les couleurs de la combinaison que HAl porpose
			short c1 = 3;
			Couleur* couleur1 = new Couleur(c1);

			short c2 = 3;
			Couleur* couleur2 = new Couleur(c2);

			short c3 = 5;
			Couleur* couleur3 = new Couleur(c3);

			short c4 = 8;
			Couleur* couleur4 = new Couleur(c4);

			Combinaison* ref = new Combinaison(*couleur1, *couleur2, *couleur3, *couleur4);

			//combiniason du joueur(3835)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 1;
			tabVerdict[1] = 2;
			tabVerdict[2] = 2;
			tabVerdict[3] = 2;

			//premier nettoyage
			mastermind.nettoyerListe(ref, tabVerdict);
			

			//les couleurs de la deuxième combinaison que HAl porpose
			short r1 = 3;
			Couleur* couleur5 = new Couleur(r1);

			short r2 = 8;
			Couleur* couleur6 = new Couleur(r2);

			short r3 = 3;
			Couleur* couleur7 = new Couleur(r3);

			short r4 = 5;
			Couleur* couleur8 = new Couleur(r4);

			Combinaison* ref2 = new Combinaison(*couleur5, *couleur6, *couleur7, *couleur8);

			//les réponses du joueur
			short tabVerdict2[4];

			tabVerdict2[0] = 1;
			tabVerdict2[1] = 1;
			tabVerdict2[2] = 1;
			tabVerdict2[3] = 1;


			//la fonction devrait retourner 21 car la première fois que Hal a fait un nettoyage il en a retiré 4074
			//sur les 22 restantes une seule est valide
			//la méthode devrait retourner (22-1(celle valide))
			Assert::IsTrue(mastermind.nettoyerListe(ref2, tabVerdict2) == 21);
			

		}

		TEST_METHOD(LorsqueLaRéponseDuJoueurEst1222Ensuite1122etEnsuite1111LaFonctionDevraitRetournerLesCombinaisonsRestantesAprèsLesPremiersNettoyagesExceptéUne)
		{
			ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
			Mastermind mastermind(liste);

			//les couleurs de la combinaison que HAl porpose
			short c1 = 3;
			Couleur* couleur1 = new Couleur(c1);

			short c2 = 3;
			Couleur* couleur2 = new Couleur(c2);

			short c3 = 5;
			Couleur* couleur3 = new Couleur(c3);

			short c4 = 8;
			Couleur* couleur4 = new Couleur(c4);

			Combinaison* ref = new Combinaison(*couleur1, *couleur2, *couleur3, *couleur4);

			//combiniason du joueur(3835)
			//les réponses du joueur
			short tabVerdict[4];

			tabVerdict[0] = 1;
			tabVerdict[1] = 2;
			tabVerdict[2] = 2;
			tabVerdict[3] = 2;

			//premier nettoyage
			mastermind.nettoyerListe(ref, tabVerdict);


			//les couleurs de la deuxième combinaison que HAl porpose
			short r1 = 3;
			Couleur* couleur5 = new Couleur(r1);

			short r2 = 8;
			Couleur* couleur6 = new Couleur(r2);

			short r3 = 5;
			Couleur* couleur7 = new Couleur(r3);

			short r4 = 3;
			Couleur* couleur8 = new Couleur(r4);

			Combinaison* ref2 = new Combinaison(*couleur5, *couleur6, *couleur7, *couleur8);

			//les réponses du joueur
			short tabVerdict2[4];

			tabVerdict2[0] = 1;
			tabVerdict2[1] = 1;
			tabVerdict2[2] = 2;
			tabVerdict2[3] = 2;

			//deuxième nettoyage
			mastermind.nettoyerListe(ref2, tabVerdict2);

			//les couleurs de la troisième combinaison que HAl porpose
			short t1 = 3;
			Couleur* couleur9 = new Couleur(t1);

			short t2 = 8;
			Couleur* couleur10 = new Couleur(t2);

			short t3 = 3;
			Couleur* couleur11 = new Couleur(t3);

			short t4 = 5;
			Couleur* couleur12 = new Couleur(t4);

			Combinaison* ref3 = new Combinaison(*couleur9, *couleur10, *couleur11, *couleur12);

			//les réponses du joueur
			short tabVerdict3[4];

			tabVerdict3[0] = 1;
			tabVerdict3[1] = 1;
			tabVerdict3[2] = 1;
			tabVerdict3[3] = 1;


			//la fonction devrait retourner 7 car la première fois que Hal a fait un nettoyage il en a retiré 4074 et la deuxième fois 14 (4096-4074=22 et 22-14=8)
			//sur les 8 restantes une seule est valide
			//la méthode devrait retourner (35-1(celle valide))
			Assert::IsTrue(mastermind.nettoyerListe(ref3, tabVerdict3) == 7);
		}
	};
}