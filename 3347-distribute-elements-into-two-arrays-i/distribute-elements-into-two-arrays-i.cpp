class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result,arr1,arr2;
        int n=nums.size();
        int i;
        for(auto i:nums){
            if(arr1.empty()){
                arr1.push_back(i);
            }else if(arr2.empty())arr2.push_back(i);
            else if(arr1.back()>arr2.back())arr1.push_back(i);
            else arr2.push_back(i);
        }
        for(int i=0;i<arr1.size();i++){
            result.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            result.push_back(arr2[i]);
        }
        return result;

    }
};