#include "gobelin.h"
#include "joueur.h"
#include <iostream>
#include <vector>
#pragma once
using namespace std;
class game
{
private:
	int round;

	vector<gobelin> listGoblin;

	joueur player;

	//Regarde s'il ne reste plus de goblins
	int CheckGoblins();

	//Regarde si le joueur gagne
	void PlayerWins(bool condition);
public:

	//Est le jeu
	void GameOn();

	//Initialise les goblins
	void InitGoblin();

	//Initialise le joueur
	void InitPlayer();

};

