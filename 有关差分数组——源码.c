//c
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) {
    int* nums = malloc(sizeof(int) * n);
    memset(nums, 0, sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < bookingsSize; i++) {
        //开始连续的标记
        nums[bookings[i][0] - 1] += bookings[i][2];
        if (bookings[i][1] < n) {
            //这个数字该结束了
            nums[bookings[i][1]] -= bookings[i][2];
        }
    }
    for (int i = 1; i < n; i++) {
        //继承前面的结果
        nums[i] += nums[i - 1];
    }
    return nums;
} 
