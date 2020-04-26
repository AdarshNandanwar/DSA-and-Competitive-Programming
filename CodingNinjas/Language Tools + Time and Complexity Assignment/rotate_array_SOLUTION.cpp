void swapp(int *input, int i, int j)
{
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}
void Reverse(int *input, int start, int end)
{
    int i = start, j = end;
    while (i < j)
    {
        swapp(input, i, j);
        i++;
        j--;
    }
}
void Rotate(int *input, int d, int n)
{
    if (d >= n)
        d = d % n;
    Reverse(input, 0, n - 1);
    Reverse(input, 0, n - d - 1);
    Reverse(input, n - d, n - 1);
}