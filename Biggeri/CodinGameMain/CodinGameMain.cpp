// CodinGameMain.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include "..\Bender1\BenderEp1.h"
#include "..\WarStatic\War.h"

using std::cin;
using std::cout;
using std::endl;



int main() {
	std::streambuf *backup;
	backup = std::cin.rdbuf();

	while (true) {
		cin.rdbuf(backup);

		cout << "Biggeri" << endl;
		cout << "Tools" << endl << endl;
		cout << "1) Bender" << endl;
		cout << "2) War" << endl;

		cout << endl;
		cout << "Inserire numero" << endl;

		int selection;
		cin >> selection;

		switch (selection) {
		case 0:
			return 0;
		case 1:
		{
			cout << "Inserire numero test, da 0 a 11" << endl;

			cin >> selection;
			std::string file = "..\\Bender1\\Test\\"+ std::to_string(selection) +".txt";
			std::ifstream inputFileStream{ file };
			if (!inputFileStream.good())
			{
				cout << "File inesistente" << endl;
			}
			else
			{
				BenderEp1 bender1{ file };
				bender1.Execute();
			}
			break;
		}
		case 2:
		{
			cout << "Inserire numero test, da 0 a 8" << endl;

			cin >> selection;
			std::string file = "..\\WarStatic\\Test\\" + std::to_string(selection) + ".txt";
			std::ifstream inputFileStream{ file };
			if (!inputFileStream.good())
			{
				cout << "File inesistente" << endl;
			}
			else
			{
				War war{ file };
				war.Execute();
			}
			break;
		}
		default:
			cout << "numero inesistente" << endl;
		}
		cout << endl;
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
