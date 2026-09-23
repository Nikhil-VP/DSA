class Solution {
public:
    void sim(vector<int>& nums,int index, vector<int>& ds,vector<vector<int>>& result){
        if(index == nums.size()){
            auto it = find(result.begin(), result.end(), ds);
            if(it == result.end())
                result.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        sim(nums, index+1, ds, result);
        ds.pop_back();
        sim(nums, index+1, ds, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
       vector<int> ds;
       sort(nums.begin(), nums.end());
       sim(nums, 0, ds, result);
       return result; 
    }
};