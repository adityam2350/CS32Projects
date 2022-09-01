//
//  PersonProfile.cpp
//  CS32-Project4
//
//  Created by Adi Mehta on 3/4/22.
//

#include "PersonProfile.h"
PersonProfile::PersonProfile(std::string name, std::string email)
{
    m_name=name;
    m_email=email;
    m_size=0;
    
}
PersonProfile::~PersonProfile()
{
}
std::string PersonProfile::GetName() const
{

    return m_name;
}
std::string PersonProfile::GetEmail() const
{
    return m_email;
}
void PersonProfile::AddAttValPair(const AttValPair &attval)
{
    //Checks if value is already in the darn RadixTree, so size doesn't increase when it doesn't need to
    if (m_pairs.search(attval.value)==nullptr)
    {
        m_size++;
    }
    
    m_pairs.insert(attval.value, attval.attribute); //Add the key-val combo to the radix tree
    std::string toAdd=attval.value;
    m_temp.insert(toAdd);
    //temp set is used to be used by GetAttVall
    
}
int PersonProfile::GetNumAttValPairs() const
{
    return m_size;
}
bool PersonProfile::GetAttVal(int attribute_num, AttValPair &attval) const
{
    if (attribute_num>m_size)
    {
        return false;
    }
    //if the attribute number is to big, we just return false;
    
    int i=0;
    std::set<std::string>::iterator it=m_temp.begin();
    //to find a unique value
    
    while (i!=attribute_num)
    {
        it++;
        i++;
    }
    attval.value=*it;
    attval.attribute=*m_pairs.search(*it);
    
    
    return true;
}

