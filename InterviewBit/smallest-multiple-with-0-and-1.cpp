// https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

// Method 1 (BFS, string generation):

string Solution::multiple(int A) {
    // rem
    queue<int> q;        
    // parent[i] = rem of parent of the element who gave rem i
    // step[i] = last step (0 or 1) taken to reach the number who gave rem i
    //              i.e. step from parent to cut
    vector<int> parent(A, -1), step(A, -1);
    q.push(1%A);
    step[1%A] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur == 0) break;
        for(auto i:{0, 1}){
            int next = (cur*10+i)%A;
            if(next != 1 and parent[next] == -1){
                parent[next] = cur;
                step[next] = i;
                q.push(next);
            }
        }
    }
    // building the reverse string using rem, parent and step
    string res = "";
    int rem = 0;
    while(rem != -1){
        res.push_back(step[rem]+'0');
        rem = parent[rem];
    }
    reverse(res.begin(), res.end());
    return res;
}

// Method 2 (BFS, string answer construction, TLE):

bool isMultiple(string & s, int & A){
    int rem = 0, len = s.length();
    for(int i = 0; i<len; i++){
        if(s[i] == '0') continue;
        int tempRem = 1%A;
        for(int j = 0; j<len-1-i; j++) tempRem = (tempRem*10)%A;
        rem = (rem+tempRem)%A;
    }
    return rem == 0;
}

string Solution::multiple(int A) {
    string a = to_string(A);
    string start = "1";
    queue<string> q;
    q.push(start);
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        if(isMultiple(cur, A)) return cur;
        q.push(cur+"0");
        q.push(cur+"1");
    }
    return "";
}

// Method 3 (BFS, int answer construction, TLE):

string Solution::multiple(int A) {
    string a = to_string(A);
    long long int start = 1;
    queue<long long int> q;
    q.push(start);
    while(!q.empty()){
        long long int cur = q.front();
        q.pop();
        if(cur%A == 0) return to_string(cur);
        q.push(cur*10);
        q.push(cur*10+1);
    }
    return "";
}

// Method 4 (Brute Force, TLE):

bool isValid(string & s){
    for(auto c:s) if(c!='0' and c!='1') return 0;
    return 1;
}

void addString(string & a, string & b){
    int pa = a.length()-1, pb = b.length()-1, carry = 0;
    while(0<=pa and 0<=pb){
        int digit = a[pa]-'0'+b[pb]-'0'+carry;
        a[pa] = (digit%10)+'0';
        carry = digit/10;
        pa--;
        pb--;
    }
    while(0<=pa){
        int digit = a[pa]-'0'+carry;
        a[pa] = (digit%10)+'0';
        carry = digit/10;
        pa--;
    }
    while(0<=pb){
        int digit = b[pb]-'0'+carry;
        a = string(1, (digit%10)+'0') + a;
        carry = digit/10;
        pb--;
    }
    if(carry){
        a = string(1, carry+'0') + a;
    }
}

string Solution::multiple(int A) {
    string a = to_string(A);
    if(isValid(a)) return a;
    string sum = a;
    while(!isValid(sum)){
        addString(sum, a);
    }
    return sum;
}
