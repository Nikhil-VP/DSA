class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Precompute connected component IDs for each node in O(n)
        vector<int> comp(n, 0);
        int currentComp = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentComp++; // Start a new component when gap > maxDiff
            }
            comp[i] = currentComp;
        }
        
        // Step 2: Answer each query in O(1) time
        vector<bool> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            answer[i] = (comp[queries[i][0]] == comp[queries[i][1]]);
        }
        
        return answer;
    }
};