#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

Item::Item()
{
	this->name = "Item";
	cout << "CTOR Item" << endl;
}

Item::~Item()
{
	cout << "DELETE Item" << endl;
}

string Item::GetName()
{
	return this->name;
}

void Item::Use(Character* character)
{
	cout << character->GetName() << "Use Default Item!!" << endl;
}

HealPotion::HealPotion(string name, int amount)
{
	cout << "CTOR Heal Potion" << endl;

	this->name = name;
	this->healAmount = amount;
}

HealPotion::~HealPotion()
{
	cout << "DELETE Heal Potion" << endl;
}


void HealPotion::Use(Character* character)
{
	character->currentHP += healAmount;
}


AttackPowerUp::AttackPowerUp(string name, int amount)
{
	cout << "CTOR AttackPowerUp" << endl;

	this->name = name;
	this->powerUpAmount = amount;
}

AttackPowerUp::~AttackPowerUp()
{
	cout << "DELETE AttackPowerUp" << endl;
}

void AttackPowerUp::Use(Character* character)
{
	character->attackPower += powerUpAmount;
}
