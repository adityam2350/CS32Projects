//
//  main.cpp
//  CS-32HWPt3
//
//  Created by Adi Mehta on 1/18/22.
//

#include "CarMap.h"
 #include <iostream>
 #include <cassert>
 using namespace std;

int main()
{
    CarMap g;
    
    assert(g.addCar("123BCD")&&g.addCar("OUI623")&&g.addCar("PMV761"));
    assert(g.addCar("123BCD")==false);
    
    assert(g.drive("123BCD", 47.8)&&(!g.drive("MNB123", 45))&&g.drive("OUI623", 23.4)&&g.drive("OUI623", 234.2));
    
    assert(g.miles("123BCD")==47.8&&g.miles("MNB123")==-1);
    
    assert(g.fleetSize()==3);
    
    
    cerr<<"all test succeeded"<<endl;
}
