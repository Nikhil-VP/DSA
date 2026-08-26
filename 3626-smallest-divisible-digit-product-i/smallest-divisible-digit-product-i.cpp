class Solution {
public:
    int sd(int n){
        int rem {0},sum {1};
        while(n!=0){
        rem = n % 10;
        sum = sum * rem;
        n = n/10;
        }
        return sum;
    }
    int smallestNumber(int n, int t) {
        while(true){
        int result = sd(n);
        if(result % t == 0)
            return n;
        else
            n+=1;
        }
    }
};