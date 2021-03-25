// https://leetcode.com/problems/sliding-window-median/

// NOTE: The value of the iterator dosen't change if the elements are inserted or deleted in the set
// i.e. location of the data dosen't change
// althought the relative distance from the begin() will change.
// kind of like a linked list indertion and deletion

// Code 1 (Clean code):

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        long long int n = nums.size();
        multiset<long long int> s(nums.begin(), nums.begin()+k);
        
        // upper median in even k
        auto it = next(s.begin(), k/2);
        
        long long int i = k;
        
        while(true){
            
            // pushing median
            ans.push_back((*it + *prev(it, 1-(k&1)))/2.0);
            
            if(i == n){
                return ans;
            }
            
            // adding nums[i]
            s.insert(nums[i]);
            if(k&1 and nums[i] >= *it)
                it++;
            else if(!(k&1) and nums[i] < *it)
                it--;            
            
            long long int new_k = k+1;            
            
            // deleting nums[i-k];
            auto it1 = s.lower_bound(nums[i-k]);
            if(it1 == it){
                if(new_k&1)
                    it++;
                else
                    it--;
            } else {
                if(nums[i-k] <= *it and new_k&1)
                    it++;
                else if(nums[i-k] > *it and !(new_k&1))
                    it--;
            }
            s.erase(it1);
            
            i++;
            
        }
        
        return ans;
    }
};

// Code 2 (My code):

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        long long int n = nums.size();
        multiset<long long int> s;
        
        for(int i =0; i<k; i++){
            s.insert(nums[i]);
        }
        
        // lower median in even k

        int m = k/2;
        if(k%2 == 0){
            m--;
        }
        
        auto median = s.begin();
        
        for(int i = 0; i<m; i++){
            median++;
        }
        
        if(k%2 == 0){
            auto median2 = median;
            median2++;
            ans.push_back((*median + *median2)/2.0);
        } else {
            ans.push_back(*median);
        }
        
        int p1 = 0, p2 = k;
        while(p2<n){
            
            // insert element at p2
            if(k%2 == 0){
                if(nums[p2] < *median){         
                    // no equality as if the element to be inserted is present in the multiset then the element is inserted in the end of the repeating elements
                    s.insert(nums[p2]);
                } else {
                    s.insert(nums[p2]);
                    median++;
                }
            } else {
                if(nums[p2] < *median){
                    s.insert(nums[p2]);
                    median--;
                } else {
                    s.insert(nums[p2]);
                }
            }
            
            // delete element at p1
            
            if((k+1)%2 == 0){
                if(nums[p1] <= *median){
                    median++;
                    s.erase(s.lower_bound(nums[p1]));
                } else {
                    s.erase(s.find(nums[p1]));
                }
            } else {
                if(nums[p1] < *median){
                    s.erase(s.find(nums[p1]));
                } else {
                    median--;
                    auto it2 = s.upper_bound(nums[p1]);
                    it2--;
                    s.erase(it2);
                }
            }
            
            p1++;
            p2++;
            
            if(k%2 == 0){
                auto median2 = median;
                median2++;
                ans.push_back((*median + *median2)/2.0);
            } else {
                ans.push_back(*median);
            }
        }
            
        return ans;
    
    }
};