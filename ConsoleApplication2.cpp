#include "pch.h"
#include <iostream>
#include "monster.h"
#include "character.h"
#include "gamefunctions.h"
//LOOK INTO STATE MACHINES
using namespace std;
int main()
{
	Character character1;
	GameFunctions game;
	Monster monster1;
	game.introScreen(character1);
	monster1.Initialize();
	game.Combat(character1, monster1);
	return 0;
}