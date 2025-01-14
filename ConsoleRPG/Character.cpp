#include "Character.h"

#include <format>
#include <iostream>
#include "ExceptionHandler.h"

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

string Character::GetName()
{
	return this->name;
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

map<string, class Inventory> Character::GetInventory()
{
	return this->inventory;
}

//map<EquipmentType, int> Character::GetEquipmentItems()
//{
//	return this->equipmentItems;
//}

void Character::UseItem(const string& itemKey)
{
	if (inventory.find(itemKey) == inventory.end())
	{
		throw ExceptionHandler(Unknown, "�������� �����ϴ�.");
	}
	else
	{
		Inventory selectedItem = inventory[itemKey];
		if (selectedItem.ItemType == Consumable)
		{
			selectedItem.Item->Use(this);
			selectedItem.Count--;

			if (selectedItem.Count == 0)
			{
				inventory.erase(itemKey);
			}
		}
	}

}

void Character::TakeExp(const int& exp)
{
	if (level != maxLevel)
	{
		currentExp += exp;
		cout << format("����ġ�� ȹ���߽��ϴ�! ����ġ : {}", exp) << endl;

		if (currentExp >= requiredLevelUpExp)
		{
			LevelUp();
		}
	}
}

void Character::TakeGold(const int& gold)
{
	this->gold += gold;
}

void Character::TakeItem(class Item* item)
{
	// TO DO : if Can't Find Add Key
	string itemName = item->GetName();
	if (inventory.find(itemName) == inventory.end())
	{
		inventory[itemName] = Inventory(item, 1);
		cout << format("�ű� �������� �߰��ƽ��ϴ�!! ������ �̸� : {}, ���� : {}", itemName, inventory[itemName].Count) << endl;
	}
	else
	{
		inventory[itemName].Count++;
		cout << format("���� ������ ������ �߰��ƽ��ϴ�!! ������ �̸� : {}, ���� : {}", itemName, inventory[itemName].Count) << endl;
	}
}

//void Character::TakeItem(const int& equipmentKey)
//{
//	// TO DO : Parameter Replace : (class)EquipableItem
//
//}

void Character::TakeDamage(const int& damage)
{
	// TODO : ���¿� ���� ������ ���� ����
	currentHP -= damage;
}


void Character::LevelUp()
{
	//TO DO : Level Up
	if (level < maxLevel)
	{
		currentExp -= requiredLevelUpExp;

		IncreaseMaxHP(level);
		IncreaseAttackPower(level);
		IncreaseRequireLevelUpExp(level);

		level++;
		if (level == maxLevel)
		{
			currentExp = requiredLevelUpExp;
			cout << "�ִ� ������ �����߽��ϴ�." << endl;
		}
	}
	else
	{
		//cout << "�ִ� ������ �����߽��ϴ�." << endl;

		//currentExp = requiredLevelUpExp;
		//level = maxLevel;
	}
}

void Character::IncreaseMaxHP(const int& level)
{
	maxHP += level * 20;
}

void Character::IncreaseAttackPower(const int& level)
{
	attackPower += level * 5;
}

void Character::IncreaseRequireLevelUpExp(const int& level)
{
	requiredLevelUpExp += level * 10;
}


