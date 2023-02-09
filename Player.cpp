//
// Created by Nayan Mallet on 07/02/2023.
//
#include "Player.h"
using namespace std;

// constructor for a player ✅
Player::Player(string NAME, int NIV, int MONEY, int ATT, int DEF, int PV):
        m_NAME(NAME),
        m_NIV(NIV), m_XP(0), m_MONEY(MONEY),
        // m_STATS(STATS),
        m_ATT(ATT), m_DEF(DEF), m_PV(PV),
        //
        XP_NEEDED_PER_LEVEL(30*NIV){}

// show infos of the player ✅
void Player::show() {
    cout << "----- " << m_NAME << " -----" << endl << endl;
    cout << "* LVL" << m_NIV << " * (" << m_XP << "/" << XP_NEEDED_PER_LEVEL << ")" << endl;
    cout << "Money: " << m_MONEY << " $" << endl;
    cout << "ATT: " << m_ATT << " DEF: " << m_DEF << " PV: " << m_PV << endl;
    cout << endl << "-----------------" << endl;
};

// destructor for a player ✅
Player::~Player() {
    INVENTORY.clear();
};

// getters of the player ✅{
    string Player::getNAME() { return m_NAME; };

    int Player::getNIV() { return m_NIV; };

    int Player::getXP() { return m_XP; };

    int Player::getMONEY() { return m_MONEY; };

    // Stats getSTATS() { return m_STATS; };
    int Player::getPV() { return m_PV; };

    int Player::getDEF() { return m_DEF; };

    int Player::getATT() { return m_ATT; };
    //

    Weapon* Player::getLEFTHAND() { return m_LEFTHAND; };

    Weapon* Player::getRIGHTHAND() { return m_RIGHTHAND; };

    Armor* Player::getARMOR() { return m_ARMOR; };

    Talisman* Player::getTALISMAN() { return m_TALISMAN; };

    int Player::getXP_NEEDED_PER_LEVEL() { return XP_NEEDED_PER_LEVEL; };
// }

// show inventory of the player ✅
void Player::showBag() {
    cout << "----- INVENTORY -----" << endl << endl;
    if (!INVENTORY.empty()) {
        for (int i=0; i < INVENTORY.size(); i++) {
            INVENTORY[i]->show();
            cout << endl;
        };
        cout << endl << "-----------------" << endl;
        return;
    }
    cout << "Nothing in the bag !" << endl;
    cout << endl << "-----------------" << endl;
};

// show equiped items of the player ✅
void Player::showEquipement() {
    cout << "----- EQUIPEMENT -----" << endl;
    if (m_LEFTHAND != nullptr || m_RIGHTHAND != nullptr || m_ARMOR != nullptr || m_TALISMAN != nullptr) {
        if (m_LEFTHAND != nullptr || m_RIGHTHAND != nullptr) {
            cout << endl << "--- WEAPONS ---" << endl << endl;
            if (m_LEFTHAND != nullptr) {
                cout << "- Left hand - " << endl;
                m_LEFTHAND->show();
            }
            if (m_RIGHTHAND != nullptr) {
                cout << endl << "- Right hand - " << endl;
                m_RIGHTHAND->show();
            }
        }
        if (m_ARMOR != nullptr) {
            cout << endl << "--- ARMOR ---" << endl << endl;
            m_ARMOR->show();
        }
        if (m_TALISMAN != nullptr) {
            cout << endl << "--- TALISMAN ---" << endl << endl;
            m_TALISMAN->show();
        }
        cout << endl << "-----------------" << endl;
        return;
    }
    cout << endl << "Nothing equiped !" << endl;
    cout << endl << "-----------------" << endl;
};

void Player::setWEAPON(Weapon *WEAPON) {
    if (m_LEFTHAND == nullptr || m_RIGHTHAND == nullptr) {
        if (WEAPON->getNIV() <= m_NIV) {
            if (m_LEFTHAND == nullptr) {
                // no weapon in left hand
                for (int i = 0; i < INVENTORY.size(); i++) {
                    if (INVENTORY[i] == WEAPON) {
                        m_LEFTHAND = WEAPON;
                        m_ATT += WEAPON->getATT();
                        cout << WEAPON->getNAME() << " equipped !" << endl;
                        cout << "+" << WEAPON->getATT() << " ATT" << endl;
                        INVENTORY.erase(INVENTORY.begin() + i);
                    }
                }
                return;
            }
            // no weapon in right hand
            for (int i = 0; i < INVENTORY.size(); i++) {
                if (INVENTORY[i] == WEAPON) {
                    m_RIGHTHAND = WEAPON;
                    m_ATT += WEAPON->getATT();
                    cout << WEAPON->getNAME() << " equipped !" << endl;
                    cout << "+" << WEAPON->getATT() << " ATT" << endl;
                    INVENTORY.erase(INVENTORY.begin() + i);
                }
            }
            return;
        }
        cout << "Weapon is too high level !" << endl;
        return;
    }
    cout << m_LEFTHAND->getNAME() << " and " << m_RIGHTHAND->getNAME() << " already equipped !" << endl;
}

void Player::setARMOR(Armor *ARMOR) {
    if (m_ARMOR == nullptr) {
        if (ARMOR->getNIV() <= m_NIV) {
            // no armor
            for (int i = 0; i < INVENTORY.size(); i++) {
                if (INVENTORY[i] == ARMOR) {
                    m_ARMOR = ARMOR;
                    m_DEF += ARMOR->getDEF();
                    cout << ARMOR->getNAME() << " equipped !" << endl;
                    cout << "+" << ARMOR->getDEF() << " DEF" << endl;
                    INVENTORY.erase(INVENTORY.begin() + i);
                }
            }
            return;
        }
        cout << "Armor is too high level !" << endl;
        return;
    }
    cout << m_ARMOR->getNAME() << " already equipped !" << endl;
}

