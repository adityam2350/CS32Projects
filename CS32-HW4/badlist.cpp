

  // Remove the movies in li with a rating below 50 and destroy them.
  // It is acceptable if the order of the remaining movies is not
  // the same as in the original list.
void removeBad(list<Movie*>& li)
{
    
    list<Movie*>::iterator temp;
    list<Movie*>::iterator it;
    
    it=li.begin();
    
    while (it!=li.end())
    {
        if ((*it)->rating()<50)
        {
            temp=it;
            delete (*temp);
            li.erase(temp);
            it--;
        }
        it++;
    }
}
