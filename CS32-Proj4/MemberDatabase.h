//
//  MemberDatabase.hpp
//  Week2LA
//
//  Created by Adi Mehta on 3/8/22.
//

#ifndef MemberDatabase_h
#define MemberDatabase_h
#include "provided.h"
#include "utility.h"
#include <fstream>
#include <map>
#include <vector>

#include "RadixTree.h"

class PersonProfile;
class MemberDatabase
{
public:
    MemberDatabase();
    ~MemberDatabase();
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
private:
    std::vector<std::string> emails;
    RadixTree<std::vector<std::string>>* pairs_to_email;
    RadixTree<PersonProfile*>* emails_to_person;
};
#endif /* MemberDatabase_hpp */
