#include "Character.h"

#include <format>
#include <iostream>

using namespace std;

Character::Character(const string& name)
{
	this->name = name;	

	cout << "ĳ���� " << name << " ���� �Ϸ�!";
	cout << " ���� : " << level << ", ü�� : " << currentHP << " / " << maxHP << ", ���ݷ� : " << attackPower << endl;
}

Character::~Character()
{
}


const int& Character::GetAcctackPower()
{
	return this->attackPower; // + ������ + ����
}

const int& Character::GetGold()
{
	return this->gold;
}

void Character::DisplayStatus()
{
	cout << GetCharacterStatusString();
}

string Character::GetCharacterStatusString()
{
	string returnValue;
	returnValue += format("�̸� : {}\n", name);
	returnValue += format("���� : {}\n", level);
	returnValue += format("HP : {}/{}\n", currentHP, maxHP);
	returnValue += format("���ݷ� : {}\n", attackPower);
	returnValue += format("Gold : {}\n", gold);
	returnValue += format("����ġ : {}/{}\n", currentExp, requiredLevelUpExp);

	return returnValue;
}

map<EquipmentType, int> Character::GetEquipmentItems()
{
	return this->equipmentItems;
}

map<string, int> Character::GetInventory()
{
	return this->inventory;
}

void Character::UseItem(const string& itemKey)
{
}

void Character::TakeExp(const int& exp)
{
	currentExp += exp;
	if (currentExp >= requiredLevelUpExp)
	{
		LevelUp();
	}
}

void Character::TakeGold(const int& gold)
{
	this->gold += gold;
}

void Character::TakeItem(const string& itemKey)
{
	// TO DO : if Can't Find Add Key
	inventory[itemKey]++;

}

void Character::TakeItem(const int& equipmentKey)
{
	// TO DO : Parameter Replace : (class)EquipableItem

}

void Character::TakeDamage(const int& damage)
{
	currentHP -= damage;
}



void Character::LevelUp()
{
	//TO DO : Level Up
	currentExp -= requiredLevelUpExp;
	level++;

	IncreaseMaxHP(level);
	IncreaseAttackPower(level);
	IncreaseRequireLevelUpExp(level);
}

void Character::IncreaseMaxHP(const int& level)
{
}

void Character::IncreaseAttackPower(const int& level)
{
}

void Character::IncreaseRequireLevelUpExp(const int& level)
{

}


