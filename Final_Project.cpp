// Text Based RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct class_stats
{
	string type;
	int cur_exp; // current exp
	int max_exp; // amount of exp to level up
	int level;
	int health;
	int mana;
	int attack;
	int ability;
	string ability_name;
	int skill_pt_cnt;
}character;

class character_select
{
public:
	void initialize_and_display_class_stats()
	{
		do
		{
			cout << "Choose a class!\n";
			cout << "Type 1 to choose the Knight\n";
			cout << "Type 2 to choose the Mage\n";
			cout << "Type 3 to choose the Bard\n";
			cout << "Answer: ";
			cin >> class_choice;
			cout << endl;

			switch (class_choice)
			{
			case 1:
				character.type = "Knight"; // NSTC (name subject to change)
				character.ability = 1;
				character.ability_name = "Berserk"; // NSTC 
				break;
			case 2:
				character.type = "Mage"; // NSTC
				character.ability = 2;
				character.ability_name = "Magic Missle"; // NSTC
				break;
			case 3:
				character.type = "Bard"; // NSTC
				character.ability = 3;
				character.ability_name = "Seduce"; // NSTC
				break;
			}
			character.max_exp = 10;
			character.cur_exp = 0;
			character.health = 5;
			character.mana = 5;
			character.attack = 5;
			character.skill_pt_cnt = 10;
			cout << character.type << " Stats\n";
			cout << "Heath: " << character.health << endl;
			cout << "Mana: " << character.mana << endl;
			cout << "Attack: " << character.attack << endl;
			cout << character.type << " Abilities\n";
			cout << "-----------------\n";
			cout << "Ability: " << character.ability_name << endl;
			cout << endl;

			cout << "Do you want to continue? Type 1 for Yes or 0 for No: ";
			cin >> condition;
			cout << endl;
		} while (condition == 0);
		cout << endl;
	}
private:
	int class_choice;
	int condition;
};

class stat_initialization
{
public:
	void initialize_class_stats()
	{
		do
		{
			do
			{
				cout << "--------------------------------------\n";
				cout << "You have " << character.skill_pt_cnt << " skill points to spend.\n";
				cout << "Health: " << character.health << endl;
				cout << "Mana: " << character.mana << endl;
				cout << "Attack: " << character.attack << endl;
				cout << "--------------------------------------\n";
				cout << "Type 1 to increase your health or 7 to decrease your health\n";
				cout << "Type 2 to increase your mana or 8 to decrease your mana\n";
				cout << "Type 3 to increase your attack or 9 to decrease your attack\n";
				cout << "Answer: ";
				cin >> answer;
				cout << endl;
				switch (answer)
				{
				case 1:
					cout << "How many points do you want to give to your health?\n";
					cin >> points;
					character.health += points;
					character.skill_pt_cnt -= points;
					break;
				case 2:
					cout << "How many points do you want to give to your mana?\n";
					cin >> points;
					character.mana += points;
					character.skill_pt_cnt -= points;
					break;
				case 3:
					cout << "How many points do you want to give to your attack?\n";
					cin >> points;
					character.attack += points;
					character.skill_pt_cnt -= points;
					break;
				case 7:
					cout << "How many points do you want to take from your health?\n";
					cin >> points;
					character.health -= points;
					character.skill_pt_cnt += points;
					break;
				case 8:
					cout << "How many points do you want to take from your mana?\n";
					cin >> points;
					character.mana -= points;
					character.skill_pt_cnt += points;
					break;
				case 9:
					cout << "How many points do you want to take from your attack?\n";
					cin >> points;
					character.attack -= points;
					character.skill_pt_cnt += points;
					break;
				}
				cout << "You have " << character.skill_pt_cnt << " skill points left to spend.\n";
				cout << "Health: " << character.health << endl;
				cout << "Mana: " << character.mana << endl;
				cout << "Attack: " << character.attack << endl;
				cout << endl;
				cout << "Are you satisfied with your stats? Type 1 for Yes or 0 for No: ";
				cin >> condition;
				cout << endl;
				if (condition == 0)
				{
					switch (answer)
					{
					case 1:
						character.health -= points;
						character.skill_pt_cnt += points;
						break;
					case 2:
						character.mana -= points;
						character.skill_pt_cnt += points;
						break;
					case 3:
						character.attack -= points;
						character.skill_pt_cnt += points;
						break;
					case 7:
						character.health += points;
						character.skill_pt_cnt -= points;
						break;
					case 8:
						character.mana += points;
						character.skill_pt_cnt -= points;
						break;
					case 9:
						character.attack += points;
						character.skill_pt_cnt -= points;
						break;
					}
				}
				else
				{
					break;
				}
			} while (condition == 0);

		} while (character.skill_pt_cnt != 0);
	}
private:
	int points;
	int answer;
	int condition;
};

class character_ability_list
{
public:
	int choose_class_ability(int response)
	{
		switch (response) // Each case will have the corresponding class called for that ability. This class function will be called everytime we use an ability.
		{
		case 1:
			// Ability Class Call for Knight
			break;
		case 2:
			// Ability Class Call for Mage
			break;
		case 3:
			// Ability Class Call for Bard
			break;
		}
		return (response);
	}
};

class character_level_up
{
public:
	void level_up()
	{
		cout << "Level Up!\n";
		cout << endl;
		character.max_exp += 10;
		character.cur_exp = 0;
		character.skill_pt_cnt = 5;
	}
};

int main()
{
	character_select s;
	stat_initialization stat;
	// character_ability_list abl;
	// character_level_up l;

	s.initialize_and_display_class_stats();
	stat.initialize_class_stats();
	// l.level_up();
	// stat.initialize_class_stats();

	// abl.choose_class_ability(character.ability);

	cout << endl;
	system("pause");
	return 0;
}