//
//  newMap.cpp
//  CS32HW1-Pt2
//
//  Created by Adi Mehta on 1/17/22.
//

#include "newMap.h"
//
//  Map.cpp
//  CS-32HW1
//
//  Created by Adi Mehta on 1/16/22.
//
Map::Map()
{
    m_n=0;
    m_max=DEFAULT_MAX_ITEMS;
    m_map=new KeyValue[m_max];
}
Map::Map(int max)
{
    m_n=0;
    m_max=max;
    m_map=new KeyValue[m_max];
}

Map::Map(const Map &src)
{
    m_max=src.m_max;
    m_n=src.m_n;
    m_map=new KeyValue[m_max];
    for (int j=0;j<m_n;j++)
    {
        m_map[j]=src.m_map[j];
    }
}

Map& Map::operator=(const Map &src)
{
    if (&src==this)
    {
        return *this;
    }
    delete []m_map;
    m_max=src.m_max;
    m_n=src.m_n;
    m_map=new KeyValue[m_max];
    for (int j=0;j<m_n;j++)
    {
        m_map[j]=src.m_map[j];
    }
    return *this;
}

Map::~Map()
{
    delete [] m_map;
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
    if (m_n>=m_max)
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
    if (m_n>=m_max)
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
    Map temp=other;
    other=*this;
    *this=temp;
}
void Map::dump() const
{
    for (int i=0;i<m_n;i++)
    {
        std::cout<<m_map[i].key<<"----"<<m_map[i].value<<std::endl;
    }
}

