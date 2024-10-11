string encryption(string s) {
    int a,b,c;
    float d;
    a = s.length();
    d = pow(a, 0.5);
    b = d;
    if(b*(b+1)<a)
    {
        c = b+1;
        b+=1; 
    } 
    else
    {
        c = b+1;
    }
    if(d-(int)d == 0) c--;
    string s2[c];
    string s3;
    for(int i=0;i<c;i++)
    {
        for(int k=0,j=0;k<b;k++,j+=c)
        {
            if(s[i+j] != '\0') s2[i] += s[i+j];
        }
    s3 += s2[i] + " "; 
    }
    return s3;
}