// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string word, jLine;
        int curLen = 0, space, bigSpaceCount, smallSpaceLen, smallSpaceCount, spaceWordCount;
        vector<string> line, res;
        for(auto word:words){
            if(word == "") continue;
            if(curLen+line.size()+word.length() > maxWidth){
                // make a line
                if(line.size() == 1){
                    jLine = line[0]+string(maxWidth-curLen, ' ');
                } else {
                    spaceWordCount = line.size()-1;
                    jLine = "";
                    space = maxWidth-curLen;
                    smallSpaceLen = space/spaceWordCount;
                    bigSpaceCount = space - spaceWordCount*smallSpaceLen;
                    smallSpaceCount = spaceWordCount - bigSpaceCount;
                    int k = 0;
                    while(bigSpaceCount--){
                        jLine += (line[k]+string(smallSpaceLen+1, ' '));
                        k++;
                    }
                    while(smallSpaceCount--){
                        jLine += (line[k]+string(smallSpaceLen, ' '));
                        k++;
                    }
                    jLine += line[k];
                }
                res.push_back(jLine);
                line = {word};
                curLen = word.length();
            } else {
                // add the word in line
                line.push_back(word);
                curLen += word.length();
            }
        }

        if(curLen){
            // last line
            jLine = line[0];
            for(int i = 1; i<line.size(); i++) jLine += (" " + line[i]);
            jLine += string(maxWidth-jLine.length(), ' ');
            res.push_back(jLine);
        }

        return res;
        
    }
};