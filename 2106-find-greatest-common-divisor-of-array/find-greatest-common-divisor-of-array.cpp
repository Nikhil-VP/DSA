class Solution {
public:
    int gcd(int a,int b){
        if(a==0 || b==0){
            return max(a,b);
        }
        int rem=a%b;
        return gcd(b,rem);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[nums.size()-1]; 
        return gcd(a,b);
    }
};