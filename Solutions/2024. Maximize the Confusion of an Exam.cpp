class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // int n = answerKey.size();
        // int maxT = 0, nF = 0;
        // int i=0, j=0;
        // while(j < n){
        //     if(answerKey[j] == 'F'){
        //         nF++;
        //     }

        //     while(i<j && nF > k){
        //         nF = answerKey[i] == 'F'?nF-1:nF;
        //         i++;
        //     }

        //     maxT = max(maxT, j-i+1);
        // }

        // int maxF = 0, nT = 0;
        // i=0, j=0;
        // while(j < n){
        //     if(answerKey[j] == 'T'){
        //         nT++;
        //     }

        //     while(i<j && nT > k){
        //         nT = answerKey[i] == 'T'?nT-1:nT;
        //         i++;
        //     }

        //     maxF = max(maxF, j-i+1);
        // }

        // return max(maxF, maxT);

        int nT = 0, nF = 0, ans = 0, n = answerKey.size();

        for(int i=0, j=0; j<n;j++){
            if(answerKey[j] == 'F'){
                nF++;
            }
            else{
                nT++;
            }
            while(i<j && min(nF, nT) > k){
                nF = answerKey[i] == 'F'?nF-1:nF;
                nT = answerKey[i] == 'T'?nT-1:nT;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
