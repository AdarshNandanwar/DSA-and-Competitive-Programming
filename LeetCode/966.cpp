// https://leetcode.com/problems/vowel-spellchecker/

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> s;
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        unordered_map<string, string> lower_to_first, vowel_replaced_lower_to_first;
        
        for(auto word:wordlist){
            s.insert(word);
            
            string word_lower = word; 
            for(auto & c:word_lower) c = tolower(c);
            if(!lower_to_first.count(word_lower)) lower_to_first[word_lower] = word;
            
            string word_vowel_replaced_lower = word_lower;
            for(auto & c:word_vowel_replaced_lower) c = vowels.count(c)?'#':c;
            if(!vowel_replaced_lower_to_first.count(word_vowel_replaced_lower)) vowel_replaced_lower_to_first[word_vowel_replaced_lower] = word;
        } 
        
        for(auto q:queries){
            if(s.count(q)){
                ans.push_back(q);
                continue;
            }
            
            string word_lower = q; 
            for(auto & c:word_lower) c = tolower(c);
            if(lower_to_first.count(word_lower)){
                ans.push_back(lower_to_first[word_lower]);
                continue;
            }
            
            string word_vowel_replaced_lower = word_lower;
            for(auto & c:word_vowel_replaced_lower) c = vowels.count(c)?'#':c;
            if(vowel_replaced_lower_to_first.count(word_vowel_replaced_lower)){
                ans.push_back(vowel_replaced_lower_to_first[word_vowel_replaced_lower]);    
                continue;
            }
            
            ans.push_back("");
        }
        
        return ans;
    }
};