const int mxN = 26;

class Trie {

private:

    Trie *children[mxN];

    bool is_end;

public:

    Trie() {

        for(int i=0; i<mxN; ++i) children[i] = nullptr;

        is_end = false;

    }

    

    void insert(string word) {

        Trie *curr = this;

        for(int i=0; i<word.size(); ++i) {

            int idx = word[i] - 'a';

            if(curr->children[idx] == nullptr) {

                curr->children[idx] = new Trie();

            }

            curr = curr->children[idx];

        }

        curr->is_end = true;

    }

    

    bool search(string word, bool is_prefix=false) {

        Trie *curr = this;

        for(int i=0; i<word.size(); ++i) {

            int idx = word[i] - 'a';

            if(curr->children[idx] == nullptr) return false;

            curr = curr->children[idx];

        }

        if(is_prefix) return true;

        return curr->is_end;

    }

    

    bool startsWith(string prefix) {

        return search(prefix, true);

    }

};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix)**/