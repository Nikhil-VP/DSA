class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int xxor =0;
        for(int n:nums){
            xxor = xxor ^ n;
        }

        return xxor;
    }
};