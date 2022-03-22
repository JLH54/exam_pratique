#pragma once
#include <iostream>
class joueur
{
private:
	int hp;
	int dmg;
	int armor;

	void GetHp(int hp);

	void GetDmg(int dmg);

	void GetArmor(int armor);

public:
	//Initialise la vie, le damage que le joueur peut faire et sont armure
	void PlayerInitializer(int hp, int dmg, int armor);

	//Calcule son attaque
	int PlayerAttack();

	//Calcule le nombre de point de degat recu
	void takeDmg(int dmgTaken);

	//Regarde le nombre d'hp restant, s'il en reste <= a 0, il a perdu
	int HealhCheckUp();
};

