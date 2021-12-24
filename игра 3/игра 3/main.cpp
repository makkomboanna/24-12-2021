#include <iostream>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <ctime>
using namespace std;
/*
* Суть:
   +Игрок сталкивается с одним случайно выбранным монстром.
   С каждым монстром игрок может либо (R)un, либо (F)ight.
   Если игрок решает Run, то шансы на удачный побег составляют 50%.
   Если игроку удается сбежать, то ??он благополучно переходит к следующему монстру (его здоровье/урон/золото при этом не уменьшается).
   Если игроку не удается сбежать, то монстр его атакует. Здоровье игрока уменьшается от урона монстра. Затем игрок выбирает свое следующее действие.
   Если игрок выбирает Fight, то он атакует монстра. Здоровье монстра уменьшается от урона игрока.
   Если монстр умирает, то игрок забирает всё золото монстра + увеличивает свой level и урон на 1.
   Если монстр не умирает, то он атакует игрока. Здоровье игрока уменьшается от урона монстра.
   Игра заканчивается, если игрок умер (проигрыш) или достиг 20 уровня (выигрыш).
   Если игрок умирает, то программа должна сообщить игроку, какой уровень у него был и сколько золота он имел.
   Если игрок побеждает, то игра должна сообщить игроку, что он выиграл и сколько у него есть золота.
*/
void attackMonster(Player& p, Monster& m);
void attackPlayer(Player& p, Monster& m);
int main() {
	//настраиваем генератор случайных чисел
	srand(time(0));
	rand();
	//создаем игрока, передаем только имя, в остальные поля устанавливаются значения
	//по умолчанию из конструктора
	Player p("Vova");
	//основной игровой цикл
	//пока игрок не умер и не выиграл
	while (!p.isDead() && !p.hasWon()) {
		//создается монстр
		Monster m = Monster::getRandomMonster();
		//выводим "Вы встретили" и имя (название) монстра
		cout << "You have encountered a " << m.getName() << endl;
		char input;
		// предлагаем выбрать Побег или Бой
		cout << "(R)un or (F)ight: ";
		cin >> input;
		//игрок выбрал Побег
		if (input == 'R' || input == 'r') {
			// задаем вероятность 50% что сбежать удалось
			if (rand() % 100 < 50) {
				cout << "You successfully fled\n";
				//пропускаем дальнешие действия и возвращаемся в начало цикла
				continue;
			}
			//сбежать не удалось
			else {
				//монстр бьет игрока
				attackPlayer(p, m);
			}
		}
		//игрок выбрал сражение
		if (input == 'F' || input == 'f') {
			//игрок бьет монстра
			attackMonster(p, m);
			//монстр бьет игрока
			attackPlayer(p, m);
		}
	}
	//проверка на смерть и выигрыш
	if (p.isDead()) {
		cout << "You died!\n";
	}
	else if (p.hasWon()) {
		cout << "You win!\n";
	}
	return 0;
}
void attackMonster(Player& p, Monster& m) {
	cout << "You hit " << m.getName() << " for " << p.getDamage() << " damage\n";
	m.reduceHealth(p.getDamage());
	if (m.isDead()) {
		cout << "You kill " << m.getName() << endl;
		p.levelUp();
		cout << "Your level is " << p.getLevel() << endl;
		p.addGold(m.getGold());
		cout << "You found " << m.getGold() << " gold\n";
	}
}
void attackPlayer(Player& p, Monster& m) {
	if (m.isDead()) return;
	cout << m.getName() << " hit you for " << m.getDamage() << " damage\n";
	p.reduceHealth(m.getDamage());
}