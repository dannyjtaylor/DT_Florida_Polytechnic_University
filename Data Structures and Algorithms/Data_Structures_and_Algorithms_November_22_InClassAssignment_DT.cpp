// Given an array of words as input. Display the words and their corresponding length. Also
/*display the biggest word.
	Input array:{"apple", "banana", "Floridapoly","Algorithm", "data"};
	Output: 
	apple 5
	banana 6
	Floridapoly 11
	Algorithm 9
	data 4
	Biggest word: Floridapoly
----------------------------------------------------------------------
// Don't submit c++ code. Submit a screenshot that includes code and output. */
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
   

int main() {
    // Input array of words
    string words[] = {"apple", "banana", "Floridapoly","Algorithm", "data"};
    unordered_map<string s, int size> hm;
    //variable for largest size of the string
    int largestStringLength = 0;
    int largestIndex = 0;

    //iterate through the word array
    for(int i: words) {
        //add each word and its size to hashmap
        hm[i].s = words[i];
        hm[i].size = words[i].length();

        //if the current hashmap object's size is greater than the largest string length, set new largest to that size, and update the index accordingly
        if hm[i].size > largestStringLength {
            largestStringLength = hm[i].size;
            largestIndex = i;
        }
        cout << hm[i].s << ' ' << hm[i].size << endl;
    }
    cout << "Biggest word: " << hm[largestIndex].s << endl;
    return 0;
}