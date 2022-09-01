//
//  main.cpp
//  CS32-HW2
//
//  Created by Adi Mehta on 1/27/22.
//

#include <iostream>
#include <stack>
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
    stack<Coord> MazeStack;
    Coord cur=Coord(sr,sc);
    maze[sr].at(sc)='#';
    MazeStack.push(cur);
    
    int curr=-1;
    int curc=-1;
    
    while(!MazeStack.empty())
    {
        curr=MazeStack.top().r();
        curc=MazeStack.top().c();

        MazeStack.pop();
        
        if (curr==er&&curc==ec)
        {
            return true;
        }
        if (maze[curr].at(curc-1)!='X' && maze[curr].at(curc-1)!='#')
        {
            maze[curr].at(curc-1)='#';
            cur=Coord(curr,curc-1);
            MazeStack.push(cur);
        }
        
        if (maze[curr+1].at(curc)!='X' && maze[curr+1].at(curc)!='#')
        {
            maze[curr+1].at(curc)='#';
            cur=Coord(curr+1,curc);
            MazeStack.push(cur);
        }
        if (maze[curr].at(curc+1)!='X' && maze[curr].at(curc+1)!='#')
        {
            maze[curr].at(curc+1)='#';
            cur=Coord(curr,curc+1);
            MazeStack.push(cur);
        }
        if (maze[curr-1].at(curc)!='X' && maze[curr-1].at(curc)!='#')
        {
            maze[curr-1].at(curc)='#';
            cur=Coord(curr-1,curc);
            MazeStack.push(cur);
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
    string maze[10] = {
                "XXXXXXXXXX",
                "X.X..X...X",
                "X....XXX.X",
                "X.XXXX.X.X",
                "X......XXX",
                "X.XX.X...X",
                "X.X..X.X.X",
                "X.X.XXXX.X",
                "X.X...X..X",
                "XXXXXXXXXX"
            };
        
            if (pathExists(maze, 10,10, 4,6, 1,1))
                cout << "Solvable!" << endl;
            else
                cout << "Out of luck!" << endl;

}
