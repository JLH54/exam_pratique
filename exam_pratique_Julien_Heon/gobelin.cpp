#include "gobelin.h"

void gobelin::GetHp(int hp)
{
	this->hp = hp;
}

void gobelin::GetDmg(int dmg)
{
	this->dmg = dmg;
}

void gobelin::GetArmor(int armor)
{
	this->armor = armor;
}

void gobelin::GetName(char* name)
{
	this->name = name;
}

void gobelin::GoblinInitializer(int hp, int dmg, int armor, char* name)
{
	GetHp(hp);
	GetDmg(dmg);
	GetArmor(armor);
	GetName(name);
}

int gobelin::GoblinAttack()
{
	return dmg = dmg % rand() + 1;
}

void gobelin::takeDmg(int dmgTaken)
{
	dmgTaken = dmgTaken - (armor % rand() + 1);
	hp = hp - dmgTaken;
	cout << "Goblin " << name << " a recu " << dmgTaken << " de degat, il lui reste "<< hp << " de point(s) de vie" << endl;
}

int gobelin::HealhCheckUp()
{
	if (hp <= 0)
	{
		cout << "Goblin " << name << " died fighting with his brothers" << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}


