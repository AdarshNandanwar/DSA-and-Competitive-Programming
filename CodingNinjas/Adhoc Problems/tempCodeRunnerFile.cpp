if(arr[end]==aim) {
            while(start<n){
                while(arr[start]<aim){
                    cost+=l;
                }
                start++;
            }
            min_cost=min(min_cost, cost);
        }
        continue;