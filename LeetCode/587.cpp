// https://leetcode.com/problems/erect-the-fence/

// Method 1 (Convex Hull, Jarvis Algorithm, O(n2)):

class Solution {
public:
    
    int get_cross_product(vector<int> &A, vector<int> &B, vector<int> &C){
        // returns cross product of vectors: AB x AC
        return ((B[0]-A[0]) * (C[1]-A[1])) - ((B[1]-A[1]) * (C[0]-A[0]));
    }
    
    vector<int> get_farther(vector<int> &A, vector<int> &B, vector<int> &C){
        // returns the point from B and C which is closer to A based on euclidean distance.
        int dist_AB = pow(B[0]-A[0], 2) + pow(B[1]-A[1], 2);
        int dist_AC = pow(C[0]-A[0], 2) + pow(C[1]-A[1], 2);
        return dist_AB < dist_AC ? C : B;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() < 3) return trees;
        vector<vector<int>> ans;
        
        vector<int> leftmost = {101, 101};
        for(auto &i:trees){
            if(leftmost[0] > i[0]){
                leftmost = i;
            }
        }
        
        vector<int> A = leftmost;
        do{
            ans.push_back(A);
            
            // initializing B to any point except A
            vector<int> B = trees[0];
            if(B == A) B = trees[1];
            
            for(auto &C:trees){
                if(C == A or C == B) continue;
                int cp = get_cross_product(A, B, C);
                if(cp > 0){
                    // A->B->C are in anti-clockwise direction
                    B = C;
                } else if(cp == 0){
                    // A->B->C are collinear
                    B = get_farther(A, B, C);
                }
            }
            
            // adding all collinear points between A and B
            for(auto &C:trees){
                if(C == A or C == B or get_cross_product(A, B, C) != 0) continue;
                if(count(ans.begin(), ans.end(), C) == 0) ans.push_back(C);                
            }
            
            A = B;
            
        } while(A != leftmost);
        
        return ans;
    }
};

// Method 2 (Breaking into quarters and solve, WA, 81/84 passed):

class Solution {
public:
    
