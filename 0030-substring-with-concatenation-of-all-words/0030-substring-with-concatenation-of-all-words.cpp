class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Return an empty list if s or words are empty
    if (s.empty() || words.empty())
        return {};

    // Calculate the length of each word and the total length of the concatenated string
    int word_len = words[0].length();
    int concat_len = words.size() * word_len;

    // Create a frequency map for the words array
    unordered_map<string, int> words_freq;
    for (const string& word : words)
        words_freq[word]++;

    // Create a list to store the starting indices of the concatenated substrings
    vector<int> result;

    // Iterate over the entire string with a sliding window of size concat_len
    for (int i = 0; i < s.length() - concat_len + 1; i++) {
        string window = s.substr(i, concat_len);
        unordered_map<string, int> window_freq;

        // Create a frequency map for the current window
        for (int j = 0; j < concat_len; j += word_len) {
            string curr_word = window.substr(j, word_len);
            window_freq[curr_word]++;
        }

        // Check if the current window is a concatenated substring
        if (window_freq == words_freq)
            result.push_back(i);
    }

    return result;
    }
};