#include <iostream>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <ctime>
using namespace std;
/*
* ����:
   +����� ������������ � ����� �������� ��������� ��������.
   � ������ �������� ����� ����� ���� (R)un, ���� (F)ight.
   ���� ����� ������ Run, �� ����� �� ������� ����� ���������� 50%.
   ���� ������ ������� �������, �� ??�� ������������ ��������� � ���������� ������� (��� ��������/����/������ ��� ���� �� �����������).
   ���� ������ �� ������� �������, �� ������ ��� �������. �������� ������ ����������� �� ����� �������. ����� ����� �������� ���� ��������� ��������.
   ���� ����� �������� Fight, �� �� ������� �������. �������� ������� ����������� �� ����� ������.
   ���� ������ �������, �� ����� �������� �� ������ ������� + ����������� ���� level � ���� �� 1.
   ���� ������ �� �������, �� �� ������� ������. �������� ������ ����������� �� ����� �������.
   ���� �������������, ���� ����� ���� (��������) ��� ������ 20 ������ (�������).
   ���� ����� �������, �� ��������� ������ �������� ������, ����� ������� � ���� ��� � ������� ������ �� ����.
   ���� ����� ���������, �� ���� ������ �������� ������, ��� �� ������� � ������� � ���� ���� ������.
*/
void attackMonster(Player& p, Monster& m);
void attackPlayer(Player& p, Monster& m);
int main() {
	//����������� ��������� ��������� �����
	srand(time(0));
	rand();
	//������� ������, �������� ������ ���, � ��������� ���� ��������������� ��������
	//�� ��������� �� ������������
	Player p("Vova");
	//�������� ������� ����
	//���� ����� �� ���� � �� �������
	while (!p.isDead() && !p.hasWon()) {
		//��������� ������
		Monster m = Monster::getRandomMonster();
		//������� "�� ���������" � ��� (��������) �������
		cout << "You have encountered a " << m.getName() << endl;
		char input;
		// ���������� ������� ����� ��� ���
		cout << "(R)un or (F)ight: ";
		cin >> input;
		//����� ������ �����
		if (input == 'R' || input == 'r') {
			// ������ ����������� 50% ��� ������� �������
			if (rand() % 100 < 50) {
				cout << "You successfully fled\n";
				//���������� ��������� �������� � ������������ � ������ �����
				continue;
			}
			//������� �� �������
			else {
				//������ ���� ������
				attackPlayer(p, m);
			}
		}
		//����� ������ ��������
		if (input == 'F' || input == 'f') {
			//����� ���� �������
			attackMonster(p, m);
			//������ ���� ������
			attackPlayer(p, m);
		}
	}
	//�������� �� ������ � �������
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