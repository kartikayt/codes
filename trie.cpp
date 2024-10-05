#include <iostream>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;
};

// Trie class
class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->links[word[i] - 'a']) {
                Node *newNode = new Node();
                node->links[word[i] - 'a'] = newNode;
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->links[word[i] - 'a']) {
                return false;
            }
            node = node->links[word[i] - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->links[prefix[i] - 'a']) {
                return false;
            }
            node = node->links[prefix[i] - 'a'];
        }
        return true;
    }
};
