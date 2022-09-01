//
//  main.cpp
//  CS32-HW2
//
//  Created by Adi Mehta on 1/27/22.
//

#include <iostream>
#include <queue>
using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    queue<Coord> MazeQueue;
    Coord cur=Coord(sr,sc);
    maze[sr].at(sc)='#';
    MazeQueue.push(cur);
    
    int curr=-1;
    int curc=-1;
    
    while(!MazeQueue.empty())
    {
        curr=MazeQueue.front().r();
        curc=MazeQueue.front().c();
        MazeQueue.pop();
        
        if (curr==er&&curc==ec)
        {
            return true;
        }
        if (maze[curr].at(curc-1)!='X' && maze[curr].at(curc-1)!='#')
        {
            maze[curr].at(curc-1)='#';
            cur=Coord(curr,curc-1);
            MazeQueue.push(cur);
        }
        
        if (maze[curr+1].at(curc)!='X' && maze[curr+1].at(curc)!='#')
        {
            maze[curr+1].at(curc)='#';
            cur=Coord(curr+1,curc);
            MazeQueue.push(cur);
        }
        if (maze[curr].at(curc+1)!='X' && maze[curr].at(curc+1)!='#')
        {
            maze[curr].at(curc+1)='#';
            cur=Coord(curr,curc+1);
            MazeQueue.push(cur);
        }
        if (maze[curr-1].at(curc)!='X' && maze[curr-1].at(curc)!='#')
        {
            maze[curr-1].at(curc)='#';
            cur=Coord(curr-1,curc);
            MazeQueue.push(cur);
        }

        
    }
    if (curr==er&&curc==ec)
    {
        return true;
    }
    return false;
    
}

int main()
{
}
