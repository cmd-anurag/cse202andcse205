#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Animal {
    protected:
        string species;
        int age;
        float weight;

    public:
        Animal() : species("unknown"), age(0), weight(0) {};
        Animal(string s, int a, float w) : species(s), age(a), weight(w) {};

    void displayInfo() {
        cout << "Species: " << species << '\n';
        cout << "Age: " << age <<  " years\n";
        cout << "Weight: " << fixed << setprecision(3) << weight << " kilograms\n";
    }

};

class Mammal : public Animal {
    protected:
        string furColor;
    
    public:
        Mammal() : furColor("unknown") {};
        Mammal(string s, int a, float w, string f) : Animal(s, a, w), furColor(f) {};

    void makeSound() {
        cout << species << " makes a sound\n";
    }

};

class Bird : virtual public Animal {
    protected:
        float wingSpan;

    public:
        Bird() : wingSpan(0) {};
        Bird(string s, int a, float w, float ws) : Animal(s, a, w), wingSpan(ws) {};
    
    void fly() {
        cout << species << " is flying with a wingspan of " << fixed << setprecision(1) << wingSpan << " meters\n";
    }

};

class Reptile : virtual public Animal {
    protected:
        bool isVenomous;
    public:
        Reptile() : isVenomous(true) {};
        Reptile(string s, int a, float w, bool isVenom) : Animal(s, a, w), isVenomous(isVenom) {};

    void crawl() {
        cout << species << " is crawling\n";
    }

};

class Lion : public Mammal {
    protected:
        int prideSize;
    public:
        Lion() : prideSize(0) {};
        Lion(string s, int a, float w, string f, int ps) : Mammal(s, a, w, f), prideSize(ps) {};

    void hunt() {
        cout << species << " hunts with its pride of " << prideSize << " members\n";
    }

    void makeSound() {
        cout << species << " roars\n";
    }

};

class FlyingReptile : public Bird, public Reptile {
    public:
        FlyingReptile() {};
        FlyingReptile(string s, int a, float w, float ws, bool isVenom) : Animal(s, a, w), Bird(s, a, w, ws), Reptile(s, a, w, isVenom) {};

    void glide() {
        cout << species << " is gliding with a wingspan of " << fixed << setprecision(1) << wingSpan << " meters\n";
    }

};

class Elephant : public Mammal {
    protected:
        float trunkLength;
    public:
        Elephant() : trunkLength(0) {};
        Elephant(string s, int a, float w, string f, float tl) : Mammal(s, a, w, f), trunkLength(tl) {};

    void useTrunk() {
        cout << species << " uses its trunk to drink water\n";
    }

};

int main() {

    Lion lionObject("Lion", 5, 190, "Golden", 6);
    lionObject.displayInfo();
    lionObject.makeSound();
    lionObject.hunt();

    Bird Parrot("Parrot", 2, 1.5, 0.8);
    Parrot.displayInfo();
    Parrot.fly();

    Reptile Crocodile("Crocodile", 12, 400, false);
    Crocodile.displayInfo();
    Crocodile.crawl();

    Elephant Elephantobject("Elephant", 10, 5000, "Grey", 2);
    Elephantobject.displayInfo();
    Elephantobject.makeSound();
    Elephantobject.useTrunk();

    FlyingReptile flyingReptile("Pterodactyl", 3, 50, 3, true);
    flyingReptile.displayInfo();
    flyingReptile.fly();
    flyingReptile.crawl();
    flyingReptile.glide();

    return 0;
}