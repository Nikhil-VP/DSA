class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> unique;
        vector<int> result;
        sort(nums.begin(),nums.end());
        int minnum = nums[0];
        int maxnum = nums[nums.size()-1];
        for(int i=0;i < nums.size();i++){
            unique.insert(nums[i]);
        }
        for(int i = minnum+1;i < maxnum; i++)
        {
            if(!unique.contains(i)){
                result.push_back(i);
            }
        }
        return result;
    }
};