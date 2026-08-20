class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort: start point ascending, end point descending
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int remaining = 0;
        int prev_end = 0;

        for (const auto& interval : intervals) {
            // If current interval's end extends beyond prev_end, it is NOT covered
            if (interval[1] > prev_end) {
                remaining++;
                prev_end = interval[1];
            }
        }

        return remaining;
    }
};