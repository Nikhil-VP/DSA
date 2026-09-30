class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0;

        // Step 1: Calculate initial sum of taking all k cards from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        int max_points = lsum;
        int r = n - 1;

        // Step 2: Remove cards from left one by one and add from the right
        for (int l = k - 1; l >= 0; l--) {
            lsum -= cardPoints[l];
            rsum += cardPoints[r--];
            max_points = max(max_points, lsum + rsum);
        }

        return max_points;
    }
};