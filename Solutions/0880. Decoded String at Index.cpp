class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // string ans = "";

        // for (int i = 0; i < s.length(); i++) {
        //     if (s[i] >= 'a' && s[i] <= 'z') {
        //         ans += s[i];
        //     } 
        //     else {
        //         long long d = s[i] - '0'-1;
        //         string temp = ans;
        //         while(d){
        //             ans += temp;
        //             d--;
        //         }
        //     }

        //     cout<<ans<<endl;
        //     if (ans.length() > k) {
        //         return string(1, ans[k-1]);
        //     }
        // }

        // return string(1, ans[k-1]);`

        stack<long long> characterLengths; // Stores the lengths of characters in the decoded string

        // Calculate lengths for each character in the encoded string
        characterLengths.push(0); // Start with 0 length

        for (size_t i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                // If the character is a digit, update the length based on the digit
                long long length = characterLengths.top() * (s[i] - '0');
                characterLengths.push(length);
            } else {
                // If the character is a letter, increment the length
                long long length = characterLengths.top() + 1;
                characterLengths.push(length);
            }
        }

        // Traverse the character lengths to decode and find the kth character
        size_t ln = characterLengths.size();
        while (!characterLengths.empty()) {
            k %= characterLengths.top(); // Adjust k based on the character length
            ln--;
            // If k is 0 and the character is an alphabet letter, return it
            if (k == 0 && isalpha(s[ln - 1])) {
                return string(1, s[ln - 1]);
            }

            // Move to the previous character length
            characterLengths.pop();
        }

        return ""; // Return an empty string if no character is found
    }
};
