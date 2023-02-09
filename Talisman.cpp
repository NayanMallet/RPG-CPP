//
// Created by Nayan Mallet on 07/02/2023.
//
#include "Talisman.h"
using namespace std;

// constructor for a talisman ✅
Talisman::Talisman(string NAME, int NIV, int MONEY, int PV): Item(NAME, NIV, MONEY), m_PV(PV) {};

// equip the talisman ✅
void Talisman::equip(Player &PLAYER) {
    PLAYER.setTALISMAN(this);
}

// unequip the talisman ✅
void Talisman::unequip(Player &PLAYER) {
    PLAYER.unsetTALISMAN(this);
}

// show the talisman ✅
void Talisman::show() {
    cout << "!! " << getNAME() << " !! * LVL" << getNIV() << " *" << endl;
    cout << "Money: " << getMONEY() << " $" << endl;
    cout << "+ " << m_PV << " PV" << endl;
};

// get DEF value of the armor ✅
int Talisman::getPV() {
    return m_PV;
};

// level up the talisman ✅
void Talisman::levelUp() {
    setNivUp();
    m_PV += 1;
};