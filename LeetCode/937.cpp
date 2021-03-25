// https://leetcode.com/problems/reorder-data-in-log-files/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<vector<string>> letterLogs, digitLogs;
        string cur;
        for(int i = 0; i<n; i++){
            vector<string> lv;
            istringstream iss(logs[i]);
            getline(iss, cur, ' ');
            lv.push_back(cur);
            lv.push_back(logs[i].substr(cur.length()+1, logs[i].length()-(cur.length()+1)));
            if(isdigit(lv[1][0])) digitLogs.push_back(lv);
            else letterLogs.push_back(lv);
        }
        
        sort(letterLogs.begin(), letterLogs.end(), [](const vector<string> & a, const vector<string> & b){
            return a[1] == b[1] ? a[0]<b[0] : a[1] < b[1];
        });
        int index = 0;
        for(auto i:letterLogs) logs[index++] = i[0]+" "+i[1];
        for(auto i:digitLogs) logs[index++] = i[0]+" "+i[1];
        return logs;
    }
};