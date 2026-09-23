class Solution {
public:
    void sim(vector<int>& nums,int index, vector<int>& ds,vector<vector<int>>& result){
        if(index == nums.size()){
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        sim(nums, index+1, ds, result);
        ds.pop_back();
        sim(nums, index+1, ds, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
       vector<int> ds;
       sort(nums.begin(), nums.end());
       sim(nums, 0, ds, result);
       return result; 
    }
};