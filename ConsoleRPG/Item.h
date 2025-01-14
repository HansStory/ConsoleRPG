#pragma once
#include "Character.h"
#include <string>

using namespace std;

class Item
{
	friend class Character;
public:
	Item();
	virtual ~Item();

	string GetName();
	virtual void Use(Character* character);

protected:
	string name = "";
	enum ItemType ItemType;
};


class HealPotion : public Item
{
public:
	HealPotion(string name, int amount);
	virtual ~HealPotion();
	
	void Use(Character* character);
private:
	int healAmount;
};


class AttackPowerUp : public Item
{
public:
	AttackPowerUp(string name, int amount);
	virtual ~AttackPowerUp();

	virtual void Use(Character* character);
private:
	int powerUpAmount;
	int duration;
};

