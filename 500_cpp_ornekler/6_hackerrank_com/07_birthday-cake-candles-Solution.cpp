int birthdayCakeCandles(vector<int> ar) {
    sort(ar.begin(),ar.end());
    int counter = 0;
    int y = ar.size();
    int x = ar[y-1];
    for(int i=y-1;i>=0;i--)
        {
            if(ar[i] == x) counter++;
        }
        return counter;
}