#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "Zasob.h"

using namespace std; 

// wyœwietlanie menu
void functions::menu() 
{
	cout << "Co chcesz zrobic?\n";
	cout << "1) Dodaj produkt\n";
	cout << "2) Usun produkt\n";
	cout << "3) Wyswietl liste produktow\n";
	cout << "4) Wyswietl liste produktow i zmien dane\n";
	cout << "5) Wyswietl liste produktow uzywajac filtra\n> ";
}
/* Dodawanie broni, poprzez pytanie najpierw o nazwe broni, a nastêpnie o ka¿d¹ mo¿liw¹ dane i wpisanie nastêpne do pliku "data.txt".
dane broni s¹ nieobowi¹zkowe i jeœli nie zostan¹ wpisane bêd¹ potetm wyœwitlany znak "-" */
void functions::addWeapon() 
{
	ofstream data("data.txt", ios::app);
	zasob name;
	char flag;

	cout << "Podaj nazwe broni:\n> ";
	cin >> name.name;
	if (name.name.length() > 100)
	{
		name.name = "\n-";
	}
	data<<endl<< name.name<<" ; ";

	cout << "Czy chcesz wpisac dane?(t/n)\n> ";
	cin >> flag;

	if (flag == 't')
	{
		cout << "Podaj producenta:\n> ";
		cin >> name.producer;
		if (name.producer.length() > 256)
		{
			name.producer = "-";
		}
		cout << "Podaj typ broni(krotka, dluga, material wybuchowy, granat, mina, amunicja, pocisk rakietowy, bomba lotnicza, inne):\n> ";
		cin >> name.typeOfWeapone;
		if (name.typeOfWeapone != "krotka" || name.typeOfWeapone != "dluga" || name.typeOfWeapone != "material wybuchowy" || name.typeOfWeapone != "granat" || name.typeOfWeapone != "mina" || name.typeOfWeapone != "amunicja" || name.typeOfWeapone != "pocisk rakietowy" || name.typeOfWeapone != "bomba lotnicza" || name.typeOfWeapone != "inne")
		{
			name.typeOfWeapone = "-";
		}
		else if (name.typeOfWeapone != "Krotka" || name.typeOfWeapone != "Dluga" || name.typeOfWeapone != "Material wybuchowy" || name.typeOfWeapone != "Granat" || name.typeOfWeapone != "Mina" || name.typeOfWeapone != "Amunicja" || name.typeOfWeapone != "Pocisk rakietowy" || name.typeOfWeapone != "Bomba lotnicza" || name.typeOfWeapone != "Inne")
		{
			name.typeOfWeapone = "-";
		}
		cout << "Podaj wage broni:\n> ";
		cin >> name.weight;
		cout << "Podaj typ amunicji:\n> ";
		cin >> name.typeOfAmmunition;
		if (name.typeOfAmmunition.length() > 50)
		{
			name.typeOfAmmunition = "-";
		}
		cout << "Podaj ilosc sztuk w magazynie:\n> ";
		cin >> name.quantityInStorage;
		cout << "Podaj ilosc sztuk w ewidencji:\n> ";
		cin >> name.quantityInEvidence;
		if (name.quantityInEvidence < name.quantityInStorage)
		{
			name.quantityInStorage = name.quantityInEvidence;
		}
		cout << "Podaj date dostawy\n> ";
		cin >> name.date;
		if (name.date.length() <= 8 || name.date.length() >= 10)
		{
			name.date = "-";
		}
		cout << "Podaj swoje uwagi\n> ";
		cin >> name.remarks;
		if (name.remarks.length() >= 1000)
		{
			name.remarks = "-";
		}
		cout << "Wymaga przeszkolenia?(true/false)\n> ";
		cin >> name.additionalTraining;
		if (name.additionalTraining == "false" || "true")
		{
			name.additionalTraining = "false";
		}
		cout << "Wymaga dodatkowego przeszkolenia?(true/false)\n> ";
		cin >> name.additionalSafety;
		if (name.additionalSafety == "false" || "true")
		{
			name.additionalSafety = "false";
		}
		data << name.producer << " ; ";
		data << name.typeOfWeapone << " ; ";
		data << name.weight << " ; ";
		data << name.typeOfAmmunition << " ; ";
		data << name.quantityInStorage << " ; ";
		data << name.quantityInEvidence << " ; ";
		data << name.date << " ; ";
		data << name.remarks << " ; ";
		data << name.additionalTraining << " ; ";
		data << name.additionalSafety << " ; / ";
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			data << " - ;";
		}
		data << " / ";
	}
}
/*Usuwanie jednego punktu z pliku "data.txt"*/
void functions::deleteWeapon()
{
	/*wpisywanie danych z pliku "data.txt" do tablicy dynamicznej dwuwymiarowej*/
	int fileLength = howLongIsFile();
	int z = 1;
	int x = 0;
	fstream plik;
	ifstream datain("data.txt");
	ifstream datain2("data.txt");
	string liczby;
	string linia;
	string** tabFirst = new string*[fileLength];
	string** tab = new string * [fileLength];
	int* tabLenght = new int[fileLength];

	plik.open("data.txt", ios::in);
	for (int i =0;i<fileLength;i++)
	{
		getline(plik, linia);
		x=linia.length();
		tabFirst[i] = new string[x];
		for (int j = 0; j < x; j++)
		{
			datain >> tabFirst[i][j];
			if (tabFirst[i][j] == "/")
			{
				tab[i] = new string[j+1];
				tabLenght[i] = j+1;
				j = x;
			}
		}
	}
	plik.close();

		//Wyœwitlenie listy produktów
	cout << "L.P.  Nazwa  Producent  Typ  Waga  Amunicja  Magazyn  Ewidencja  Dostawa	Uwaga  Przeszkolenie  Dod. Przeszkolenie\n";
	for (int i = 0; i < fileLength; i++)
	{
		cout << i + 1 << ".    ";
		for (int j = 0; j < tabLenght[i]; j++)
		{
			datain2 >> tab[i][j];
			if (tab[i][j] != ";" && tab[i][j] != "/")
			{
				cout << tab[i][j] << "	";
			}
			if (tab[i][j] == "/")
			{
				j = tabLenght[i];
			}
		}
		cout << " " << endl;
	}
	ofstream dataout("data.txt");
	int choice = 0 ;
		
	//wybór produktu do usuniêcia
	cout << "Ktore chcesz usunac?(wpisz 0 jesli zadne)\n> ";
	cin >> choice;
	//usuniêcie produktu poprzez wpisanie wszysytkich danych z tablicy do pliku "data.txt" pomijaj¹c wybrany produkt
	for (int i = 0; i < fileLength; i++)
	{
		if (i != choice-1)
		{
			for (int j = 0; j < tabLenght[i]; j++)
			{
				dataout << tab[i][j]<<"	";
				if (tab[i][j] == "/")
				{
					j = tabLenght[i];
				}
			}
			if (i != fileLength - 1)
			{
				dataout << "\n";
			}
		}
	}

	for (int i = 0; i < fileLength; ++i) {
		delete[] tab[i];
	}
	delete[] tab;
}

