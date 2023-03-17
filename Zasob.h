#include <iostream>
using namespace std;
//zasób w³asnej klasy u¿ywanej w Menu.cpp
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
//W³asna klasa w której znajduj¹ siê funkcje
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