#include "Player.h"
void Player::levelUp() {
	m_level++;
	m_damage++;
	m_hp += 2;
}
bool Player::hasWon() { return m_level == 20; }