//
// Created by Nayan Mallet on 07/02/2023.
//
#include "Seller.h"
#include <string>
#include <iostream>
using namespace std;

// constructor for a seller ✅
Seller::Seller(string NAME): m_NAME(NAME){};

// show the seller's inventory ✅
void Seller::show() {
    cout << "----- " << m_NAME << " SHOP -----" << endl;

    if (!m_ITEMS.empty()) {
        for (int i=0; i < m_ITEMS.size(); i++) {
            m_ITEMS[i]->show();
            cout << endl;
        };
        cout << "-----------------" << endl;
        return;
    }
    cout << "Nothing to sell !" << endl;

    cout << "-----------------" << endl;
};

// destructor for a seller ✅
Seller::~Seller() {
    m_ITEMS.clear();
};

// add an item to the seller's inventory ✅
void Seller::addITEM(Item* ITEM) {
    m_ITEMS.push_back(ITEM);
};

// remove an item from the seller's inventory ✅
void Seller::removeITEM(Item* ITEM) {
    if (!m_ITEMS.empty()) {
        for (int i=0; i < m_ITEMS.size(); i++) {
            if (m_ITEMS[i]->getNAME() == ITEM->getNAME()) {
                m_ITEMS.erase(m_ITEMS.begin() + i);
            };
        };
        return;
    }
    cout << "Nothing to withdraw !" << endl;
};

// update the seller's inventory ✅
    void Seller::updateITEMS() {
        if (!m_ITEMS.empty()) {
            for (int i=0; i < m_ITEMS.size(); i++) {
                m_ITEMS[i]->levelUp();
            }
            return;
        }
        cout << "Nothing to update !" << endl;
    };
