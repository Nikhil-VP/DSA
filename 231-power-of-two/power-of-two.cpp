class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long n1 = n;
        if (n1==0) return false;
        if((n1 & n1-1) == 0) return true;
        return false;

    }
};