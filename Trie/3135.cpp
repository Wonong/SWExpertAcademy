#include <iostream>

struct Trie_node{
    int cnt = 0;
    Trie_node* next[26];
    ~Trie_node(){
        for(int i=0; i<26; i++){
            if(next[i] != nullptr) delete next[i];
        }
    }
    void insert_trie(char *key){
        if(*key != '\0'){
            int curr = *key - 'a';
            if(next[curr] == nullptr){
                next[curr] = new Trie_node();
            }
            // 해당 노드까지의 문자열로 시작하는 문자열의 갯수 증가
            next[curr]->cnt++;
            next[curr]->insert_trie(key+1);
        }
    }
    Trie_node* find_trie(char *key){
        if(*key == '\0') return this;
        int curr = *key - 'a';
        if(next[curr] == nullptr){
            next[curr] = new Trie_node();
        }
        next[curr]->find_trie(key+1);
    }
    int cnt_trie(char *key){
        if(*key == '\0') return cnt;
        int curr = *key - 'a';
        if(next[curr] == nullptr) return 0;
        next[curr]->cnt_trie(key+1);
    }
};
    Trie_node* root;
void init(void) {
	free(root);
    root = new Trie_node();
}

void insert(int buffer_size, char *buf) {
    root->insert_trie(buf);
}

int query(int buffer_size, char *buf) {
    int cnt = root->cnt_trie(buf);
	return cnt;
}