class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map <char , char> seen;
        unordered_map <char , bool> helper;
        for(int i = 0 ; i < n ; i++)
        {
            if(seen.count(s[i]))
            {
                if(seen[s[i]] != t[i])
                    return false;
            }
            else
            {
                if(helper[t[i]])
                    return false;
                seen[s[i]] = t[i];
                helper[t[i]] = true;
            }
        }
        return true;
    }
};
