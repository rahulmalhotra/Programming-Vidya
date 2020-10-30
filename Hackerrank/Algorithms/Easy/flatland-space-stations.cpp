/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Flatland Space Stations problem
*   Problem Link:- https://www.hackerrank.com/challenges/flatland-space-stations/problem
*	Website:- www.programmingvidya.com
*/
// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {

    // * Initializing variables
    int cLength = c.size(), previousCity = -1, i = 0, distance, maxDistance = 0;
    bitset<100000> cities;

    // * Marking the cities with space stations
    for(int i=0; i<cLength; i++) {
        cities.set(c[i]);
    }

    // * Checking for each city one by one
    for(i=0; i<n; i++) {

        // * If the current city has a space station
        if(cities.test(i)) {

            /*
            *   Calculating the distance.
            *   If the current city is the first city with a space station,
            *   distance = distance of the first city from the current city,
            *   otherwise, distance = distance between current city and previous city
            *   with space station divided by 2
            */
            distance = previousCity == -1 ? (i-previousCity-1) :  (i-previousCity)/2;

            // * Marking the current city as the previous city with space station
            previousCity = i;

            // * Updating the maximum distance
            maxDistance = max(maxDistance, distance);
        }
    }

    /*
    *   Calculating the distance of last city from the previous city with space station.
    *   Updating the maximum distance
    */
    distance = (i-previousCity-1);
    maxDistance = max(maxDistance, distance);

    // * Returning the maximum distance
    return maxDistance;
}