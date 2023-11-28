class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //to store first occurance  and last occurance of every alphabet.
        vector<pair<int, int>> v(26, {-1, -1});

        int n = s.length();

        for(int i=0;i<n;i++){
            if(v[s[i] - 'a'].first == -1)
                v[s[i] - 'a'].first = i; // storing when alphabet appered first time.
            else
                v[s[i] - 'a'].second = i; // storing when alphabet appered first time.
        }

        int ans = 0;

        for (int i = 0 ; i <26 ;i++ ){ //traversing over all alphabets.
            if (v[i].second != -1 ){ //only if alphabet occured second time.
                
                unordered_set<char> st; //using set to keep only unique elements between the range.
                
                for (int x = v[i].first + 1 ; x < v[i].second ; x++ ) st.insert(s[x]); // set keeps only unique elemets.
                    
                ans += ((int)st.size()); // adding number of unique elements to the answer.
            }
        }
        return ans;
    }
};
