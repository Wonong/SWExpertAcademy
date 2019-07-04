struct vector{
    int size, capacity;
    int *vc;

    vector(){
        capacity = 4;
        size = 0;
        vc = new int[capacity];
    }
    void push_back(int num){
        if(capacity == num){
            capacity *= 2;
            int *temp = new int[capacity];
            for(int i=0; i<size; i++) temp[i] = vc[i];
            delete []vc;
            vc = temp;
        }
        vc[size++] = num;
    }


};