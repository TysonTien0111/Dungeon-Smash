#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior {
    public:
        Warrior();
        void initialize_srand();
        int generate_seed();
        void set_health_stat();
        void set_attack_stat();
        void set_armor_stat();
        void set_guard_status();
        void set_weakening_strike_status();
        void display_current_stats(int warrior_number);
        void attack(int warrior_number);
        void weakening_strike(int warrior_number);
        void sword_strike(int warrior_number);
        double get_health_stat();
        double get_attack_stat();
        double get_armor_stat();
        bool get_guard_status();
        bool get_weakening_strike_status();
        void update_health_stat(double x);
        void update_armor_stat(double x);
        ~Warrior(); 
    private:
        double health_stat;
        double attack_stat;
        double armor_stat;
        bool guard_status; 
        bool weakening_strike_status;
};

#endif // WARRIOR_H
