class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = words[i].size();
            int j = i + 1;

            // Keep adding words until the line exceeds the maximum width
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;

            // Construct the justified line
            std::string line = words[i];

            // Special case when there's only one word or it's the last line
            if (numWords == 1 || j == n) {
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += std::string(maxWidth - line.size(), ' ');
            } else {
                int spacesBetweenWords = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int k = i + 1; k < j; k++) {
                    line += std::string(spacesBetweenWords, ' ');
                    if (extraSpaces > 0) {
                        line += " ";
                        extraSpaces--;
                    }
                    line += words[k];
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
