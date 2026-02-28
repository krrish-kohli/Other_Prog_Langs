/* Name: Krrish Kohli
Course : CECS 329
Assignment 4 - Implement a DFA
Tools used:
 - Compiler: gcc
 - Editor: VS Code
 - Terminal / Shell: Mac Terminal / bash
 - Websites: https://en.cppreference.com/w/cpp/string/basic_string/getline.html
*/

#include "DFA.cpp"

int main() 
{   
    string first,last, test;
    cout << "Enter your first name: ";
    getline(cin, first);
    cout << first << endl;
    cout << "Enter your last name: ";
    getline(cin, last);
    cout << last << endl;
    cout << "Enter your input that contains only alphabet characters: ";
    getline(cin, test);
    cout << test << endl;

    string result = transition(first,last, test);
    cout << result << endl;
    return 0;
}