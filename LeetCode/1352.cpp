// https://leetcode.com/problems/product-of-the-last-k-numbers/

// Method 1 (Vector, O(n)):

class ProductOfNumbers {
    vector<long long> prefixProd;
public:
    ProductOfNumbers() {
        prefixProd.clear(); // Product of all trailing non-zero elements
    }
    
    void add(int num) {
        if(num == 0){
            prefixProd.clear();
        } else {
            if(prefixProd.empty()){
                prefixProd.push_back(num);
            } else {
                prefixProd.push_back(prefixProd.back() * num);
            }
        }
    }
    
    int getProduct(int k) {
        int n = prefixProd.size();
        if(k > n){
            return 0;
        } else if(k == n){
            return prefixProd.back();
        } else {
            int res = prefixProd.back();
            res /= prefixProd[n-k-1];
            return res;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

//  Attempt 1 (1D DP logic, O(n), MLE (int overflow)):

class ProductOfNumbers {
    vector<long long> prefixProd;
    vector<int> zeroCount;
public:
    ProductOfNumbers() {
        prefixProd.clear();
    }
    
    void add(int num) {
        if(prefixProd.empty()){
            if(num == 0){
                prefixProd.push_back(1);
                zeroCount.push_back(1);
            } else {
                prefixProd.push_back(num);
                zeroCount.push_back(0);
            }
        } else {
            if(num == 0){
                prefixProd.push_back(prefixProd.back());
                zeroCount.push_back(zeroCount.back() + 1);
            } else {
                prefixProd.push_back(prefixProd.back() * num);
                zeroCount.push_back(zeroCount.back());
            }
        }
    }
    
    int getProduct(int k) {
        int n = prefixProd.size();
        if(n == k){
            if(zeroCount.back() > 0){
                return 0;
            } else {
                return prefixProd.back();
            }
        } else {
            if(zeroCount.back() > zeroCount[n-k-1]){
                return 0;
            } else {
                int res = prefixProd.back();
                if(prefixProd[n-k-1] != 0){
                    res /= prefixProd[n-k-1];
                }
                return res;
            }
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
