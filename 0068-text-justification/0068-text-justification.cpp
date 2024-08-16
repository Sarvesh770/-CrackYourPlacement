class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int curr_len = 0, start = 0, end = -1;
        for (string s : words)
        {
            if ((end - start + 1) + curr_len + s.size() <= maxWidth)
                curr_len += s.size(), end++;
            else
            {
                // Start the current line as the word at index start
                string sentence = words[start];
                int extra_space = maxWidth - curr_len, padding = extra_space / max(1, end - start);
                // extra is the extra space that has to be adjusted so as to make the length equal to maxWidth
                int extra = extra_space % max(1, end - start);
                // Now add the words from 'start index + 1' to 'end index'
                for (int i = start + 1; i <= end; i++)
                {
                    // Add the padding first
                    for (int j = 0; j < padding; j++)
                        sentence += " ";
                    // Add the xtra padding, if needed
                    if (extra)
                        sentence += " ", extra--;
                    sentence += words[i];
                }
                // Just in case the sentence has only one word
                while (sentence.size() < maxWidth)
                    sentence += " ";
                ans.push_back(sentence);
                // Set the current word as the starting point of the new line
                start = end + 1, curr_len = s.size(), end++;
            }
        }
        // Last line has to be dealt with a bit differently, i.e. left justified
        string sentence = words[start];
        for (int i = start + 1; i <= end; i++)
            sentence += " " + words[i];
        while (sentence.size() < maxWidth)
            sentence += " ";
        ans.push_back(sentence);
        return ans;
    }
};