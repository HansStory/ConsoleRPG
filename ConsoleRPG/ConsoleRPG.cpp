#include <iostream>
#include "GameManager.h"
#include "Character.h"

int main()
{
    Character* character = new Character("������");

    character->DisplayStatus();

    return 0;
}

