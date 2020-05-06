// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& A) {
//         deque<int> odd, even;
//         for(auto i:A){
//             if(i%2){
//                 odd.push_back(i);
//             } else {
//                 even.push_back(i);
//             }
//         }
//         for(int i = 0; i<A.size(); i++){
//             if(i%2){
//                 A[i] = odd.front();
//                 odd.pop_front();
//             } else {
//                 A[i] = even.front();
//                 even.pop_front();
//             }
//         }
//         return A;
//     }
// };

// O(1) Space Solution

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd= 1, even = 0, n = A.size();
        while(odd<n && even<n){
            while(odd<n && A[odd]%2){
                odd+=2;
            }
            while(even<n && !(A[even]%2)){
                even+=2;
            }
            if(odd<n && even<n){
                swap(A[odd], A[even]);
                odd+=2;
                even+=2;
            }
        }
        return A;
    }
};