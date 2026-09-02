class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        long long curr = lower;
        for(int num:nums){
            if(num < lower) continue;
            if(num > upper) break;
            if(num > curr){
                ans.push_back({(int)curr,num - 1});
            }
            curr =(long long)num+1;
        }
        if(curr <= upper){
            ans.push_back({(int)curr,upper});
        }
        return ans;
    }
};