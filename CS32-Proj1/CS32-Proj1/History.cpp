//
//  History.cpp
//  CS32-Proj1
//
//  Created by Adi Mehta on 1/10/22.
//

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
    m_rows=nRows;
    m_cols=nCols;
    for (int r=0;r<m_rows;r++)
    {
        for (int c=0;c<m_cols;c++)
        {
            m_sheet[r][c]=0;
        }
    }
}
bool History::record(int r, int c)
{

    if (r < 1  ||  r > m_rows  ||  c < 1  ||  c > m_cols)
    {
        return false;
    }
    else
    {
        m_sheet[r-1][c-1]++;
        return true;
    }
}
void History::display() const
{
    clearScreen();
    char label;
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
        {
            
            if (m_sheet[r][c]!=0&&m_sheet[r][c]<26)
            {
                label='A'+(m_sheet[r][c]-1);
                cout<<label;
            }
            else if(m_sheet[r][c]>=26)
            {
                cout<<'Z';
            }
            else
            {
                cout<<'.';
            }
        }
        cout<<endl;
    }
    cout<<"Press enter to continue";
    cin.ignore(10000,'\n');

}
