class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> columns;
        unordered_set<int> rows;
        for(int i=0;i < matrix.size();i++){
            for(int j = 0;j< matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    columns.insert(j);
                    rows.insert(i);
                }
            }
        }
        for(int i=0;i < matrix.size();i++){
            for(int j = 0;j< matrix[0].size();j++){
                if(rows.find(i)!=rows.end() || columns.find(j)!=rows.end()){
                    matrix[i][j] = 0;
                }
                
            }
        }
        for(int i=0;i < matrix.size();i++){
            for(int j = 0;j< matrix[0].size();j++){
                cout << matrix[i][j] << " ";
                }
            }
        }
    
};