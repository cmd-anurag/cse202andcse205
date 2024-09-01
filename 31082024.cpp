#include <iostream>
#include <vector>
#include <string>


using namespace std;

int findSecondLargest(vector<int> arr) {
    int largest = INT32_MIN;

    for(int i : arr) {
        if(i > largest) {
            largest = i;
        }
    }
    int secondLargest = INT32_MIN;

    for(int i : arr) {
        if(i > secondLargest && i != largest) {
            secondLargest = i;
        }
    }
    if(secondLargest!=INT32_MIN) {
        return secondLargest;
    }
    else {
        return -1;
    }

} 

class Student {
    public:
        string name;
        int roll;
        int age;
    Student() {

    }
    Student(string n, int r, int a) : name(n), roll(r), age(a) {};

    Student(Student &studentObj) {
        name = studentObj.name;
        roll = studentObj.roll;
        age = studentObj.age;
    }
    ~Student() {
        cout << name << " has been destroyed" << endl;
    }

};

int main() {
    Student s1("DJ", 20, 49);
    Student s2(s1);

    cout << s2.name << endl;
    cout << s2.age << endl;
    cout << s2.roll << endl;
}