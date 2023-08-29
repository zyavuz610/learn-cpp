int jumpingOnClouds(vector<int> c) {
    int counter = 0;
    for(int i=0;i<c.size();i++)
    {
        if(c[i+2] == 0)
        {
            if(c.size() == 2) counter+=2;
            else counter++;
            i++;
        }
        else if(c[i+1] == 0)
        { 
            counter++;
        }
    }
    return counter-1;
}