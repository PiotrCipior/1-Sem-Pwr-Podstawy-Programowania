#include <iostream>
#include <vector>
#include "Zasob.h"
using namespace std;

functions doSomething; // odwłołanie do funkcji z pliku Menu.cpp
zasob z; // odwłołanie do struktury

/* Plik głowny składa służy jedynie do zapętlenie menu i wywoływaniu funkcji*/
int main()
{
	char flag; //zmienna służaca za obsługe opuszczenia pętli do while
	char menuChoice; // zmienna służąca do menu switch
	do
	{
		system("CLS"); //funkcja czyszcząca terminal przy każdej pętli
		doSomething.menu(); // wyświetlanie menu
		cin >> menuChoice;
		//funkcje opisane są w pliku Menu.cpp
		switch (menuChoice)
		{
		case '1':
		{
			doSomething.addWeapon();
			break;
		}
		case '2':
		{
			doSomething.deleteWeapon();
			break;
		}
		case '3':
		{
			doSomething.showProducts();
			break;
		}
		case '4':
		{
			doSomething.changeInformation();
			break;
		}
		case '5':
		{
			doSomething.filtringSearch();
			break;
		}
		default:
			cout << "Zly wybor!\n";
			break;
		}
		cout << "Koontynuowac(t/n):\n> ";
		cin >> flag;
	} while (flag != 'n');
}