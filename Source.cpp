#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

//Serperior attributes, "hero"
string serperiorName = "Serperior";
int decision;
int selectedAttack;
int serperiorMaxHp = 240;
int serperiorHp = 240;
int serperiorGigadrain;
int oldSerperiorHp;
int serperiorWringOut;
bool serperiorAlive = true;

//Torterra attributes
string torterraName = "Torterra";
int torterraHp = 240;
int torterraDamage;
bool torterraAlive = true;

//Blastoise attributes
string blastoiseName = "Blastoise";
int blastoiseHp = 240;
int blastoiseDamage;
bool blastoiseAlive = true;

//Others
int aux = 0;
int hitAmount = 0;

//Functions
void menu() {
	cout << "------POKEMON FIGHT------\n";
	cout << "Oh, no! A wild " << torterraName << " and " << blastoiseName << " have just appeared!\n";
	cout << "Go on, " << serperiorName << "!\n\n";
	cout << "NOTE: Remember that serperior starts with full hp! (240/240)\nTorterra and Blastoise also start with 240hp each.\n\n";
}

int attackTorterra(string enemy1Name, string heroName, int& enemy1Hp, int& heroHp, bool& enemy1Alive) {
	cin >> selectedAttack;
	if (selectedAttack == 1) {
		system("cls");

		if (enemy1Alive) {
			enemy1Hp = enemy1Hp - (rand() % ((130 + 1) - 110) + 110); //random with params, attack x1
		}
		else {
			system("cls");
			cout << enemy1Name << " is dead! Leave his suffering behind!";
		}
		while (enemy1Hp <= 0 && aux < 1) {
			enemy1Hp = 0;
			cout << enemy1Name << " is " << enemy1Hp << ". " << enemy1Name << " has weakened!" << "\n";
			aux++;
		}
	}

	else if (selectedAttack == 2) {

		system("cls");
		if (enemy1Alive) {
			serperiorWringOut = 1 + ((double)enemy1Hp / 200) * (rand() % ((120 + 1) - 100) + 100); //Wring Out algorithm, casting hp for using double
			enemy1Hp = enemy1Hp - serperiorWringOut; // attack x1
		}
		else {
			system("cls");
			cout << enemy1Name << " is dead! Leave his suffering behind!";
		}
		while (enemy1Hp <= 0 && aux < 1) {
			enemy1Hp = 0;
			cout << enemy1Name << " is " << enemy1Hp << ". " << enemy1Name << " has weakened!" << "\n";
			aux++;
		}
	}

	else if (selectedAttack == 3) {
		system("cls");

		if (enemy1Alive) {
			enemy1Hp = enemy1Hp - (rand() % ((90 + 1) - 70) + 70); // attack x1
		}
		else {
			system("cls");
			cout << enemy1Name << " is dead! Leave his suffering behind!";
		}
		while (enemy1Hp <= 0 && aux < 1) {
			enemy1Hp = 0;
			cout << enemy1Name << " is " << enemy1Hp << ". " << enemy1Name << " has weakened!" << "\n";
			aux++;
		}
	}

	else if (selectedAttack == 4 && hitAmount == 0) {
		system("cls");
		hitAmount++;

		if (enemy1Alive) {
			serperiorGigadrain = (rand() % ((85 + 1) - 65) + 65);
			enemy1Hp = enemy1Hp - serperiorGigadrain;  // attack x1
			oldSerperiorHp = heroHp; //Hp before getting healed

			if (enemy1Hp > 0) {
				heroHp = heroHp + serperiorGigadrain; //himself healing

				if (heroHp > serperiorMaxHp) {
					heroHp = serperiorMaxHp;
					cout << heroName << " healed himself " << serperiorMaxHp - oldSerperiorHp << "hp!\n"; //if heal exceeds the maxHp serperior can have
				}
				else {
					cout << heroName << " healed himself " << serperiorGigadrain << "hp!\n"; //if maxHp is not exceeded and enemy still alive
				}

			}
			else {
				heroHp = heroHp + serperiorGigadrain - abs(torterraHp); //himself healing if enemy gets killed
				cout << heroName << " healed himself " << serperiorGigadrain - abs(torterraHp) << "hp!\n";
			}
		}
		else {
			system("cls");
			cout << enemy1Name << " is dead! Leave his suffering behind!";
		}
		while (torterraHp <= 0 && aux < 1) {
			torterraHp = 0;
			cout << enemy1Name << " is " << torterraHp << ". " << enemy1Name << " has weakened!" << "\n";
			aux++;
		}

	}
	else {
		system("cls");
		cout << "You missed the attack!\n";
	}
	return selectedAttack;
}

