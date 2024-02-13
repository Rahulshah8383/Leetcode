class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;

        for(auto it : arr){
            hash[it]++;
        }

        vector<int> count;
        for(auto it : hash){
            if(find(count.begin(), count.end(), it.second) != count.end()){
                return false;
            }
            count.push_back(it.second);
        }

        return true;
    }
};
