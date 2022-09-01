#include "AttributeTranslator.h"
AttributeTranslator::AttributeTranslator()
{
    //std::cout<<"AT Constructed"<<std::endl;
}
AttributeTranslator::~AttributeTranslator()
{
}
bool AttributeTranslator::Load(std::string filename)
{
    std::ifstream trans_file(filename);
    char x;
    
    if (trans_file.is_open())
    {
        std::string temp="";
        int comma_count=0;
        std::string pair2;
        std::string pair1;
        while (trans_file.good())
        {
            x=trans_file.get();
            if (x=='\n')
            {
                if(temp!="")
                {
                    comma_count=0;
                    pair2=temp; //set the remaining value of temp to pair2 once we hit a new line
                    temp="";
                    //if pair1 is not in the add the set that will hold all of its compatible pairs
                    if (m_pairs.search(pair1)==nullptr)
                    {
                        std::set<std::string> temp;
                        temp.insert(pair2);
                        m_pairs.insert(pair1, temp);
                    }
                    else //else just add the other pair to the vector of pair1's compatible pairs
                    {
                        m_pairs.search(pair1)->insert(pair2);
                    }
                }
            }
            else if (x==',')
            {
               if (comma_count==0) //If we in encounter one comma while traversing through the array we just add it
               {
                   temp=temp+x;
                   comma_count++;
               }
               else if (comma_count==1) //if we encounter a second comma we know that is our first pair
               {
                   pair1=temp;
                   temp="";
                   comma_count=0;
                   
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
std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const
{
    std::string input=source.attribute+","+source.value;
    //create an input that our radix tree can read
    std::set<std::string>* it=m_pairs.search(input);
    //get the set that correlates to that certain input
    std::vector<AttValPair> pairs_to_return;
    if (it==nullptr) //if there is no compatible paris just return an empty vector LOLZ
    {
        return pairs_to_return;
    }
    else
    {
        std::set<std::string>::const_iterator it_set=it->begin();
        
        //Translate the values within the set to a vector of AttValPairs that we can return
        while(it_set!=it->end())
        {
            std::string temp=(*it_set);
            int index=temp.find(",");
            AttValPair p;
            p.attribute=temp.substr(0,index);
            p.value=temp.substr(index+1,temp.size()-index-1);
            pairs_to_return.push_back(p);
            it_set++;
        }
    }
   

    return pairs_to_return;
}

