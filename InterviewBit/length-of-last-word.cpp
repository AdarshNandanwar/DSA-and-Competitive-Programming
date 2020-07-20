// https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) {
    istringstream iss(A);
    string last;
    while(getline(iss, last, ' ')){};
    return last.length();
}
