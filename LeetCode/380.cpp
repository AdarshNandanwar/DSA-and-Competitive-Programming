// https://leetcode.com/problems/insert-delete-getrandom-o1/

// Method 1 (vector, hash map, O(1) time):

class RandomizedSet {
public:
    vector<int> m_Data;
    unordered_map<int, int> m_Index;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(m_Index.count(val) != 0){
            return false;
        }
        m_Data.push_back(val);
        m_Index[val] = m_Data.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m_Index.count(val) == 0){
            return false;
        }

        int size = m_Data.size();
        int index = m_Index[val];

        // Here, the order of the following operations is very important due to
        // 1. Swapping locations (indices)
        // 2. Handle the case where m_Size = 1
        swap(m_Data[index], m_Data[size-1]);
        m_Index[m_Data[index]] = index;
        m_Index.erase(m_Data[size-1]);
        m_Data.pop_back();

        return true;
    }
    
    int getRandom() {
        int index = rand() % m_Data.size();
        return m_Data[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Method 2 (Static array, hash map, O(1) time):

class RandomizedSet {
public:
    int m_Data[200000];
    int m_Size;
    unordered_map<int, int> m_Index;

    RandomizedSet() {
        m_Size = 0;
    }
    
    bool insert(int val) {
        if(m_Index.count(val) != 0){
            return false;
        }
        m_Data[m_Size] = val;
        m_Index[val] = m_Size;
        m_Size++;
        return true;
    }
    
    bool remove(int val) {
        if(m_Index.count(val) == 0){
            return false;
        }
        int index = m_Index[val];

        // Here, the order of the following operations is very important due to
        // 1. Swapping locations (indices)
        // 2. Handle the case where m_Size = 1
        swap(m_Data[index], m_Data[m_Size-1]);
        m_Index[m_Data[index]] = index;
        m_Index.erase(m_Data[m_Size-1]); // m_Index.erase(val);

        m_Size--;
        return true;
    }
    
    int getRandom() {
        int index = rand() % m_Size;
        return m_Data[index];
    }
};

// Method 3 (list, hash map, O(n) time for random):

class RandomizedSet {
public:
    
    unordered_map<int, list<int>::iterator> m;
    list<int> l;
    
    RandomizedSet() {
        l.clear();
        m.clear();
    }
    
    bool insert(int val) {
        if(m.count(val)) return false;
        l.push_back(val);
        m[val] = prev(l.end());
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        l.erase(m[val]);
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return *next(l.begin(), rand()%l.size());
    }
};
