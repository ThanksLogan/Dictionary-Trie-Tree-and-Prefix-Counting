//

//

//this file will IMPLEMENT THE .h file, dictionary.h (#include dictionary.h)

#include <cstring>
#include <string.h>
#include <iostream>
#include <fstream>
#include "dictionary.h"
#include <queue>


int main(int argc, char **argv) {

    // VOCABULARY FILE READING METHOD
    //std::cout << "Beginning File Read and Adding Words to Tree" << std::endl;
    Dictionary dict;
    std::ifstream dictstream(argv[1]); // open file for parsing
    //std::ifstream dictstream("vocabulary.txt"); //for testing
    std::string line;
    const char *delimiters = "\n\r !\"#$%&()*+,./0123456789:;<=>?@[\\]^`{|}~";
    // iterate over dictionary file line by line
    while (std::getline(dictstream, line)) {
        char *word = strtok(const_cast<char *>(line.c_str()), delimiters);
        while (word != nullptr) {
            // call add method to insert word to build the dictionary tree
            dict.add(word);
            //std::cout << "here" << std::endl;
            // handle error from insertion result

            //read next word
            word = strtok(nullptr, delimiters);
        }
    }
    dictstream.close();

    //TESTFILE READING METHOD and FILE WRITING
    //std::cout << "Beginning Test File Read and Searching/Counting Word Prefixes" << std::endl;
    std::ifstream teststream(argv[2]); //open test file
    //std::ifstream teststream("testfile1.txt");
    //std::ofstream outputFile("outputPrefixes.txt");

    // iterate over test file by line
    while (std::getline(teststream, line)) {
        char *word = strtok(const_cast<char *>(line.c_str()), delimiters); //word with delimiters
        while (word != nullptr) {
            // search for word in dictionary tree
            //std::cout << word << std::endl;
            dictNode *node = dict.findEndingNodeOfAStr(word);
            //searches for the word in the tree we created, and fetches the ending node

            // if word is found, count and print the number of words starting from the node
            if (node) { //makes sure the node exists
                int count = 0;
                dict.countWordsStartingFromANode(count, node);
                //std::cout << count << std::endl;
                std::cout << word << " " << count << std::endl;
                //outputFile << word ;
                //outputFile << " " << count << std::endl;
            } else {
                std::cout << word << " 0" << std::endl;
            }
            // read next word
            word = strtok(nullptr, delimiters);
        }
    }
    teststream.close();
    //outputFile.close();


    return 0;

}

