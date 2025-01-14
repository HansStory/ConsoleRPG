#include "Character.h"

#include <format>
#include <iostream>
#include "ExceptionHandler.h"

using namespace std;


Character::Character(const string& name)
{
	this->name = name;	

	cout << "캐릭터 " << name << " 생성 완료!";
	cout << " 레벨 : " << level << ", 체력 : " << currentHP << " / " << maxHP << ", 공격력 : " << attackPower << endl;
}

Character::~Character()
{
}


const int& Character::GetAcctackPower()
{
	return this->attackPower; // + 아이템 + 버프
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
	returnValue += format("이름 : {}\n", name);
	returnValue += format("레벨 : {}\n", level);
	returnValue += format("HP : {}/{}\n", currentHP, maxHP);
	returnValue += format("공격력 : {}\n", attackPower);
	returnValue += format("Gold : {}\n", gold);
	returnValue += format("경험치 : {}/{}\n", currentExp, requiredLevelUpExp);

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
		throw ExceptionHandler(Unknown, "아이템이 없습니다.");
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
		cout << format("경험치를 획득했습니다! 경험치 : {}", exp) << endl;

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
		cout << format("신규 아이템이 추가됐습니다!! 아이템 이름 : {}, 개수 : {}", itemName, inventory[itemName].Count) << endl;
	}
	else
	{
		inventory[itemName].Count++;
		cout << format("기존 아이템 개수가 추가됐습니다!! 아이템 이름 : {}, 개수 : {}", itemName, inventory[itemName].Count) << endl;
	}
}

//void Character::TakeItem(const int& equipmentKey)
//{
//	// TO DO : Parameter Replace : (class)EquipableItem
//
//}

void Character::TakeDamage(const int& damage)
{
	// TODO : 방어력에 대한 데미지 계산식 적용
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
			cout << "최대 레벨에 도달했습니다." << endl;
		}
	}
	else
	{
		//cout << "최대 레벨에 도달했습니다." << endl;

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


