class Solution {
public:
    bool isFascinating(int n) {
        std::stringstream ss;
        ss << n << 2 * n << 3 * n;

        std::string concatenatedString = ss.str();
        long long ans = std::stoll(concatenatedString); 

        std::vector<int> v;

        while (ans) {
            int digit = ans % 10;
            auto it = find(v.begin(), v.end(), digit);
            if (it != v.end() || digit == 0) {
                return false;
            }
            v.push_back(digit);
            ans = ans / 10;
        }
        return true;
    }
};
