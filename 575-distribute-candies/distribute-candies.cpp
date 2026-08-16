#include <algorithm>
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        long long n = candyType.size();
        long long candies = n / 2;
        unordered_set<int> type;
        for(int i=0; i < n;i++){
            type.insert(candyType[i]);
        }
        int maxval =std::min<int>(candies,type.size());
        return(maxval);

    }
};