class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        unordered_map<char, int> mp1, mp2;

        if(n != m){
            return false;
        }

        set<char> s1(word1.begin(), word1.end());
        set<char> s2(word2.begin(), word2.end());

        if(s1 != s2){
            return false;
        }

        for(int i=0;i<n;i++){
            mp1[word1[i]]++; 
        }

        for(int i=0;i<m;i++){
            mp2[word2[i]]++;
        }

        vector<int> v1, v2;
        for(auto it : mp1){
            v1.push_back(it.second);
        }
        for(auto it : mp2){
            v2.push_back(it.second);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" "<<v2[i]<<endl;
            if(v1[i] != v2[i]){
                return false;
            }
        }

        return true;
    }
};
