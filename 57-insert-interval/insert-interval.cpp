class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> modint;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]){
            modint.push_back(intervals[i]);
            i++;
        }
        while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i+=1;  
        }
        modint.push_back(newInterval);
        while(i<intervals.size()){
            modint.push_back(intervals[i]);
            i+=1;
        }
        return modint;
    }
};