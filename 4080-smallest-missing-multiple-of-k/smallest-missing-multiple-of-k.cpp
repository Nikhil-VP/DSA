class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hash;
        int multiple = k;
        for(int i =0 ;i<nums.size();i++)
            hash.insert(nums[i]);
        while(hash.contains(multiple)){
            multiple += k;
        }
        return multiple;
    }
};