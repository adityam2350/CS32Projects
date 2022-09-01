//
//  Radix.h
//  Proj4-Acc
//
//  Created by Adi Mehta on 3/14/22.
//

#ifndef Radix_h
#define Radix_h
#include <string>
#include <list>
using namespace std;
template <typename ValueType>
class RadixTree
{
public:
    RadixTree();
    ~RadixTree();
    void insert(std::string key, const ValueType& value);
    ValueType* search(std::string key) const;
    
    private:
        struct Node;
        struct Edge;
        int getPos(char l) const
        {
            return l-'\0';
            //gets the position of a possible element in an array
        }
        struct Node
        {
            ValueType* isEnd=nullptr;
            Edge* edges[128]={};
        };
        struct Edge
        {
            std::string label;
            Node* next;
            
        };
    void destruct(Node* node, Edge* edge)
    {
        if (node==nullptr)
        {
            destruct(edge->next, nullptr);
            delete edge;
            
        }
        else
        {
            for (int i=0;i<128;i++)
            {
                if (node->edges[i]!=nullptr)
                {
                    destruct(nullptr,node->edges[i]);
                }
            }
            delete node;
        }
    }
    std::list<ValueType> container;
    Node* root;
};
template <typename ValueType>
RadixTree<ValueType>::RadixTree()
{
    root=new Node;
    root->isEnd=nullptr;
    //std::cout<<"RadixTree Constructed"<<std::endl;
}

template<typename ValueType>
RadixTree<ValueType>::~RadixTree()
{
    destruct(root,nullptr);
    //std::cout<<"RadixTree Destructed"<<std::endl;
}


template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key,const ValueType& value)
{
    //We add the value to our list of ValueTypes for easy access to the address
    container.push_front(value);
    ValueType* address=&(*container.begin());
    
    
    Node* curr=root;
    int i=0;
    while(i<key.size())
    {
        char currChar=key[i];
        std::string currString=key.substr(i,key.size()-i);
        
        Edge* currEdge=curr->edges[getPos(currChar)];
        
        //There is no associated edge with the first letter of the word so we add it
        if (currEdge==nullptr)
        {
            Edge* nextEdge=new Edge;
            nextEdge->label=currString;
            
            Node* r=new Node;
            r->isEnd=address;
            
            nextEdge->next=r;
            curr->edges[getPos(currChar)]=nextEdge;
            break;
        }
        int locOfDiff=-1;
    
        int it=0;
        while (it!=currEdge->label.size()&&it!=currString.size())
        {
            if (currEdge->label[it]!=currString[it])
            {
                locOfDiff=it;
                break;
            }
            it++;
        }
        //Finds the location of a difference and returns -1 if up to the end of the strings there is no difference
        if (locOfDiff==-1)
        {
            //if the currentString is the seame as the edge just decleare its next node with the address of value
            if (currString.size()==currEdge->label.size())
            {
                currEdge->next->isEnd=address;
                break;
            }
            else if (currString.size()<currEdge->label.size()) //if the we are adding "slow" while slower exists this is what we do
            {
                int remSize=currEdge->label.size()-currString.size();
                std::string overhang= currEdge->label.substr(currString.size(),remSize);
                currEdge->label=currString;
        
                //find the extra letters on the current edges label
                
                Node* n=currEdge->next;
                n->isEnd=currEdge->next->isEnd;
                //Set n to the next node on the current edge (in this case it would be a node with no edges that holds the value type v)
                
                Edge* e=new Edge;
                e->label=overhang;
                e->next=n;
                
                //we create a new edge with the label l
                
                Node* p=new Node;
                p->isEnd=address;
                p->edges[getPos(overhang[0])]=e;
                //we create a new node P with an edge pointing to the first letter of the over hang
                currEdge->next=p;
                //you set this as the new n.
                break;
            }
            else
            {
                locOfDiff=currEdge->label.size();
            }
        }
        else
        {
            //We create a new edge with the overhang and change the label on the previous one
            int remSize=currEdge->label.size()-locOfDiff;
            std::string overhang=currEdge->label.substr(locOfDiff,remSize);
            currEdge->label=currEdge->label.substr(0,locOfDiff);
            
            Node* n=currEdge->next;
            
            Edge* e=new Edge;
            e->label= overhang;
            e->next=n;
            
            Node* p=new Node;
            p->edges[getPos(overhang[0])]=e;
            currEdge->next=p;
        }
        //iterate through to the next location of difference on operate throught here
        curr=currEdge->next;
        i=i+locOfDiff;
    }
}
template<typename ValueType>
ValueType* RadixTree<ValueType>::search(std::string key) const
{
    Node* current=root;
    int i=0;
    while (i<key.size())
    {
        char currChar=key[i];
        Edge* currEdge=current->edges[getPos(currChar)];
        //if there is no edge return nullptr
        if (currEdge==nullptr)
        {
            return nullptr;
        }
        std::string currString=key.substr(i,key.size()-i);
        int isIn=currString.find(currEdge->label);
        //if the current string doesn't start with the null ptr return
        if (isIn!=0)
        {
            return nullptr;
        }
        i=i+currEdge->label.size();
        current=currEdge->next;
        //keep iterating
    }
    return current->isEnd;
}

#endif /* Radix_h */

