// https://leetcode.com/problems/stamping-the-sequence/

// Method 1 (Greedy, Brute Force)

class Solution {
public:
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.length(), m = stamp.length(), stars = 0;
        bool change = false;
        vector<int> ans;
        do{
            change = false;
            for(int i = 0; i<n-m+1; i++){
                bool match = true, all_stars = true;
                for(int j = 0; j<m; j++){
                    if(target[i+j] != stamp[j] and target[i+j] != '*'){
                        match = false;
                        break;
                    } else {
                        if(target[i+j] != '*') all_stars = false;
                    }
                }
                if(match and !all_stars){
                    for(int j = 0; j<m; j++){
                        if(target[i+j] != '*'){
                            stars++;
                            change = true;
                            target[i+j] = '*';
                        }
                    } 
                    ans.push_back(i);
                }
            }
        }while(change);
        reverse(ans.begin(), ans.end());
        if(stars == n) return ans;
        return {};
    }
};

// Method 2 (WRONG, KMP/LongestPrefixSuffix)

/*
Input:
"aq"
"aqaaqaqqqaqqaaq"
Output:
[]
Expected:
[8,11,7,1,12,10,6,4,2,13,9,5,3,0]
*/

class Solution {
public:
    
    vector<int> get_lps(string & s){
        int n = s.length();
        vector<int> lps(n, 0);
        int i = 1, j = lps[i-1];
        while(i<n){
            if(s[i] == s[j]){
                lps[i] = j+1;
                i++;
                j = lps[i-1];
            } else {
                if(j == 0){
                    lps[i] = 0;
                    i++;
                    j = lps[i-1];
                } else {
                    j = lps[j-1];
                }
            }
        }
        return lps;
    }
    
    vector<int> kmp(string & s, string & pattern){
        int n = s.length(), m = pattern.length();
        auto lps = get_lps(pattern);
        
        vector<int> longest_prefix(n, 0);
        int i = 0, j = 0;
        while(i<n){
            while(i<n and j<m and s[i] == pattern[j]){
                if(i>0) longest_prefix[i] = j+1;
                else longest_prefix[i] = 1;
                i++; j++;
            }
            if(j == 0){
                longest_prefix[i] = j;
                i++;
            } else {
                j = lps[j-1];
            }
        }
        return longest_prefix;
    }
    
    vector<int> kmp_rev(string s, string pattern){
        
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());
        
        int n = s.length(), m = pattern.length();
        auto lps = get_lps(pattern);
        
        vector<int> longest_prefix(n, 0);
        int i = 0, j = 0;
        while(i<n){
            while(i<n and j<m and s[i] == pattern[j]){
                if(i>0) longest_prefix[i] = j+1;
                else longest_prefix[i] = 1;
                i++; j++;
            }
            if(j == 0){
                longest_prefix[i] = j;
                i++;
            } else {
                j = lps[j-1];
            }
        }
        reverse(longest_prefix.begin(), longest_prefix.end());
        return longest_prefix;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.length(), m = stamp.length();
        
        // kmp
        auto longest_prefix = kmp(target, stamp);
        
        // reverse kmp
        auto longest_suffix = kmp_rev(target, stamp);

        // checking is the solution exists              
        int first_zero_in_prefix = n;
        for(int i = 0; i<n; i++){
            if(longest_prefix[i] == 0){
                first_zero_in_prefix = i;
                break;
            } 
        }        
        int first_zero_in_suffix = -1;
        for(int i = n-1; i>=0; i--){
            if(longest_suffix[i] == 0){
                first_zero_in_suffix = i;
                break;
            } 
        }
        
        
        // left of max_index must be > 0 in longest_prefix
        // right of max_index must be > 0 in longest_suffix
        int max_index = -1;
        for(int i = first_zero_in_suffix+1; i<first_zero_in_prefix; i++){
            if(longest_suffix[i] == m){
                max_index = i;
                break;
            }
        }
        
        cout<<first_zero_in_suffix<<" "<<first_zero_in_prefix<<" "<<max_index<<endl;
        
        for(auto i:longest_prefix) cout<<i<<" "; cout<<endl;
        for(auto i:longest_suffix) cout<<i<<" "; cout<<endl;
        
        if(max_index == -1) return {};
        
        vector<int> ans;
        ans.push_back(max_index);
        
        int i = max_index-1, j = max_index+m;
        while(i>=0){
            ans.push_back(i-longest_prefix[i]+1);
            i -= longest_prefix[i];
        }
        while(j<n){
            ans.push_back(j-m+longest_suffix[j]);
            j += longest_suffix[j];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};