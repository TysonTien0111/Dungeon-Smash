#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits>
// #include <pthread.h>
// #include <thread>
// #include <chrono>
#include "Warrior.hpp"

using namespace std;

void battle(Warrior& one, Warrior& two, double w_one_dmg_reduction, double w_two_dmg_reduction) {
    cout << "Please press enter to continue..." << endl;
    
    while (cin.get() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please press enter to continue..." << endl;
    }

    system("cls");
    
    do {
        one.attack(1);

        if (one.get_guard_status() == true) {
            if (one.get_weakening_strike_status() == true) {
                cout << "Warrior Two takes " << (w_two_dmg_reduction * one.get_attack_stat()) << " slashing damage from Warrior One." << endl;
                cout << "Additionally, Warrior Two receives a second effect where their armor stat is decreased by 2." << endl;
                
                two.update_health_stat(two.get_health_stat() - (w_two_dmg_reduction * one.get_attack_stat()));
                two.update_armor_stat(two.get_armor_stat() - 2.0);
                
                cout << "Warrior Two now has " << two.get_health_stat() << " hp left." << endl << endl;
            } else {
                cout << "Warrior Two takes " << (w_two_dmg_reduction * one.get_attack_stat()) << " slashing damage from Warrior One." << endl; 
                cout << "However, Warrior Two doesn't receive the second effect of Warrior One's weakening strike." << endl;

                two.update_health_stat(two.get_health_stat() - (w_two_dmg_reduction * one.get_attack_stat()));
                
                cout << "Warrior Two now has " << two.get_health_stat() << " hp left." << endl << endl;
            }
        } else {
            cout << "Warrior Two takes " << (w_two_dmg_reduction * one.get_attack_stat()) << " slashing damage from Warrior One." << endl; 
            
            two.update_health_stat(two.get_health_stat() - (w_two_dmg_reduction * one.get_attack_stat()));  
            
            cout << "Warrior Two now has " << two.get_health_stat() << " hp left." << endl << endl;
        } 

        if (two.get_health_stat() <= 0) {
            break;
        }

        cout << "Please press enter to continue the battle..." << endl;
        while (cin.get() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please press enter to continue the fucking battle you moron..." << endl;
        }

        system("cls");

        two.attack(2);

        if (two.get_guard_status() == true) {
            if (two.get_weakening_strike_status() == true) {
                cout << "Warrior one takes " << (w_one_dmg_reduction * two.get_attack_stat()) << " slashing damage from Warrior Two." << endl;
                cout << "Additionally, Warrior One recieves a second effect where their armor stat is decreased by 2." << endl;

                one.update_health_stat(one.get_health_stat() - (w_one_dmg_reduction * two.get_attack_stat()));
                one.update_armor_stat(one.get_armor_stat() - 2.0);

                cout << "Warrior One now has " << one.get_health_stat() << " hp left." << endl << endl;
            } else {
                cout << "Warrior One takes " << (w_one_dmg_reduction * two.get_attack_stat()) << " slashing damage from Warrior Two." << endl;
                cout << "However, Warrior One doesn't receive the second effect of Warrior Two's weakening strike." << endl;

                one.update_health_stat(one.get_health_stat() - (w_one_dmg_reduction * two.get_attack_stat()));

                cout << "Warrior One now has " << one.get_health_stat() << " hp left." << endl << endl;
            }
        } else {
            cout << "Warrior One takes " << (w_one_dmg_reduction * two.get_attack_stat()) << " slashing damage from Warrior Two." << endl;

            one.update_health_stat(one.get_health_stat() - (w_one_dmg_reduction * two.get_attack_stat()));

            cout << "Warrior One now has " << one.get_health_stat() << " hp left." << endl << endl;
        }

        if (one.get_health_stat() <= 0) {
            break;
        }

        cout << "Please press enter to continue the battle..." << endl;
        while (cin.get() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please press enter to continue the fucking battle you moron..." << endl;
        }
        
        system("cls");
    } while((one.get_health_stat() > 0.0) && (two.get_health_stat() > 0.0));
}

int main() {
    string user_input;

    do {
        Warrior one;
        Warrior two;
        double w_one_dmg_reduction = fabs(1 - (one.get_armor_stat() * 0.05));
        double w_two_dmg_reduction = fabs(1 - (two.get_armor_stat() * 0.05));

        cout << "Welcome to Dungeon Smash!" << endl << endl;

        // for (int i = 0; i < 3; i++) {
        //     cout << ".";
        //     std::this_thread::sleep_for(std::chrono::seconds(1));
        // }

        one.display_current_stats(1);
        two.display_current_stats(2);

        cout << "Let the battle begin!" << endl << endl;

        battle(one, two, w_one_dmg_reduction, w_two_dmg_reduction);

        if (one.get_health_stat() <= 0) {
            cout << "Warrior Two won!" << endl << endl;
        } else {
            cout << "Warrior One won!" << endl << endl;
        }

        cout << "To restart the game, please type \"Restart\" or \"restart\"." << endl;
        cout << "Or to exit the game, just press any key on your keyboard." << endl;

        getline(cin, user_input);
    } while ((user_input == "Restart") || (user_input == "restart"));

    cout << "Exiting the game. Thank for you for play testing!" << endl;

    return 0;
}
