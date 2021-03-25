// https://leetcode.com/problems/find-the-closest-palindrome/

// Method 1 (stoll conversion, O(n)):

class Solution {
public:    
    string prevLargest(string A) {
        if(A == "1") return "0";
        int n = A.size();
        string firstHalf = A.substr(0, (n+1)/2), secondHalf = A.substr(0, n/2);
        reverse(secondHalf.begin(), secondHalf.end());
        if(firstHalf+secondHalf < A) return firstHalf+secondHalf;
        string newFirstHalf = to_string(stoll(firstHalf)-1);
        if(newFirstHalf != "0" and firstHalf.length() == newFirstHalf.length()){
            string newSecondHalf = n%2 ? newFirstHalf.substr(0, n/2) : newFirstHalf;
            reverse(newSecondHalf.begin(), newSecondHalf.end());
            return newFirstHalf+newSecondHalf;
        } else {
            return string(n-1, '9');
        }        
    }  
    
    string nextSmallest(string A) {        
        int n = A.size();
        string firstHalf = A.substr(0, (n+1)/2), secondHalf = A.substr(0, n/2);
        reverse(secondHalf.begin(), secondHalf.end());
        if(firstHalf+secondHalf > A) return firstHalf+secondHalf;
        string newFirstHalf = to_string(stoll(firstHalf)+1);
        if(newFirstHalf != "0" and firstHalf.length() == newFirstHalf.length()){
            string newSecondHalf = n%2 ? newFirstHalf.substr(0, n/2) : newFirstHalf;
            reverse(newSecondHalf.begin(), newSecondHalf.end());
            return newFirstHalf+newSecondHalf;
        } else {
            return "1"+string(n-1, '0')+"1";
        } 
    }
    
    string nearestPalindromic(string n) {
        string prevString = prevLargest(n), nextString = nextSmallest(n);        
        long long num, prev, next;
        num = stoll(n);
        prev = stoll(prevString);
        next = stoll(nextString);
        return abs(num-prev) > abs(next-num) ? nextString : prevString;
    }
};

// Method 2 (String Traversal, O(n)):

class Solution {
public:    
    string prevLargest(string A) {
        if(A == "1") return "0";
        int n = A.size();
        if(n%2){
            // odd length
            int mid = n/2, i;
            
            // mirror string
            string prev = A.substr(0, mid);
            reverse(prev.begin(), prev.end());
            prev = A.substr(0, mid)+string(1, A[mid])+prev;
            if(A > prev) return prev;

            for(i = 0; mid-i>=0;i++){
                if(A[mid-i] != '0'){
                    if(mid-i == 0 and A[mid-i] == '1') continue;
                    prev[mid-i] = prev[mid+i] = A[mid-i]-1;
                    return prev;
                } else {
                    prev[mid-i] = prev[mid+i] = '9';
                }
            }

            // 100xx
            return string(n-1, '9');
        } else {
            // even length
            int mid = n/2, i;

            // mirror string
            string prev = A.substr(0, mid);
            reverse(prev.begin(), prev.end());
            prev = A.substr(0, mid)+prev;
            if(A > prev) return prev;

            for(i = 0; mid+i<n;i++){
                if(A[mid-i-1] != '0'){
                    if(mid-i-1 == 0 and A[mid-i-1] == '1') continue;
                    prev[mid-i-1] = prev[mid+i] = A[mid-i-1]-1;
                    return prev;
                } else {
                    prev[mid-i-1] = prev[mid+i] = '0';
                }
            }

            // 100xxx
            return string(n-1, '9');
        }
    }  
    
    string nextSmallest(string A) {
        int n = A.size();
        if(n%2){
            // odd length
            int mid = n/2, i;

            string next = A.substr(0, mid);
            reverse(next.begin(), next.end());
            next = A.substr(0, mid)+string(1, A[mid])+next;
            if(A < next) return next;

            for(i = 0; mid-i>=0;i++){
                if(A[mid-i] != '9'){
                    next[mid-i] = next[mid+i] = A[mid-i]+1;
                    return next;
                } else {
                    next[mid-i] = next[mid+i] = '0';
                }
            }

            // all nines
            return "1"+string(n-1, '0')+"1";
        } else {
            // even length
            int mid = n/2, i;

            string next = A.substr(0, mid);
            reverse(next.begin(), next.end());
            next = A.substr(0, mid)+next;
            if(A < next) return next;

            for(i = 0; mid+i<n;i++){
                if(A[mid-i-1] != '9'){
                    next[mid-i-1] = next[mid+i] = A[mid-i-1]+1;
                    return next;
                } else {
                    next[mid-i-1] = next[mid+i] = '0';
                }
            }

            // all nines
            return "1"+string(n-1, '0')+"1";
        }
    }
    
    string nearestPalindromic(string n) {
        string prevString = prevLargest(n), nextString = nextSmallest(n);        
        long long num, prev, next;
        num = stoll(n);
        prev = stoll(prevString);
        next = stoll(nextString);
        return abs(num-prev) > abs(next-num) ? nextString : prevString;
    }
};