// key here is we dont even need to store the characters, only a bool var that indicates if this is the last character ( end of the word)
// this needs to be done at insertion when we are finished with inserting a word in the end
// the code is pretty self explanatory:

// each node has 26 pointers to next node.
// each node represents a character, a-z
// if the node is not null then that means that node exist in our trie-tree
typedef struct trie_node {
    struct trie_node *sub_letters[26];
    bool end_of_word;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie * obj = (Trie*)calloc(1,sizeof(Trie));
    return obj;
}
/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
  int i;
    while(*word) {
        if(obj->sub_letters[(*word)-'a'] == NULL ) {
            obj->sub_letters[(*word)-'a'] = (Trie *)calloc(1,sizeof(Trie));
        }
        obj = obj->sub_letters[(*word)-'a'];
        word++;
    }
    obj-> end_of_word = true;
}
/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    while(*word) {
        if(!obj->sub_letters[(*word)-'a']) return false;
        obj = obj->sub_letters[(*word)-'a'];
        word++;
    }
    if(!obj->end_of_word) return false;
    else return true;
}
/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    while(*prefix) {
        if(!obj->sub_letters[(*prefix)-'a']) return false;
        obj = obj->sub_letters[(*prefix)-'a'];
        prefix++;
    }
    return true;
}
void trieFree(Trie* obj) {
    for(int i=0;i<26;i++) {
        if(obj->sub_letters[i]) {
            trieFree(obj->sub_letters[i]);
			//freeing the memory is IMPORTANT, but more important to avoid heap-use-after-free is to set the pointer NULL
            obj->sub_letters[i] = NULL;
        } 
    }
     free(obj);
}
/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
