    int pprod=1, nprod=-1, max_prod=INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>0){
            pprod*=arr[i];
            nprod*=arr[i];
        }else if(arr[i]<0){
            int temp=pprod;
            pprod=nprod*arr[i];
            nprod=temp*arr[i];
        }else{
            max_prod=max(max_prod, pprod);
            pprod=1;
            nprod=-1;
        }
    }
    max_prod=max(max_prod, pprod);
    return max_prod;