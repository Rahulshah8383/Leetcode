class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> first;
        stack<int> second;

        for(int i=0;i<s.size();i++){
            if(s[i] == '#'){
                if(first.size()>0) 
                    first.pop();
            }
            else{
                first.push(s[i]);
            }
        }

        for(int i=0;i<t.size();i++){
            if(t[i] == '#'){
                if(second.size()>0)
                    second.pop();
            }
            else{
                second.push(t[i]);
            }
        }

        if(first == second){
            return true;
        }
        else{
            return false;
        }
    }
};