void Player::setTALISMAN(Talisman *TALISMAN) {
    if (m_TALISMAN == nullptr) {
        if (TALISMAN->getNIV() <= m_NIV) {
            for (int i = 0; i < INVENTORY.size(); i++) {
                if (INVENTORY[i] == TALISMAN) {
                    m_TALISMAN = TALISMAN;
                    m_PV += TALISMAN->getPV();
                    cout << TALISMAN->getNAME() << " equipped !" << endl;
                    cout << "+" << TALISMAN->getPV() << " HP" << endl;
                    INVENTORY.erase(INVENTORY.begin() + i);
                }
            }
            return;
        }
        cout << "Armor is too high level !" << endl;
        return;
    }
    cout << m_TALISMAN->getNAME() << " already equipped !" << endl;
};

void Player::unsetWEAPON(Weapon* WEAPON){
    if (m_LEFTHAND == WEAPON) {
        m_ATT -= WEAPON->getATT();
        INVENTORY.push_back(WEAPON);
        m_LEFTHAND = nullptr;
        cout << WEAPON->getNAME() << " unequipped !" << endl;
        cout << "-" << WEAPON->getATT() << " ATT" << endl;
        return;
    } else if (m_RIGHTHAND == WEAPON) {
        m_ATT -= WEAPON->getATT();
        INVENTORY.push_back(WEAPON);
        m_RIGHTHAND = nullptr;
        cout << WEAPON->getNAME() << " unequipped !" << endl;
        cout << "-" << WEAPON->getATT() << " ATT" << endl;
        return;
    }
    cout << "Nothing equipped !" << endl;
}

void Player::unsetARMOR(Armor* ARMOR) {
    if (m_ARMOR == ARMOR) {
        m_DEF -= ARMOR->getDEF();
        INVENTORY.push_back(ARMOR);
        m_ARMOR = nullptr;
        cout << ARMOR->getNAME() << " unequipped !" << endl;
        cout << "-" << ARMOR->getDEF() << " DEF" << endl;
        return;
    }
    cout << "Nothing equipped !" << endl;
}

void Player::unsetTALISMAN(Talisman* TALISMAN) {
    if (m_TALISMAN == TALISMAN) {
        m_PV -= TALISMAN->getPV();
        INVENTORY.push_back(TALISMAN);
        m_TALISMAN = nullptr;
        cout << TALISMAN->getNAME() << " unequipped !" << endl;
        cout << "-" << TALISMAN->getPV() << " PV" << endl;
        return;
    }
    cout << "Nothing equipped !" << endl;
};


// player buy an item ✅
void Player::buyITEM(Item* ITEM, Seller& SELLER) {
    if (ITEM->getNIV() <= m_NIV) {
        if (m_MONEY >= ITEM->getMONEY()) {
            m_MONEY -= ITEM->getMONEY();
            cout << "!! " << ITEM->getNAME() << " Bought !!" << endl;
            cout << "- " << ITEM->getMONEY() << " $" << endl;
            INVENTORY.push_back(ITEM);
            SELLER.removeITEM(ITEM);
            return;
        }
        cout << "Not enough money !" << endl;
        return;
    }
    cout << "You can't buy this item !" << endl;
};

// player sell an item ✅
void Player::sellITEM(Item *ITEM, Seller &SELLER) {
    if (!INVENTORY.empty()) {
        for (int i = 0; i < INVENTORY.size(); i++) {
            if (INVENTORY[i] == ITEM) {
                SELLER.addITEM(ITEM);
                m_MONEY += ITEM->getMONEY();
                m_XP += ITEM->getNIV() * 30;
                cout << "!! " << INVENTORY[i]->getNAME() << " SELL !!" << endl;
                cout << "+ " << ITEM->getMONEY() << " $" << endl;
                cout << "+ " << ITEM->getNIV() * 30 << " XP" << endl;
                INVENTORY.erase(INVENTORY.begin() + i);
            };
        };
        levelUp(SELLER);
        return;
    };
    cout << "You can't sell anything !" << endl;
};

// player level up ✅
void Player::levelUp(Seller &seller) {
        if (m_XP >= XP_NEEDED_PER_LEVEL) {
            m_XP -= XP_NEEDED_PER_LEVEL;
            cout << "!! LEVEL UP !!" << endl;
            cout << " - " << XP_NEEDED_PER_LEVEL << " XP" << endl;
            cout << " + " << ( 50 * m_NIV) << " $" << endl;
            XP_NEEDED_PER_LEVEL *= 2;
            m_NIV++;
            m_MONEY += ( 50 * m_NIV);
            cout << "What do you want to upgrade ?" << endl;
            cout << "ATT(1) - DEF(2) - PV(3)" << endl;
            int choice;
            cin >> choice;
            while (choice < 1 || choice > 3) {
                cout << "Choose a number between 1 and 3 !" << endl;
                cin >> choice;
            }
            switch (choice) {
                case 1:
                    m_ATT++;
                    cout << "+ 1 ATT" << endl;
                    break;
                case 2:
                    m_DEF++;
                    cout << "+ 1 DEF" << endl;
                    break;
                case 3:
                    m_PV++;
                    cout << "+ 1 PV" << endl;
                    break;
            }
            cout << "Your new stats are : " << endl;
            show();
            seller.updateITEMS();
        }
    };
