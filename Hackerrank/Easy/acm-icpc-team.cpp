/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank ACM ICPC Team problem
*   Problem Link:- https://www.hackerrank.com/challenges/acm-icpc-team/problem
*/

/*
*   This method is used to convert two strings into bitsets,
*   perform an OR operation and find the number of set bits
*   in the resultant bitset
*/
int numberOfTopicsCoveredByATeamUsingBitset(string c1, string c2) {

    // * Initializing bitsets
    bitset<500> c1Bits(c1);
    bitset<500> c2Bits(c2);

    /*
    *   Performing an OR operation between both bitsets
    *   and updating the first bitset
    */
    c1Bits = c1Bits | c2Bits;

    // * Returning the number of set bits in updated first bitset
    return c1Bits.count();
}

/*
*   This method is used to compare two strings
*   and find the number of characters equal to 1 at same index
*   in either of the two strings
*/
int numberOfTopicsCoveredByATeam(string c1, string c2) {

    // * Initializing variables
    int length = c1.length(), totalTopics = 0;

    /*
    *   Comparing two strings and increasing the count
    *   of totalTopics by 1 if any one of the string has '1'
    *   at the current index
    *
    */
    for(int i=0; i<length; i++) {
        if(
            c1[i]=='1' ||
            c2[i]=='1'
        ) {
            totalTopics++;
        }
    }

    // * Returning total topics
    return totalTopics;
}

vector<int> acmTeam(vector<string> topic) {

    // * Initializing variables
    vector<int> result;
    int topicLength = topic.size(), maxTopic = 0;
    int totalTopics = topicLength*(topicLength-1)/2, totalTeams = 0;

    // * Considering all teams one by one
    for(int i=0; i<topicLength; i++) {
        for(int j=i+1; j<topicLength; j++) {

            // * Finding the number of topics covered by current team
            // * Any one of the two methods can be used
            // int numberOfTopicsCovered = numberOfTopicsCoveredByATeam(topic[i], topic[j]);
            int numberOfTopicsCovered = numberOfTopicsCoveredByATeamUsingBitset(topic[i], topic[j]);

            /*
            *   If the number of topics covered by the current team are more than
            *   the maximum number of topics, updating the maximum number of topics
            *   and initializing the total teams having maximum number of topics to 1
            */
            if(numberOfTopicsCovered > maxTopic) {
                maxTopic = numberOfTopicsCovered;
                totalTeams = 1;
            }

            /*
            *   If the number of topics covered by the current team is equal to
            *   the maximum number of topics, incrementing the total teams
            *   having maximum number of topics by 1
            */
            else if(numberOfTopicsCovered == maxTopic) {
                totalTeams++;
            }
        }
    }

    // * Adding maximum number of topics to the result vector
    result.push_back(maxTopic);

    // * Adding total teams having maximum number of topics to the result vector
    result.push_back(totalTeams);

    // * Returning the result vector in the response
    return result;
}