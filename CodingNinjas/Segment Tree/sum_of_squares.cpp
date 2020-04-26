// Sum Of Squares
// Send Feedback
// Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
// The sum of squares over a range with range updates of 2 types:
// 1) increment in a range
// 2) set all numbers the same in a range.
// Input
// There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
// The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

// 2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

// 1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

// 0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
// Output
// For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
// Input:
// 2
// 4 5
// 1 2 3 4
// 2 1 4
// 0 3 4 1
// 2 1 4
// 1 3 4 1
// 2 1 4
// 1 1
// 1
// 2 1 1
// Output:
// Case 1:
// 30
// 7
// 13
// Case 2:
// 1

#include<bits/stdc++.h>
using namespace std;

struct node_tree {
    int square_sum;
    int sum;
};

struct node_update {
    int type;
    int value;
};

void build_tree(int * arr, node_tree * tree, int tree_node, int start, int end){
    if(start == end){
        tree[tree_node].sum = arr[start];
        tree[tree_node].square_sum = arr[start]*arr[start];
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, 2*tree_node, start, mid);
    build_tree(arr, tree, 2*tree_node+1, mid+1, end);
    tree[tree_node].sum = tree[2*tree_node].sum + tree[2*tree_node+1].sum;
    tree[tree_node].square_sum = tree[2*tree_node].square_sum + tree[2*tree_node+1].square_sum;
    return;
}

