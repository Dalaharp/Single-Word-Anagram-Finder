# Single-Word-Anagram-Finder

This C++ code defines a program that finds single-word anagrams for a given input word within a provided wordlist. Here's a breakdown of the code:

The program includes necessary header files, such as <iostream>, <fstream>, <vector>, and <unordered_map>, and also the <algorithm> header for the sort function.

The loadWordlist function reads a wordlist from a file and stores it in a vector of strings. Each line from the file is treated as a separate word.

The getKey function takes a word as input and returns a unique key for that word by sorting its characters.

The main function, anagram, takes an input word and a wordlist as parameters. It builds a dictionary (implemented using an unordered_map) where the key is a unique key generated for each word, and the value is a vector of strings containing all words with the same key (anagrams).

The main function then generates a key for the input word and retrieves the vector of anagrams associated with that key from the map.

The commented-out main function shows how to use the loadWordlist and anagram functions. It prompts the user to enter a word, loads a wordlist from a file ("wordlist.txt"), and finds and displays the anagrams of the input word.
