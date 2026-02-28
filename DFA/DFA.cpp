#include <iostream>
#include <fstream>
#include "DFA.h"

using namespace std;

static string to_lower(string& str)
{
    size_t str_length = str.length();
    for (int i = 0; i < str_length; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

static bool validate(string& str)
{
    size_t str_length = str.length();
    if (str_length == 0)
        return false;
    for (size_t i = 0; i < str_length; i++)
    {
        if((str[i] < 'a') || (str[i] > 'z'))
            return false;
    }
    return true;
}


string transition(string& first, string& last, string& test)
{
    first = to_lower(first);
    last = to_lower(last);
    test = to_lower(test);
    if(!validate(first) || !validate(last) || !validate(test))
        return "Reject";

    int state1 = 0, state2 = 0;
    size_t len1 = first.length();
    size_t len2 = last.length();
    size_t lenT = test.length();
    size_t i = 0;
    while(i < lenT && state1 < len1)
    {
        if (test [i] == first[state1])
        {
            state1++;
            i++;
        }
        else if (state1 > 0) {state1 = 0;}
        else {i++;}
    }
    
    while(i < lenT && state2 < len2)
    {
        if (test [i] == last[state2])
        {
            state2++;
            i++;
        }
         else 
        {
            if(test[i] == last[0] && state2 > 0)
            {
                state2 = 1;
                i++;
            }
            else
            {
                state2 = 0;
                i++;
            }
        }
    }
    if(state1 == len1 && state2 == len2)
    {
        return "Accept";
    }
    else
    {
        return "Reject";
    }
}