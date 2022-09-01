//
//  CarMap.cpp
//  CS-32HWPt3
//
//  Created by Adi Mehta on 1/18/22.
//

#include "CarMap.h"


CarMap::CarMap()
{
    
}
bool CarMap::addCar(std::string license)
{
    return m_fleet.insert(license, 0);
    
}
double CarMap::miles(std::string license) const
{
    double miles;
    bool in=m_fleet.get(license, miles);
    if(in)
    {
        return miles;
    }
    else
    {
        return -1;
    }
}
int CarMap::fleetSize() const
{
    return m_fleet.size();
}
bool CarMap::drive(std::string license, double distance)
{
    double m=distance+miles(license);
    return m_fleet.update(license, m);
    
}

void CarMap::print() const
{
    for (int i=0; i<fleetSize();i++)
    {
        std::string lic="error";
        double mil=0.0;
        
        m_fleet.get(i, lic, mil);
        
        std::cout<<lic<<" "<<mil<<std::endl;
    }
}
