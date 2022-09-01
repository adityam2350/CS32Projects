//
//  PersonProfile.hpp
//  Week2LA
//
//  Created by Adi Mehta on 3/8/22.
//

#ifndef PersonProfile_h
#define PersonProfile_h
#include "provided.h"
#include <string>
#include <set>
#include "RadixTree.h"

class PersonProfile
{
    public:
        PersonProfile(std::string name, std::string email);
        ~PersonProfile();
        std::string GetName() const;
        std::string GetEmail() const;
        void AddAttValPair(const AttValPair& attval);
        int GetNumAttValPairs() const;
        bool GetAttVal(int attribute_num, AttValPair& attval) const;
    private:
    
        RadixTree<std::string> m_pairs;
        std::set<std::string> m_temp;
    
    
        int m_size;
        std::string m_name;
        std::string m_email;
};

#endif /* PersonProfile_hpp */
