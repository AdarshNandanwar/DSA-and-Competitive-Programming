// https://www.interviewbit.com/problems/justified-text/

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    string word, jLine;
    int curLen = 0, space, bigSpaceCount, smallSpaceLen, smallSpaceCount, spaceWordCount;
    vector<string> line, res;
    for(auto word:A){
        if(word == "") continue;
        if(curLen+line.size()+word.length() > B){
            // make a line
            if(line.size() == 1){
                jLine = line[0]+string(B-curLen, ' ');
            } else {
                spaceWordCount = line.size()-1;
                jLine = "";
                space = B-curLen;
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
        jLine += string(B-jLine.length(), ' ');
        res.push_back(jLine);
    }
    
    return res;
}
