#include <iostream>
using namespace std;
//zas�b w�asnej klasy u�ywanej w Menu.cpp
class zasob
{
public:
	string name;
	string producer;
	string typeOfWeapone;
	double weight = 0;
	string typeOfAmmunition;
	unsigned int quantityInStorage = 0;
	unsigned int quantityInEvidence = 0;
	string date;
	string remarks;
	string additionalTraining;
	string additionalSafety;
};
//W�asna klasa w kt�rej znajduj� si� funkcje
class functions
{
public:
	void menu();
	void addWeapon();
	void deleteWeapon();
	void showProducts();
	void changeInformation();
	void filtringSearch();
	int howLongIsFile();
};