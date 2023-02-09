#ifndef POO_RPG_EVAL_TALISMAN_H
#define POO_RPG_EVAL_TALISMAN_H

#include "Player.h"
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Talisman : public Item {
    int m_PV;
public:
    Talisman(string NAME, int NIV, int MONEY, int PV);
    void equip(Player& PLAYER) override;
    void unequip(Player& PLAYER) override;
    void show() override;
    int getPV();
    void levelUp() override;
};

#endif //POO_RPG_EVAL_TALISMAN_H

//class Talisman : public Item {
//public:
//    // constuctor for a talisman ✅
//    Talisman(string NAME, int NIV, int MONEY, int PV): Item(NAME, NIV, MONEY), m_PV(PV) {};
//
//    void equip(Player& PLAYER) {
//        PLAYER.setITEM(*this);
//    }
//
//    void unequip(Player& PLAYER) {
//        PLAYER.unsetITEM(*this);
//    }
//
//    // show the talisman ✅
//    void show() {
//        cout << "- " << getNAME() << " -" << endl << "* LVL" << getNIV() << " *" << endl;
//        cout << "Money: " << getMONEY() << " $" << endl;
//        cout << "+ " << m_PV << " PV" << endl;
//    };
//
//    // get the PV of the talisman ✅
//    int getPV() {
//        return m_PV;
//    };
//private:
//    int m_PV;
//};