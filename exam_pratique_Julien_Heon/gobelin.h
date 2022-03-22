#pragma once
#include <iostream>
using namespace std;
class gobelin
{
private:
	int hp;
	int dmg;
	int armor;
	char* name;

	void GetHp(int hp);

	void GetDmg(int dmg);

	void GetArmor(int armor);

	void GetName(char* name);
public:
	//Initialise la vie, le damage que le goblin peut faire et sont armure
	void GoblinInitializer(int hp, int dmg, int armor, char* name);

	//Calcule son attaque
	int GoblinAttack();

	//Calcule le nombre de point de degat recu
	void takeDmg(int dmgTaken);

	//Regarde le nombre d'hp restant, s'il en reste <= a 0, il a perdu
	int HealhCheckUp();
};

