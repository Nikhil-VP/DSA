class Solution {
public:

    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*n + n;
        int temp;
        while(sumOdd !=0){
            temp = sumOdd;
            sumOdd = sumEven % sumOdd;
            sumEven = temp;
        }
        return sumEven;
    }
};