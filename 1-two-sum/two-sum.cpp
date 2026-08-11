class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;int req;
        vector<int> arr(2);
        for(i=0;i < nums.size();i++)
        {
            req = target - nums[i];
            for(j=i+1; j<nums.size();j++)
            {
                if(req == nums[j])
                {
                    arr[0] = i;
                    arr[1] = j;
                }
            }
        }
        return arr;
    }
};