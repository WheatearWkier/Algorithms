//C
typedef struct {
    int* pre;       //前缀和数组
    int preSize;    //前缀和数组的长度
    int total;      //权重总和
} Solution;         //一个Solution代表一组w[]

//对这组w[]进行预处理，求出前缀和
Solution* solutionCreate(int* w, int wSize) {
    Solution* obj = malloc(sizeof(Solution));
    obj->pre = malloc(sizeof(int) * wSize);
    obj->preSize = wSize;
    obj->total = 0;
    for (int i = 0; i < wSize; i++) {
        obj->total += w[i];
        if (i > 0) {
            obj->pre[i] = obj->pre[i - 1] + w[i];
        } else {
            obj->pre[i] = w[i];
        }
    }
    return obj;
}

//用二分查找抽到的球根据对应的前缀和求出落在的区间
int binarySearch(Solution* obj, int x) {
    int low = 0, high = obj->preSize - 1;
    while (low < high) {
        int mid = (high - low) / 2 + low;
        if (obj->pre[mid] < x) {
            low = mid + 1; //如果比前缀和上界大，那必是在其后面的区间
        } else {
            high = mid;    //否则，必是在包含该区间的前面众多区间中
        }
    }
    return low;
}

int solutionPickIndex(Solution* obj) {
    int x = rand() % obj->total + 1;   //先随机出一个数
    return binarySearch(obj, x);       //二分查找
}

void solutionFree(Solution* obj) {
    free(obj->pre);
    free(obj);
}
