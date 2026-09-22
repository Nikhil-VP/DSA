// class Solution {
// public:
//     void sim(vector<int>& candidates,int index, int target, vector<int> ds,vector<vector<int>> result )
//     {
        
//         if(target < 0){
//             if(index == candidates.size()){
//                 result.push_back(ds);
//             }
            
//             return;
//         }
//         if(candidates[index]<=target){
//             ds.push_back(candidates[index]);
//             sim(candidates, index, target - candidates[index], ds, result);
//             ds.pop_back();
//         }
//         sim(candidates, index+1, target, ds, result);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         sim(candidates, 0, target, {}, result);
//         return result;
//     }
// };
class Solution {
private:
    void sim(vector<int>& candidates, int index, int target, vector<int>& ds, vector<vector<int>>& result) {
        // Base Case 1: Found a valid combination
        if (target == 0) {
            result.push_back(ds);
            return;
        }

        // Base Case 2: Out of bounds or target exceeded
        if (index == candidates.size() || target < 0) {
            return;
        }

        // Pick current element (stay at same index since elements can be reused)
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            sim(candidates, index, target - candidates[index], ds, result);
            ds.pop_back(); // Backtrack
        }

        // Skip current element (move to next index)
        sim(candidates, index + 1, target, ds, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        sim(candidates, 0, target, ds, result);
        return result;
    }
};