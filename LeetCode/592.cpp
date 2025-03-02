// https://leetcode.com/problems/fraction-addition-and-subtraction/

// Method 1 (Loops, HCF, O(n)):

class Solution {
    struct Fraction{
        bool isNegative;
        int numerator, denominator;
    };

    // {fraction, nextIndex}
    pair<Fraction, int> getNextFraction(const string expression, int start){
        int n = expression.size();

        int index = start;
        Fraction f;
        f.isNegative = expression[index] == '-';
        if(!isdigit(expression[index])){
            index++;
        }
        int numeratorStartIndex = index;
        while(index < n and isdigit(expression[index])){
            index++;
        }
        f.numerator = stoi(expression.substr(numeratorStartIndex, index - numeratorStartIndex));
        index++;
        int denominatorStartIndex = index;
        while(index < n and isdigit(expression[index])){
            index++;
        }
        f.denominator = stoi(expression.substr(denominatorStartIndex, index - denominatorStartIndex));

        return make_pair(f, index);
    }

    Fraction addFractions(Fraction f1, Fraction f2){
        int denominatorHcf = __gcd(f1.denominator, f2.denominator);
        int multFactor1 = f2.denominator / denominatorHcf;
        int multFactor2 = f1.denominator / denominatorHcf;
        int numerator1 = f1.numerator * multFactor1;
        int numerator2 = f2.numerator * multFactor2;
        int denominator = f1.denominator * multFactor1;

        if(f1.isNegative){
            numerator1 *= -1;
        }
        if(f2.isNegative){
            numerator2 *= -1;
        }

        int numerator = numerator1 + numerator2;
        bool isNegative = false;
        if(numerator < 0) {
            isNegative = true;
        }
        numerator = abs(numerator);

        int fractionHcf = __gcd(numerator, denominator);
        numerator /= fractionHcf;
        denominator /= fractionHcf;

        return Fraction(isNegative, numerator, denominator);
    }
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        int index = 0;

        auto res = getNextFraction(expression, index);
        Fraction ans = res.first;
        index = res.second;

        while(index < n){
            res = getNextFraction(expression, index);
            Fraction operand = res.first;
            index = res.second;

            ans = addFractions(ans, operand);
        }

        string stringAns = "";

        if(ans.isNegative){
            stringAns += "-";
        }
        stringAns += to_string(ans.numerator);
        stringAns += "/";
        stringAns += to_string(ans.denominator);

        return stringAns;
    }
};
