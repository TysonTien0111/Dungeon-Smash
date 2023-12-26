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
        void display_current_stats(int warrior_number);
        double get_health_stat();
        ~Warrior(); 
    private:
        double health_stat;
        double attack_stat;
        double armor_stat;
        bool guard_status; 
};

#endif // WARRIOR_H
