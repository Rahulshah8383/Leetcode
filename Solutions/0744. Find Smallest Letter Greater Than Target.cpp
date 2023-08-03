class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        /*
        for(int i=0;i<letters.size();i++){
            if(letters[i] > target){
                return letters[i];
            }
        }

        return letters[0];
        */

        int n = letters.size();

        if(letters[n/2] <= target){
            for(int i=n/2;i<n;i++){
                if(letters[i] > target){
                    return letters[i];
                }
            }
        }
        else if(letters[n/2] > target){
            for(int i=0;i<=n;i++){
                if(letters[i] > target){
                    return letters[i];
                }
            }
        }
        return letters[0];
    }
};
