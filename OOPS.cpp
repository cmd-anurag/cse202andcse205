#include<iostream>
using namespace std;

class Rectangle {
    int length;
    int breadth;
    public:
        Rectangle(int l, int b) : length(l), breadth(b) {}

        int getArea() {
            return length*breadth;
        }
        int getLength() {
            return length;
        }
        void setLength(int l) {
            length = l;
        }
        int getBreadth() {
            return breadth;
        }
        void setBreadth(int b) {
            breadth = b;
        }
};

class BankAccount {
    int balance;
    public:
        BankAccount() : balance(0) {};
        void deposit(int amount) {
            if(amount < 0) {
                cout << "Invalid Amount";
                return;
            }
            cout << amount << " deposited in the account.\n";
            balance += amount;
        }
        void withdraw(int amount) {
            if(amount < 0) {
                cout << "Invalid Amount\n";
                return;
            }
            if(amount > balance) {
                cout << "Insufficient balance\n";
                return;
            }
            balance -= amount;
        }
        int getBalance() {
            return balance;
        }
};

int main()
{
    BankAccount account1;
    account1.deposit(200);
    account1.withdraw(50);
    account1.withdraw(350);
    cout << account1.getBalance();
    return 0;
}