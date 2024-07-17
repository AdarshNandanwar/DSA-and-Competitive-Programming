// https://leetcode.com/problems/number-of-atoms/

// Method 1 (Reverse Traversal with Stack, O(nlogn) time, O(n) space):

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();

        map<string, int> freq;
        stack<int> multiplier;
        multiplier.push(1);
        int index = n-1;
        while(index >= 0){
            if(isdigit(formula[index])){
                int startIndex = index;
                while(startIndex-1 >= 0 and isdigit(formula[startIndex-1])){
                    startIndex--;
                }
                int value = stoi(formula.substr(startIndex, index-startIndex+1));

                multiplier.push(multiplier.top() * value);
                index = startIndex-1;
            } else if(isalpha(formula[index])){
                // Check if multiplier is implicit
                if(index+1 == n or !isdigit(formula[index+1])){
                    multiplier.push(multiplier.top());
                }

                int startIndex = index;
                while(startIndex >= 0 and 'a' <= formula[startIndex] and formula[startIndex] <= 'z'){
                    startIndex--;
                }
                string element = formula.substr(startIndex, index-startIndex+1);

                freq[element] += multiplier.top();
                multiplier.pop();
                index = startIndex-1;
            } else if(formula[index] == ')'){
                // Check if multiplier is implicit
                if(index+1 == n or !isdigit(formula[index+1])){
                    multiplier.push(multiplier.top());
                }
                index--;
            } else if(formula[index] == '('){
                multiplier.pop();
                index--;
            } else {
                cout<<"Input not allowed"<<endl;
            }
        }

        string response = "";
        for(const auto f:freq){
            response += f.first;
            if(f.second > 1){
                response += to_string(f.second);
            }
        }
        return response;
    }
};
