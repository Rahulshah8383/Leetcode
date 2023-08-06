class Solution {
public:
    int largestVariance(string s) {
        vector<int> freq(26, 0); // It will store freq of all char of s

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        // we will iterate over all 26X26 pairs and maximize the difference
        int maxi = 0; // which is our maximum variance
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                int curr_freq_i = 0, curr_freq_j = 0;
                int left_i = freq[i], left_j = freq[j];

                // freq of i > freq of j -> consideration
                for(auto ele : s){
                    if(ele == 'a'+i){
                        curr_freq_i++;
                        left_i--;
                    }
                    if(ele == 'a'+j){
                        curr_freq_j++;
                        left_j--;
                    }
                    if(curr_freq_j > 0){
                        maxi = max(maxi, curr_freq_i - curr_freq_j); 

                    }
                    if(curr_freq_j > curr_freq_i && left_j > 0){
                        // we will move towards ew substring..
                        curr_freq_i = 0;
                        curr_freq_j = 0;
                    }
                }
            }
        }
        return maxi;
    }
};
