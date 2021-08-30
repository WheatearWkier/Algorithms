//C
typedef struct {
    int* pre;       //ǰ׺������
    int preSize;    //ǰ׺������ĳ���
    int total;      //Ȩ���ܺ�
} Solution;         //һ��Solution����һ��w[]

//������w[]����Ԥ�������ǰ׺��
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

//�ö��ֲ��ҳ鵽������ݶ�Ӧ��ǰ׺��������ڵ�����
int binarySearch(Solution* obj, int x) {
    int low = 0, high = obj->preSize - 1;
    while (low < high) {
        int mid = (high - low) / 2 + low;
        if (obj->pre[mid] < x) {
            low = mid + 1; //�����ǰ׺���Ͻ���Ǳ���������������
        } else {
            high = mid;    //���򣬱����ڰ����������ǰ���ڶ�������
        }
    }
    return low;
}

int solutionPickIndex(Solution* obj) {
    int x = rand() % obj->total + 1;   //�������һ����
    return binarySearch(obj, x);       //���ֲ���
}

void solutionFree(Solution* obj) {
    free(obj->pre);
    free(obj);
}
