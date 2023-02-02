#include <bits/stdc++.h>
using namespace std;
// function to check whether mid is a possible solution or not
bool isPossible(int arr[], int N, int mid, int M)
{
    int sum = 0;
    // traverse the array
    for (int i = 0; i < N; i++)
    {
        // if height of tree is greater than height of sawblade then only it is possible to cut the tree and add that height i.e arr[i]-mid into sum
        if (arr[i] > mid)
        {
            // update the sum so that he has a track of how much wood he have at current instance
            sum += arr[i] - mid;
        }
        // check that if he get required amount of wood or not and if yes return true
        if (sum >= M)
        {
            return true;
        }
    }
    // not get required amount of wood
    return false;
}
int main()
{
    // N-no of elements in array i.e no of trees
    // M-amount of wood needed
    int N, M;
    cin >> N >> M;
    // creating an array of N size at runtime
    int *arr = new int[N];
    // take input in array from user
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    // initialise start = 1 as reuired wood amount is atleast one and end=2*pow(10,9) i.e max amount of wood he takes
    int s = 1, e = 2e9;
    int ans = -1;
    // appling binary search
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // check if he get the required amount of wood i.e M or not by setting the sawblade at mid height
        if (isPossible(arr, N, mid, M))
        {
            // if yes maybe it is a valid ans and he increase the height as ATQ we have to find the max sawblade height possible
            ans = mid;
            s = mid + 1;
        }
        else
        {
            // if not decrease the height as he is not able to get the required amount of wood
            e = mid - 1;
        }
    }
    // print the result
    cout << ans;
    return 0;
}