// Time Complexity : O(n)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach in three sentences only
// First split the string s into individual words and store them
// Map the character to individual word and word to character
// If we find an inconsistency in mapping, return false, else return true at the end of the program

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord; // mappings of char in string pattern to word in string s
        unordered_map<string, char> wordToChar; // mappings of word in string s to char in string pattern
        vector<string> words; // individual words in string s stored in vector
        int sLength = s.length();
        string word = "";
        for(int i=0; i<sLength; i++){ // split the string s into individual words
            char ch = s[i];
            if(ch == ' '){
                if(!word.empty()) {
                    words.push_back(word);
                    word = "";
                } 
            } else {
                word += ch;
            }
        }
        if(!word.empty()) words.push_back(word); // push last word into words vector

        if(words.size() != pattern.length()) return false; // early return if number of words != number of chars

        for(int i=0; i<pattern.length(); i++) { // to check mapping
            char currentChar = pattern[i];
            string currentWord = words[i];
            if(wordToChar.find(currentWord) != wordToChar.end()) {
                if(wordToChar[currentWord] != currentChar) return false; // current word already present in map, but mapped to a different char
            } else {
                wordToChar[currentWord] = currentChar;
            }

            if(charToWord.find(currentChar) != charToWord.end()) {
                if(charToWord[currentChar] != currentWord) return false; // current char already present in map, but mapped to a different word
            } else {
                charToWord[currentChar] = currentWord;
            }
        }

        return true; // return true at the end of the program
    }
};

int main() {
    Solution solution;
    string s = "dog cat cat dog";
    string pattern = "abba";
    bool ans = solution.wordPattern(pattern, s);
    if(ans) cout <<"'"<<s<<"' matches the pattern '"<<pattern<<"'"<<endl;
    else cout <<"'"<<s<<"' does not match the pattern '"<<pattern<<"'"<<endl;

    s = "word";
    pattern = "ab";
    ans = solution.wordPattern(pattern, s);
    if(ans) cout <<"'"<<s<<"' matches the pattern '"<<pattern<<"'"<<endl;
    else cout <<"'"<<s<<"' does not match the pattern '"<<pattern<<"'"<<endl;

    s = "dog cat cat fish";
    pattern = "abba";
    ans = solution.wordPattern(pattern, s);
    if(ans) cout <<"'"<<s<<"' matches the pattern '"<<pattern<<"'"<<endl;
    else cout <<"'"<<s<<"' does not match the pattern '"<<pattern<<"'"<<endl;

    s = "";
    pattern = "";
    ans = solution.wordPattern(pattern, s);
    if(ans) cout <<"'"<<s<<"' matches the pattern '"<<pattern<<"'"<<endl;
    else cout <<"'"<<s<<"' does not match the pattern '"<<pattern<<"'"<<endl;

    return 0;
}