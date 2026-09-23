class Solution {
public:

    void sim(vector<int>& candidates, int target,
             vector<int>& ds, int index,
             vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            sim(candidates, target - candidates[i],
                ds, i + 1, result);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        vector<vector<int>> result;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        sim(candidates, target, ds, 0, result);

        return result;
    }
};