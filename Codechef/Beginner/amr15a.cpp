/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for Codechef AMR15A Problem
*   Problem Link:- https://www.codechef.com/problems/AMR15A
*/
#include <iostream>
using namespace std;
int main() {

    // * Initializing variables
    int numberOfSoldiers, numberOfSoldiersWithEvenWeapons = 0,
    numberOfSoldiersWithOddWeapons = 0, numberOfWeaponsWithCurrentSoldier;

    // * Accepting the number of soldiers in the army
    cin>>numberOfSoldiers;

    /*
    *   Calculating the total number of soldiers
    *   with even and odd number of weapons
    */
    while(numberOfSoldiers--) {

        // * Accepting the number of weapons with current soldier
        cin>>numberOfWeaponsWithCurrentSoldier;

        /*
        *   If the number of weapons with current soldier is odd,
        *   increasing the soldier count with odd weapons by 1
        *   Otherwise, if the number of weapons with current soldier is even,
        *   increasing the soldier count with even weapons by 1
        */
        if(numberOfWeaponsWithCurrentSoldier&1) {
            numberOfSoldiersWithOddWeapons++;
        } else {
            numberOfSoldiersWithEvenWeapons++;
        }
    }

    /*
    *   If the number of soldiers with even weapons is greater than the number
    *   of soldiers with odd weapons, display:- READY FOR BATTLE
    *   Otherwise, display:- NOT READY
    */
    if(numberOfSoldiersWithEvenWeapons>numberOfSoldiersWithOddWeapons) {
        cout<<"READY FOR BATTLE"<<endl;
    } else {
        cout<<"NOT READY"<<endl;
    }
}