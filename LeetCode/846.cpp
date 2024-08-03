// https://leetcode.com/problems/hand-of-straights/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        // Use the fact that if freq of previous card value is 0,
        // the current card is the start of one of the sequences.

        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[hand[i]]++;
        }

        while(freq.size()){
            int randomCard = freq.begin()->first;

            int groupStartCard = randomCard;
            while(freq.count(groupStartCard-1)){
                groupStartCard--;
            }

            while(groupStartCard <= randomCard){
                if(freq.count(groupStartCard) == 0){
                    groupStartCard++;
                    continue;
                }

                for(int i=0; i<groupSize; i++){
                    int curCard = groupStartCard + i;
                    if(freq.count(curCard) == 0){
                        return false;
                    }
                    freq[curCard]--;
                    if(freq[curCard] == 0){
                        freq.erase(curCard);
                    }
                }
            }

        }
        
        return true;
    }
};

// Method 2 (Ordered Map, O(nlogn)):

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[hand[i]]++;
        }

        while(freq.size()){
            auto smallestCardEntry = freq.begin();
            int smallestCard = smallestCardEntry->first;
            freq[smallestCard]--;
            if(freq[smallestCard] == 0){
                freq.erase(smallestCard);
            }

            for(int i=1; i<groupSize; i++){
                int curCard = smallestCard + i;
                if(freq.count(curCard) == 0){
                    return false;
                }
                freq[curCard]--;
                if(freq[curCard] == 0){
                    freq.erase(curCard);
                }
            }
        }
        
        return true;
    }
};
