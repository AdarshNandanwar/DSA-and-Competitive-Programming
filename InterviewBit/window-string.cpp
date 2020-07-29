// https://www.interviewbit.com/problems/window-string/

string Solution::minWindow(string A, string B) {
    if(B.length() == 0) return "";
    int n = A.length(), p1 = 0, p2 = 0, remaining = B.length(), st = 0, end = 0;
    unordered_map<char, int> freq;
    for(auto i:B) freq[i]--;
    
    // A[p1..p2)
    while(p2<n){
        
        while(p2<n and remaining){
            freq[A[p2]]++;
            if(freq[A[p2]] <= 0) remaining--;
            p2++;
        }
        
        while(p1<p2 and !remaining){
            if(end == 0 or end-st > p2-p1){
                st = p1; 
                end = p2;
            } 
            freq[A[p1]]--;
            if(freq[A[p1]] < 0) remaining++;
            p1++;
        }
    }
    return A.substr(st, end-st);
}
