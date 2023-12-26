#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Warrior.hpp"

using namespace std;

int main() {
    Warrior one;
    Warrior two;
    int to;

    cout << "Welcome to Dungeon Smash!" << endl << endl;

    // do {
        one.display_current_stats(1);
        two.display_current_stats(2);
    // } while((one.get_health_stat != 0) && (two.get_health_stat != 0));

    cin >> to;

    return 0;
}
