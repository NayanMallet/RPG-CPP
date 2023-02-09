#ifndef POO_RPG_EVAL_SELLER_H
#define POO_RPG_EVAL_SELLER_H
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"


using namespace std;

class Seller {
    string m_NAME;
public:
    Seller(string NAME);

    vector<Item*> m_ITEMS;

    void show();

    void addITEM(Item* ITEM);

    void removeITEM(Item* ITEM);

    void updateITEMS();

    ~Seller();

};


#endif //POO_RPG_EVAL_SELLER_H

//class Seller {
//public:
//    // constructor for a seller ✅
//    Seller(string NAME): m_NAME(NAME){};
//
//    vector<Item*> m_ITEMS;
//
//// show the seller's inventory ✅
//    void show() {
//        cout << "----- " << m_NAME << " SHOP -----" << endl;
//
//        if (!m_ITEMS.empty()) {
//            for (int i=0; i < m_ITEMS.size(); i++) {
//                m_ITEMS[i]->show();
//                cout << endl;
//            };
//            cout << "-----------------" << endl;
//            return;
//        }
//        cout << "Nothing to sell !" << endl;
//
//        cout << "-----------------" << endl;
//    };
//
//// add an item to the seller's inventory ✅
//    void addITEM(Item* ITEM) {
//        m_ITEMS.push_back(ITEM);
//    };
//
//// remove an item from the seller's inventory ✅
//    void removeITEM(Item* ITEM) {
//        if (!m_ITEMS.empty()) {
//            for (int i=0; i < m_ITEMS.size(); i++) {
//                if (m_ITEMS[i]->getNAME() == ITEM->getNAME()) {
//                    m_ITEMS.erase(m_ITEMS.begin() + i);
//                };
//            };
//            return;
//        }
//        cout << "Nothing to withdraw !" << endl;
//    };
//
////// update the seller's inventory ✅
////    void updateITEMS() {
////        if (!m_ITEMS.empty()) {
////            for (int i=0; i < m_ITEMS.size(); i++) {
////                m_ITEMS[i]->levelUp();
////            }
////            return;
////        }
////        cout << "Nothing to update !" << endl;
////    };
//
//// destructor for a seller 🔴
//    ~Seller() {
//        m_ITEMS.clear();
//    };
//
//private:
//    string m_NAME{ "Seller" };
//};