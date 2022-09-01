//
//  utility.cpp
//  Week2LA
//
//  Created by Adi Mehta on 3/11/22.
//

#include "utility.h"
std::string ToLower(std::string input)
{
    std::string output=input;
    for (int i=0; i!=input.size();i++)
    {
        output[i]=tolower(output[i]);
    }
    return output;
}
bool operator<(const EmailCount &a, const EmailCount &b)
{
    if (a.count==b.count)
    {
        return ToLower(a.email)<ToLower(b.email);
    }
    else
    {
        return a.count>b.count;
    }
}
bool operator<(const AttValPair &a, const AttValPair &b)
{
    if (a.value==b.value)
    {
        return a.attribute<b.attribute;
    }
    else
    {
        return a.value>b.value;
    }
}
