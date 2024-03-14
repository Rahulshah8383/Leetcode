class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> ans;
    //     int n = strs.size();

    //     for (int i = 0; i < n; i++) {
    //         string str = strs[i];
    //         if (str == "$") {
    //             continue;  // Skip already processed strings
    //         }

    //         vector<string> result;
    //         unordered_map<char, int> t1;
    //         for (int k = 0; k < str.size(); k++) {
    //             t1[str[k]]++;
    //         }
    //         result.push_back(str);

    //         for (int j = i + 1; j < n; j++) {
    //             string temp = strs[j];
    //             unordered_map<char, int> t2;
    //             for (int k = 0; k < temp.size(); k++) {
    //                 t2[temp[k]]++;
    //             }

    //             if (t1 == t2) {
    //                 strs[j] = "$";  // Mark the string as processed
    //                 result.push_back(temp);
    //             }
    //         }

    //         ans.push_back(result);
    //     }

    //     return ans;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramGroup;

        for(auto str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());

            anagramGroup[temp].push_back(str);
        }

        for(auto group : anagramGroup){
            ans.push_back(group.second);
            // cout<<x.first<<" : ";
            // for(int i=0;i<x.second.size();i++){
            //     cout<<x.second[i]<<", ";
            // }

            // cout<<endl;
        }


        return ans;
    }

};
