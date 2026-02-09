int findMin(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
        {
            // Minimum is in right half
            left = mid + 1;
        }
        else
        {
            // Minimum is at mid or left half
            right = mid;
        }
    }

    return nums[left];
}
