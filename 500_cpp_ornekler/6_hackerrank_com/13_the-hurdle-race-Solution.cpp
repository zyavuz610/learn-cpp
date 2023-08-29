int hurdleRace(int k, vector<int> height) {
    sort(height.begin(),height.end());
    if(k> height[height.size() -1]) return 0;
    else return (height[height.size() -1]-k);
}