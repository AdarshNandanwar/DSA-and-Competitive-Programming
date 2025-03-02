
int getPrefixSum(const vector<int> & BIT, int index){
    index++;
    int n = BIT.size();
    int sum = 0;
    for(int i = index; i>=1; i -= i&(-i)){
        sum += BIT[i];
    }
    return sum;
}

void updateBIT(vector<int> & BIT, int index, int delta){
    index++;
    int n = BIT.size();
    for(int i = index; i<=n; i += i&(-i)){
        BIT[i] += delta;
    }
}

int getValue(const vector<int> & BIT, int index){
    if(index == 0){
        return getPrefixSum(BIT, 0);
    }
    return getPrefixSum(BIT, index) - getPrefixSum(BIT, index-1);
}

int main(){
    vector<int> BIT(n+1);
    for(int i=0; i<n; i++){
        updateBIT(BIT, i, v[i]);
    }
}