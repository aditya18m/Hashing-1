// Time Complexity : O(n*k), where n = number of strings, k = average length of string
// Space Complexity : O(n*k)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach in three sentences only
// The idea here is that we assign a unique prime number to each of the 26 lowercase letters.
// Then we can hash each string by calculating the prime product of its characters, with the hash serving as the key.
// All anagrams will share the same hash/key since they have the same characters by definition, so it becomes easier to group them together.


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    double getPrimeProduct(string str) {
        int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101}; // first 26 primes
        double product = 1.0;
        for(char ch :  str) {
            product *= primes[ch - 'a'];
        }
        return product; // prime product
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<double, vector<string>> map;

        for(string str : strs) { // O(n), go over all the strings
            double primeProduct = getPrimeProduct(str); // O(k), find the prime product of the string
            map[primeProduct].push_back(str); // store string in map with key = prime product, all anagrams will have same prime product
        }

        vector<vector<string>> result;
        for(auto& it: map) {
            result.push_back(it.second);
        }

        return result;
    }

    void printInput(vector<string>& strs) { // helper to print input, not required on leetcode
        cout<<"Input: ";
        for(int i=0; i<strs.size(); i++) {
            cout<<strs[i]<<" ";
        }
        cout<<"\n \n";
        return;
    }

    void printOutput(vector<vector<string>> ans) { // helper to print output, not required on leetcode
        cout<<"Anagrams: "<<endl;
        for(int i=0; i<ans.size(); i++) {
            for(int j=0; j<ans[i].size(); j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"ant", "bat", "tea"};
    solution.printInput(strs);
    vector<vector<string>> ans = solution.groupAnagrams(strs);
    solution.printOutput(ans);

    strs = {"eat","tea","tan","ate","nat","bat"};
    solution.printInput(strs);
    ans = solution.groupAnagrams(strs);
    solution.printOutput(ans);

    return 0;
}