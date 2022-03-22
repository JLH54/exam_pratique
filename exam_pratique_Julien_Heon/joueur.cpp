#include "joueur.h"
using namespace std;

void joueur::GetHp(int hp)
{
	this->hp = hp;
}

void joueur::GetDmg(int dmg)
{
	this->dmg = dmg;
}

void joueur::GetArmor(int armor)
{
	this->armor = armor;
}

void joueur::PlayerInitializer(int hp, int dmg, int armor)
{
	GetHp(hp);
	GetDmg(dmg);
	GetArmor(armor);
}

int joueur::PlayerAttack()
{
	return dmg = dmg % rand() + 1;
}

void joueur::takeDmg(int dmgTaken)
{
	dmgTaken = dmgTaken - (armor % rand() + 1);
	hp = hp - dmgTaken;
	cout << "Vous avez prit " << dmgTaken<< "du/des goblin(s), il vous reste " << hp << " de point de vie" << endl;
}

int joueur::HealhCheckUp()
{
	if (hp <= 0)
	{
		cout << "YOU DIED" << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}
