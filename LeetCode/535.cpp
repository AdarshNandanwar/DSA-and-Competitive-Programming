// https://leetcode.com/problems/encode-and-decode-tinyurl/

// Method 1 (Best Approach: Hash + timeHash + random):
// https://www.youtube.com/watch?v=fMZMm_0ZhK4

// Method 2 (Basic counter approach, O(1)):

class Solution {
    unordered_map<string, string> m;
    int counter = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortURL = to_string(counter);
        counter++;
        m[shortURL] = longUrl;
        return shortURL;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));