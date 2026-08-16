class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());// if no sort O(n)
        int n = nums.size();
        long long maxpro = 0;
        if(nums[n-1] < 0 && nums[n-2] < 0 )
        {
           maxpro = max(nums[n-1] * nums[n-2] * nums[0], nums[2] * nums[1] * nums[0]);

        }
        else{
            maxpro =nums[2] * nums[1] * nums[0] ;
        }

        return maxpro;
    }
};