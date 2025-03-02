// https://leetcode.com/problems/string-matching-in-an-array/

// Method 1 (Loops, O(n2m2)):

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        for(int i=0; i<n; i++){
            bool added = false;
            for(int j=0; j<n; j++){
                if(i == j or words[i].length() > words[j].length()){
                    continue;
                }
                int ni = words[i].length();
                int nj = words[j].length();
                for(int k=0; k+ni-1<nj; k++){
                    int l = 0;
                    while(l<ni){
                        if(words[i][l] != words[j][k+l]){
                            break;
                        }
                        l++;
                    }
                    if(l == ni){
                        res.push_back(words[i]);
                        added = true;
                        break;
                    }
                }
                if(added){
                    break;
                }
            }
        }
        return res;
    }
};
