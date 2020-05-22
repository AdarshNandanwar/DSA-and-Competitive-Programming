// https://leetcode.com/problems/prison-cells-after-n-days/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        string curr = "";
        for(int i = 0; i<8; i++){
            curr += to_string(cells[i]);
        }
        string orig = curr;
        unordered_map<string, int> m;
        int i;
        for(i = 0; i<=256 && i<=N; i++){
            if(m.find(curr) != m.end()){
                break;
            } else {
                m[curr] = i;
                string next = "00000000";
                for(int j = 1; j<7; j++){
                    if((curr[j-1] == '1' && curr[j+1] == '1') || (curr[j-1] == '0' && curr[j+1] == '0')){
                        next[j] = '1';
                    } else {
                        next[j] = '0';
                    }
                }
                curr = next;
            }
        }
        int n;
        if(m[curr] > N){
            n = N;
        } else {
            int cycle_length = i-m[curr];
            n = m[curr] + ((N-m[curr])%cycle_length);
        }
        curr = orig;
        for(int i = 0; i<n; i++){
            string next = "00000000";
            for(int j = 1; j<7; j++){
                if((curr[j-1] == '1' && curr[j+1] == '1') || (curr[j-1] == '0' && curr[j+1] == '0')){
                    next[j] = '1';
                } else {
                    next[j] = '0';
                }
            }
            curr = next;
        }
        vector<int> ans;
        for(int i =0; i<8; i++){
            ans.push_back(curr[i]-'0');
        }
        return ans;
    }
};