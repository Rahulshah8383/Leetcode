class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int newColor = color;
        if (image[sr][sc] == newColor) {
            return image;
        }
        
        // set the starting pixel color to newColor
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        
        // check the neighboring pixels and perform flood fill recursively
        if (sr > 0 && image[sr-1][sc] == oldColor) {
            floodFill(image, sr-1, sc, newColor);
        }
        if (sc > 0 && image[sr][sc-1] == oldColor) {
            floodFill(image, sr, sc-1, newColor);
        }
        if (sr < image.size()-1 && image[sr+1][sc] == oldColor) {
            floodFill(image, sr+1, sc, newColor);
        }
        if (sc < image[0].size()-1 && image[sr][sc+1] == oldColor) {
            floodFill(image, sr, sc+1, newColor);
        }
        
        return image;
    }
};
