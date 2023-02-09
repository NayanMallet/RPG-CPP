#include <iostream>
#include <string>
#include "Seller.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Talisman.h"


using namespace std;

int GAME() {
    cout << "------ POO-RPG ------" << endl;
    cout << "Quel est votre nom: " << endl;
    string NAME;
    getline(cin, NAME);

    // set up initial values {
    Player player(NAME, 5, 2500, 10, 10, 10);

    Weapon *arme1 = new Weapon("Epee de la mort", 10, 1000, 10);
    Weapon *arme2 = new Weapon("Epee de base", 2, 200, 2);
    Armor *armure1 = new Armor("Armure de la mort", 4, 1000, 10);
    Armor *armure2 = new Armor("Armure de peon", 1, 100, 1);
    Talisman *talisman1 = new Talisman("Talisman de la mort", 3, 1000, 10);
    Talisman *talisman2 = new Talisman("Talisman de la regeneration totale", 5, 2000, 50);

    Seller seller("Vendeur");
    seller.addITEM(arme1);
    seller.addITEM(arme2);
    seller.addITEM(armure1);
    seller.addITEM(armure2);
    seller.addITEM(talisman1);
    seller.addITEM(talisman2);
    // }

    cout << "Bienvenue " << NAME << " !" << endl;

    cout << "Tu commence avec 2500$ amuse toi !" << endl;
    cout << "Voici vos STATS: " << endl;
    player.show();
    cout << endl;

    string ACTION, WEAPON;
    while (ACTION != "exit") {
        cout << "Que veux-tu faire ?" << endl << "Acheter(A) - Vendre(V) - Inventaire(I) - Player(P) - Stop(exit)" << endl << endl;
        getline(cin, ACTION);

        if (ACTION == "A" || ACTION == "a") {
            cout << "Bonjour " << NAME << " !" << endl << "Voici ce que je peux te proposer: " << endl;
            seller.show();
            cout << "Quelle arme veux-tu acheter ?" << endl;
            getline(cin, WEAPON);
            for (int i = 0; i < seller.m_ITEMS.size(); i++) {
                if (WEAPON == seller.m_ITEMS[i]->getNAME()) {
                    player.buyITEM(seller.m_ITEMS[i], seller);
                }
            }
            player.showBag();
            cout << "Merci de votre achat !" << endl;

        } else if (ACTION == "V" || ACTION == "v") {
            if (player.INVENTORY.empty()) {
                cout << "Tu n'as rien a vendre !" << endl << endl;
                continue;
            }
            cout << "Bonjour " << NAME << " !" << endl << "Voici ce que tu peux vendre: " << endl;
            player.showBag();
            cout << "Quelle arme veux-tu vendre ?" << endl;
            getline(cin, WEAPON);
            for (int i = 0; i < player.INVENTORY.size(); i++) {
                if (WEAPON == player.INVENTORY[i]->getNAME()) {
                    player.sellITEM(player.INVENTORY[i], seller);
                }
            }
            player.showBag();
            cout << "Merci pour cette affaire !" << endl << endl;

        } else if (ACTION == "I" || ACTION == "i") {
            player.showBag();
            cout << "Que veux tu faire ?" << endl << "Equiper(E) ou Desequiper(D)?" << endl;
            getline(cin, ACTION);
            if (ACTION == "E") {
                if (player.INVENTORY.empty()) {
                    cout << "Tu n'as rien dans l'inventaire !" << endl << endl;
                    continue;
                }
                player.showBag();
                cout << "Quelle arme veux-tu utiliser ?" << endl;
                getline(cin, WEAPON);
                for (int i = 0; i < player.INVENTORY.size(); i++) {
                    if (WEAPON == player.INVENTORY[i]->getNAME()) {
                        player.INVENTORY[i]->equip(player);
                    }
                }
                player.showEquipement();
                player.show();
            } else if (ACTION == "D" || ACTION == "d") {
                if (player.getLEFTHAND() == NULL && player.getRIGHTHAND() == NULL && player.getARMOR() == NULL && player.getTALISMAN() == NULL) {
                    cout << "Tu n'as rien d'equiper !" << endl << endl;
                    continue;
                }
                player.showEquipement();
                cout << "Quelle arme veux-tu desequiper ?" << endl;
                getline(cin, WEAPON);
                if (WEAPON == player.getLEFTHAND()->getNAME()) {
                    player.getLEFTHAND()->unequip(player);
                } else if (WEAPON == player.getRIGHTHAND()->getNAME()) {
                    player.getRIGHTHAND()->unequip(player);
                } else if (WEAPON == player.getARMOR()->getNAME()) {
                    player.getARMOR()->unequip(player);
                } else if (WEAPON == player.getTALISMAN()->getNAME()) {
                    player.getTALISMAN()->unequip(player);
                }
                player.showBag();
            };
        } else if (ACTION == "P" || ACTION == "p") {
            cout << "Voici vos Stats: " << endl;
            player.show();
            cout << "Votre Inventaire: " << endl;
            player.showBag();
            cout << "Votre équipement: " << endl;
            player.showEquipement();
        }
    };

    return 0;
}

