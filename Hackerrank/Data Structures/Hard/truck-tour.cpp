/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Truck Tour problem
*   Problem Link:- https://www.hackerrank.com/challenges/truck-tour/problem
*   Website:- www.programmingvidya.com
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the truckTour function below.
 */
int truckTour(vector<vector<int>> petrolpumps) {

    // * Initializing variables
    int length = petrolpumps.size(), cumulativeExtraDistance = 0, petrolPumpIndex = -1, lowestDistance = INT_MAX;

    /*
    *   Calculating the extra distance truck can travel
    *   if it starts from the first petrol pump and
    *   assigning it to cumulative extra distance
    */
    cumulativeExtraDistance = (petrolpumps[0][0] - petrolpumps[0][1]);

    /*
    *   Calculating the cumulative extra distance
    *   by considering each petrol pump one by one
    */
    for(int i=1; i<length; i++) {

        /*
        *   If the previous cumulative extra distance is less than
        *   the lowest distance found so far, mark the current index
        *   as the petrol pump index to start from and the previous
        *   cumulative extra distance as the lowest distance
        */
        if(cumulativeExtraDistance<lowestDistance) {
            petrolPumpIndex = i;
            lowestDistance = cumulativeExtraDistance;
        }

        /*
        *   Calculating the extra distance truck can travel
        *   if it starts from the current petrol pump and
        *   adding it to cumulative extra distance
        */
        cumulativeExtraDistance += (petrolpumps[i][0] - petrolpumps[i][1]);
    }

    /*
    *   If the final cumulative extra distance
    *   is less than or equal to the lowest distance
    *   assign the petrol pump index to 0
    */
    if(cumulativeExtraDistance<=lowestDistance) {
        petrolPumpIndex = 0;
    }

    // * Returning the petrol pump index
    return petrolPumpIndex;
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

    fout.close();

    return 0;
}