int attackBlastoise(string enemy2Name, string heroName, int& enemy2Hp, int& heroHp, bool& enemy2Alive) {
	cin >> selectedAttack;
	if (selectedAttack == 1) {

		system("cls");

		if (enemy2Alive) {
			enemy2Hp = enemy2Hp - (rand() % ((200 + 1) - 180) + 180); // attack x2
		}
		else {
			system("cls");
			cout << enemy2Name << " is dead! Leave his suffering behind!";
		}
		while (enemy2Hp <= 0 && aux < 1) {
			enemy2Hp = 0;
			cout << enemy2Name << " is " << enemy2Hp << ". " << enemy2Name << " has weakened!" << "\n";
			aux++;
		}
	}

	else if (selectedAttack == 2) {
		system("cls");

		if (enemy2Alive) {
			serperiorWringOut = 1 + ((double)enemy2Hp / 200) * (rand() % ((120 + 1) - 100) + 100); //Wring Out algorithm, casting hp for using double
			enemy2Hp = enemy2Hp - serperiorWringOut; // attack x1
		}
		else {
			system("cls");
			cout << enemy2Name << " is dead! Leave his suffering behind!";
		}
		while (enemy2Hp <= 0 && aux < 1) {
			enemy2Hp = 0;
			cout << enemy2Name << " is " << enemy2Hp << ". " << enemy2Name << " has weakened!" << "\n";
			aux++;
		}
	}

	else if (selectedAttack == 3) {
		system("cls");

		if (enemy2Alive) {
			enemy2Hp = enemy2Hp - (rand() % ((80 + 1) - 60) + 60); // attack x1
		}
		else {
			system("cls");
			cout << enemy2Name << " is dead! Leave his suffering behind!";
		}
		while (enemy2Hp <= 0 && aux < 1) {
			enemy2Hp = 0;
			cout << enemy2Name << " is " << enemy2Hp << ". " << enemy2Name << " has weakened!" << "\n";
			aux++;
		}
	}

	else if (selectedAttack == 4 && hitAmount == 0) {
		system("cls");
		hitAmount++;

		if (enemy2Alive) {

			serperiorGigadrain = (rand() % ((170 + 1) - 130) + 130);
			enemy2Hp = enemy2Hp - serperiorGigadrain;  // attack x1
			oldSerperiorHp = heroHp; //Hp after getting healed

			if (enemy2Hp > 0) {
				heroHp = heroHp + serperiorGigadrain; //himself healing

				if (heroHp > serperiorMaxHp) {
					heroHp = serperiorMaxHp;
					cout << heroName << " healed himself " << serperiorMaxHp - oldSerperiorHp << "hp!\n"; //if heal exceeds the maxHp serperior can have
				}
				else {
					cout << heroName << " healed himself " << serperiorGigadrain << "hp!\n"; //if maxHp is not exceeded and enemy still alive
				}

			}
			else {
				heroHp = heroHp + serperiorGigadrain - abs(enemy2Hp); //himself healing if enemy gets killed
				cout << heroName << " healed himself " << serperiorGigadrain - abs(enemy2Hp) << "hp!\n";
			}
		}
		else {
			system("cls");
			cout << torterraName << " is dead! Leave his suffering behind!";
		}
		while (enemy2Hp <= 0 && aux < 1) {
			enemy2Hp = 0;
			cout << enemy2Name << " is " << enemy2Hp << ". " << enemy2Name << " has weakened!" << "\n";
			aux++;
		}
	}

	else {
		system("cls");
		cout << "You missed the attack!\n";
	}
	return selectedAttack;
}

int enemySelection(int& whoAttack, string enemy1Name, string enemy2Name, string heroName) {
	cout << "Who should " << heroName << " attack?\n";
	cout << "[1] " << enemy1Name << "\n";
	cout << "[2] " << enemy2Name << "\n";
	cin >> whoAttack;
	return whoAttack;
}

