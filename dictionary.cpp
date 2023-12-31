

#include <cstring>
#include <string.h>
#include "dictionary.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <queue>

Dictionary::Dictionary() {
    root = new dictNode;
    // Initialize all pointers in the next array to NULL
    for (int i = 0; i < 29; i++) {
        root->next[i] = nullptr;
    }
}

bool Dictionary::add(const char * wordBeingInserted) {
    // Check if the wordBeingInserted is already present
    if (wordBeingInserted == nullptr) {
        return false;
    }

    //Code to add the node to the data structure
    //must start at root node, add a letter by creating a new node using the index of the created array
    dictNode *current = root; //denotes pointer to root, where we must begin
    //letters a-z are index 0-25, and specials are 26-28. terminator /0 is 29.
    int index; //takes track of index in letter array index next[]
    for (int i = 0; i <= strlen(wordBeingInserted); i++) {
        if (wordBeingInserted[i] == '\'') {
            index = 26; // '
        }
        else if (wordBeingInserted[i] == '-') {
            index = 27; // -
        }
        else if (wordBeingInserted[i] == '_') {
            index = 28; // _
        }
        else {
            index = tolower(wordBeingInserted[i]) - 'a';//this assigns a letter to an index based on ASCII
        }
        if (i == strlen(wordBeingInserted)){
            //if we're at the end of the given word from vocab, we add a
            // terminator char node to denote the end
            index = 29; // this is terminator index
        }
        if (!current->next[index]) { //if we're not at the root, new node needs to be created for next letter
            current->next[index] = new dictNode(); //instantiates with the class dictNode for a leaf node
        }
        current = current->next[index]; //assigns new node to a letter (based on index array)
    }
    return true;
}
dictNode* Dictionary::findEndingNodeOfAStr(const char *strBeingSearched) {
    dictNode* current = root; //node to keep track of where we are in the tree
    int index; //corresponds to next[]
    for (int i = 0; strBeingSearched[i] != '\0'; i++) { //goes down until a null terminator is found
        if (strBeingSearched[i] == '\'') {
            index = 26; //index for '
        }
        else if (strBeingSearched[i] == '-') {
            index = 27; //index for -
        }
        else if (strBeingSearched[i] == '_') {
            index = 28; // index for _
        }
        else {
            index = tolower(strBeingSearched[i]) - 'a'; //uses ASCII value of a to find index of alphabet letter
        }
        if (!current->next[index]) {
            return nullptr;
        }
        current = current->next[index];
        // current is a dictNode, where at the end right before returning it points to an index
    }
    return current; //returns of type dictNode
}

void Dictionary::countWordsStartingFromANode(int &count, dictNode *node) {

    //node denoted as visited to keep track of recurring tree parsing
    node -> visited = true;
    if (node->next[29]) { //index 29 is the null terminator \0 //!node->next[29]
        count++; //increment count once we reach a new word from the given prefix
    }

    //loop traverses a through _, excluding null terminator since we are only looking for valid leaf nodes
    //if a leaf node is no longer found (i=29), the for loop ends and we have found all words
    for (int i = 0; i < 29; i++) { //since there are 29 letters, we have these many children possibilities
        if (node->next[i] != nullptr ) { //
            countWordsStartingFromANode(count, node->next[i]);
            //^ this recursively calls our method with the next node and count as parameter
        }
    }
}