//Wyœwietlenie danych z pliku "data.txt"
void functions::showProducts()
{
	/*wpisywanie danych z pliku "data.txt" do tablicy dynamicznej dwuwymiarowej*/
	int fileLength = howLongIsFile();
	int  z = 1;
	int x = 0;
	fstream plik;
	ifstream datain("data.txt");
	ifstream datain2("data.txt");
	string liczby;
	string linia;
	string** tab = new string * [fileLength];
	string** tabFirst = new string * [fileLength];
	int* tabLenght = new int[fileLength];

	plik.open("data.txt", ios::in);
	for (int i = 0; i < fileLength; i++)
	{
		getline(plik, linia);
		x = linia.length();
		tabFirst[i] = new string[x];
		for (int j = 0; j < x; j++)
		{
			datain >> tabFirst[i][j];
			if (tabFirst[i][j] == "/")
			{
				tab[i] = new string[j + 1];
				tabLenght[i] = j + 1;
				j = x;
			}
		}
	}
	plik.close();

	//Wypisanie danych z tablicy do terminala z pominiêciem znaków typu ";" lub "/"
	cout << "L.P.  Nazwa  Producent  Typ  Waga  Amunicja  Magazyn  Ewidencja  Dostawa	Uwaga  Przeszkolenie  Dod. Przeszkolenie\n";
	for (int i = 0; i < fileLength; i++)
	{
		cout << i + 1 << ".    ";
		for (int j = 0; j < tabLenght[i]; j++)
		{
			datain2 >> tab[i][j];
			if (tab[i][j] != ";" && tab[i][j] != "/")
			{
				cout << tab[i][j] << "	";
			}
			if (tab[i][j] == "/")
			{
				j = tabLenght[i];
			}
		}
		cout << " " << endl;
	}
	for (int i = 0; i < fileLength; ++i) {
		delete[] tab[i];
	}
	delete[] tab;
}
//zmiana informacji w pliku poprzez podstawienie nowych danych w tablicy
void functions::changeInformation()
{
	/*wpisywanie danych z pliku "data.txt" do tablicy dynamicznej dwuwymiarowej*/
	int fileLength = howLongIsFile();
	int z = 1;
	int x = 0;
	fstream plik;
	ifstream datain("data.txt");
	ifstream datain2("data.txt");
	string liczby, linia;
	string** tab = new string * [fileLength];
	string** tabFirst = new string * [fileLength];
	int* tabLenght = new int[fileLength];

	plik.open("data.txt", ios::in);

	for (int i = 0; i < fileLength; i++)
	{
		getline(plik, linia);
		x = linia.length();
		tabFirst[i] = new string[x];
		for (int j = 0; j < x; j++)
		{
			datain >> tabFirst[i][j];
			if (tabFirst[i][j] == "/")
			{
				tab[i] = new string[j + 1];
				tabLenght[i] = j + 1;
				j = x;
			}
		}
	}
	plik.close();

	//Wypisanie danych z tablicy do terminala z pominiêciem znaków typu ";" lub "/"
	cout << "L.P.  Nazwa  Producent  Typ  Waga  Amunicja  Magazyn  Ewidencja  Dostawa	Uwaga  Przeszkolenie  Dod. Przeszkolenie\n";
	for (int i = 0; i < fileLength; i++)
	{
		cout << i + 1 << ".    ";
		for (int j = 0; j < tabLenght[i]; j++)
		{
			datain2 >> tab[i][j];
			if (tab[i][j] != ";" && tab[i][j] != "/")
			{
				cout << tab[i][j] << "	";
			}
			if (tab[i][j] == "/")
			{
				j = tabLenght[i];
			}
		}
		cout << " " << endl;
	}
	
	int choice = 0;
	int choiceAction;
	int buffer = 0;
	int jj = 0;
	stringstream ss;
	zasob name;

	//zmiana danych poprzez podstawienie w tablicy
	cout << "Wybierz w ktorym wersie chcesz zmienic dane\n> ";
	cin >> choice;
	choice--;
	cout << "Co chcesz zedytowac:\n1) Wszystkie dane\n2) Wszystkie dane oprocz nazwy\n3) Tylko date\n> ";
	cin >> choiceAction;

	if (choiceAction == 1 || choiceAction == 2)
	{
		if (choiceAction == 1)
		{
			cout << "Podaj nazwe broni:\n> ";
			cin >> name.name;
			if (name.name.length() > 100)
			{
				name.name = "\n-";
			}
			tab[choice][1] = name.name;
		}
		else if (choiceAction == 2)
		{
			for (int i = 0; i < tabLenght[choice]; i++)
			{
				if (tab[choice][i] == ";")
				{
					jj = i;
					i = fileLength;
				}
			}
		}

		cout << "Podaj producenta:\n> ";
		cin >> name.producer;
		if (name.producer.length() > 256)
		{
			name.producer = "-";
		}
		cout << "Podaj typ broni(krotka, dluga, material wybuchowy, granat, mina, amunicja, pocisk rakietowy, bomba lotnicza, inne):\n> ";
		cin >> name.typeOfWeapone;
		if (name.typeOfWeapone != "krotka" || name.typeOfWeapone != "dluga" || name.typeOfWeapone != "material wybuchowy" || name.typeOfWeapone != "granat" || name.typeOfWeapone != "mina" || name.typeOfWeapone != "amunicja" || name.typeOfWeapone != "pocisk rakietowy" || name.typeOfWeapone != "bomba lotnicza" || name.typeOfWeapone != "inne")
		{
			name.typeOfWeapone = "-";
		}
		else if (name.typeOfWeapone != "Krotka" || name.typeOfWeapone != "Dluga" || name.typeOfWeapone != "Material wybuchowy" || name.typeOfWeapone != "Granat" || name.typeOfWeapone != "Mina" || name.typeOfWeapone != "Amunicja" || name.typeOfWeapone != "Pocisk rakietowy" || name.typeOfWeapone != "Bomba lotnicza" || name.typeOfWeapone != "Inne")
		{
			name.typeOfWeapone = "-";
		}
		cout << "Podaj wage broni:\n> ";
		cin >> name.weight;
		cout << "Podaj typ amunicji:\n> ";
		cin >> name.typeOfAmmunition;
		if (name.typeOfAmmunition.length() > 50)
		{
			name.typeOfAmmunition = "-";
		}
		cout << "Podaj ilosc sztuk w magazynie:\n> ";
		cin >> name.quantityInStorage;
		cout << "Podaj ilosc sztuk w ewidencji:\n> ";
		cin >> name.quantityInEvidence;
		if (name.quantityInEvidence < name.quantityInStorage)
		{
			name.quantityInStorage = name.quantityInEvidence;
		}
		cout << "Podaj date dostawy\n> ";
		cin >> name.date;
		if (name.date.length() < 8 || name.date.length() > 10)
		{
			name.date = "-";
		}
		cout << "Podaj swoje uwagi\n> ";
		cin >> name.remarks;
		if (name.remarks.length() >= 1000)
		{
			name.remarks = "-";
		}
		cout << "Wymaga przeszkolenia?(true/false)\n> ";
		cin >> name.additionalTraining;
		if (name.additionalTraining == "false" || "true")
		{
			name.additionalTraining = "false";
		}
		cout << "Wymaga dodatkowego przeszkolenia?(true/false)\n> ";
		cin >> name.additionalSafety;
		if (name.additionalSafety == "false" || "true")
		{
			name.additionalSafety = "false";
		}
		if (choiceAction == 1)
		{
			tab[choice][0] = name.name;
			tab[choice][1] = ";";
			tab[choice][2] = name.producer;
			tab[choice][3] = ";";
			tab[choice][4] = name.typeOfWeapone;
			tab[choice][5] = ";";
			ss << name.weight;
			ss >> tab[choice][6];
			tab[choice][7] = ";";
			tab[choice][8] = name.typeOfAmmunition;
			tab[choice][9] = ";";
			ss << name.typeOfAmmunition;
			ss >> tab[choice][10];
			tab[choice][11] = ";";
			ss << name.quantityInStorage;
			ss >> tab[choice][12];
			tab[choice][13] = ";";
			tab[choice][14] = name.date;
			tab[choice][15] = ";";
			tab[choice][16] = name.remarks;
			tab[choice][17] = ";";
			tab[choice][18] = name.additionalTraining;
			tab[choice][19] = ";";
			tab[choice][20] = name.additionalSafety;
			tab[choice][21] = ";";
			tab[choice][22] = "/";
			tabLenght[choice] = 23;
		}
		if (choiceAction == 2)
		{
			int j = jj;
			tab[choice][j] = name.producer;
			j++;
			tab[choice][j] = ";";
			j++;
			tab[choice][j] = name.typeOfWeapone;
			j++;
			tab[choice][j] = ";";
			j++;
			ss << name.weight;
			ss >> tab[choice][j];
			j++;
			tab[choice][j] = ";";
			j++;
			tab[choice][j] = name.typeOfAmmunition;
			ss << name.typeOfAmmunition;
			ss >> tab[choice][j];
			j++;
			tab[choice][j] = ";";
			j++;
			ss << name.quantityInStorage;
			ss >> tab[choice][j];
			j++;
			tab[choice][j] = ";";
			j++;
			tab[choice][j] = name.date;
			j++;
			tab[choice][j] = ";";
			j++;
			tab[choice][j] = name.remarks;
			j++;
			tab[choice][j] = ";";
			j++;
			tab[choice][j] = name.additionalTraining;
			j++;
			tab[choice][j] = ";";
			j++;
			tab[choice][j] = name.additionalSafety;
			j++;
			tab[choice][j] = ";";
			j++;
			tab[choice][j] = " /";
			tabLenght[choice] = j+1;
		}

	}

	if (choiceAction == 3)
	{
		for (int i = 0; i < tabLenght[choice]; i++)
		{
			if (tab[choice][i] == ";")
			{
				buffer++;
			}
			if (buffer == 7)
			{
				cout << "Podaj now¹ date\n> ";
				i++;
				cin >> tab[choice][i];
				if (name.date.length() < 8 || name.date.length() > 10)
				{
					name.date = "-";
				}
				i = tabLenght[choice];
			}
		}
	}
	ofstream dataout("data.txt");

	for (int i = 0; i < fileLength; i++)
	{
		for (int j = 0; j < tabLenght[i]; j++)
		{
			dataout << tab[i][j] << "	";
			if (tab[i][j] == "/")
			{
				j = tabLenght[i];
			}
		}
		if (i != fileLength - 1)
		{
			dataout << "\n";
		}
	}
	for (int i = 0; i < fileLength; ++i) {
		delete[] tab[i];
	}
	delete[] tab;
}
//Wyszukanie danych poprzez u¿ycie podstawowego filtra
void functions::filtringSearch()
{
	int fileLength = howLongIsFile();
	int z = 1;
	int x = 0;
	fstream plik;
	ifstream datain("data.txt");
	ifstream datain2("data.txt");
	string liczby, linia;
	string** tabFirst = new string * [fileLength];
	string** tab = new string * [fileLength];
	int* tabLenght = new int[fileLength];

	/*wpisywanie danych z pliku "data.txt" do tablicy dynamicznej dwuwymiarowej*/
	plik.open("data.txt", ios::in);
	for (int i = 0; i < fileLength; i++)
	{
		getline(plik, linia);
		x = linia.length();
		tabFirst[i] = new string[x];
		for (int j = 0; j < x; j++)
		{
			datain >> tabFirst[i][j];
			if (tabFirst[i][j] == "/")
			{
				tab[i] = new string[j + 1];
				tabLenght[i] = j + 1;
				j = x;
			}
		}
	}
	plik.close();

	for (int i = 0; i < fileLength; i++)
	{
		for (int j = 0; j < tabLenght[i]; j++)
		{
			datain2 >> tab[i][j];
			if (tab[i][j] == "/")
			{
				j = tabLenght[i];
			}
		}
	}

	int choice = 1;
	int buffer = 0;
	int buffer2 = 0;
	int counter = 0;
	int	counter2 = 0;
	string phrase;
	bool lever = false;
	bool lever2=false;

	//Wyszukanie gdzie szukaæ danej czêœci produktów a nastêpnie sprawdzenie co pasuje do wpisanego wzorca
	cout << "Co chcesz wyszukac?\n1) Nazwa\n2) Producent\n3) Typ\n4) Waga\n5) Amunicja\n6) Magazyn\n7) Ewidencja\n8) Dostawa\n9) Uwaga\n10) Przeszkolenie\n11) Dod. Przeszkolenie\n> ";
	cin >> choice;
	choice--;
	cout << "Podaj fraze do wyszukania:\n> ";
	cin >> phrase;
	cout << "L.P.  Nazwa  Producent  Typ  Waga  Amunicja(mm)  Magazyn  Ewidencja  Dostawa	Uwaga  Przeszkolenie  Dod. Przeszkolenie\n";

	for (int i = 0; i < fileLength; i++)
	{
		for (int j = 0; j < tabLenght[i]; j++)
		{
			if (tab[i][j] == ";")
			{
				counter++;
			}
			else
			{
				counter2++;
			}
			if (lever == false && counter == choice)
			{
				buffer = counter2 - counter;
				for (int z = j-buffer; z <= j; z++)
				{
					if (tab[i][z] == phrase)
					{
						j = 0;
						lever = true;
						counter = 0;
						counter2 = 0;
					}		
				}
			}
			if (tab[i][j] != ";" && tab[i][j] != "/"  && lever== true)
			{
				cout << tab[i][j] << "	";
			}
			if (tab[i][j] == "/" && lever == true)
			{
				j = tabLenght[i];
				cout << endl;
			}
		}
		counter = 0;
		lever = false;
		lever2 = false;
	}
	for (int i = 0; i < fileLength; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}
//wyszukanie d³ugoœci pliku "data.txt" poprzez policzenie linijek i zwrócenie iloœci tych linijek
int functions::howLongIsFile()
{
	fstream plik;
	string liczby;
	string linia;
	int x = 0;

	plik.open("Data.txt", ios::in);
	while (plik.eof() != true)
	{
		getline(plik, linia);
		x++;
	}
	plik.close();
	return x;
}