#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Warrior.hpp"

/* Reduction Damage Percent = armor_stat * 6 */

using namespace std;

Warrior::Warrior() {
    initialize_srand();
    set_health_stat();
    set_attack_stat();
    set_armor_stat();
    set_guard_status();
}

void Warrior::initialize_srand() {
    srand(generate_seed());
}

int Warrior::generate_seed() {
    int seed = time(0) + rand();
    return seed;
}

void Warrior::set_health_stat() {
    health_stat = static_cast<double>((rand() % 10) + 1.0);
}

void Warrior::set_attack_stat() {
    attack_stat = static_cast<double>((rand() % 10) + 1.0); 
}

void Warrior::set_armor_stat() {
    armor_stat = static_cast<double>((rand() % 10) + 1.0);
}

void Warrior::set_guard_status() {
    if ((rand() % 2) == 0) {
        guard_status = true; 
    } else {
        guard_status = false;
    }
}

void Warrior::display_current_stats(int warrior_number) {
    cout << fixed << setprecision(1);
    if (warrior_number == 1) {
        cout << setw(15) << "Warrior One's Stats" << endl;
    } else {
        cout << setw(15) << "Warrior Two's Stats" << endl;
    }
    cout << setw(15) << "Health Stat: " << health_stat << endl;
    cout << setw(15) << "Attack Stat: " << attack_stat << endl;
    cout << setw(15) << "Armor Stat: " << armor_stat << endl;
    cout << setw(15) << boolalpha << "Guard Status: " << guard_status << endl << endl;
}

double Warrior::get_health_stat() {
    return health_stat;
}

Warrior::~Warrior() {
}


