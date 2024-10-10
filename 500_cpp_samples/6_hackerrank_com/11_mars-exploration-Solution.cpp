int marsExploration(string s) {
    int counter=0;
    for (int i=0;i<s.length();i+=3)
    {
        if(s.substr(i,1) != "S") counter++;
        if (s.substr(i+1,1) != "O") counter++;
        if (s.substr(i+2,1) != "S") counter++;
    }
    return counter;
}