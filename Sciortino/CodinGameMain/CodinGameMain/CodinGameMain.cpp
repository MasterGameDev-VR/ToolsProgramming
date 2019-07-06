// CodinGameMain.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	streambuf* cinbuffer = cin.rdbuf();
	string ANEOSponsoredPuzzleTestsPath{ "..\\ANEOSponsoredPuzzle\\Tests\\ANEOSponsoredPuzzleTest" };
	string PathTermination{ ".txt" };
	string WinamaxSponsoredContestTestsPath{ "..\\WinamaxSponsoredContest\\Tests\\WinamaxSponsoredContestTest" };

	cout << "     PROGETTI TOOLS - VITTORIO SCIORTINO A.A. 2018 - 2019  " <<endl<<endl;
	cout << "     1. ANEO Sponsored Puzzle Tests: calcola la velocità massima per poter attraversare" << endl;
	cout << "        una serie di semafori senza rallentare." << endl << endl;
	cout << "     2. Winamax Sponsored Contest Tests: risolve tabelle che rappresentano campi da golf," << endl;
	cout << "        in cui le palline inizialmente sono rappresentate da numeri e si possono muovere" << endl;
	cout << "        solo in orizzontale o in verticale del numero di celle fissato dal numero, il quale " << endl;
	cout << "        diminuisce ogni volta di 1, riducendo il numero di passi per la volta successiva; " << endl;
	cout << "        l'algoritmo sfrutta la ricorsione per trovare tutte le possibili traiettorie per ciascuna " << endl;
	cout << "        pallina, e successivamente il backtracking per assemblare queste traiettorie scegliendone una " << endl;
	cout << "        sola per pallina; si torna indietro ogni volta che le traiettorie si intersecano o che attraversano " << endl;
	cout << "        una cella con una pallina - numero o una buca - lettera H; X rappresenta il water hazard." << endl << endl;
	cout << "     0. Uscita "<< endl << endl << endl;
	while (true) 
	{
		cout << "   INPUT A VALID KEY   " << endl;
		char selector;
		cin.rdbuf(cinbuffer);
		cin >> selector;
		switch (selector) 
		{
		case '1':
			for (unsigned int i = 1; i <= 10; i++) {
				ANEOpuzzleExercise exercise{ ANEOSponsoredPuzzleTestsPath + std::to_string(i) + PathTermination };
				exercise.PrintTrafficLightsTable();
				exercise.Execute();
			}
		
			break;
		case '2':
			for (unsigned int i = 1; i <= 21; i++) {

				DiscreteGolfTableSolver exercise(WinamaxSponsoredContestTestsPath + std::to_string(i) + PathTermination);
				exercise.Execute();
			}
			break;
		case '0':
			return 0;
		default:
			cout <<"  Wrong key pressed! Try again!  " << endl << endl;
			break;
		}

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
