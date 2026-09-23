class Solution {
public:
    void sim(vector<int>& nums,int index, vector<int>& ds,vector<vector<int>>& result, int sum ,int target, int k){
        if(index == nums.size()){
            
            if(ds.size()==k && sum == target)
                result.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        sim(nums, index+1, ds, result, sum+nums[index], target, k);
        ds.pop_back();
        sim(nums, index+1, ds, result, sum, target, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
       vector<int> ds;
       vector<int> nums = {1,2,3,4,5,6,7,8,9};
       sim(nums, 0, ds, result, 0, n, k);
       return result; 
    }
};