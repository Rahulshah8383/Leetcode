class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {        
//         if(n == 3){
//             int a = nums[0];
//             int b = nums[1];
//             int c = nums[2];
            
//             int ans = (a-b)*c;
//             if(ans > 0){
//                 return ans;
//             }
//             else{
//                 return 0;
//             }
//         }
//         vector<int> minv(n, nums[n-1]);
        
//         for(int i=n-2;i>=0;i--){
//             minv[i] = min(minv[i+1], nums[i]);
//         }
        
//         vector<int> maxv(n, nums[n-1]);
        
//         for(int i=n-2;i>=0;i--){
//             maxv[i] = max(maxv[i+1], nums[i]);
//         }
        
//         for(auto it : minv){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//         for(auto it : maxv){
//             cout<<it<<" ";
//         }
        
//         int ans = 0;
//         for(int i=0;i<n-2;i++){
//             int a = nums[i];
//             int b = minv[i+1];
//             int c = maxv[i+2];
            
//             ans = max(ans, ((a-b)*c));
//         }
        
//         return ans;
        
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int a = nums[i];

            for (int j = i + 1; j < n - 1; j++) {
                int b = nums[j];

                for (int k = j + 1; k < n; k++) {
                    int c = nums[k];

                    long long tripletProduct = static_cast<long long>(a - b) * static_cast<long long>(c);
                    ans = max(ans, tripletProduct);
                }
            }
        }

        return ans;
    }
};
