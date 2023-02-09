//
// Created by Nayan Mallet on 07/02/2023.
//
#include "Item.h"

// constructor for an item ✅
Item::Item(string NAME, int NIV, int MONEY): m_NAME(NAME), m_NIV(NIV), m_MONEY(MONEY) {};

// getters for an item ✅
string Item::getNAME() {
    return m_NAME;
}
int Item::getMONEY() {
    return m_MONEY;
}
int Item::getNIV() {
    return m_NIV;
}

// setters for an item ✅
void Item::setNivUp() {
    m_NIV += 1;
    m_MONEY += 50;
}

