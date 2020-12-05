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




	};
}