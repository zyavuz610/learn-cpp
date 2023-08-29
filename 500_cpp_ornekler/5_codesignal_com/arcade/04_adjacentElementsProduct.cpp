/*
  Komşu 2 elemanın çarpımlarının maksimumu
Original Text:
For inputArray = [3, 6, -2, -5, 7, 3], the output should be
adjacentElementsProduct(inputArray) = 21.

7 and 3 produce the largest product.


*/
int adjacentElementsProduct(std::vector<int> inputArray) {
    int mx = -2000000,p;
    for (int i = 1; i < inputArray.size(); i++){
        p = inputArray[i] * inputArray[i - 1];
        if(p>mx) mx = p;
    }
    return mx;
}
