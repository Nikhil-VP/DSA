class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int initColor, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        // Out of bounds check
        if (r < 0 || r >= n || c < 0 || c >= m) return;
        
        // Stop if pixel color doesn't match original color
        if (image[r][c] != initColor) return;
        
        // Change color
        image[r][c] = newColor;
        
        // Recurse on 4-directional neighbors
        dfs(image, r + 1, c, initColor, newColor);
        dfs(image, r - 1, c, initColor, newColor);
        dfs(image, r, c + 1, initColor, newColor);
        dfs(image, r, c - 1, initColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        
        // Avoid infinite loop if starting color is already target color
        if (initColor != color) {
            dfs(image, sr, sc, initColor, color);
        }
        
        return image;
    }
};