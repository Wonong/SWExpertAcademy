#include <iostream>
#include "./trie.h"

using namespace std;

char in[100];

int main(){
    Trie_node root;
    int type;

    while(true){
        cin >> type >> in;
        if(type == 1){
            root.insert(in);
        }
        if(type == 2){
            Trie_node *temp = root.find(in);
            if(temp != nullptr){
                cout << "it existed" << endl;
            }else{
                cout << "no\n";
            }
        }
        
    }

    return 0;
}
