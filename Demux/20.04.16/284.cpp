// https://leetcode.com/problems/peeking-iterator/

// Method 1 

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    
    int cache;
    bool cacheValid;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    cacheValid = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(cacheValid){
            return cache;
        }
        cache = Iterator::next();
        cacheValid = true;
        return cache;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(cacheValid){
            cacheValid = false;
            return cache;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
        if(cacheValid){
            return true;
        }
        return Iterator::hasNext();
	}
};

// Method 2

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    
    int cache;
    bool cacheValid;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    cacheValid = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        Iterator * it = new Iterator(*this);
        return it->next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        return Iterator::next();
	}
	
	bool hasNext() const {
        return Iterator::hasNext();
	}
};