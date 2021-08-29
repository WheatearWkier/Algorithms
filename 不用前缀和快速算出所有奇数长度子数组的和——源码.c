//前缀和
int sumOddLengthSubarrays(int* arr, int arrSize)
{
    int sum[arrSize+1];
    sum[0] = 0;
    for(int i = 1;i <= arrSize;i++)
    {
        sum[i] = arr[i-1]+sum[i-1];       //预处理求前缀和
    }
    int ret = 0;
    for(int i = 1;i <= arrSize;i += 2)
    {
        for(int j = i;j <= arrSize;j++)
        {
            ret += sum[j]-sum[j-i];       //应用
        }
    }
    return ret;
}

//找规律
int sumOddLengthSubarrays(int* arr, int arrSize)
{  
    int ret = 0;
    for(int i = 0;i < arrSize;i++)
    {
        int left = i + 1,right = arrSize - i;
        //当两边为偶数数组
        int left_even = (left+1) >> 1,right_even = (right+1) >> 1;
        //当两边为奇数数组
        int left_odd = left >> 1,right_odd = right >> 1;             
        //求两边贡献度和
        ret += (left_even*right_even+left_odd*right_odd)*arr[i];
    }
    return ret;
} 
