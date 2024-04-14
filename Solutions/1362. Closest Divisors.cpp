class Solution {
public:
    vector<int> closestDivisors(int num) {
    int n = num + 1, m = num + 2;
    int a = 0, b = 0;
    int diff = INT_MAX;

    // for(int i=1;i<n;i++){
    //     for(int j=i;j<=m;j++){
    //         int p = i*j;

    //         if(p ==  n || p == m){
    //             if((j-i) < diff){
    //                 a = i; b = j;
    //                 diff = j - i;
    //             }
    //         }
    //     }
    // }


        vector<int> divisor;

        for(int i=1;i*i<=n; i++){
            if(n%i == 0){
                divisor.push_back(i);
                divisor.push_back(n/i);
            }
        }

        for(int i=1;i*i<=m; i++){
            if(m%i == 0){
                divisor.push_back(i);
                divisor.push_back(m/i);
            }
        }

        sort(divisor.begin(), divisor.end());

        // for(auto it : divisor){
        //     cout<<it<<" ";
        // }

        int i = 0, j = divisor.size()-1;

        while(i <= j){
            int p = divisor[i]*divisor[j];
            
            if(p ==  n || p == m){
                if((divisor[j] - divisor[i]) < diff){
                    a = divisor[i]; b = divisor[j];
                    diff = divisor[j] - divisor[i];
                }
                j--;
            }
            else if(p > m){
                j--;
            }
            else{
                i++;
            }
        }


        vector<int> ans{a, b};
        return ans;
    }
};
