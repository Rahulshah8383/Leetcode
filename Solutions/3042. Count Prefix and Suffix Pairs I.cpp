class Solution {
public:
    
    bool isPrefix(string s1, string s2){
        int i = 0;
        
        while(i<s1.length()){
            if(s1[i] != s2[i]){
                return false;
            }
            i++;
        }
        
        return true;
    }
    
    bool isSuffix(string s1, string s2){
        int i = s1.length()-1, j = s2.length()-1;
        
        while(i>=0){
            if(s1[i] != s2[j]){
                return false;
            }
            i--; j--;
        }
        
        return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefix(words[i], words[j]) && isSuffix(words[i], words[j])){
                    ans++;            
                }
            }
        }
        
        return ans;
    }
};
