#include<iostream>
using namespace std;

// EXCEPTION HANDLING

int main()
{
    int kills = 4;
    int deaths = 0;

    try {
        if(deaths == 0) {
            throw out_of_range("");
        }
        float kdRatio = kills/deaths;
        cout << "KD Ratio is : " << kdRatio << '\n';
    }
    catch(out_of_range e) {
        cout << e.what() << " ";
    }

    return 0;
}