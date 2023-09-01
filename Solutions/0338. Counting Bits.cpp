class Solution {
public:
    int binary(int n){
        if(n == 0 || n == 1){
            return n;
        }
    	
        int count = 0;

        while(n){
            int digit = n%2;
            if(digit == 1){
                count++;
            }
            n = n/2;
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans;

        // for(int i=0;i<=n;i++){
        //     string s1 = bitset<32> (i).to_string();
        //     bitset<32> x(s1);

        //     int ones = x.count();
        //     ans.push_back(ones);
        // }

        for(int i=0;i<=n;i++){
            int n = binary(i);
            ans.push_back(n);
        }

        return ans;
    }
};
