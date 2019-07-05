// CodinGameMain.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
	//D:\\progetti_Master\\Tools_Zamprogno_esame\\Sciortino\\CodinGameMain
	std::string ANEOSponsoredPuzzleTestsPath{ "..\\ANEOSponsoredPuzzle\\Tests\\ANEOSponsoredPuzzleTest" };
	std::string PathTermination{ ".txt" };
	for (unsigned int i = 1; i <= 10; i++) {
		ANEOpuzzleExercise exercise{ ANEOSponsoredPuzzleTestsPath + std::to_string(i)+ PathTermination};
		exercise.Execute();
	}
	
	std::string WinamaxSponsoredContestTestsPath{ "..\\WinamaxSponsoredContest\\Tests\\WinamaxSponsoredContestTest" };
	for (unsigned int i = 2; i <= 4; i++) {
	
		DiscreteGolfTableSolver exercise(WinamaxSponsoredContestTestsPath + std::to_string(i) + PathTermination);
		exercise.Execute();
	}

	
}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
