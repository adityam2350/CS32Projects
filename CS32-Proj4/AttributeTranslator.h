//
//  AttributeTranslator.hpp
//  Week2LA
//
//  Created by Adi Mehta on 3/8/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h
#include "provided.h"
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include "RadixTree.h"

class AttributeTranslator
{
    public:
    AttributeTranslator();
    ~AttributeTranslator();
    bool Load(std::string filename);
    std::vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
    
    private:
    RadixTree<std::set<std::string>> m_pairs;
};

#endif /* AttributeTranslator_hpp */
