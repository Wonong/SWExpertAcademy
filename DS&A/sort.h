void swap(int *a, int *b);

void merge(int origin[], int sorted[], int low, int mid, int high){
    int i = low;
    int j = low;
    int h = mid + 1;

    // 두 부분 배열의 각 요소값(i, h)을 비교하며 넣음
    while(i <= mid && h <= high){
        if(origin[i] <= origin[h]) sorted[j++] = origin[i++];
        else sorted[j++] = origin[h++];
    }

    // 부분배열 중 남은 값이 있는 배열의 값을 전부 넣음
    if(i > mid) while(h <= high) sorted[j++] = origin[h++];
    else while(i <= mid) sorted[j++] = origin[i++];

    // 원래 배열로 복사
    for(int l = low; l<=high; l++){
        origin[l] = sorted[l];
    }
}

void mergeSort(int origin[], int sorted[], int low, int high){
    int mid = (low+high)/2;
    
    if(low < high){
        mergeSort(origin, sorted, low, mid);
        mergeSort(origin, sorted, mid+1, high);
        merge(origin, sorted, low, mid, high);
    }
    
}

int partition(int list[], int low, int high){
    // 제일 오른쪽의 값을 pivot으로 선정
    int pivot = list[high];
    
    int left = low;
    int right = high-1;

    // 왼쪽(left)은 pivot보다 작으면 증가, 오른쪽(right)은 pivot보다 크면 감소
    // while문 첫번째 조건은 이미 정렬된 경우를 고려한 것
    // 진행 중단시, 서로의 값을 swap --> 이 과정을 서로가 교차할때까지 반복
    do{
        while(left <= high && list[left] < pivot) left++;
        while(right >= low && list[right] > pivot) right--;
        if(left<right) swap(&list[left], &list[right]);
    }while(left < right);

    // swap pivot element
    swap(&list[high], &list[left]);

    return left;
}

void quickSort(int list[], int low, int high){

    if(low < high){
        int pivot = partition(list, low, high);
        quickSort(list, low, pivot-1);
        quickSort(list, pivot+1, high);
    }
    
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}