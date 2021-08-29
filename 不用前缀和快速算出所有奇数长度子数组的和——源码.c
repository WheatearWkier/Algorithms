//ǰ׺��
int sumOddLengthSubarrays(int* arr, int arrSize)
{
    int sum[arrSize+1];
    sum[0] = 0;
    for(int i = 1;i <= arrSize;i++)
    {
        sum[i] = arr[i-1]+sum[i-1];       //Ԥ������ǰ׺��
    }
    int ret = 0;
    for(int i = 1;i <= arrSize;i += 2)
    {
        for(int j = i;j <= arrSize;j++)
        {
            ret += sum[j]-sum[j-i];       //Ӧ��
        }
    }
    return ret;
}

//�ҹ���
int sumOddLengthSubarrays(int* arr, int arrSize)
{  
    int ret = 0;
    for(int i = 0;i < arrSize;i++)
    {
        int left = i + 1,right = arrSize - i;
        //������Ϊż������
        int left_even = (left+1) >> 1,right_even = (right+1) >> 1;
        //������Ϊ��������
        int left_odd = left >> 1,right_odd = right >> 1;             
        //�����߹��׶Ⱥ�
        ret += (left_even*right_even+left_odd*right_odd)*arr[i];
    }
    return ret;
} 
