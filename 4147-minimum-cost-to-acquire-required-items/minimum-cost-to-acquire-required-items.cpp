class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common = min({(long long)need1,(long long)need2});

        long long ans = common * min((long long)costBoth,(long long)cost1+cost2);
        long long rem1 = need1-common;
        long long rem2 = need2 - common;
        ans += rem1 * min((long long)costBoth ,(long long)cost1);
        ans += rem2 * min((long long)costBoth ,(long long)cost2);
        return ans;

    }
};