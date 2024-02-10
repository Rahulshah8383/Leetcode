class Solution {
public:
    int compress(std::vector<char>& chars) {
        std::string compressedStr;
        for (int i = 0; i < chars.size(); ) {
            char c = chars[i];
            int cnt = 1;
            while (i + 1 < chars.size() && c == chars[i + 1]) {
                i++;
                cnt++;
            }
            compressedStr += c;
            if (cnt > 1) {
                compressedStr += std::to_string(cnt);
            }
            i++;
        }

        for (int i = 0; i < compressedStr.size(); i++) {
            chars[i] = compressedStr[i];
        }

        return compressedStr.size();
    }
};
