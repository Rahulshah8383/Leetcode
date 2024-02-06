class Solution {
public:
    // int ans = 0;
    // void Count_Beams(vector<string>& bank, int row, int col, int condition2){
        
    //     for(int i=row+1;i<bank.size();i++){
    //         for(int j=0;j<bank[i].size();j++){
    //             if(bank[i][j] == '1'){
    //                 condition2 = 1;
    //                 ans++;
    //             }
    //         }

    //         if(condition2 == 1){
    //             return;
    //         }
    //     }
    // }

    // int numberOfBeams(vector<string>& bank) {
    //     for(int i=0;i<bank.size();i++){
    //         for(int j=0;j<bank[i].size();j++){
    //             if(bank[i][j] == '1'){
    //                 Count_Beams(bank, i, 0, 0);
    //             }
    //         }
    //     }

    //     return ans;
    // }

    int numberOfBeams(vector<string>& bank){
        int ans = 0;
        vector<int> v;
        
        for(auto s : bank){
            int cnt = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] == '1') cnt++;
            }

            if(cnt != 0){
                v.push_back(cnt);
            }
        }

        for(int i=1;i<v.size();i++){
            int t = v[i-1]*v[i];
            ans += t;
        }


        return ans;
    }
};
