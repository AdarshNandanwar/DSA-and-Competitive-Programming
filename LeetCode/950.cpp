// https://leetcode.com/problems/reveal-cards-in-increasing-order/

// Method 1 (Queue, O(n)):

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[q.front()] = deck[i];
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};
