// 소문자 문자열 저장을 위한 trie 자료구조 헤더
#include <iostream>

using namespace std;

struct Trie_node{
    bool fin;
    Trie_node* next[26];
    
    ~Trie_node(){
        for(int i=0; i<26; i++) delete next[i];
    }

    void insert(char *key){
        if(*key == '\0'){
            fin = true;
        }
        else{
            int cur = *key - 'a';
            if(next[cur] == nullptr){
                // create new trie when now key chracter does not exist
                next[cur] = new Trie_node();
            }
            next[cur]->insert(key+1);
        }
    }

    Trie_node* find(char *key){
        // if current character is end of string, return this.
        if(*key == '\0') return this;
        int cur = *key - 'a';
        // if current character does not exist,
        if(next[cur] == nullptr) return nullptr;
        return next[cur]->find(key+1);
    }
};