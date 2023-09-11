#include<iostream>
#include<string>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        //Assumption that word that prsented word will be in caps
        int index = word[0] - 'A';
        TrieNode* child;
        
        //present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            //absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        //recursive call
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word) {
        insertUtil(root, word);
    }
    
    bool searchUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            return root -> isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        
        //present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            //absent
            return false;
        }
        //recursion dekh lega
        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    void deleteUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root -> isTerminal = false;
            return;
        }
        
        int index = word[0] - 'A';
        TrieNode* child;
        
        //assuming that the words is present before deleting
        if(root -> children[index] != NULL) {
            child = root -> children[index];
            deleteUtil(child, word.substr(1));
        }
        else {
            return;
        }

    }
    
    void deleteWord(string word) {
        deleteUtil(root, word);
    }
};

int main() {
    
    Trie *t = new Trie();
    
    t -> insertWord("LAKHAN");
    t -> insertWord("RAMU");
    t -> insertWord("SHYAMU");
        
    t -> deleteWord("SHYAMU");
    
    bool ans = t -> search("SHYAMU");
    
    if(ans)
        cout << "Word is Present " << endl;
    else 
        cout << "Word is not present " << endl;
    
    
    return 0;
}