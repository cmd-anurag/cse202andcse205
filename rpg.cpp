#include<iostream>
using namespace std;

class Character {
    string name;
    string type;
    int health = 100;
    int attackPower;
    int defensePower;
    int magicPower;

    public:
        Character() : name("Unknown"), type("Unknown"), attackPower(1), defensePower(1), magicPower(0) {};
        Character(string n, string t, int h, int aP, int dP, int mP) : name(n), type(t), health(h), attackPower(aP), defensePower(dP), magicPower(mP)  {};
        Character(string n, string t, int h, int aP, int dP) : name(n), type(t), health(h), attackPower(aP), defensePower(dP), magicPower(0) {};

        void setName(string s) {
            name = s;
        }
        string getName() {
            return name;
        }

        void setType(string t) {
            type = t;
        }
        string getType() {
            return type;
        }
        void setHealth(int h) {
            if(h > 100) {
                cout << "Health value cannot exceed 100";
                return;
            }
            if(h < 0) {
                cout << "Health cannot be negative";
                return;
            }
            health = h;
        }
        int getHealth() {
            return health;
        }
        void setAttackPower(int ap) {
            attackPower = ap;
        }
        int getAttackPower() {
            return attackPower;
        }
        void setDefensePower(int dp) {
            defensePower = dp;
        }
        int getDefensePower() {
            return defensePower;
        }
        void setMagicPower(int mp) {
            if(type != "Mage") {
                cout << "Not a magic character\n";
                return;
            }
            magicPower = mp;
        }
        int getMagicPower() {
            if(type != "Mage") {
                cout << "Not a magic character\n";
                return 0;
            }
            return magicPower;
        }

        void attack(Character& target) {
            cout << this->name << " attacks " << target.name << endl;
        }
        void defend(Character& target) {
            cout << this->name << " defends against " << target.name << endl;
        }
        void useMagic() {
            if(type != "Mage") {
                cout << "Not a magic character\n";
                return;
            }
            cout << this->name <<" uses magic\n";
        }
};





int main()
{
    Character wizard("wizard1", "Mage", 100, 20, 10, 25);
    Character archer("archer1", "Archer", 100, 20, 10);

    wizard.attack(archer);
    archer.defend(wizard);
    wizard.useMagic();
    archer.useMagic();
    return 0;
}