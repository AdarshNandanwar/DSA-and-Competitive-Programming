#include <bits/stdc++.h>
using namespace std;
void findIndexes(int input[], int currIndex, int size, int x, int output[], int &k)
{
    if (currIndex == size)
        return;
    if (input[currIndex] == x)
    {
        output[k] = currIndex;
        k++;
    }
    findIndexes(input, currIndex + 1, size, x, output, k);
}
int allIndexes(int input[], int size, int x, int output[])
{
    /* Don't write main().
Don't read input, it is passed as function argument.
Save all the indexes in the output array passed and return the size of output
array.
Taking input and printing output is handled automatically.
*/
    int k = 0;
    findIndexes(input, 0, size, x, output, k);
    return k;
}