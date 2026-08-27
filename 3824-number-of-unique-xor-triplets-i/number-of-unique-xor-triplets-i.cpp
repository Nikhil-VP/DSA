class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==2 || n==1) return n;
        int msb = log2(n);
        return 1<<(msb+1);
    }
};