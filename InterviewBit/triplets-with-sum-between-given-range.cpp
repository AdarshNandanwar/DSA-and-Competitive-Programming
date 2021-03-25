// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

// Method 1 (Bucketing, O(n)):

int Solution::solve(vector<string> &A) {
    
    // https://stackoverflow.com/questions/19557505/triplet-whose-sum-in-range-1-2
    
    // x1 = (0, 1/2)
    // x2 = [1/2, 2/3)
    // x = (0, 2/3)
    // y = [2/3, 1]
    // z = (1, 2)
    
    int x1 = 0, x2 = 0, x = 0, y = 0, z = 0;
    double x_max_1 = 0, x_max_2 = 0, x_max_3 = 0, y_max_1 = 0;
    double x_min_1 = 2, x_min_2 = 2, y_min_1 = 2, y_min_2 = 2, z_min_1 = 2;
    
    for(auto s:A){
        double d = stod(s);
        if(0<d and d<=2.0/3){
            // x
            x++;
            
            if(d>x_max_1){
                x_max_3 = x_max_2;
                x_max_2 = x_max_1;
                x_max_1 = d;
            } else if(d>x_max_2){
                x_max_3 = x_max_2;
                x_max_2 = d;
            } else if(d>x_max_3){
                x_max_3 = d;
            }
            if(d<x_min_1){
                x_min_2 = x_min_1;
                x_min_1 = d;
            } else if(d<x_min_2){
                x_min_2 = d;
            }
            
            if(d<1.0/2){
                // x1
                x1++;
            } else {
                //x2
                x2++;
            }
        } else if(2.0/3<=d and d<=1){
            // y
            y++;
            
            y_max_1 = max(y_max_1, d);
            if(d<y_min_1){
                y_min_2 = y_min_1;
                y_min_1 = d;
            } else if(d<y_min_2){
                y_min_2 = d;
            }
        } else if(1<d and d<2){
            // z
            z++;
            
            z_min_1 = min(z_min_1, d);
        }
    }
    
    if(x>=1 and y>=2 and x_min_1+y_min_1+y_min_2<2) return 1;
    if(x>=1 and y>=1 and z>=1 and x_min_1+y_min_1+z_min_1<2) return 1;
    
    if(x>=2 and y>=1) {
        if(x1>=1 and x2>=1 and x_min_1+x_min_2+y_min_1<2) return 1; 
        if(x2>=2 and x_min_1+x_min_2+y_min_1<2) return 1; 
        if(x1>=2 and x_max_1+x_max_2+y_max_1>1) return 1; 
    }
    
    if(x>=2 and z>=1 and x_min_1+x_min_2+z_min_1<2) return 1;
    if(x>=3 and x_max_1+x_max_2+x_max_3>1) return 1;
    
    
    return 0;
}
