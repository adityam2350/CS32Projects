
  // Remove the movies in li with a rating below 50 and destroy them.
  // It is acceptable if the order of the remaining movies is not
  // the same as in the original list.
void removeBad(vector<Movie*>& v)
{
    
    vector<Movie*>::iterator temp;
    vector<Movie*>::iterator it;
    
    it=v.begin();
    
    while (it!=v.end())
    {
        if ((*it)->rating()<50)
        {
            temp=it;
            delete (*temp);
            v.erase(temp);
            it--;
        }
        it++;
    }
}
