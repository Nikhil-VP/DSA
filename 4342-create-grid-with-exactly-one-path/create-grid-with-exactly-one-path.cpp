class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string curr = "";
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                if(i==0){
                    curr.push_back('.');
                }
                else{
                    curr.push_back('#');
                }
                
                
            }
            curr.push_back('.');
            ans.push_back(curr);
            curr = "";
        }
        return ans;
    }
};