#pragma once
#include "Creature.h"

class Monster : public Creature {

public:
	enum MonsterType { DRAGON, ORC, SLIME, MAX_TYPE };
	struct MonsterData {
		std::string name;
		char symbol;
		int hp;
		int damage;
		int gold;
	};
	static MonsterData monster_array[MAX_TYPE];
	Monster(MonsterType type) :
		Creature(
			monster_array[type].name,
			monster_array[type].symbol,
			monster_array[type].hp,
			monster_array[type].damage,
			monster_array[type].gold
		)
	{}
	static Monster getRandomMonster() {
		return Monster(MonsterType(rand() % MAX_TYPE));
	}
};
Monster::MonsterData Monster::monster_array[Monster::MAX_TYPE]{
	{"dragon",'d',20,4,100},
	{"orc",'o',4,2,25},
	{"slime",'s',1,1,10}
};
