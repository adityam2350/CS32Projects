//
//  MatchMaker.cpp
//  Week2LA
//
//  Created by Adi Mehta on 3/8/22.
//

#include "MatchMaker.h"
MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at)
{
    db=&mdb;
    a=&at;
}
MatchMaker::~MatchMaker()
{
}
std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email, int threshold) const
{
    const PersonProfile* p=db->GetMemberByEmail(email);
    if (threshold<1)
    {
        threshold=1;
    }
    //Check if threshold is proper value
    
    std::vector<EmailCount> emails;
    //Initialize the vector we will return
    
    std::vector<AttValPair> person_pair;
    for (int i=0;i<p->GetNumAttValPairs();i++)
    {
        AttValPair pair;
        p->GetAttVal(i, pair);
        person_pair.push_back(pair);
    }
    //Push back all the person's pairs to an vector
    
    std::set<std::string> compat_pairs_str;
    for (int i=0; i<person_pair.size();i++)
    {
        std::vector<AttValPair> comp=a->FindCompatibleAttValPairs(person_pair[i]);
    
        for (int j=0;j<comp.size();j++)
        {
            std::string pair_string=comp[j].attribute+","+comp[j].value;
            compat_pairs_str.insert(pair_string);
        }
    }
    //Insert all of the values compatiable to the member's values into a single set
    
    
    std::set<std::string>::const_iterator it_set=compat_pairs_str.begin();
    std::map<std::string, int> emails_count;
    
    while(it_set!=compat_pairs_str.end())
    {
        std::string temp=(*it_set);
        int index=temp.find(",");
        AttValPair p;
        p.attribute=temp.substr(0,index);
        p.value=temp.substr(index+1,temp.size()-index-1);
        //translate the string in compat_pairs_str to a AttValPair
        
        std::vector<std::string>temp_emails=db->FindMatchingMembers(p);
        
        //Add the emails and their count to a map from strings to ints
        for (int i=0; i<temp_emails.size();i++)
        {
            if (emails_count.find(temp_emails[i])==emails_count.end() && temp_emails[i]!=email)
            {
                emails_count[temp_emails[i]]=1;
            }
            else if (temp_emails[i]!=email)
            {
                emails_count[temp_emails[i]]++;
            }
        }
        it_set++;
    }
    
    std::map<std::string,int>::const_iterator it_email=emails_count.begin();
    it_email=emails_count.begin();
    std::set<EmailCount> emails_to_copy;
    //copy these to a set of EmailCounts
    while(it_email!=emails_count.end())
    {
        if (it_email->second >= threshold)
        {
            EmailCount ec(it_email->first,it_email->second);
            emails_to_copy.insert(ec);
        }
        it_email++;
    }
    //copy that set to a vector of Email counts and voila!
    std::set<EmailCount>::const_iterator it_final=emails_to_copy.begin();
    while (it_final!=emails_to_copy.end())
    {
        emails.push_back(*it_final);
        it_final++;
    }
    return emails;
}
