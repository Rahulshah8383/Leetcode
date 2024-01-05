class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> adjList;

        // Create an adjacency list
        for (const auto& path : paths) {
            adjList[path[0]] = path[1];
        }

        // Find the destination city
        string currentCity = paths[0][0];
        while (adjList.find(currentCity) != adjList.end()) {
            currentCity = adjList[currentCity];
        }

        return currentCity;
    }
};
