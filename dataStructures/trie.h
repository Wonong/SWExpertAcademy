// 문자열 저장을 위한 trie 자료구조 헤더

struct Trie_node{
    bool fin;
    char val;
    Trie_node* next[26];
    
    ~Trie_node(){
        for(int i=0; i<26; i++) delete next[i];
    }

    void insert(char *key){
        if(key == '\0') fin = true;
        else{
            int cur = *key - 'A';
            if(next[cur] == NULL){
                next[cur] = new Trie();
            }
            next[curr]->insert(key+1);
        }
    }

    Trie_node* find(char *key){
        if(*key == '\0') return this;
        int cur = *key - 'A';
        if(next[cur] == NULL) return NULL;
        return next[cur]->find(key+1);
    }
};