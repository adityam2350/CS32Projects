#include "newMap.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;


int main()
{
    Map m;
    assert(m.empty());
    ValueType v = -1234.5;
    
    assert( !m.get("abc", v)  &&  v == -1234.5);
    
    m.insert("xyz", 9876.5);
    m.insert("Rusillo", 89.2);
    m.insert("KOC", 43.23);
    m.insert("Simmons", 923.13);
    assert(m.size() == 4);
    
    KeyType k = "hello";
    
    assert(m.get(3, k, v) && k=="xyz" && v==9876.5);
    assert(m.get(0, k, v) && k=="KOC" && v==43.23);
    
    Map r;
    r.insert("Steve Nash", 13.05);
    r.insert("Jason Kidd", 32.01);
    r.insert("Kevin Johnson", 7.94);
    r.insertOrUpdate("Kevin Johnson", 7.96);
    r.insertOrUpdate("Chris Paul", 3.21);
    
    r.swap(m);
    
    assert(r.contains("Rusillo")&&r.contains("KOC"));
    assert(m.contains("Steve Nash")&&m.contains("Jason Kidd"));
    
    
    assert((!m.erase("Eric Bledsoe")) && m.erase("Jason Kidd") && m.size()==3&& (!m.contains("Jason Kidd")));
    
    
    cerr<<"Hello we got it Baby!"<<endl;
}
