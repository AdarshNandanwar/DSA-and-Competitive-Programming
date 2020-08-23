// https://www.interviewbit.com/problems/pretty-json/

string getNewLine(int bracketCount){
    string line = "";
    for(int j = 0; j<bracketCount; j++) line += "\t";
    return line;
}

void parseJSON(const string & A, int bracketCount, int st, int end, vector<string> & ans);

void parseArray(const string & A, int bracketCount, int st, int end, vector<string> & ans){
    string line;
    int prevSt = st, curBracketCount = 0;
    for(int i = st; i<=end+1; i++){
        if((A[i] == ',' and curBracketCount == 0) or i == end+1){
            if(A[prevSt] == '{'){
                ans.push_back(getNewLine(bracketCount)+"{");
                parseJSON(A, bracketCount+1, prevSt+1, i-2, ans);
                ans.push_back(getNewLine(bracketCount)+"}"+(i!=end+1 ? "," : ""));
            } else if(A[prevSt] == '['){
                ans.push_back(getNewLine(bracketCount)+"[");
                parseArray(A, bracketCount+1, prevSt+1, i-2, ans);
                ans.push_back(getNewLine(bracketCount)+"]"+(i!=end+1 ? "," : ""));
            } else {
                line = getNewLine(bracketCount);
                line += A.substr(prevSt, i-prevSt);
                if(i != end+1) line += ",";
                ans.push_back(line);
            }
            prevSt = i+1;
        } else if(A[i] == '[' or A[i] == '{'){
            curBracketCount++;
        } else if(A[i] == ']' or A[i] == '}'){
            curBracketCount--;
        }
    }
}

void parseEntry(const string & A, int bracketCount, int st, int end, vector<string> & ans, bool last){
    int i = st;
    while(A[i] != ':') i++;
    string key = A.substr(st, i-st), val = A.substr(i+1, end-i);
    string line = getNewLine(bracketCount);
    line = line+key+":";
    if(val[0] == '{'){
        ans.push_back(line);
        ans.push_back(getNewLine(bracketCount)+"{");
        parseJSON(A, bracketCount+1, i+2, end-1, ans);
        line = getNewLine(bracketCount);
        line.push_back('}');
    } else if(val[0] == '['){
        ans.push_back(line);
        ans.push_back(getNewLine(bracketCount)+"[");
        parseArray(A, bracketCount+1, i+2, end-1, ans);
        line = getNewLine(bracketCount);
        line.push_back(']');
    } else {
        line += val;
    }
    if(!last) line.push_back(',');
    ans.push_back(line);
}

void parseJSON(const string & A, int bracketCount, int st, int end, vector<string> & ans){
    string line;
    int prevSt = st, curBracketCount = 0;
    for(int i = st; i<=end; i++){
        if(A[i] == ',' and curBracketCount == 0){
            parseEntry(A, bracketCount, prevSt, i-1, ans, 0);
            prevSt = i+1;
        } else if(i == end){
            parseEntry(A, bracketCount, prevSt, i, ans, 1);
        } else if(A[i] == '[' or A[i] == '{'){
            curBracketCount++;
        } else if(A[i] == ']' or A[i] == '}'){
            curBracketCount--;
        }
    }
}

vector<string> Solution::prettyJSON(string A) {
    vector<string> ans;
    int n = A.length(), bracketCount = 0;
    if(n == 0) return {};
    string line;
    if(A[0] == '{'){
        ans.push_back(getNewLine(bracketCount)+"{");
        parseJSON(A, bracketCount+1, 1, n-2, ans);
        ans.push_back(getNewLine(bracketCount)+"}");
    } else if(A[0] == '['){
        ans.push_back(getNewLine(bracketCount)+"[");
        parseArray(A, bracketCount+1, 1, n-2, ans);
        ans.push_back(getNewLine(bracketCount)+"]");
    }
    return ans;
}
