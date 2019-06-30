// max heap 구현 및 예제 코드 작성
#include <iostream>
#define MAX_HEAP 1000

using namespace std;

int heapArr[MAX_HEAP];
int heapLen = 0;

void insert(int data){
    heapArr[heapLen++] = data;

    int child = heapLen;
    int parent = child/2;
    while(1<child && heapArr[child] < heapArr[parent]){
        swap(&heapArr[child], &heapArr[parent]);
        child = parent;
        parent = child/2;
    }
}

int popHeap(int data){
    // 빈 heap이면 -1 반환
    if(heapLen == 0) return -1;

    int ret = heapArr[1];
    int child = heapLen;

    // 루트와 마지막 요소 swap
    swap(&heapArr[1], &heapArr[heapLen--]);

    // 현재 루트 요소부터 내려가면서 위치를 찾음
    int parent = 1;
    int child = parent*2;
    // max heap이므로 큰 수를 가지는 child 우선.
    if(child+1 <= heapLen){
        child = (heapArr[child] > heapArr[child+1]) ? child : child+1;
    }

    while(child <= heapLen && heapArr[parent] < heapArr[child]){
        swap(&heapArr[parent], &heapArr[child]);

        parent = child;
        child = child*2;
        if(child+1 <= heapLen){
            child = (heapArr[child] > heapArr[child+1]) ? child : child+1;
        }
    }

    return ret;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){

    int temp;
}  
