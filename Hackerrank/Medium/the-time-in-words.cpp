/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank The Time in Words Problem
*   Problem Link:- https://www.hackerrank.com/challenges/the-time-in-words/problem
*/
string timeInWords(int h, int m) {

    // * Initializing variables
    string time = "";

    // * Initializing hours map
    unordered_map<int, string> hoursMap;
    hoursMap[1] = "one";
    hoursMap[2] = "two";
    hoursMap[3] = "three";
    hoursMap[4] = "four";
    hoursMap[5] = "five";
    hoursMap[6] = "six";
    hoursMap[7] = "seven";
    hoursMap[8] = "eight";
    hoursMap[9] = "nine";
    hoursMap[10] = "ten";
    hoursMap[11] = "eleven";
    hoursMap[12] = "twelve";

    // * Initializing minutes map
    unordered_map<int, string> minutesMap;
    minutesMap[1] = "one minute";
    minutesMap[2] = "two minutes";
    minutesMap[3] = "three minutes";
    minutesMap[4] = "four minutes";
    minutesMap[5] = "five minutes";
    minutesMap[6] = "six minutes";
    minutesMap[7] = "seven minutes";
    minutesMap[8] = "eight minutes";
    minutesMap[9] = "nine minutes";
    minutesMap[10] = "ten minutes";
    minutesMap[11] = "eleven minutes";
    minutesMap[12] = "twelve minutes";
    minutesMap[13] = "thirteen minutes";
    minutesMap[14] = "fourteen minutes";
    minutesMap[15] = "quarter";
    minutesMap[16] = "sixteen minutes";
    minutesMap[17] = "seventeen minutes";
    minutesMap[18] = "eighteen minutes";
    minutesMap[19] = "nineteen minutes";
    minutesMap[20] = "twenty minutes";
    minutesMap[21] = "twenty one minutes";
    minutesMap[22] = "twenty two minutes";
    minutesMap[23] = "twenty three minutes";
    minutesMap[24] = "twenty four minutes";
    minutesMap[25] = "twenty five minutes";
    minutesMap[26] = "twenty six minutes";
    minutesMap[27] = "twenty seven minutes";
    minutesMap[28] = "twenty eight minutes";
    minutesMap[29] = "twenty nine minutes";
    minutesMap[30] = "half";
    minutesMap[31] = "twenty nine minutes";
    minutesMap[32] = "twenty eight minutes";
    minutesMap[33] = "twenty seven minutes";
    minutesMap[34] = "twenty six minutes";
    minutesMap[35] = "twenty five minutes";
    minutesMap[36] = "twenty four minutes";
    minutesMap[37] = "twenty three minutes";
    minutesMap[38] = "twenty two minutes";
    minutesMap[39] = "twenty one minutes";
    minutesMap[40] = "twenty minutes";
    minutesMap[41] = "nineteen minutes";
    minutesMap[42] = "eighteen minutes";
    minutesMap[43] = "seventeen minutes";
    minutesMap[44] = "sixteen minutes";
    minutesMap[45] = "quarter";
    minutesMap[46] = "fourteen minutes";
    minutesMap[47] = "thirteen minutes";
    minutesMap[48] = "twelve minutes";
    minutesMap[49] = "eleven minutes";
    minutesMap[50] = "ten minutes";
    minutesMap[51] = "nine minutes";
    minutesMap[52] = "eight minutes";
    minutesMap[53] = "seven minutes";
    minutesMap[54] = "six minutes";
    minutesMap[55] = "five minutes";
    minutesMap[56] = "four minutes";
    minutesMap[57] = "three minutes";
    minutesMap[58] = "two minutes";
    minutesMap[59] = "one minute";

    /*
    *   If minutes value is zero, this means that we have to use
    *   "o' clock" to denote the time
    */
    if(m==0) {
        time = hoursMap[h] + " o' clock";
    }

    /*
    *   If minutes value is greater than 30, this means that we have to use
    *   "to" to denote the time and we also need to increase hour by 1
    *   as we're denoting the time in terms of the upcoming hour
    */
    else if(m>30) {
        time = minutesMap[m] + " to " + hoursMap[h+1];
    }

    /*
    *   If minutes value is less than or equal to 30, this means that we have to use
    *   "past" to denote the time
    */
    else {
        time = minutesMap[m] + " past " + hoursMap[h];
    }

    // * Returning the time in words
    return time;
}