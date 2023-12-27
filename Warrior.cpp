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

/* Reduction Damage Percent = armor_stat * 0.05
 * If guard_status is up then, the warrior has a 15% chance of decreasing the
 * armor stat of the opponent by 2 with weakening_strike. */

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
    health_stat = static_cast<double>((rand() % 26) + 25.0);
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

void Warrior::set_weakening_strike_status() {
    if (((rand() % 100) + 1) <= 15) {
        weakening_strike_status = true;
    } else {
        weakening_strike_status = false;
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

void Warrior::attack(int warrior_number) {
    if (guard_status == true) {
        weakening_strike(warrior_number);
    } else {
        sword_strike(warrior_number);
    }
}

void Warrior::weakening_strike(int warrior_number) {
    if (warrior_number == 1) {
        if (weakening_strike_status == true) {
            cout << "Warrior One uses weakening strike with their " << attack_stat << " attack stat." << endl; 
        } else {
            cout << "Warrior One uses weakening strike with their " << attack_stat << " attack stat." << endl;
        }
    } else {
        if (weakening_strike_status == true) {
            cout << "Warrior Two uses weakening strike with their " << attack_stat << " attack stat." << endl;
        } else {
            cout << "Warrior Two uses weakening strike with their " << attack_stat << " attack stat." << endl;
        }
    }
}

void Warrior::sword_strike(int warrior_number) {
    if (warrior_number == 1) {
        cout << "Warrior One uses sword strike with their " << attack_stat << " attack stat." << endl;
    } else {
        cout << "Warrior Two uses sword strike and deals " << attack_stat << " slashing damage to Warrior One." << endl;
    }
}

double Warrior::get_health_stat() {
    return health_stat;
}

double Warrior::get_attack_stat() {
    return attack_stat;
}

double Warrior::get_armor_stat() {
    return armor_stat;
}

bool Warrior::get_guard_status() {
    return guard_status;
}

bool Warrior::get_weakening_strike_status() {
    return weakening_strike_status;
}

void Warrior::update_health_stat(double x) {
    health_stat = x;
}

void Warrior::update_armor_stat(double x) {
    armor_stat = x;
}

Warrior::~Warrior() {
}
