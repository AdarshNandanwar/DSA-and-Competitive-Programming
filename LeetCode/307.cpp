// https://leetcode.com/problems/range-sum-query-mutable/

// Method 1 (Fenwick Tree, O(n+qlogn)):

class NumArray {
    vector<int> bit;
    void updateBit(int index, int delta){
        index++;
        for(int i=index; i<bit.size(); i += (i&(-i))){
            bit[i] += delta;
        }
    }
    int prefixSum(int index){
        if(index<0){
            return 0;
        }
        index++;
        int sum = 0;
        for(int i=index; i>0; i -= (i&(-i))){
            sum += bit[i];
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        bit = vector<int>(n+1, 0);
        for(int i=0; i<n; i++){
            updateBit(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int prevVal = sumRange(index, index);
        int delta = val-prevVal;
        updateBit(index, delta);
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right)-prefixSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// Method 2 (Fenwick Tree with extra vector, O(n+qlogn));

class NumArray {
public:
    
    vector<int> fenwick_tree;
    vector<int> v;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        fenwick_tree = vector<int>(n+1, 0);
        v = vector<int>(n, 0);
        for(int i = 0; i<n; i++){
            v[i] = nums[i];
            update_fenwick_tree(i, nums[i]);
        }
    }
    
    void update_fenwick_tree(int index, int val){
        // fenwick tree vector is 1 indexed
        index++;
        while(index<fenwick_tree.size()){
            fenwick_tree[index] += val;
            index += (index&(-index));
        }
    }
    
    int get_cumulative_sum(int index){
        // fenwick tree vector is 1 indexed
        index++;
        int res = 0;
        while(index>0){
            res += fenwick_tree[index];
            index -= (index&(-index));
        }
        return res;
    }
    
    void update(int index, int val) {
        update_fenwick_tree(index, val-v[index]);
        v[index] = val;
    }
    
    int sumRange(int left, int right) {
        return get_cumulative_sum(right)-get_cumulative_sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// Method 2 (TLE, O(n2) as set iterator is Bidirectional and not random access):

class NumArray {
public:
    
    vector<int> v;
    // {value, set of index where it appers}
    unordered_map<int, set<int>> m;
    
    NumArray(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            v.push_back(nums[i]);
            m[nums[i]].insert(i);
        }
    }
    
    void update(int index, int val) {
        m[v[index]].erase(index);
        m[val].insert(index);
        v[index] = val;
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        for(auto &i:m){
            auto end = i.second.upper_bound(right);
            auto it = i.second.lower_bound(left);
            int count = 0;
            while(it != end) {
                count++;
                it++;
            }
            res += i.first*count;
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */