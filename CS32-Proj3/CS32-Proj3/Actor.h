//
//  Actor.cpp
//  CS32-Proj3
//
//  Created by Adi Mehta on 2/15/22.
//
#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class Actor: public GraphObject
{
    public:
        Actor(int imageID, int startX, int startY, int startDirection);
        virtual ~Actor();
        virtual void doSomething()=0;
        bool getIfAlive();
        void killActor();
        virtual void getBonked()=0;
        int getHitPoints();
        void Harm();
    private:
        bool is_alive;
        int hit_points;
};
class Peach: public Actor
{
public:
    Peach(int imageID, int startX, int startY, int startDirection);
    virtual ~Peach();
    virtual void doSomething();
    virtual void getBonked()=0;
private:
    bool is_alive;
    int hit_points

}

#endif // ACTOR_H_