void add_tree(node_update * lazy, node_tree * tree, int tree_node, int start, int end , int left, int right, int val){
    if(lazy[tree_node].value != 0){
        if(lazy[tree_node].type == 1){
            tree[tree_node].square_sum += (end-start+1)*lazy[tree_node].value*lazy[tree_node].value + 2*tree[tree_node].sum*lazy[tree_node].value;
            tree[tree_node].sum += (end-start+1)*lazy[tree_node].value;
            if(start != end){
                lazy[2*tree_node].value += lazy[tree_node].value;
                lazy[2*tree_node].type = 1;
                lazy[2*tree_node+1].value += lazy[tree_node].value;
                lazy[2*tree_node+1].type = 1;
            }
            lazy[tree_node] = {0,0};
        } else if(lazy[tree_node].type == 2){
            tree[tree_node].square_sum = (end-start+1)*lazy[tree_node].value*lazy[tree_node].value;
            tree[tree_node].sum = (end-start+1)*lazy[tree_node].value;
            if(start != end){
                lazy[2*tree_node].value = lazy[tree_node].value;
                lazy[2*tree_node].type = 2;
                lazy[2*tree_node+1].value = lazy[tree_node].value;
                lazy[2*tree_node+1].type = 2;
            }
            lazy[tree_node] = {0,0};
        }
    }

    if(start > end){
        return;
    }
    if(left > end || right < start){
        return;
    }
    if(left <= start && end <= right){
        tree[tree_node].square_sum += (end-start+1)*val*val + 2*tree[tree_node].sum*val;
        tree[tree_node].sum += (end-start+1)*val;
        if(start != end){
            lazy[2*tree_node].value += val;
            lazy[2*tree_node].type = 1;
            lazy[2*tree_node+1].value += val;
            lazy[2*tree_node+1].type = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    add_tree(lazy, tree, 2*tree_node, start, mid, left, right, val); 
    add_tree(lazy, tree, 2*tree_node+1, mid+1, end, left, right, val);
    tree[tree_node].sum = tree[2*tree_node].sum + tree[2*tree_node+1].sum;
    tree[tree_node].square_sum = tree[2*tree_node].square_sum + tree[2*tree_node+1].square_sum;
    return;
}

void set_tree(node_update * lazy, node_tree * tree, int tree_node, int start, int end , int left, int right, int val){
    if(lazy[tree_node].value != 0){
        if(lazy[tree_node].type == 1){
            tree[tree_node].square_sum += (end-start+1)*lazy[tree_node].value*lazy[tree_node].value + 2*tree[tree_node].sum*lazy[tree_node].value;
            tree[tree_node].sum += (end-start+1)*lazy[tree_node].value;
            if(start != end){
                lazy[2*tree_node].value += lazy[tree_node].value;
                lazy[2*tree_node].type = 1;
                lazy[2*tree_node+1].value += lazy[tree_node].value;
                lazy[2*tree_node+1].type = 1;
            }
            lazy[tree_node] = {0,0};
        } else if(lazy[tree_node].type == 2){
            tree[tree_node].square_sum = (end-start+1)*lazy[tree_node].value*lazy[tree_node].value;
            tree[tree_node].sum = (end-start+1)*lazy[tree_node].value;
            if(start != end){
                lazy[2*tree_node].value = lazy[tree_node].value;
                lazy[2*tree_node].type = 2;
                lazy[2*tree_node+1].value = lazy[tree_node].value;
                lazy[2*tree_node+1].type = 2;
            }
            lazy[tree_node] = {0,0};
        }
    }

    if(start > end){
        return;
    }
    if(left > end || right < start){
        return;
    }
    if(left <= start && end <= right){
        tree[tree_node].square_sum = (end-start+1)*val*val;
        tree[tree_node].sum = (end-start+1)*val;
        if(start != end){
            lazy[2*tree_node].value = val;
            lazy[2*tree_node].type = 2;
            lazy[2*tree_node+1].value = val;
            lazy[2*tree_node+1].type = 2;
        }
        return;
    }
    int mid = (start+end)/2;
    set_tree(lazy, tree, 2*tree_node, start, mid, left, right, val); 
    set_tree(lazy, tree, 2*tree_node+1, mid+1, end, left, right, val);
    tree[tree_node].sum = tree[2*tree_node].sum + tree[2*tree_node+1].sum;
    tree[tree_node].square_sum = tree[2*tree_node].square_sum + tree[2*tree_node+1].square_sum;
    return;
}

node_tree sum_square_tree(node_update * lazy, node_tree * tree, int tree_node, int start, int end, int left, int right){
    
    if(lazy[tree_node].value != 0){
        if(lazy[tree_node].type == 1){
            tree[tree_node].square_sum += (end-start+1)*lazy[tree_node].value*lazy[tree_node].value + 2*tree[tree_node].sum*lazy[tree_node].value;
            tree[tree_node].sum += (end-start+1)*lazy[tree_node].value;
            if(start != end){
                lazy[2*tree_node].value += lazy[tree_node].value;
                lazy[2*tree_node].type = 1;
                lazy[2*tree_node+1].value += lazy[tree_node].value;
                lazy[2*tree_node+1].type = 1;
            }
            lazy[tree_node] = {0,0};
        } else if(lazy[tree_node].type == 2){
            tree[tree_node].square_sum = (end-start+1)*lazy[tree_node].value*lazy[tree_node].value;
            tree[tree_node].sum = (end-start+1)*lazy[tree_node].value;
            if(start != end){
                lazy[2*tree_node].value = lazy[tree_node].value;
                lazy[2*tree_node].type = 2;
                lazy[2*tree_node+1].value = lazy[tree_node].value;
                lazy[2*tree_node+1].type = 2;
            }
            lazy[tree_node] = {0,0};
        }
    }

    if(start > end){
        return {0,0};
    }
    if(left > end || right < start){
        return {0,0};
    }
    if(left <= start && end <= right){
        return tree[tree_node];
    }
    int mid = (start+end)/2;
    node_tree op1 = sum_square_tree(lazy, tree, 2*tree_node, start, mid, left, right); 
    node_tree op2 = sum_square_tree(lazy, tree, 2*tree_node+1, mid+1, end, left, right);
    node_tree ans;
    ans.sum = op1.sum + op2.sum;
    ans.square_sum = op1.square_sum + op2.square_sum;
    return ans;    
}

int main() {

	// Write your code here
    int T;
    cin>>T;
    for (int t = 1; t <= T; t++){
        int n, q;
        cin>>n>>q;
        cout<<"Case "<<t<<":"<<endl;
        int * arr = new int[n]();
        node_tree * tree = new node_tree[4*n]();
        node_update * lazy = new node_update[4*n]();
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        build_tree(arr, tree, 1, 0, n-1);
        while(q--){
            int type, x, y, val;
            cin>>type;
            if(type == 0){
                cin>>x>>y>>val;
                set_tree(lazy, tree, 1, 0, n-1, x-1, y-1, val);
            } else if(type == 1){
                cin>>x>>y>>val;
                add_tree(lazy, tree, 1, 0, n-1, x-1, y-1, val);
            } else {
                cin>>x>>y;
                node_tree ans = sum_square_tree(lazy, tree, 1, 0, n-1, x-1, y-1);
                cout<<ans.square_sum<<endl;
            }
        }
        delete [] arr;
        delete [] tree;
        delete [] lazy;
    }
    return 0;
}