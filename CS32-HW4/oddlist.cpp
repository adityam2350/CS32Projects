
void removeOdd(list<int>& li)
{
    list<int>::iterator temp;
    list<int>::iterator it;
    it=li.begin();
    
    while (it!=li.end())
    {
        if ((*it)%2==1)
        {
            temp=it;
            li.erase(temp);
            it--;
        }
        it++;
    }
}
