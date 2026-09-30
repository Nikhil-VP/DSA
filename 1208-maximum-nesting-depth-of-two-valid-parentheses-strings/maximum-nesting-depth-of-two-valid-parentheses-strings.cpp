class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.length();
        vector<int> arr(n);
        int depth = 0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                depth += 1;
                arr[i] = depth % 2;
            }
            else{
                
                arr[i] = depth % 2 ;
                depth -=1;
            }
        }
        return arr;
    }
};