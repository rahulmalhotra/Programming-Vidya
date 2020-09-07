/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Poisonous Plants Problem
*   Problem Link:- https://www.hackerrank.com/challenges/poisonous-plants/problem
*/
int poisonousPlants(vector<int> p) {

    // * Initializing variables
    stack<pair<int, int>> s;
    int size = p.size();
    int numberOfDaysAfterWhichNoPlantsDie = 0, daysAfterWhichCurrentPlantWillDie;

    // * Iterating the pesticides amount for each plant
    for (int i=0; i<size; i++) {

        // * Initializing the number of days after which current plant will die to 0
        daysAfterWhichCurrentPlantWillDie = 0;

        /*
        *   While stack is not empty and the current amount of pesticide
        *   is less than or equal to the amount of pesticide of the plant
        *   present at the top of stack
        */
        while(!s.empty() && s.top().first >= p[i]) {

            // * Calculating the number of days after which current plant will die
            daysAfterWhichCurrentPlantWillDie = max(s.top().second, daysAfterWhichCurrentPlantWillDie);
            s.pop();
        }

        // * If the stack is empty, add the amount of pesticide and -1 number of days to the stack
        if(s.empty()) {
            s.push(make_pair(p[i], -1));
        }

        // * Otherwise, push the amount of pesticide and the number of days after which the current plant will die to the stack
        else {
            daysAfterWhichCurrentPlantWillDie++;
            s.push(make_pair(p[i], daysAfterWhichCurrentPlantWillDie));
        }

        // * Updating the number of days after which no plants die
        numberOfDaysAfterWhichNoPlantsDie = max(numberOfDaysAfterWhichNoPlantsDie, daysAfterWhichCurrentPlantWillDie);
    }

    // * Returning the number of days after which no plants die
    return numberOfDaysAfterWhichNoPlantsDie;
}