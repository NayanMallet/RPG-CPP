#ifndef POO_RPG_EVAL_PLAYER_H
#define POO_RPG_EVAL_PLAYER_H
class Armor;
class Weapon;
class Talisman;
#include "Weapon.h"
#include "Armor.h"
#include "Talisman.h"
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Seller.h"

using namespace std;

class Player {
    string m_NAME;
    int m_NIV, m_XP, m_MONEY;
    // Stats m_STATS;
    int m_PV, m_DEF, m_ATT;
    //
    Weapon* m_LEFTHAND = nullptr;
    Weapon* m_RIGHTHAND = nullptr;
    Armor* m_ARMOR = nullptr;
    Talisman* m_TALISMAN = nullptr;
    int XP_NEEDED_PER_LEVEL;
public:
    Player(string NAME, int NIV, int MONEY, int ATT, int DEF, int PV);

    vector<Item*> INVENTORY;

    void show();
    ~Player();

    // getters of the player ✅{
    string getNAME();
    int getNIV();
    int getXP();
    int getMONEY();
    // Stats getSTATS();
    int getPV();
    int getDEF();
    int getATT();
    //
    Weapon* getLEFTHAND();
    Weapon* getRIGHTHAND();
    Armor* getARMOR();
    Talisman* getTALISMAN();
    int getXP_NEEDED_PER_LEVEL();
// }

    void showBag();

    void showEquipement();

    void setWEAPON(Weapon* WEAPON);

    void setARMOR(Armor* ARMOR);

    void setTALISMAN(Talisman* TALISMAN);

    void unsetWEAPON(Weapon* WEAPON);

    void unsetARMOR(Armor* ARMOR);

    void unsetTALISMAN(Talisman* TALISMAN);

    void buyITEM(Item* ITEM, Seller& SELLER);

    void sellITEM(Item* ITEM, Seller& SELLER);

    void levelUp(Seller &seller);

};

#endif //POO_RPG_EVAL_PLAYER_H