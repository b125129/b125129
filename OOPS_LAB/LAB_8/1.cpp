#include <iostream>
using namespace std;

class Character {
public:
    virtual void attack() {
        cout << "Base character attack." << endl;
    }
};

class Warrior : public Character {
private:
    double strength;
public:
    Warrior(double s) {
        strength = s;
    }
    
    void attack() override {
        double damage = 20 + 2 * strength;
        cout << "Warrior deals " << damage << " damage." << endl;
    }
};

class Archer : public Character {
private:
    double agility;
public:
    Archer(double a) {
        agility = a;
    }
    
    void attack() override {
        double damage = 15 + 3 * agility;
        cout << "Archer deals " << damage << " damage." << endl;
    }
};

int main() {
    double str, agi;
    
    cout << "Enter the strength value for the Warrior: ";
    cin >> str;
    
    cout << "Enter the agility value for the Archer: ";
    cin >> agi;
    
    cout << "\n--- Battle Results ---" << endl;
    
    Warrior warrior(str);
    Archer archer(agi);
    
    warrior.attack();
    archer.attack();
    
    return 0;
}