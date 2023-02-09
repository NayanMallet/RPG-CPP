//
// Created by Nayan Mallet on 07/02/2023.
//
#include "Weapon.h"
using namespace std;

// constructor for a weapon ✅
Weapon::Weapon(string NAME, int NIV, int MONEY, int ATT): Item(NAME, NIV, MONEY), m_ATT(ATT) {};

// equip the weapon ✅
void Weapon::equip(Player &PLAYER) {
    PLAYER.setWEAPON(this);
}

// unequip the weapon ✅
void Weapon::unequip(Player &PLAYER) {
    PLAYER.unsetWEAPON(this);
}

// show the talisman ✅
void Weapon::show() {
    cout << "!! " << getNAME() << " !! * LVL" << getNIV() << " *" << endl;
    cout << "Money: " << getMONEY() << " $" << endl;
    cout << "+ " << m_ATT << " ATT" << endl;
};

// get DEF value of the armor ✅
int Weapon::getATT() {
    return m_ATT;
};

// level up the weapon ✅
void Weapon::levelUp() {
    setNivUp();
    m_ATT += 1;
};
