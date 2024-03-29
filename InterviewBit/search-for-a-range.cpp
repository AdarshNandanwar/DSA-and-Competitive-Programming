// https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    if(binary_search(A.begin(), A.end(), B)){
        return {lower_bound(A.begin(), A.end(), B)-A.begin(), upper_bound(A.begin(), A.end(), B)-A.begin()-1};
    } else {
        return {-1, -1};
    }
}