void attackSelectionText(int gigaDrainHits) {
	if (gigaDrainHits == 0) {
		system("cls");
		cout << "What shall " << serperiorName << " do?\n";
		cout << "[1] Leaf Storm\n";
		cout << "[2] Wring Out\n";
		cout << "[3] Slam\n";
		cout << "[4] Giga Drain - Only usable 1 time\n";

	}
	else {
		system("cls");
		cout << "What shall " << serperiorName << " do?\n";
		cout << "[1] Leaf Storm\n";
		cout << "[2] Wring Out\n";
		cout << "[3] Slam\n";
		cout << "[4] Giga Drain - No more uses available\n";
	}
}

boolean isAlive(int& checkHp) {

	if (checkHp <= 0) {
		checkHp = 0;
		return false;
	}
}

void serperiorAttacksAndKills(string enemy1Name, string enemy2Name, string heroName, int& enemy1Hp, int& enemy2Hp, int& heroHp, bool& enemy1Alive, bool& enemy2Alive) {
	if (decision == 1) {
		attackTorterra(enemy1Name, heroName, enemy1Hp, heroHp, enemy1Alive);
	}
	else if (decision == 2) {
		attackBlastoise(enemy2Name, heroName, enemy2Hp, heroHp, enemy2Alive);
	}
	else {
		system("cls");
		cout << "Please, choose " << enemy1Name << " or " << enemy2Name << " for " << heroName << "'s next attack\n";
	}

	if (enemy1Hp > 0) {
		cout << enemy1Name << " is " << enemy1Hp << "hp!\n\n";
	}
	else {
		enemy1Alive = isAlive(enemy1Hp);
	}

	if (enemy2Hp > 0) {
		cout << enemy2Name << " is " << enemy2Hp << "hp!\n\n";
	}
	else {
		enemy2Alive = isAlive(enemy2Hp);
	}

	if (enemy1Hp <= 0 && enemy2Hp <= 0) {
		cout << "Serperior won fight!";
	}
}

void enemiesAttacksAndKill(string enemy1Name, string enemy2Name, string heroName, int& heroHp, int enemy1Damage, int enemy2Damage, bool& enemy1Alive, bool& enemy2Alive, bool& heroAlive) {
	if (heroAlive && enemy1Alive) {
		//Torterra attack
		enemy1Damage = rand() % 100 + 1;
		heroHp -= enemy1Damage;

		if (heroHp <= 0) {
			cout << enemy1Name << " killed " << heroName << "\n";
			heroAlive = isAlive(heroHp);
		}
		else {
			cout << enemy1Name << " is going to attack!\n";
			cout << enemy1Name << " hitted " << heroName << " for " << enemy1Damage << ". " << heroName << " is now " << heroHp << "\n\n";
		}
	}

	if (heroAlive && enemy2Alive) {
		//Blastoise attack
		enemy2Damage = rand() % 100 + 1;
		heroHp -= enemy2Damage;

		if (heroHp <= 0) {
			cout << enemy2Name << " killed " << heroName << "\n";
			heroAlive = isAlive(heroHp);
		}
		else {
			cout << enemy2Name << " is going to attack!\n";
			cout << enemy2Name << " hitted " << heroName << " for " << enemy2Damage << ". " << heroName << " is now " << heroHp << "\n\n";
		}
	}
}

int main() {
	srand(time(NULL));
	bool background = PlaySound(TEXT("Pokemon_background.wav"), NULL, SND_ASYNC);
	//MENU//
	menu();
	//Starts fight
	while (serperiorAlive && (torterraAlive || blastoiseAlive)) {
		enemySelection(decision, torterraName, blastoiseName, serperiorName);
		attackSelectionText(hitAmount);
		serperiorAttacksAndKills(torterraName, blastoiseName, serperiorName, torterraHp, blastoiseHp, serperiorHp, torterraAlive, blastoiseAlive);
		enemiesAttacksAndKill(torterraName, blastoiseName, serperiorName, serperiorHp, torterraDamage, blastoiseDamage, torterraAlive, blastoiseAlive, serperiorAlive);
	}
}