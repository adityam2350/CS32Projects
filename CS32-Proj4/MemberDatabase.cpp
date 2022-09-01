//
//  MemberDatabase.cpp
//  Week2LA
//
//  Created by Adi Mehta on 3/8/22.
//

#include "MemberDatabase.h"
#include "PersonProfile.h"
MemberDatabase::MemberDatabase()
{
    pairs_to_email=new RadixTree<std::vector<std::string>>();
    emails_to_person=new RadixTree<PersonProfile*>();
    
}
MemberDatabase::~MemberDatabase()
{
    for (int i=0; i<emails.size();i++)
    {
        PersonProfile** a=emails_to_person->search(emails[i]);
        if (a!=nullptr)
        {
            if (*a!=nullptr)
            {
                delete *a;
            }
        }
        
    }
    delete pairs_to_email;
    delete emails_to_person;
}
bool MemberDatabase::LoadDatabase(std::string filename)
{
    std::ifstream trans_file(filename);
    
    char x;
    
    if (trans_file.is_open())
    {
        std::string temp="";
        std::string name="";
        std::string email="";
        PersonProfile* p=nullptr;
        int count=0;
        int num_traits=-1;
        int num_trace=0;
        while (trans_file.good())
        {
            x=trans_file.get();
            if (x=='\n')
            {
                if (temp!="")
                {
                    if (count==0) //if it's the first line set that to the name
                    {
                        name=temp;
                        temp="";
                        count++;
                    }
                    else if (count==1) //if it's the second line set that the email
                    {
                        email=temp;
                        temp="";
                        count++;
                    }
                    else if (count==2) //if it's the third line process the number of traits and create a new person profile
                    {
                        num_traits=std::stoi(temp);
                        p=new PersonProfile(name,email);
                        count++;
                        temp="";
                    }
                    else //if it's any other line in the profile we add pairs to email and add the necessary AttValPairs to p
                    {
                        if (pairs_to_email->search(temp)==nullptr)
                        {
                            std::vector<std::string> t;
                            t.push_back(email);
                            pairs_to_email->insert(temp, t);
                        }
                        else
                        {
                            pairs_to_email->search(temp)->push_back(email);
                        }
                        int index=temp.find(",");
                        AttValPair to_add;
                        to_add.attribute=temp.substr(0,index);
                        to_add.value=temp.substr(index+1,temp.size()-index-1);
                        p->AddAttValPair(to_add);
                        temp="";
                        num_trace++;
                        if (num_trace==num_traits)
                        {
                            num_traits=-1;
                            num_trace=0;
                            count=0;
                            temp="";
                            emails_to_person->insert(email, p);
                            emails.push_back(email);
                        }
                    }
                }
            }
            else
            {
                temp=temp+x;
            }
        }
    }
    else
    {
      return false;
    }
    return true;
}
std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const
{
    std::string to_search=input.attribute+","+input.value;
    //Translate the input into something the RadixTree can process
    std::vector<std::string>* it=pairs_to_email->search(to_search);
    //find that adjoining emails to that pair
    
    std::vector<std::string> empty;
    if (it==nullptr)
    {
        return empty;
    }
    //if there are no such pairs return an empty vector
    return *it;
    
}
const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const
{
    PersonProfile** p=emails_to_person->search(email);
    //find the adjoiinngi profile to that email
    if (p==nullptr)
    {
        return nullptr;
    }
    return *p;
    
}
