#include "Creature.h"
void Creature::reduceHealth(int health) { m_hp -= health; }
bool Creature::isDead() { return m_hp <= 0; }
void Creature::addGold(int gold) { m_gold += gold; }