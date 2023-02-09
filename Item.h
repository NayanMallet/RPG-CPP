#ifndef POO_RPG_EVAL_ITEM_H
#define POO_RPG_EVAL_ITEM_H
class Player;
#include <string>

using namespace std;

class Item {
    string m_NAME;
    int m_NIV, m_MONEY;
    public:
    Item(string NAME, int NIV, int MONEY);

    virtual void equip(Player& PLAYER) = 0;

    virtual void unequip(Player& PLAYER) = 0;

    virtual void show() = 0;

    string getNAME();

    int getMONEY();

    int getNIV();
    void setNivUp();

    virtual void levelUp() = 0;
};


//class Player;
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Item {
//public:
//// constructor for an item ✅
//    Item(string NAME, int NIV, int MONEY):
//            m_NAME(NAME),
//            m_NIV(NIV),
//            m_MONEY(MONEY){};
//
//
//
//    // get Name of the item ✅
//    string getNAME() {
//        return m_NAME;
//    };
//
//    // get Price of the item ✅
//    int getMONEY() {
//        return m_MONEY;
//    };
//
//    // get NIV of the item ✅
//    int getNIV() {
//        return m_NIV;
//    };
//
//
//private:
//    string m_NAME{ "nothing" };
//    int m_NIV{ 0 };
//    int m_MONEY{ 0 };
//};

#endif //POO_RPG_EVAL_ITEM_H
