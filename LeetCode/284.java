// https://leetcode.com/problems/peeking-iterator/

// Method 1 (Keep iterator one step ahead, O(1)):

// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    private boolean hasCur = false;
    private int cur = 0;
    private Iterator<Integer> iterator;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
        if(iterator.hasNext()){
            this.hasCur = true;
            this.cur = iterator.next();
        } else {
            this.hasCur = false;
        }
        this.iterator = iterator;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return cur;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    int prev = this.cur;
        if(iterator.hasNext()){
            this.cur = iterator.next();
        } else {
            this.hasCur = false;
        }
        return prev;
	}
	
	@Override
	public boolean hasNext() {
	    return this.hasCur;
	}
}