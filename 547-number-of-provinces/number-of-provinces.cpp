class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>& visit){
    visit[node] = true;
    for( int i=0; i< isConnected.size();i++){
        if(isConnected[node][i]== 1&& !visit[i]){
            dfs(i,isConnected, visit);
        }
    }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       vector<bool> visit(n,false);
       int numberOfComponents = 0;
       for(int i=0; i<n;i++){
        if(!visit[i]){
            numberOfComponents++;
            dfs(i, isConnected ,visit);
        }
       }
       return numberOfComponents;
    }

    
};