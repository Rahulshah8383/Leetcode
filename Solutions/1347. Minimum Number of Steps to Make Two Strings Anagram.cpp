class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count_s(26, 0);
        vector<int> count_t(26, 0);

        for(auto ch : s){
            count_s[ch - 'a']++;
        }

        for(auto ch : t){
            count_t[ch - 'a']++;
        }

        int steps = 0;

        for(int i=0;i<26;i++){
            steps += abs(count_s[i] - count_t[i]);
        }

        return steps/2;
    }
};
