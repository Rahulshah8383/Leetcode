
class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int beautiful_pair = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int first_digit = nums[i];
                int last_digit = nums[j];
                
                // Extract the first and last digits
                while (first_digit >= 10) {
                    first_digit /= 10;
                }
                last_digit %= 10;
                
                // Check if the first and last digits are coprime
                if (gcd(first_digit, last_digit) == 1) {
                    beautiful_pair++;
                }
            }
        }
        return beautiful_pair;
    }
};
