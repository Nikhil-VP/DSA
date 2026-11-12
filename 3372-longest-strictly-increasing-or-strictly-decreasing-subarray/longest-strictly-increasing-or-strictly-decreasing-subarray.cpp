class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int j = 0;
        int inc =1;
        int dec =1;
        if(n==1)return 1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc +=1;
            }
            else{
                inc = 1;
            }
            ans = max(inc,ans);
        }
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                dec +=1;
            }
            else{
                dec = 1;
            }
            ans = max(dec,ans);
        }
        return ans;
    }
};