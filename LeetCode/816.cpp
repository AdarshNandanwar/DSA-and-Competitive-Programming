// https://leetcode.com/problems/ambiguous-coordinates/

// Method 1 (string operations):

class Solution {
public:
    
    string strip(string s){
        bool is_int = true;
        for(auto c:s) if(c == '.') is_int = false;
        if(is_int) return s;
        
        while(s.back() == '0' or s.back() == '.'){
            if(s.back() == '.'){
                s.pop_back();
                return s;            
            }
            s.pop_back();
        }
        return s;            
    }
    
    vector<string> get_value(string s){
        int n = s.length();
        if(n == 0) return {};
        if(n == 1) return {s};
        if(n > 1 and s == string(n, '0')) return {};
        vector<string> res;
        if(s[0] == '0'){
            // double
            if(s[n-1] == '0') return {};
            return {s.substr(0, 1)+"."+s.substr(1)};
        } else {
            if(s[n-1] == '0') return {s};
            res.push_back(s);
            s.push_back('.');
            for(int i = n-1; i>0; i--){
                swap(s[i], s[i+1]);
                res.push_back(s);
            }
            return res;   
        }
    }
    
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.length()-2);
        for(int i = 1; i<s.length(); i++){
            auto x_vector = get_value(s.substr(0, i));
            auto y_vector = get_value(s.substr(i));
            for(auto j:x_vector){
                for(auto k:y_vector){
                    ans.push_back("("+strip(j)+", "+strip(k)+")");                    
                }
            }
        }
        return ans;
    }
};

// Method 2 (stod, WA due to precision):

class Solution {
public:
    
    void strip(string & s){
        bool is_int = true;
        for(auto c:s) if(c == '.') is_int = false;
        if(is_int) return;
        while(s.back() == '0' or s.back() == '.'){
            if(s.back() == '.'){
                s.pop_back();
                return;            
            }
            s.pop_back();
        }
    }
    
    vector<double> get_value(string s){
        int n = s.length();
        if(n == 0) return {};
        if(n == 1) return {stod(s)};
        if(n > 1 and s == string(n, '0')) return {};
        vector<double> res;
        if(s[0] == '0'){
            // double
            if(s[n-1] == '0') return {};
            return {stod(s)/pow(10, n-1)};
        } else {
            if(s[n-1] == '0') return {stod(s)};
            double val = stod(s);
            while(floor(val)){
                res.push_back(val);
                val /= 10;
            }
            return res;   
        }
    }
    
    string better_to_string(double n){
        stringstream ss;
        ss.precision(12);
        ss<<fixed<<n;
        return ss.str();
    }
    
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.length()-2);
        for(int i = 1; i<s.length(); i++){
            auto x_vector = get_value(s.substr(0, i));
            auto y_vector = get_value(s.substr(i));
            for(auto j:x_vector){
                for(auto k:y_vector){
                    string temp;
                    temp = temp+"("+better_to_string(j);
                    strip(temp);
                    temp = temp+", "+better_to_string(k);
                    strip(temp);
                    temp = temp+")";
                    ans.push_back(temp);                    
                }
            }
        }
        return ans;
    }
};