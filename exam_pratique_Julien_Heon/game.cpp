#include "game.h"

//Je l'ai mit comme ca pour pouvoir avoir un acces facile pour modifier certaine variables
#pragma region goblin
#define GOBLINHP 10
#define GOBLINDMG 6
#define GOBLINARMOR 4
#define MAXGOBLIN 5
#pragma endregion

#pragma region player
#define PLAYERHP 100
#define PLAYERDMG 20
#define PLAYERARMOR 6
#pragma endregion 

int game::CheckGoblins()
{
	if (listGoblin.size() == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void game::PlayerWins(bool condition)
{
	if (condition)
	{
		cout << "Vous avez exterminer tout ce qui etait autour de vous, excepter votre ami. Vous l'avez sauvez\n";
	}
	else if (!condition)
	{
		cout << "Les goblins ont eu le meilleur de vous... vous avez maintenant rejoin votre ami" << endl;
	}
}

void game::GameOn()
{
	InitGoblin();
	InitPlayer();
	bool condition = true;
	round = 1;
	while (condition)
	{
		cout << "round #" << round << endl;
		int playerDmg = player.PlayerAttack();
		for (int i = 0; i < listGoblin.size(); i++)
		{
			int state = 1;
			listGoblin[i].takeDmg(playerDmg);
			state = listGoblin[i].HealhCheckUp();
			//On ne veut pas que le goblin attaque s'il est mort
			if (state == 0)
			{
				//Je ne comprend pas pourquoi le erase ne prend pas la position
				listGoblin.erase(listGoblin[i]);
			}
			else
			{
				int goblinAttack = listGoblin[i].GoblinAttack();
				player.takeDmg(goblinAttack);
			}
		}
		int conditionGoblin = CheckGoblins();
		if (conditionGoblin == 0)
		{
			PlayerWins(true);
			break;
		}

		int conditionPlayer = player.HealhCheckUp();
		if (conditionPlayer == 0)
		{
			PlayerWins(false);
			break;
		}
		round++;
	}
}


void game::InitGoblin()
{
	vector<gobelin> listGoblin;
	for (int i = 0; i < MAXGOBLIN; i++)
	{
		char* nom;
		cout << "Veuillez entrez le nom du gobelin : \n";
		cin >> nom;
		listGoblin[i].GoblinInitializer(GOBLINHP, GOBLINDMG, GOBLINARMOR, nom);
		listGoblin.emplace_back(listGoblin[i]);
	}
}


void game::InitPlayer()
{
	joueur player;
	player.PlayerInitializer(PLAYERHP, PLAYERDMG, PLAYERARMOR);
}
