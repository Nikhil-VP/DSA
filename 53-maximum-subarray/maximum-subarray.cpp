class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = INT_MIN,sum = 0;
        for(int i=0;i < nums.size();i++){
            sum += nums[i];
            if(sum > maxs){
                maxs = sum;
            }
            if(sum < 0){
                sum = 0;
            }

        }
        return maxs;
    }
};
// class Solution{
//     public:
//          int maxSubArray(vector<int>& nums) {
//            return divideandconquer(nums , 0 ,nums.size()-1); 
//          }
//     private:
//         int divideandconquer(vector<int>& nums,int left,int right){
//             if(left == right) return nums[left];
//             int mid = left +(right - left)/2;
//             int left_max= divideandconquer(nums , left , mid);
//             int right_max= divideandconquer(nums , mid+1 , right);
//             int cross_max = maxcrossingsum(nums, left, mid, right);
//             return max({left_max,right_max,cross_max});
//         }
//         int maxcrossingsum(vector <int>& nums,int left,int mid,int right){
//             int sum=0;
//             int left_sum = INT_MIN;
//             for(int i =mid;i>= left;i--){
//                 sum += nums[i];
//                 left_sum = max(left_sum,sum);
//             }
//             sum = 0;
//             int right_sum = INT_MIN;
//             for(int i=mid+1; i <=right;i++){
//                 sum += nums[i];
//                 right_sum = max(right_sum,sum);
//             }
//             return left_sum + right_sum;
//         }
// };