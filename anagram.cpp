/*
 * Name: Prahalad Gururajan
 * Date Submitted: 10/27/23
 * Assignment Name: Single Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

/*int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}*/

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

// Function to create a unique key for a word based on its letters
string getKey(string word) {
    string key = word;
    sort(key.begin(), key.end()); // Sort the characters in the word to create a key
    return key;
}

// Function to find anagrams of a given word within a list of words
vector<string> anagram(string word, vector<string> wordlist) {
    unordered_map<string, vector<string>> anagramMap; // Create a map to store words grouped by their anagram keys

    // Iterate through the list of words
    for (string w : wordlist) {
        string key = getKey(w); // Generate a unique key for the current word
        anagramMap[key].push_back(w); // Add the word to the corresponding key's group
    }

    // Find anagrams of the input word
    string inputKey = getKey(word); // Generate a key for the input word to find its anagrams
    vector<string> anagrams = anagramMap[inputKey]; // Retrieve the list of anagrams associated with the key

    return anagrams; // Return the list of anagrams for the input word
}
