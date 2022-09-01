//
//  Map.cpp
//  CS-32HW1
//
//  Created by Adi Mehta on 1/16/22.
//

#include "Map.h"
Map::Map()
{
    m_n=0;
}
bool Map::empty() const
{
    return m_n==0;
}
int Map::size() const
{
    return m_n;
}
bool Map::insert(const KeyType &key, const ValueType &value)
{
    if (m_n>=DEFAULT_MAX_ITEMS)
    {
        return false;
    }
    for (int i=0;i<m_n;i++)
    {
        if (m_map[i].key==key)
        {
            return false;
        }
    }
    m_map[m_n].key=key;
    m_map[m_n].value=value;
    m_n++;
    return true;
}
bool Map::update(const KeyType &key, const ValueType &value)
{
    for (int i=0;i<m_n;i++)
    {
        if (m_map[i].key==key)
        {
            m_map[i].value=value;
            return true;
        }
    }
    return false;
}
bool Map::insertOrUpdate(const KeyType &key, const ValueType &value)
{
    for (int i=0;i<m_n;i++)
    {
        if (m_map[i].key==key)
        {
            m_map[i].value=value;
            return true;
        }
    }
    if (m_n>=DEFAULT_MAX_ITEMS)
    {
        return false;
    }
    else
    {
        m_map[m_n].key=key;
        m_map[m_n].value=value;
        m_n++;
        return true;
    }
}
bool Map::erase(const KeyType &key)
{
    for (int i=0;i<m_n;i++)
    {
        if (m_map[i].key==key)
        {
            for (int j=i;j<m_n-1;j++)
            {
                m_map[j]=m_map[j+1];
            }
            m_n=m_n-1;
            return true;
        }
    }
    return false;
}
bool Map::contains(const KeyType &key) const
{
    for (int i=0;i<m_n;i++)
    {
        if (m_map[i].key==key)
        {
            return true;
        }
    }
    return false;
}
bool Map::get(const KeyType& key, ValueType& value) const
{
    for (int i=0;i<m_n;i++)
    {
        if (m_map[i].key==key)
        {
            value=m_map[i].value;
            return true;
        }
    }
    return false;
}
bool Map::get(int i, KeyType& key, ValueType& value) const
{
    if (i<0||i>=size())
    {
        return false;
    }
    int count=0;
    
    for (int r=0; r<m_n;r++)
    {
        count=0;
        for (int j=0;j<m_n;j++)
        {
            if (m_map[r].key>m_map[j].key)
            {
                count++;
            }
        }
        if (count==i)
        {
            key=m_map[r].key;
            value=m_map[r].value;
            return true;
        }
    }
    return false;
}
void Map::swap(Map &other)
{
    KeyValue temp;
    int size_temp;
     if (size()>=other.size())
     {
         for (int i=0; i<size(); i++)
         {
             temp=other.m_map[i];
             
             other.m_map[i]=m_map[i];
             
             m_map[i]=temp;
         }
         size_temp=m_n;
         other.m_n=size_temp;
         m_n=other.m_n;
     }
    else
    {
        for (int i=0; i<other.size(); i++)
        {
            temp=other.m_map[i];
            
            other.m_map[i]=m_map[i];
            
            m_map[i]=temp;
            
        }
        size_temp=m_n;
        other.m_n=size_temp;
        m_n=other.m_n;
    }
}
void Map::dump() const
{
    for (int i=0;i<m_n;i++)
    {
        std::cout<<m_map[i].key<<"----"<<m_map[i].value<<std::endl;
    }
}
