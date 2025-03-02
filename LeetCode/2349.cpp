// https://leetcode.com/problems/design-a-number-container-system/

// Method 1 (Hash Map, O(n)):

class NumberContainers {
    unordered_map<int, int> data;
    unordered_map<int, set<int>> indexes;
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(data.count(index)){
            int val = data[index];
            indexes[val].erase(index);
        }
        data[index] = number;
        indexes[number].insert(index);
    }
    
    int find(int number) {
        if(indexes.count(number) == 0 or indexes[number].size() == 0){
            return -1;
        }
        return *indexes[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
