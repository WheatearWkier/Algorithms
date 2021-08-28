//C++ 
class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int>> bigHeap;
    priority_queue<int,vector<int>,greater<int>> smallHeap;

    MedianFinder() { }
    
    void addNum(int num) 
    {
        if(smallHeap.empty() || num >= smallHeap.top())
        {
            smallHeap.push(num);
            if(smallHeap.size() > bigHeap.size()+1)
            {
                bigHeap.push(smallHeap.top());
                smallHeap.pop();
            }
        }
        else
        {
            bigHeap.push(num);
            if(bigHeap.size() > smallHeap.size())
            {
                smallHeap.push(bigHeap.top());
                bigHeap.pop();
            }
        }
    }
    
    double findMedian() 
    {
        if(smallHeap.size() == bigHeap.size())
        {
            return (double)(smallHeap.top()+bigHeap.top()) / 2;
        }
        else return smallHeap.top();
    }
};



//C 
#define MAX 100000
typedef struct {
    int num;
    int *p;
} MedianFinder;

MedianFinder *strObj;
/** initialize your data structure here. */

int bigHeap[MAX] = {0};
int smallHeap[MAX] = {0};
int bigSize;
int smallSize;

MedianFinder* medianFinderCreate() {
    strObj = malloc(sizeof(MedianFinder));
    strObj->num = 0;
    strObj->p = bigHeap;
    bigSize = 0;
    smallSize = 0;

    return strObj;
}

/*flag��1 ����� -1 С����*/
void UpdataHeap(int *heap, int size, int flag)
{
    int fatherIdx = size - 1;
    int childIdx;
    int originVal = heap[fatherIdx];

    while (fatherIdx >= 0) {
        childIdx = ((fatherIdx + 1) >> 1) - 1;
        if (childIdx < 0 || originVal * flag < heap[childIdx] * flag) { //��Ҫ�ж��Ƿ�����ӽڵ㡣��
            break;
        }
        heap[fatherIdx] = heap[childIdx];
        fatherIdx = childIdx;
    }
    heap[fatherIdx] = originVal;
    
    return;
}

void BigHeap(int num)
{
    bigHeap[bigSize++] = num;

    UpdataHeap(bigHeap, bigSize, 1);

    return;
}

void SmallHeap(int num)
{
    smallHeap[smallSize++] = num;

    UpdataHeap(smallHeap, smallSize, -1);

    return;
}

/*flag��1 ����� -1 С����*/
void AdjastHead(int index, int heapSize, int *heap, int flag)
{
    int childIdx;
    int middle;
    int max;
    int originVal = heap[index]; 
    //����ڵ�ԭʼֵ�����ﲻҪ��index��heap�е����ݺ�����ı䣡����

    middle = heapSize >> 1;

    while (index < middle) {
        childIdx = 2 * index + 1; //���ӽڵ�
        max = heap[childIdx];
        if ((childIdx + 1 < heapSize) && (flag * max < flag * heap[childIdx + 1])) { 
            //��Ҫ�ж��Ƿ�������ӽڵ㡣��
            childIdx = childIdx + 1;
            max = heap[childIdx];  //ѡ�������ӽڵ��С��ֵ
        }

        if (flag * originVal > flag * max) { 
            //�����С����������
            break;
        }

        heap[index] = heap[childIdx];
        index = childIdx;
    }
    heap[index] = originVal;

    return;
}

void DeleteBigHeapHead()
{
    bigHeap[0] = bigHeap[--bigSize]; 
    //�Ƴ�head�󣬽�ĩԪ���Ƶ�head
    AdjastHead(0, bigSize, bigHeap, 1);

    return;
}

void DeleteSmallHeapHead()
{
    smallHeap[0] = smallHeap[--smallSize]; 
    //�Ƴ�head�󣬽�ĩԪ���Ƶ�head
    AdjastHead(0, smallSize, smallHeap, -1);

    return;
}

void medianFinderAddNum(MedianFinder* obj, int num) {  
    /*1��ÿ������Ԫ���������С������СԪ�أ������С���ѣ�2�����С���Ѹ����ȴ���Ѹ�������1������С���Ѷ����Ƶ������*/
    if (smallSize == 0 || num >= smallHeap[0]) {
        SmallHeap(num);
        if (smallSize > bigSize + 1) {
            BigHeap(smallHeap[0]);
            DeleteSmallHeapHead();
        }
    } else {
        BigHeap(num);
        if (bigSize > smallSize) {
            SmallHeap(bigHeap[0]);
            DeleteBigHeapHead();
        }        
    }

    obj->num = bigSize + smallSize;

    return; 
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (smallSize == bigSize) {
        return ((double)(bigHeap[0] + smallHeap[0])) / 2;
    } else {
        return smallHeap[0];
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(strObj);
    memset(bigHeap, 0, MAX * sizeof(int));
}
