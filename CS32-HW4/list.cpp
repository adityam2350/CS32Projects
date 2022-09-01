void listAll(string path, const Class* c)  // two-parameter overload
{
    int size=c->subclasses().size();
    
    if (size==0)
    {
        cout<<path+c->name()<<endl;
        return;
    }
    if (path=="")
    {
        cout<<c->name()<<endl;
    }
    for (int i=0; i!=size;i++)
    {
        string s= path+c->name()+"=>";
        listAll(s,c->subclasses()[i]);
    }
}
