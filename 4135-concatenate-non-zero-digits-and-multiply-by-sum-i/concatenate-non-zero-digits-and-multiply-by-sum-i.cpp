class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        long long num1=0;
        long long rem;
        while(n != 0){
            rem = n%10;
            sum = sum + rem;
            if(rem != 0){
                num = num*10 + rem;
            }
            n = n/10;

        }
        while(num != 0){
            rem = num%10;
            num1 = num1*10 + rem;
            num = num/10;

        }
        return sum*num1;
    }
};