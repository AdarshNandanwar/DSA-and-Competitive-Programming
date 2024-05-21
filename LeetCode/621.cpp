// https://leetcode.com/problems/task-scheduler/

// Method 0 (Greedy, More Optimized, O(n)):

class Solution {
public:
    int leastInterval(vector<char>& tasks, int cd) {
        int n = tasks.size(), maxFreq = 0, maxFreqCount = 0;
        if(n <= 1) return n;
        
        vector<int> freq(26, 0);
        for(auto i:tasks){
            freq[i-'A']++;
            if(maxFreq < freq[i-'A']){
                maxFreq = freq[i-'A'];
                maxFreqCount = 1;                
            } else if(maxFreq == freq[i-'A']){
                maxFreqCount++;      
            }
        }
        
        return max(n, (cd+1)*(maxFreq-1)+maxFreqCount);
    }
};

// Method 1 (Greedy, O(n)):

class Solution {
public:
    int leastInterval(vector<char>& tasks, int cd) {
        int n = tasks.size(), maxFreq = 0, maxFreqCount = 0, len = 0;
        if(n <= 1) return n;
        
        vector<int> freq(26, 0);
        for(auto i:tasks){
            freq[i-'A']++;
            if(maxFreq < freq[i-'A']){
                maxFreq = freq[i-'A'];
                maxFreqCount = 1;                
            } else if(maxFreq == freq[i-'A']){
                maxFreqCount++;      
            }
        }
        
        int gapCount = maxFreq-1, gapLen = cd-(maxFreqCount-1);
        int idleCount = (gapCount*gapLen)-(n-maxFreqCount*maxFreq);
        return max(n, n+idleCount);
    }
};

// Alternate Code:

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalTasks = tasks.size();

        vector<int> freq(26, 0);
        int maxFreq = 0;
        for(const char task:tasks){
            freq[task-'A']++;
            if(freq[task-'A'] > maxFreq){
                maxFreq = freq[task-'A'];
            }
        }

        int idleTime = n*(maxFreq-1);
        int maxFreqCount = 0;
        for(int i=0; i<26; i++){
            if(freq[i] == maxFreq){
                maxFreqCount++;
            }
        }
        
        int remainingTasks = totalTasks - maxFreq - (maxFreqCount-1);
        // Max freq task that forms boundary of buckets + Extra extension after last boundary + Extra tasks if they are more than idle Time
        // [x...x...x] (= 3)  + [x...x...xyz] (= 3) = [x***x***xyz] (= 6) + [x***abx***cdexyz] (= 5)
        return maxFreq + (maxFreqCount-1) + idleTime + max(remainingTasks-idleTime, 0);
    }
};

// Method 2 (Greedy, O(n*tasks.size()):

struct Cmp{
    bool operator()(const pair<int, int> & a, const pair<int, int> & b) const { 
        return a.second == b.second ? a.first < b.first : a.second > b.second; 
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int cd) {
        int n = tasks.size(), len = 0;
        vector<int> freq(26, 0), cooldown(26, 0);
        for(auto i:tasks) freq[i-'A']++;
        // {char, freq}
        set<pair<int, int>, Cmp> s;
        for(int i = 0; i<26; i++) if(freq[i]) s.insert({i, freq[i]});
        
        while(s.size()){
            len++;
            for(int i = 0; i<26; i++) cooldown[i] = max(0, cooldown[i]-1);
            for(auto itr = s.begin(); itr != s.end(); itr++){
                if(cooldown[itr->first] == 0){
                    auto cur = *itr;
                    s.erase(itr);
                    cur.second--;
                    if(cur.second){
                        cooldown[cur.first] = cd+1;
                        s.insert(cur);
                    }
                    break;
                }
            }
        }
        return len;
    }
};