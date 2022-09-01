//
//  MatchMaker.hpp
//  Week2LA
//
//  Created by Adi Mehta on 3/8/22.
//

#ifndef MatchMaker_hpp
#define MatchMaker_hpp
#include "AttributeTranslator.h"
#include "MemberDatabase.h"
#include "PersonProfile.h"
#include "utility.h"
#include "provided.h"
#include <vector>
#include <unordered_map>


class MatchMaker
{
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    ~MatchMaker();
    std::vector<EmailCount> IdentifyRankedMatches(std::string email,int threshold) const;
private:
    const MemberDatabase* db;
    const AttributeTranslator* a;
    
};

#endif /* MatchMaker_hpp */
