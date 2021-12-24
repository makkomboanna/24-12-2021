#pragma once
#include "Creature.h"
/*
“еперь нам нужно создать класс Player, который наследует Creature. Player имеет:
   переменную-член level, котора€ начинаетс€ с 1;
   им€ (пользователь вводит с клавиатуры);
   символ @;
   10 очков здоровь€;
   1 очко урона (дл€ начала);
   0 золота.
*/
//Ќапишите метод levelUp(), который увеличивает уровень Player - а и его урон на 1. 
//“акже напишите геттер дл€ члена level и метод hasWon(), который возвращает true, 
//если Player достиг 20 уровн€.
class Player : public Creature {
private:
	int m_level;
public:
	Player(std::string name,
		char symbol = '@',
		int hp = 10,
		int damage = 1,
		int gold = 0,
		int level = 1) :
		Creature(name, symbol, hp, damage, gold), m_level{ level }
	{}
	int getLevel() { return m_level; }
	void levelUp();
	bool hasWon();
};

