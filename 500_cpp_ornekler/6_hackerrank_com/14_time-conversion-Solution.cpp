string timeConversion(string s) {
    string s1,s2;
    s1 = s.substr(8,2);
    s2 = s.substr(0,2);
    if(s1 == "PM")
    {
        stringstream a(s2);
        int x = 0;
        a >> x;
        x+= 12;
        ostringstream y;
        y << x;
        string s3 = y.str();
        s[0] = s3[0];
        s[1] = s3[1];
        string s5 = "12";
        if(x==24)
            {
                s[0] = s5[0];
                s[1] = s5[1];
            }
    }
    if(s1 == "AM" && s2 == "12")
    {
       string s6 = "00";
       s[0] = s6[0];
       s[1] = s6[1];
    }
    string s4 = s.substr(0,8);
    return s4;
}