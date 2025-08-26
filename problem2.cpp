// Time Complexity : O(n)
// Space Complexity : O(1), since s and t consist of valid ASCII chars only
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach in three sentences only
// We use 2 maps to map characters from s to t and from t to s
// We check for each character if the character mappings are unique both ways
// If the consistency breaks in either sMap or tMap, we return false else we return true at the end of the program

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if(sLen != tLen) return false;

        unordered_map<char, char> sMap; // to store mapping from s to t
        unordered_map<char, char> tMap; // to store mapping from t to s

        for(int i=0; i<sLen; i++) {
            char sChar = s[i]; // chars to be mapped
            char tChar = t[i];

            if(sMap.find(sChar) != sMap.end()) {
                if(sMap[sChar] != tChar) return false; // if sChar already exists in the sMap but its mapped to something other than tChar, return false
            } else {
                sMap[sChar] = tChar;
            }

            if(tMap.find(tChar) != tMap.end()) { // if tChar already exists in the tMap but its mapped to something other than sChar, return false
                if(tMap[tChar] != sChar) return false;
            } else {
                tMap[tChar] = sChar;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    string s = "egg";
    string t = "add";
    bool ans = solution.isIsomorphic(s,t);

    if(ans) cout<<s<<" and "<<t<<" are isomorphic"<<endl;
    else cout<<s<<" and "<<t<<" are not isomorphic"<<endl;

    s = "egs";
    t = "add";
    ans = solution.isIsomorphic(s,t);

    if(ans) cout<<s<<" and "<<t<<" are isomorphic"<<endl;
    else cout<<s<<" and "<<t<<" are not isomorphic"<<endl;

    s = "paper";
    t = "title";
    ans = solution.isIsomorphic(s,t);

    if(ans) cout<<s<<" and "<<t<<" are isomorphic"<<endl;
    else cout<<s<<" and "<<t<<" are not isomorphic"<<endl;
}