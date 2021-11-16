// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/

// Method 1 (Bit masking with Iterative Subset formation, O(n*50+m*(2^7)) = O(n+m)):

class Solution {
public:   
    int get_mask(string s){
        int mask = 0;
        for(auto &c:s) mask |= (1<<(c-'a'));
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        unordered_map<int, int> word_freq;
        for(auto &word:words) word_freq[get_mask(word)]++;
        vector<int> res;
        for(auto &puzzle:puzzles){
            int count = 0, first_set_mask = 1<<(puzzle[0]-'a'), puzzle_mask = get_mask(puzzle);
            // iterate through all submasks of mask
            for(int submask=puzzle_mask; submask>0; submask=((submask-1)&puzzle_mask)){
                if(submask & first_set_mask) count += word_freq[submask];
            }
            res.push_back(count);
        }
        return res;
    }
};

// Method 2 (Bit masking with Recursive Subset formation, O(n*50+m*(2^6)) = O(n+m)):

class Solution {
public:    
    void recurse_count(const string & puzzle, int index, unordered_map<int, int> & word_freq, int cur_mask, int & count){
        if(index == puzzle.size()){
            if(word_freq.count(cur_mask)) count += word_freq[cur_mask];
            return;
        }
        recurse_count(puzzle, index+1, word_freq, cur_mask, count);
        recurse_count(puzzle, index+1, word_freq, (cur_mask|(1<<(puzzle[index]-'a'))), count);
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        unordered_map<int, int> word_freq;
        for(auto &word:words){
            int mask = 0;
            for(auto &c:word) mask |= (1<<(c-'a'));
            word_freq[mask]++;
        }
        vector<int> res;
        for(auto &puzzle:puzzles){
            int count = 0;
            // always including the first letter
            recurse_count(puzzle, 1, word_freq, (1<<(puzzle[0]-'a')), count);
            res.push_back(count);
        }
        return res;
    }
};

// Method 3 (Bit masking with optimization, O(n*m), TLE):

class Solution {
public:
    int get_mask(string s){
        int mask = 0;
        for(auto &c:s) mask |= (1<<(c-'a'));
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        int n = words.size();
        unordered_map<int, int> word_freq;
        unordered_map<char, unordered_set<int>> first_letter_to_word_masks;
        for(auto &word:words){
            int word_mask = get_mask(word);
            word_freq[word_mask]++;
            for(auto &c:word) first_letter_to_word_masks[c].insert(word_mask);
        } 
        for(auto &puzzle:puzzles){
            int puzzle_mask = get_mask(puzzle), count = 0;
            for(auto &word_mask:first_letter_to_word_masks[puzzle[0]]){
                if((puzzle_mask&word_mask) == word_mask) count += word_freq[word_mask];
            }
            res.push_back(count);
        }
        return res;
    }
};