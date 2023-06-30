/*
 * @lc app=leetcode.cn id=2490 lang=cpp
 *
 * [2490] 回环句
 */

// @lc code=start
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        if sentence[0] != sentence[-1]:
            return False
        words = sentence.split(' ')
        return all(x[-1] == words[(i + 1) % len(words)][0] for i, x in enumerate(words))
class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        string t = "";
        for (auto& ch : sentence) {
            if (ch != ' ') {
                t += ch;
            }
            else {
                words.push_back(t);
                t = "";
            }
        }

        // 末尾要注意，不要漏
        if (t != "") words.push_back(t);

        for (int i = 0; i < words.size() - 1; ++ i) {
            if (*(words[i].end() - 1) != words[i + 1][0]) return false;
        }

        return words[0][0] == *((*(words.end() - 1)).end() - 1);
    }
};

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int len=sentence.length();
        if(sentence[0]!=sentence[len-1]){
            return false;
        }
        for(int i=0;i<len;++i){
            if(sentence[i]==' '&sentence[i+1]!=NULL){
                if(sentence[i-1]!=sentence[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

