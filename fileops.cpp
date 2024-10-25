// FILE OPERATIONS

#include <iostream>
#include <fstream>
#include<string.h>


using namespace std;

class Person {
    public:

    char name[50];
    int age;
    float weight;
};

void WriteToBinaryFile(Person &p) {
    fstream myFile("binaryfile.dat", ios::app | ios::binary);
    if(!myFile) {cout << "Error writing to file"; return;}

    myFile.write(reinterpret_cast<const char *>(&p), sizeof(p));
    cout << "Person details written to file.\n";
    myFile.close();
}

void ReadFromBinaryFile() {
    Person person;
    fstream myfile("binaryfile.dat", ios::in | ios::binary);

    if(!myfile){
        cout << "error";
        return;
    }

    while(myfile.read(reinterpret_cast<char *>(&person), sizeof(person))) {
        cout << person.name << " " << person.age << " " << person.weight << endl;
    }

    myfile.close();
}

int main() {
    Person p1;
    strcpy(p1.name, "test");
    p1.age = 23;
    p1.weight = 34.45;
    WriteToBinaryFile(p1);
    ReadFromBinaryFile();
}