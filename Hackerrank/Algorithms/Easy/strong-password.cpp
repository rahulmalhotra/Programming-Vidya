/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Solution for HackerRank Strong Password problem
*   Problem Link:- https://www.hackerrank.com/challenges/strong-password/problem
*	Website:- www.programmingvidya.com
*/
#include <bits/stdc++.h>
using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong

    // * Initializing variables
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    int passwordLength = password.length(), numbersCount = 0, lowercaseCount = 0, uppercaseCount = 0, specialcharactersCount = 0, minimumRequiredCharactersCount = 0;

    // * Checking each character of password one by one
    for(int i=0; i<passwordLength; i++) {

        /*
        *   If the current character is a number,
        *   increase the numbers count by 1
        */
        if(numbers.find(password[i])!=string::npos) {
            numbersCount++;
        }

        /*
        *   If the current character is a lowercase english alphabet,
        *   increase the lowercase count by 1
        */
        else if(lower_case.find(password[i])!=string::npos) {
            lowercaseCount++;
        }

        /*
        *   If the current character is an uppercase english alphabet,
        *   increase the uppercase count by 1
        */
        else if(upper_case.find(password[i])!=string::npos) {
            uppercaseCount++;
        }

        /*
        *   If the current character is a special character,
        *   increase the special characters count by 1
        */
        else if(special_characters.find(password[i])!=string::npos) {
            specialcharactersCount++;
        }
    }

    /*
    *   If the numbers count is zero,
    *   that means we need at least one number.
    *   Therefore, increase the minimum required characters count by 1
    */
    if(numbersCount==0) {
        minimumRequiredCharactersCount++;
    }

    /*
    *   If the lowercase english characters count is zero,
    *   that means we need at least one lowercase english character.
    *   Therefore, increase the minimum required characters count by 1
    */
    if(lowercaseCount==0) {
        minimumRequiredCharactersCount++;
    }

    /*
    *   If the uppercase english characters count is zero,
    *   that means we need at least one uppercase english character.
    *   Therefore, increase the minimum required characters count by 1
    */
    if(uppercaseCount==0) {
        minimumRequiredCharactersCount++;
    }

    /*
    *   If the special characters count is zero,
    *   that means we need at least one special character.
    *   Therefore, increase the minimum required characters count by 1
    */
    if(specialcharactersCount==0) {
        minimumRequiredCharactersCount++;
    }

    /*
    *   If the minimum required characters count is more than
    *   the number of characters required to make the password of length 6,
    *   return the minimum required characters count. Otherwise, return
    *   the number of characters required to make the password of length 6
    *   which is:- (6 - current length of password)
    */
    return max(minimumRequiredCharactersCount, 6 - passwordLength);
}

// * Main function as given by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}