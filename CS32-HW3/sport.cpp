//
//  main.cpp
//  P1-HW3-CS32
//
//  Created by Adi Mehta on 2/5/22.
//
class Sport
{
public:
    virtual string icon() const=0;
    string name() const;
    bool isOutdoor() const;
    Sport(string name);
    virtual ~Sport();
private:
    string m_name;
};
Sport::Sport(string name)
{
    m_name=name;
}
bool Sport::isOutdoor() const
{
    return m_name[0]=='T';
}
string Sport::name() const
{
    if(m_name.size()==1)
        return "";
    return m_name.substr(1,m_name.size()-1);
}
Sport::~Sport()
{
    
}
//****************************
//SNOWBOARDING IMPLEMENTATION
//****************************
class Snowboarding : public Sport
{
public:
    virtual string icon() const;
    Snowboarding(string name);
    virtual ~Snowboarding();
private:
};
Snowboarding::Snowboarding(string name):Sport("T"+name)
{
}
Snowboarding::~Snowboarding()
{
    std::cout<<"Destroying the Snowboarding object named "<<name()<<"."<<std::endl;
}
string Snowboarding::icon() const
{
    return "descending snowboarder";
}
//****************************
//BIATHALON IMPLEMENTATION
//****************************
class Biathlon:public Sport
{
public:
    virtual string icon() const;
    Biathlon(string name, double distance);
    virtual ~Biathlon();
private:
    double m_distance;
};
Biathlon::Biathlon(string name, double distance):Sport("T"+name)
{
    m_distance=distance;
}
Biathlon::~Biathlon()
{
    std::cout<<"Destroying the Biathlon object named "<<name()<<", distance "<<m_distance<<" km."<<std::endl;
}
string Biathlon::icon() const
{
    return "a skier with a rifle";
}
//****************************
//FigureSkating IMPLEMENTATION
//****************************
class FigureSkating:public Sport
{
public:
    virtual string icon() const;
   FigureSkating(string name);
    virtual ~FigureSkating();
};
FigureSkating::FigureSkating(string name):Sport("F"+name)
{
}
FigureSkating::~FigureSkating()
{
    std::cout<<"Destroying the FigureSkating object named "<<name()<<"."<<std::endl;
}
string FigureSkating::icon() const
{
    return "a skater in the Biellmann position";
}
//END OF IMPLIMENTATIONS

