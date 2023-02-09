#ifndef POO_RPG_EVAL_ARMOR_H
#define POO_RPG_EVAL_ARMOR_H

#include "Player.h"
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Armor : public Item {
    int m_DEF;
public:
    Armor(string NAME, int NIV, int MONEY, int DEF);
    void equip(Player& PLAYER) override;
    void unequip(Player& PLAYER) override;
    void show() override;
    int getDEF();
    void levelUp() override;
};

#endif //POO_RPG_EVAL_ARMOR_H

//class Armor : public Item {
//public:
//    // constuctor for an armor ✅
//    Armor(string NAME, int NIV, int MONEY, int DEF): Item(NAME, NIV, MONEY), m_DEF(DEF) {};
//
//
//    void equip(Player& PLAYER) {
//        PLAYER.setITEM(*this);
//    }
//
//    void unequip(Player& PLAYER) {
//        PLAYER.unsetITEM(*this);
//    }
//
//    // show the armor ✅
//    void show() {
//        cout << "- " << getNAME() << " -" << endl << "* LVL" << getNIV() << " *" << endl;
//        cout << "Money: " << getMONEY() << " $" << endl;
//        cout << "+ " << m_DEF  << " DEF" << endl;
//    };
//
//    // get DEF value of the armor ✅
//    int getDEF() {
//        return m_DEF;
//    };
//private:
//    int m_DEF;
//};


