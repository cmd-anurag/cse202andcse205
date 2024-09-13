// FILE OPERATIONS

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // ofstream file("testfile.txt");
    // if(file) {
    //     cout << "Success";
    // }
    // else {
    //     cout << "Failure";
    // }

    
    // if(file.is_open()) {
    //     cout << "open";
    // }
    // else {
    //     cout << "closed";
    // }

    // if(file.fail()) {
    //     // fail case
    // }

    // ifstream file("testfile.txt");

    // if(file.fail()) {
    //     cout << "failed";
    //     return 0;
    // }

    // string content;
    // while (!file.eof())
    // {
    //     getline(file, content);
    //     cout << content;
    // }
    // file.close();

    ofstream file("testfile.txt", ios::app);
    if(file.fail()) {
        return -1;
    }

    // file << "stream insertion";
    file << "\nstream insertion again";
    file.close();


}