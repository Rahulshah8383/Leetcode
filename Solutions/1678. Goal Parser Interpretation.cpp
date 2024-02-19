class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int n = command.size(), i = 0;
        
        while(i < n ){
            char c = command[i];

            if(c == 'G'){
                ans += c;
                i++;
            }
            else if (c == '(' && command[i + 1] == ')') {
                ans += 'o';
                i += 2;
            } 
            else {
                ans += "al";
                i += 4;
            }
        }

        return ans;
    }
};
