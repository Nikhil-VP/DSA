class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n<=1 ) return 0;
        int zero = n-1;
        int drops =(nums[n-1] > nums[0]?1:0);

        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                drops++;
            }
            if(nums[i]==0){
                zero = i;
            }
        }
        if(drops == 0)return 0;
        if(drops == 1)return min(zero, 2+n-zero);
        if(drops == n-1)return min(zero+2,n - zero);
        return -1;
    }
};