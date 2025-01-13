#include <iostream>
#include "GameManager.h"
#include "Character.h"

int main()
{
    Character* character = new Character("ÇÑÁ¤Çõ");

    character->DisplayStatus();

    return 0;
}

