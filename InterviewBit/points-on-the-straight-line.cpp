// https://www.interviewbit.com/problems/points-on-the-straight-line/

string getHash(int x1, int y1, int x2, int y2){
    int dx = x2-x1, dy = y2-y1;
    
    if(dx == 0 and dy == 0) return "";
    else if(dx == 0) return "v";
    else if(dy == 0) return "h";
    
    int g = __gcd(dx, dy);
    if(g){
        dx /= g;
        dy /= g;
    } 
    return to_string(dx)+"/"+to_string(dy);
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size(), maxCount = 0;
    for(int i=0; i<n; i++){
        unordered_map<string, int> m;
        int maxLocal = 0;
        for(int j=i; j<n; j++){
            string hash = getHash(A[i], B[i], A[j], B[j]);
            m[hash]++;
            if(hash.length()) maxLocal = max(maxLocal, m[hash]);
        }
        maxCount = max(maxCount, m[""]+maxLocal);
    }
    return maxCount;
}
