vector<int> permutationEquation(vector<int> v) {
    vector<int> v1(0);
    vector<int> v2(0);
    for (int key=0;key<v.size();key++)
    {
        vector<int>::iterator itr = find(v.begin(), v.end(), key+1);    
        v1.push_back((distance(v.begin(), itr))+1);
    }
    
    for (int key=0;key<v.size();key++)
    {
        vector<int>::iterator itr1 = find(v.begin(), v.end(), v1[key]);    
        v2.push_back((distance(v.begin(), itr1))+1);
    }
    return v2;
}