void simpleTest(){
    // set up initial values {
    Player player("Nayan", 5, 2500, 10, 10, 10);

    Weapon *arme1 = new Weapon("Epee de la mort", 10, 1000, 10);
    Weapon *arme2 = new Weapon("Epee de base", 2, 200, 2);
    Armor *armure1 = new Armor("Armure de la mort", 4, 1000, 10);
    Armor *armure2 = new Armor("Armure de peon", 1, 100, 1);
    Talisman *talisman1 = new Talisman("Talisman de la mort", 3, 1000, 10);
    Talisman *talisman2 = new Talisman("Talisman de la regeneration totale", 5, 2000, 50);

    Seller seller("VENdueeuur");
    seller.addITEM(arme1);
    seller.addITEM(arme2);
    seller.addITEM(armure1);
    seller.addITEM(armure2);
    seller.addITEM(talisman1);
    seller.addITEM(talisman2);
    // }

    cout << "------ POO-RPG ------" << endl;

    cout << "Bienvenue " << player.getNAME() << " !" << endl;

    cout << "Tu commence avec 2500$ amuse toi !" << endl;
    cout << "Voici vos STATS: " << endl;
    player.show();

    cout << endl << player.getNAME() << ": Trés bien je vais acheter une arme, j'achète la plus haut niveau !!" << endl;
    player.buyITEM(seller.m_ITEMS[0], seller);
    cout << endl << player.getNAME() << ": Comment !! j'ai pas un niveau assez élevé, achetons l'autre" << endl;
    player.buyITEM(seller.m_ITEMS[1], seller);
    cout << endl << player.getNAME() << ": Je prend aussi une armure et un talisman !" << endl;
    player.buyITEM(seller.m_ITEMS[2], seller);
    player.buyITEM(seller.m_ITEMS[3], seller);
    cout << endl << player.getNAME() << ": Voici mon inventaire: " << endl;
    player.showBag();
    cout << endl << player.getNAME() << ": Je vais équiper mon arme, mon armure et mon talisman !" << endl;
    for (int i = 0; i <= player.INVENTORY.size()+1; i++) {
        player.INVENTORY[0]->equip(player);
    }
    cout << endl << player.getNAME() << ": Woawww mes stats ont augmentées !! Regarde :" << endl;
    player.show();
    cout << endl << player.getNAME() << ": JE SAIS COMMENT AVOIR DES STATS À L'INFINI !" << endl << "et..." << endl << "ÊTRE LE MEILLEUR AHAHA !!!" << endl;
    player.getLEFTHAND()->unequip(player);
    player.getARMOR()->unequip(player);
    player.getTALISMAN()->unequip(player);
    cout << endl << player.getNAME() << ": Mes stats ne devraient pas avoir bougées AHAH !" << endl;
    player.show();
    cout << endl << player.getNAME() << ": OH.." << endl << "J'ai tout perdu :( allons vendre tout ces equipements.." << endl;
    player.INVENTORY[0]->show();
    player.INVENTORY[1]->show();
    player.INVENTORY[2]->show();
    for (int i = 0; i <= player.INVENTORY.size() + 1; i++) {
        player.sellITEM(player.INVENTORY[0], seller);
    }
    cout << endl << player.getNAME() << ": LEVEL UPPP J'AI GAGNÉ DES STATS REGARDE :))) !" << endl;
    player.show();
    cout << endl << player.getNAME() << ": Retournons voir le vendeur, ces armes ont du évoluer !" << endl;
    seller.show();
    cout << endl << player.getNAME() << ": Tout a augmenté de niveau génial :)" << endl;
    cout << endl << player.getNAME() << ": J'ai plus rien a faire ici, A plus !" << endl;
    cout << endl << "------ FIN DU TEST ------" << endl;
}

int main()
{
//    GAME();
    simpleTest();
    return 0;
}

