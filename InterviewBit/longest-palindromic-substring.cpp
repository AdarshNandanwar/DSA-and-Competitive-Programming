// https://www.interviewbit.com/problems/longest-palindromic-substring/

// Method 1 (Manacher Algorithm, O(n)):

// {maxCenter, maxLps}
pair<int, int> manacher(const string & s){
    int n = s.length();
    // lps[i] = longest palindromic substring centered at a
    // lps[i] = [..i..] = 2
    vector<int> lps(n, 0);
    int c = 0, r = 0, i = 0, mirror, left, right, maxC = 0, maxLps = 0;
    while(i<n){
        mirror = 2*c-i;
        lps[i] = min(lps[mirror], r-i);
        
        left = i-lps[i]-1, right = i+lps[i]+1;
        while(left>=0 and right<n and s[left] == s[right]){
            lps[i]++;
            left--;
            right++;
        }
        if(right-1 > r){
            c = i;
            r = right-1;
        }
        if(maxLps < lps[i]){
            maxLps = lps[i];
            maxC = i;
        }
        i++;
    }
    return {maxC, maxLps};
}

string formatString(const string & s){
    string res = "#";
    for(auto c:s){
        res.push_back(c);
        res.push_back('#');
    }
    return res;
}

string Solution::longestPalindrome(string A) {
    auto [maxC, maxLps] = manacher(formatString(A));
    return A.substr((maxC-maxLps)/2, maxLps);
}

// Method 2 (O(n2)):

string Solution::longestPalindrome(string A) {
    int n = A.length(), maxLen = 0, index = 0;
    if(n == 0) return "";
    for(int i = 0; i<n; i++){
        // odd
        for(int j = 0; i-j>=0 and i+j<n; j++){
            if(A[i-j] != A[i+j]) break;
            if(maxLen < 2*j+1){
                maxLen = 2*j+1;
                index = i-j;
            }
        }
        // even
        for(int j = 0; i-j>=0 and i+j+1<n; j++){
            if(A[i-j] != A[i+j+1]) break;
            if(maxLen < 2*j+2){
                maxLen = 2*j+2;
                index = i-j;
            }
        }
    }
    return A.substr(index, maxLen);
}
