
void removeOdd(vector<int>& v)
{
    vector<int>::iterator temp;
    vector<int>::iterator it;
    it=v.begin();
    
    while (it!=v.end())
    {
        if ((*it)%2==1)
        {
            temp=it;
            v.erase(temp);
            it--;
        }
        it++;
    }
}
