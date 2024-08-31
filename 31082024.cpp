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
};

int main() {
    Student s1;
    Student s2;
    Student s3;
    s1.name = "Anurag";
    s1.age = 20;
    s1.roll = 16;
    s2.name = "ABC";
    s2.age = 22;
    s2.roll = 11;
    s3.name = "XYZ";
    s3.age = 18;
    s3.roll = 15;
    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Roll no.: " << s1.roll << endl;
    cout << "Name: " << s2.name << endl;
    cout << "Age: " << s2.age << endl;
    cout << "Roll no.: " << s2.roll << endl;
    cout << "Name: " << s3.name << endl;
    cout << "Age: " << s3.age << endl;
    cout << "Roll no.: " << s3.roll << endl;
}