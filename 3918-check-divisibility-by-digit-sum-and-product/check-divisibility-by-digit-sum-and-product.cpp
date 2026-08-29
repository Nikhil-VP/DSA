class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int rem;
        int sum{0},pro{1};
        while(n!=0){
            rem =n % 10;
            sum = sum+rem;
            pro = pro*rem;
            n = n/10;
        }
        if(num % (sum+pro) == 0)
        return true;
        else
        return false;
    }
};