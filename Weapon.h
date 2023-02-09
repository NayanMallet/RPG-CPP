#ifndef POO_RPG_EVAL_WEAPON_H
#define POO_RPG_EVAL_WEAPON_H

#include "Player.h"
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Weapon : public Item {
    int m_ATT;
public:
    Weapon(string NAME, int NIV, int MONEY, int PV);
    void equip(Player& PLAYER) override;
    void unequip(Player& PLAYER) override;
    void show() override;
    int getATT();
    void levelUp() override;
};

#endif //POO_RPG_EVAL_WEAPON_H

//class Weapon : public Item {
//public:
//    // constuctor for a weapo ✅
//    Weapon(string NAME, int NIV, int MONEY, int ATT): Item(NAME, NIV, MONEY), m_ATT(ATT) {};
//
//    void equip(Player& PLAYER) {
//        PLAYER.setITEM(*this);
//    }
//
//    void unequip(Player& PLAYER) {
//        PLAYER.unsetITEM(*this);
//    }
//
//    // show the weapon ✅
//    void show() {
//        cout << "- " << getNAME() << " -" << endl << "* LVL" << getNIV() << " *" << endl;
//        cout << "Money: " << getMONEY() << " $" << endl;
//        cout << "+ " << m_ATT << " ATT"  << endl;
//    };
//
//    // get the ATT of the weapon ✅
//    int getATT() {
//        return m_ATT;
//    };
//private:
//    int m_ATT;
//};
