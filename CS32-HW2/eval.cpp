//
//  main.cpp
//  CS32-HW2Eval
//
//  Created by Adi Mehta on 1/31/22.
//

#include "Map.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

int CheckPrec(char c)
{
    if (c=='/'||c=='*')
    {
        return 2;
    }
    else if (c=='+'||c=='-')
    {
        return 1;
    }
    return 0;
}

int evaluate(string infix, const Map& values, string& postfix, int& result)
  {
    bool not_in_map=false;
    //for loop that checks the viabilty of the string
    for (int i=0; i!=infix.size();i++)
    {
        if(CheckPrec(infix.at(i))||infix.at(i)=='('||infix.at(i)==')'||infix.at(i)==' ')
        {
            continue;
        }

        if(isupper(infix.at(i))||ispunct(infix.at(i))||isdigit(infix.at(i)))
        {
            return 1;
        }
        if(islower(infix.at(i))&&!values.contains(infix.at(i)))
        {
            not_in_map=true;
        }
    }
    
    int parent=0;
    int op_count=0;
    int dig_count=0;
    bool was_sparent=false;
    bool was_eparent=false;
    
    for (int i=0; i!=infix.size();i++)
    {
        if(infix.at(i)=='(')
        {
            if (was_eparent)
            {
                return 1;
            }
            parent--;
            was_sparent=true;
        }
        if(infix.at(i)==')')
        {
            if (was_sparent)
            {
                return 1;
            }
            parent++;
            was_eparent=true;
        }
        if(islower(infix.at(i)))
        {
            if(dig_count>=1)
            {
                return 1;
            }
            dig_count++;
            op_count=0;
            was_eparent=false;
            was_sparent=false;
        }
        else if(CheckPrec(infix.at(i))!=0)
        {
            if(op_count>=1||dig_count==0||was_sparent)
            {
                return 1;
            }
            op_count++;
            dig_count=0;
            was_eparent=false;
            was_sparent=false;
        }
    }
    if(parent!=0||dig_count==0||op_count>=1)
    {
        return 1;
    }
    
    
    
    string pf="";
    stack<char>ops;
    
    for (int i=0; i!=infix.size();i++)
    {
        char ch=infix.at(i);
        
        if (ch=='(')
        {
            ops.push(ch);
        }
        else if (ch==')')
        {
            while(ops.top()!='(')
            {
                pf=pf+ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else if(isalpha(ch))
        {
            pf=pf+ch;
        }
        else if(CheckPrec(ch)!=0)
        {
            while(!ops.empty()  &&   CheckPrec(ch)<=CheckPrec(ops.top())  &&  ops.top()!='(')
            {
                pf=pf+ops.top();
                ops.pop();
            }
            ops.push(ch);
        }
            
    }
    while (!ops.empty())
    {
        pf=pf+ops.top();
        ops.pop();
    }
    
    postfix=pf;

    
    if (not_in_map)
    {
        return 2;
    }
    
    stack<int>clack;
    int num;
    for (int i=0; i!=pf.size();i++)
    {
        char c=pf[i];
        if (CheckPrec(c)==0)
        {
            int to_push;
            values.get(c, to_push);
            
            clack.push(to_push);
        }
        else
        {
            int op2=clack.top();
            clack.pop();

            int op1=clack.top();
            clack.pop();

            
            switch (c)
            {
                case '+':
                    num=op1+op2;
                    break;
                case '-':
                    num=op1-op2;
                    break;
                case '*':
                    num=op1*op2;
                    break;
                case '/':
                    if (op2==0)
                    {
                        return 3;
                    }

                    num=op1/op2;
                    break;
            }
            clack.push(num);
        }
    }
    result=clack.top();
    return 0;
    
    
  }



int main()
{
    char vars[] = { 'a', 'e', 'i', 'o', 'u', 'y', '#' };
    int  vals[] = {  3,  -9,   6,   2,   4,   1  };
    Map m;
    for (int k = 0; vars[k] != '#'; k++)
        m.insert(vars[k], vals[k]);
    string pf;
    int answer;
    answer = 999;
    
    assert(evaluate("a+ e", m, pf, answer) == 0  && pf == "ae+"  &&  answer == -6);
    answer = 999;
    assert(evaluate("", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a+", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a i", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("ai", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("()", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("()o", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("y(o+u)", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("y(*o)", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a+E", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("(a+(i-o)", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("-a", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a*b", m, pf, answer) == 2  && pf == "ab*"  &&  answer == 999);
    assert(evaluate("y +o *(   a-u)  ", m, pf, answer) == 0  && pf == "yoau-*+"  &&  answer == -1);
    answer = 999;
    assert(evaluate("o/(y-y)", m, pf, answer) == 3  && pf == "oyy-/"  &&  answer == 999);
    assert(evaluate(" a  ", m, pf, answer) == 0  && pf == "a"  &&  answer == 3);
    assert(evaluate("((a))", m, pf, answer) == 0  && pf == "a"  &&  answer == 3);
    cerr<<"nice man"<< endl;
}
