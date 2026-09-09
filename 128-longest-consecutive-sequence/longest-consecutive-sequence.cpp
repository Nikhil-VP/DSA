class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int seq = 0;
        int j=1;
        if(nums.size() == 0) return 0;
        for(int i=1;i<nums.size();i++){
            cout << j;
            if(nums[i-1] == nums[i]-1){
                j++;
            }
            else if(nums[i-1] == nums[i]){
                continue;
            }
            else{
                seq = max(seq, j);
                j=1;
            }
        }
        seq = max(seq, j);
        return seq; 
    }
};