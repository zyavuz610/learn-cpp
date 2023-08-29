vector<int> gradingStudents(vector<int> grades) {
    vector<int> x(0);
    for(int i=0;i<grades.size();i++)
    {
        if((grades[i]+1) % 5 == 0 && grades[i] >= 38)
        {
            x.push_back(grades[i]+1);
        }
        else if((grades[i]+2) % 5 == 0 && grades[i] >= 38)
        {
          x.push_back(grades[i]+2);  
        }
        else{
            x.push_back(grades[i]);
        }
    }
    return x;
}