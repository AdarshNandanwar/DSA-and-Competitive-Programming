


bool predicate(int x){

}

int main() {

    int lo = 0, hi = n-1;

    // FT Last F
    while(lo < hi){
        int mid = lo + (hi-lo+1)/2;
        if(predicate(mid)){
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    if(!predicate(lo)){     // <= Notice the NOT 
        return lo;
    } else {
        return -1;
    }

    // FT First T
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        if(predicate(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if(predicate(lo)){
        return lo;
    } else {
        return -1;
    }

}