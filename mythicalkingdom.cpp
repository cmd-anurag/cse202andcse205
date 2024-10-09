#include<iostream>
#include<vector>
using namespace std;

class Hero {
    public:
    int heroID;
    string name;
    int level;
    string classType;
    int health;
    int mana;
    int strength;
    int magic;
    int defense;
    bool available;
    string heroRank;

    
    
    void displayHeroStats() {
        cout << "----------------------------------\n";
        cout << "ID : " << heroID << "\n";
        cout << "Name of the hero : " << name << "\n";
        cout << "Level : " << level << "\n";
        cout << "Class Type : " << classType << "\n";
        cout << "Current Health : " << health << "\n";
        cout << "Mana points : " << mana << "\n";
        cout << "Strength : " << strength << "\n";
        cout << "Magic Attack Power : " << magic << "\n";
        cout << "Defense : " << defense << "\n";
        cout << "Is Hero Available? : " << available << "\n";
        cout << "----------------------------------\n";
    }

    void levelUp() {
        strength += 1;
        level += 1;
        magic += 1;
        defense += 1;
    }

    void takeDamage(int damage) {
        health -= damage;
        if(health <= 0) {
            cout << "Hero is dead\n";
        }
    }
    void restoreHealth(int h) {

        health += h;
        if(health > 100) {
            health = 100;
        }
    }

    void assignToFortress(Fortress &fortress) {
        available = false;
    }

    void fightEnemey(Enemy &enemy) {
        cout << name << " is fighting an enemy.\n";
    }


};

class Fortress {
    public:
    int fortressID;
    string location;
    int defenseRating;
    int capacity;
    int currentHeroes;
    bool isgettingattacked;
    
    
    
    void addHero(Hero &hero) {
        cout << hero.name << " is assigned to the fortress at " << location << "\n";
        ++currentHeroes;
    }
    void removeHero(Hero &hero) {
        cout << hero.name << " is removed from the fortress at " << location << "\n";
        --currentHeroes;
    }

    bool isUnderAttack() {
        return isgettingattacked;
    }

    void defend(Enemy &enemy) {
        cout << "The fortess is being defended against " << enemy.enemyType << "\n";
        isgettingattacked = true;
    }
};


class Enemy {
    public:
    int enemyId;
    string enemyType;
    int strength;
    int health;
    float speed;
    string specialAbilities;

    void attack(Fortress &fortress) {
        cout << "Attacking the fortress\n";
        fortress.defenseRating--;
        fortress.isgettingattacked = true;
    }

    void takeDamage(int damage) {
        health -= damage;
        if(health <= 0) {
            cout << "Enemy is dead\n";
        }
    }

    bool isAlive() {
        return health > 0;
    }

};

class Kingdom {
    public:

    string kingdomName;
    int resources;
    vector<Hero*> heroList;
    vector<Fortress*> fortressList;
    vector<Enemy*> enemyList;

    void recruitHero(Hero &hero) {
        heroList.push_back(&hero);
    }

    void buildFortress(Fortress &fortess) {
        fortressList.push_back(&fortess);
    }

    void defendKingdom() {
        cout << "Defending the kingdom\n";
    }

    void assignHeroToFortress(int fortressId, int heroId) {
        Hero* targetHero = nullptr;
        Fortress* targetFortress = nullptr;

        for(Hero *hero : heroList) {
            if(hero->heroID == heroId) {
                targetHero = hero;
                break;
            }
        }
        for(Fortress *fortress : fortressList) {
            if(fortress->fortressID == fortressId) {
                targetFortress = fortress;
                break;
            }
        }

        targetFortress->addHero(*targetHero);
        targetHero->assignToFortress(*targetFortress);
    }

    void launchCounterAttack(Enemy &enemy) {
        cout << "Launching counterattack against " << enemy.enemyType << "\n";
    }

    void manageResources(int allocation) {
        resources += allocation;
    }

    void viewKingdomStatus() {
        cout << "Name of the Kingdom : " << kingdomName << '\n';
        cout << "Available resources: " << resources << '\n';
        cout << "Heroes recruited: \n";
        
        for(Hero* h : heroList) {
            cout << h->name << " ";
        }

        cout << "Location of fortresses of the kingdom: " << '\n';
        for(Fortress* f : fortressList) {
            cout << f->location << " ";
        }
        cout << '\n';
        cout << "All known enemy types: " << '\n';
        for(Enemy* e : enemyList) {
            cout << e->enemyType << " ";
        }
        cout << '\n';

    }

};


class Battle {
    public:
    int battleID;
    vector<Hero*> heroGroup;
    vector<Enemy*> enemygroup;
    string battleOutcome;
    int damageDealt;

    void initiateBattle(Hero &hero, Enemy &enemy) {
        cout << "Heroes and enemies have begun the battle\n";
    }
    void calculateOutcome() {
        if(heroGroup.size() > enemygroup.size()) {
            cout << "Heroes win\n";
            battleOutcome = "Victory";
        }
        else if(heroGroup.size() < enemygroup.size()) {
            cout << "Enemies win\n";
            battleOutcome = "Defeat";
        }
        else {
            cout << "Stalemate\n";
            battleOutcome = "Stalemate";
        }
    }
    void recordBattle() {
        cout << "The battle has ended.\n";
        cout << "Status of Battle: " << battleOutcome << " for the heroes.\n";
    }
};

int main()
{
    
    return 0;
}