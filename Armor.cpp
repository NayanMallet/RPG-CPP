//
// Created by Nayan Mallet on 07/02/2023.
//
#include "Armor.h"
using namespace std;

// constuctor for an armor ✅
Armor::Armor(string NAME, int NIV, int MONEY, int DEF): Item(NAME, NIV, MONEY), m_DEF(DEF) {};

// equip the armor ✅
void Armor::equip(Player &PLAYER) {
    PLAYER.setARMOR(this);
}

// unequip the armor ✅
void Armor::unequip(Player &PLAYER) {
    PLAYER.unsetARMOR(this);
}

// show the armor ✅
void Armor::show() {
    cout << "!! " << getNAME() << " !! * LVL" << getNIV() << " *" << endl;
    cout << "Money: " << getMONEY() << " $" << endl;
    cout << "+ " << m_DEF  << " DEF" << endl;
};

// get DEF value of the armor ✅
int Armor::getDEF() {
    return m_DEF;
};

// level up the armor ✅
void Armor::levelUp() {
    setNivUp();
    m_DEF += 1;
};