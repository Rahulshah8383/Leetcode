class Solution {
public:
    void Helper(vector<char>& s, int i,int j){
        if(i>j){
            return;
        }

        swap(s[i], s[j]);
        Helper(s, i+1, j-1);
    }

    void reverseString(vector<char>& s) {
        /*
        int i=0, j=s.size()-1;

        while(i<j){
            swap(s[i], s[j]);
            i++; j--;
        }
        */

        Helper(s, 0, s.size()-1);
    }
};
