#include<iostream>
using namespace std;

void moveDisk(int n, char source, char auxillary, char destination) {
    if(n == 1) {
        cout << "Moving disk " << n << " from " << source << " to " << destination << "\n"; 
        return;
    }

    // move n-1 disks from source to auxillary rod
    moveDisk(n-1, source, destination, auxillary);

    // moving the nth disc directly from source to destination
    cout << "Moving disk " << n << " from " << source << " to " << destination << "\n";

    // move n-1 disks kept at auxillary to dsetination
    moveDisk(n-1, auxillary, source, destination);
    
}


int main()
{
    moveDisk(4, 'A', 'B', 'C');
    return 0;
}