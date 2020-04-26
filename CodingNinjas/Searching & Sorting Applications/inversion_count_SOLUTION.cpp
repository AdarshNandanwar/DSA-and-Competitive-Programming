long long Merge(int A[], int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    long long inv_cnt = 0;
    int temp[(right - left + 1)];
    while ((i < mid) && (j <= right))
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            inv_cnt += (mid - i);
        }
    }
    while (i < mid)
    {
        temp[k++] = A[i++];
    }
    while (j <= right)
    {
        temp[k++] = A[j++];
    }
    for (i = left, k = 0; i <= right; i++, k++)
    {
        A[i] = temp[k];
    }
    return inv_cnt;
}
long long MergeSort(int A[], int left, int right)
{
    long long inv_cnt = 0;
    if (right > left)
    {
        int mid = (right + left) / 2;
        /*
Divide the array into two parts
total inversion count will be the
sum of inv_cnt of left part +
inv_cnt of right part + inv_cnt of
their combined part.
*/
        inv_cnt = MergeSort(A, left, mid);
        inv_cnt += MergeSort(A, mid + 1, right);
        //Merger both parts and count their combined inversions
        inv_cnt += Merge(A, left, mid + 1, right);
    }
    return inv_cnt;
}
long long solve(int A[], int n)
{
    return MergeSort(A, 0, n - 1);
}