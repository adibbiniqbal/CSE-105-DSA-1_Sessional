#include <iostream>
#include <climits>
using namespace std;
int getMax(int a, int b, int c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
int maxCrossSum(int arr[], int low, int mid, int high, int &crossStart, int &crossEnd)
{
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int tempStart = mid, tempEnd = mid;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            tempStart = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            tempEnd = i;
        }
    }
    crossStart = tempStart;
    crossEnd = tempEnd;
    return getMax(leftSum + rightSum, leftSum, rightSum);
}
int maxSumSubarray(int arr[], int low, int high, int &start, int &end)
{
    if (low == high)
    {
        start = end = low;
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftStart, leftEnd, rightStart, rightEnd, crossStart, crossEnd;
    int leftMaxSum = maxSumSubarray(arr, low, mid, leftStart, leftEnd);
    int rightMaxSum = maxSumSubarray(arr, mid + 1, high, rightStart, rightEnd);
    int crossMaxSum = maxCrossSum(arr, low, mid, high, crossStart, crossEnd);
    int maxSum = getMax(leftMaxSum, rightMaxSum, crossMaxSum);
    if (maxSum == leftMaxSum && maxSum != rightMaxSum && maxSum != crossMaxSum)
    {
        start = leftStart;
        end = leftEnd;
    }
    else if (maxSum == rightMaxSum && maxSum != leftMaxSum && maxSum != crossMaxSum)
    {
        start = rightStart;
        end = rightEnd;
    }
    else if (maxSum == crossMaxSum && maxSum != leftMaxSum && maxSum != rightMaxSum)
    {
        start = crossStart;
        end = crossEnd;
    }
    else if (maxSum == leftMaxSum && maxSum == rightMaxSum && maxSum != crossMaxSum)
    {
        if ((leftEnd - leftStart) < (rightEnd - rightStart))
        {
            start = leftStart;
            end = leftEnd;
        }
        else
        {
            start = rightStart;
            end = rightEnd;
        }
    }
    else if (maxSum == leftMaxSum && maxSum == crossMaxSum && maxSum != rightMaxSum)
    {
        if ((leftEnd - leftStart) < (crossEnd - crossStart))
        {
            start = leftStart;
            end = leftEnd;
        }
        else
        {
            start = crossStart;
            end = crossEnd;
        }
    }
    else if (maxSum == rightMaxSum && maxSum == crossMaxSum && maxSum != leftMaxSum)
    {
        if ((rightEnd - rightStart) < (crossEnd - crossStart))
        {
            start = rightStart;
            end = rightEnd;
        }
        else
        {
            start = crossStart;
            end = crossEnd;
        }
    }
    else
    {
        if ((leftEnd - leftStart) < (rightEnd - rightStart) && (leftEnd - leftStart) < (crossEnd - crossStart))
        {
            start = leftStart;
            end = leftEnd;
        }
        else if ((rightEnd - rightStart) < (leftEnd - leftStart) && (rightEnd - rightStart) < (crossEnd - crossStart))
        {
            start = rightStart;
            end = rightEnd;
        }
        else
        {
            start = crossStart;
            end = crossEnd;
        }
    }
    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    if(n<=0)
    {
        cout << "[] with a sum of 0." << endl;
        return 0;
    }
    int scores[n];
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
    int start = -1, end = -1;
    int maxSubarraySum = maxSumSubarray(scores, 0, n - 1, start, end);
    if(maxSubarraySum<=0)
    {
        cout << "[] with a sum of 0." << endl;
        return 0;
    }
    cout << "[";
    for (int i = start; i < end; i++)
    {
        cout << scores[i] << ", ";
    }
    cout << scores[end] << "] with a sum of " << maxSubarraySum << "." << endl;
    return 0;
}