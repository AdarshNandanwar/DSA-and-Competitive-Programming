// https://leetcode.com/problems/integer-to-english-words/

// Method 1 (If else, O(log(n)) time, O(1) space):

class Solution {
    string getDigit(int num){
        switch(num){
            case 1: return " One";
            case 2: return " Two";
            case 3: return " Three";
            case 4: return " Four";
            case 5: return " Five";
            case 6: return " Six";
            case 7: return " Seven";
            case 8: return " Eight";
            case 9: return " Nine";
            default: return "";
        }
    }
    string getTensDigit(int num){
        switch(num){
            case 2: return " Twenty";
            case 3: return " Thirty";
            case 4: return " Forty";
            case 5: return " Fifty";
            case 6: return " Sixty";
            case 7: return " Seventy";
            case 8: return " Eighty";
            case 9: return " Ninety";
            default: return "";
        }
    }
    string getTeenNumber(int num){
        switch(num){
            case 0: return " Ten";
            case 1: return " Eleven";
            case 2: return " Twelve";
            case 3: return " Thirteen";
            case 4: return " Fourteen";
            case 5: return " Fifteen";
            case 6: return " Sixteen";
            case 7: return " Seventeen";
            case 8: return " Eighteen";
            case 9: return " Nineteen";
            default: return "";
        }
    }
    string parseThreeDigitNumber(int num){
        string words = "";

        int digit = (num / 100) % 10;
        if(digit > 0){
            words += getDigit(digit);
            words += " Hundred";
        }
        
        digit = (num / 10) % 10;
        if(digit > 1){
            words += getTensDigit(digit);
        }
        
        int prevDigit = digit;
        digit = num % 10;
        if(prevDigit == 1){
            words += getTeenNumber(digit);
        } else {
            words += getDigit(digit);
        }

        return words;
    }
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        string words = "";
        
        int billionsNumber = (num / 1000000000) % 1000;
        words += parseThreeDigitNumber(billionsNumber);
        if(billionsNumber > 0){
            words += " Billion";
        }
        
        int millionsNumber = (num / 1000000) % 1000;
        words += parseThreeDigitNumber(millionsNumber);
        if(millionsNumber > 0){
            words += " Million";
        }
        
        int thousandsNumber = (num / 1000) % 1000;
        words += parseThreeDigitNumber(thousandsNumber);
        if(thousandsNumber > 0){
            words += " Thousand";
        }
        
        int hundredsNumber = num % 1000;
        words += parseThreeDigitNumber(hundredsNumber);
        
        return words[0] == ' ' ? words.substr(1) : words;
    }
};
