// Minimum Number of Chocolates
// Send Feedback
// Noor is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line and each of them has a score according to performance. Noor wants to give at least 1 chocolate to each student. She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
// Note that when two students have equal score they are allowed to have different number of chocolates.
// Input Format:
// First Line: Integer N, the number of students in Noor’s class. 
// Second Line: Each of the student's score separated by spaces.
// Output Format:
// Output a single line containing the minimum number of chocolates Noor must give.
// Input Constraints
//  1 <= N <= 100000
//  1 <= score <= 100000
// Sample Input:
// 4
// 1 4 4 6
// sample Output:
// 6
// Sample Input:
// 3
// 8 7 5
// sample Output:
// 6

#include<bits/stdc++.h>
using namespace std;

int getMin(int *arr, int n){
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */
    int total_cost = 1, prev_cost = 1;
    int buffer_count[100000];
    for(int i=0; i<100000; i++){
        buffer_count[i] = 0;
    }
    stack<int> buffer;
    buffer.push(0);
    buffer_count[0] = INT_MAX;
    for(int i = 1; i<n; i++){
        if(arr[i-1] < arr[i]){
            buffer.push(i);
            buffer_count[i] = INT_MAX;  
            prev_cost++;
            total_cost += prev_cost;
        } else if (arr[i-1] > arr[i]){
            if(prev_cost == 1){
                total_cost += (i - buffer.top() + 1);
                buffer_count[buffer.top()]--;
                if(buffer_count[buffer.top()] == 0 && buffer.size() != 1){
                    buffer.pop();
                }
            } else {
                total_cost++;
                if(prev_cost - 2 > 0){
                    buffer.push(i);
                    buffer_count[i] = prev_cost - 2;                    
                }
                prev_cost = 1;
            }
        } else {
            if(prev_cost != 1){
                if(prev_cost - 2 > 0){
                    buffer.push(i);
                    buffer_count[i] = prev_cost - 2;
                }
            }
            prev_cost = 1;
            total_cost++;
        }
    }
    return total_cost;
}


int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<getMin(arr, n)<<endl;
    delete [] arr;
    return 0;
}