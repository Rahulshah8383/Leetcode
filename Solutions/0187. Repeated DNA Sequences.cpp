class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        vector<string> ans;

        for(int i=0;i<n-9;i++){
            int j = i;
            string temp;
            while(j<i+10){
                temp += s[j++];
            }
            cout<<temp<<endl;
            mp[temp]++;
        }
        
        for(auto it : mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
