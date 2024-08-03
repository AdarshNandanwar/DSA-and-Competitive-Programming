// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Method 1 (Fenwick Tree, O(nlong)):

class Solution {
    void insert(vector<int> & bit, int index, int val){
        index++;
        for(int i=index; i<bit.size(); i += (i&(-i))){
            bit[i] += val;
        }
    }
    int getPrefixSum(vector<int> & bit, int index){
        index++;
        int sum = 0;
        for(int i=index; i>0; i -= (i&(-i))){
            sum += bit[i];
        }
        return sum;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        // PreProcess - Make all valus positive
        for(int i=0; i<n; i++){
            nums[i] += 1e4;
        }

        // Fenwick Tree
        vector<int> bit(2e4 + 2); // getPrefixSum(i) = freq of elements [0, 1, 2, ... i]

        vector<int> res(n);
        for(int i=n-1; i>=0; i--){
            res[i] = getPrefixSum(bit, nums[i]-1);
            insert(bit, nums[i], 1);
        }

        return res;
    }
};

// Method 2 (Merge Sort, O(nlogn)):

class Solution {
public:
    void mergeArrays(vector<pair<int, int>> & toSort, int low, int mid, int hi, vector<int> & counts){
        vector<pair<int, int>> sortedArray;
        int p1 = low, p2 = mid+1;
        while(p1<=mid and p2<=hi){
            if(toSort[p1].first <= toSort[p2].first){
                counts[toSort[p1].second] += (p2-(mid+1));
                sortedArray.push_back(toSort[p1]);
                p1++;
            } else {
                sortedArray.push_back(toSort[p2]);
                p2++;
            }
        }
        while(p1<=mid){
            counts[toSort[p1].second] += (p2-(mid+1));
            sortedArray.push_back(toSort[p1]);
            p1++;
        }
        while(p2<=hi){
            sortedArray.push_back(toSort[p2]);
            p2++;
        }
        for(int i=low; i<=hi; i++){
            toSort[i] = sortedArray[i-low];
        }
    }
    
    void mergeSort(vector<pair<int, int>> & toSort, int low, int hi, vector<int> & counts){
        if(low >= hi){
            return;
        }
        int mid = low+(hi-low)/2;
        mergeSort(toSort, low, mid, counts);
        mergeSort(toSort, mid+1, hi, counts);
        mergeArrays(toSort, low, mid, hi, counts);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        // {value, index}
        vector<pair<int, int>> toSort;
        for(int i=0; i<n; i++){
            toSort.push_back({nums[i], i});
        }
        mergeSort(toSort, 0, n-1, counts);
        return counts;
    }
};

// Alternate Code:

class Solution {
    void mergeVectors(vector<int> & nums, int left, int mid, int right, vector<int> & smallerRight, vector<int> & originalIndex, vector<int> & buffer, vector<int> & newIndex){
        int n = nums.size();
        int p1 = left, p2 = mid+1;
        int bufferIndex = 0;
        while(p1<=mid and p2<=right){
            if(nums[p1] > nums[p2]){
                buffer[bufferIndex] = nums[p2];
                newIndex[bufferIndex] = originalIndex[p2];
                p2++;
            } else {
                smallerRight[originalIndex[p1]] += (p2-mid-1);
                buffer[bufferIndex] = nums[p1];
                newIndex[bufferIndex] = originalIndex[p1];
                p1++;                
            }
            bufferIndex++;
        }
        while(p1<=mid){
            smallerRight[originalIndex[p1]] += (right-mid);
            buffer[bufferIndex] = nums[p1];
            newIndex[bufferIndex] = originalIndex[p1];
            bufferIndex++;
            p1++; 
        }
        while(p2<=right){
            buffer[bufferIndex] = nums[p2];
            newIndex[bufferIndex] = originalIndex[p2];
            bufferIndex++;
            p2++;
        }
        for(int i=0; i<right-left+1; i++){
            nums[i+left] = buffer[i];
            originalIndex[i+left] = newIndex[i];
        }
    }
    
    void mergeSort(vector<int> & nums, int left, int right, vector<int> & smallerRight, vector<int> & originalIndex, vector<int> & buffer, vector<int> & newIndex){
        if(left>=right){
            return;
        }
        int mid = left+(right-left)/2;
        mergeSort(nums, left, mid, smallerRight, originalIndex, buffer, newIndex);
        mergeSort(nums, mid+1, right, smallerRight, originalIndex, buffer, newIndex);
        mergeVectors(nums, left, mid, right, smallerRight, originalIndex, buffer, newIndex);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> smallerRight(n, 0);
        vector<int> originalIndex(n, 0);
        vector<int> buffer(n, 0);           // memory allocation done once here to prevent TLE
        vector<int> newIndex(n, 0);         // memory allocation done once here to prevent TLE
        for(int i=0; i<n; i++){
            originalIndex[i] = i;
        }
        mergeSort(nums, 0, n-1, smallerRight, originalIndex, buffer, newIndex);
        return smallerRight;
    }
};

// Method 3 (AVL Tree, O(nlogn)):

class Solution {
public:
    struct TreeNode {
        int val;
        int height;
        int size;
        TreeNode * left;
        TreeNode * right;
        TreeNode(int val): val(val), height(1), size(1), left(nullptr), right(nullptr){};
    };

    int getHeight(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        return root->height;
    }

    int getSize(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        return root->size;
    }

    TreeNode * rotateRight(TreeNode* root){
        TreeNode * left = root->left;
        root->left = left->right;
        left->right = root;
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        left->height = 1 + max(getHeight(left->left), getHeight(left->right));
        root->size -= (1 + getSize(left->left));
        left->size = (1 + getSize(left->left) + getSize(left->right));
        return left;
    }

    TreeNode * rotateLeft(TreeNode* root){
        TreeNode * right = root->right;
        root->right = right->left;
        right->left = root;
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        right->height = 1 + max(getHeight(right->left), getHeight(right->right));
        root->size -= (1 + getSize(right->right));
        right->size = (1 + getSize(right->left) + getSize(right->right));
        return right;
    }

    TreeNode * insert(TreeNode * root, int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        
        if(val < root->val){
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        root->size ++;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if(abs(leftHeight-rightHeight) > 1){
            // Imbalance
            if(val < root->val){
                if(val < root->left->val){
                    // LL-imbalance
                    root = rotateRight(root);
                } else {
                    // LR-imbalance
                    root->left = rotateLeft(root->left);
                    root = rotateRight(root);
                }
            } else {
                if(val < root->right->val){
                    // RL-imbalance
                    root->right = rotateRight(root->right);
                    root = rotateLeft(root);
                } else {
                    // RR-imbalance
                    root = rotateLeft(root);
                }
            }
        }
        return root;
    }

    int countSmaller(TreeNode * root, int val){
        if(root == NULL){
            return 0;
        }
        int count = 0;
        if(val <= root->val){
            count += countSmaller(root->left, val);
        } else {
            count ++;
            count += getSize(root->left);
            count += countSmaller(root->right, val);
        }
        return count;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts;
        TreeNode * root = nullptr;
        for(int i=n-1; i>=0; i--){
            counts.push_back(countSmaller(root, nums[i]));
            root = insert(root, nums[i]);
        }
        return vector<int>(counts.rbegin(), counts.rend());
    }
};