    string get_key(vector<int> & v){
        if(v.size() == 0) return "empty";
        return to_string(v[0])+"_"+to_string(v[1]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() == 1) return trees;
        unordered_set<string> s;
        vector<int> left = {101, 101}, right = {-1, -1}, up = {-1, -1}, down = {101, 101};
        vector<int> start, end, cur, visited = {-1, -1};
        for(auto &tree:trees){
            if(tree[0] > right[0]) right = tree;
            if(tree[0] < left[0]) left = tree;
            if(tree[1] > up[1]) up = tree;
            if(tree[1] < down[1]) down = tree;
        }
        for(auto &tree:trees){
            if(tree[0] == right[0] or tree[0] == left[0] or tree[1] == up[1] or tree[1] == down[1]){
                s.insert(get_key(tree));
            }
        }        
        
        // top right quarter
        start = right;
        end = up;
        for(auto &tree:trees){
            if(tree[0] == start[0] and tree[1] > start[1]) start = tree;
            if(tree[1] == end[1] and tree[0] > end[0]) end = tree;
        }
        cur = start;
        while(1){
            int next = -1;
            double y = abs(end[1] - cur[1]);
            double x = abs(end[0] - cur[0]);
            double max_grad = y/x;
            for(int i = 0; i<trees.size(); i++){
                if(trees[i] == visited) continue;
                if(end[0] < trees[i][0] and trees[i][1] > cur[1]){
                    y = abs(trees[i][1] - cur[1]);
                    x = abs(trees[i][0] - cur[0]);
                    double grad = y/x;
                    if(grad > max_grad
                      or (grad == max_grad and (next == -1 or abs(trees[i][0]-cur[0]) < abs(trees[i][0]-trees[next][0])))){
                        max_grad = grad;
                        next = i;
                    }
                }
            }
            if(next != -1){
                s.insert(get_key(trees[next]));
                cur = trees[next];
                trees[next] = visited;
            } else {
                break;
            }
        }
        
        // top left quarter
        start = up;
        end = left;
        for(auto &tree:trees){
            if(tree[1] == start[1] and tree[0] < start[0]) start = tree;
            if(tree[0] == end[0] and tree[1] > end[1]) end = tree;
        }
        cur = start;
        while(1){
            int next = -1;
            double y = abs(end[1] - cur[1]);
            double x = abs(end[0] - cur[0]);
            double min_grad = y/x;
            for(int i = 0; i<trees.size(); i++){
                if(trees[i] == visited) continue;
                if(end[1] < trees[i][1] and trees[i][0] < cur[0]){
                    y = abs(trees[i][1] - cur[1]);
                    x = abs(trees[i][0] - cur[0]);
                    double grad = y/x;
                    if(grad < min_grad
                      or (grad == min_grad and (next == -1 or abs(trees[i][0]-cur[0]) < abs(trees[i][0]-trees[next][0])))){
                        min_grad = grad;
                        next = i;
                    }
                }
            }
            if(next != -1){
                s.insert(get_key(trees[next]));
                cur = trees[next];
                trees[next] = visited;
            } else {
                break;
            }
        }
            
        // bottom left quarter
        start = left;
        end = down;
        for(auto &tree:trees){
            if(tree[0] == start[0] and tree[1] < start[1]) start = tree;
            if(tree[1] == end[1] and tree[0] < end[0]) end = tree;
        }
        cur = start;
        while(1){
            int next = -1;
            double y = abs(end[1] - cur[1]);
            double x = abs(end[0] - cur[0]);
            double max_grad = y/x;
            for(int i = 0; i<trees.size(); i++){
                if(trees[i] == visited) continue;
                if(end[0] > trees[i][0] and trees[i][1] < cur[1]){
                    y = abs(trees[i][1] - cur[1]);
                    x = abs(trees[i][0] - cur[0]);
                    double grad = y/x;
                    if(grad > max_grad
                      or (grad == max_grad and (next == -1 or abs(trees[i][0]-cur[0]) < abs(trees[i][0]-trees[next][0])))){
                        max_grad = grad;
                        next = i;
                    }
                }
            }
            if(next != -1){
                s.insert(get_key(trees[next]));
                cur = trees[next];
                trees[next] = visited;
            } else {
                break;
            }
        }
        
        // bottom right quarter
        start = down;
        end = right;
        for(auto &tree:trees){
            if(tree[1] == start[1] and tree[0] > start[0]) start = tree;
            if(tree[0] == end[0] and tree[0] < end[0]) end = tree;
        }
        cur = start;
        while(1){
            int next = -1;
            double y = abs(end[1] - cur[1]);
            double x = abs(end[0] - cur[0]);
            double min_grad = y/x;
            for(int i = 0; i<trees.size(); i++){
                if(trees[i] == visited) continue;
                if(end[1] > trees[i][1] and trees[i][0] > cur[0]){
                    y = abs(trees[i][1] - cur[1]);
                    x = abs(trees[i][0] - cur[0]);
                    double grad = y/x;
                    if(grad < min_grad
                      or (grad == min_grad and (next == -1 or abs(trees[i][0]-cur[0]) < abs(trees[i][0]-trees[next][0])))){
                        min_grad = grad;
                        next = i;
                    }
                }
            }
            if(next != -1){
                s.insert(get_key(trees[next]));
                cur = trees[next];
                trees[next] = visited;
            } else {
                break;
            }
        }
        
        // construct answer
        vector<vector<int>> ans;
        for(auto &i:s){
            istringstream iss(i);
            string s1, s2;
            getline(iss, s1, '_');
            getline(iss, s2, '_');
            ans.push_back({stoi(s1), stoi(s2)});
        }
        return ans;
    }
};