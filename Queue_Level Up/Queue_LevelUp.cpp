// Queue_LevelUp Question.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<stack>
#include<list>
#include<vector>

using namespace std;


void printMaxOrMin(int arr[], int n) //MAX|MIN in each Window of Size K in an arraY->BRUTE FORCE METHOD->COMPLEXITY{O(N^3)}

{
    for (int k = 1; k <= n; k++)
    {
        int maxofMin = INT_MIN;
        for (int i = 0; i <= n-k; i++)
        {
            int min = arr[i];
            for (int j = 1; j < k; j++)
            {
                if (arr[i + j] < min)
                    min = arr[i + j];
            }
            if (min > maxofMin)
                maxofMin = min;
        }
        cout << maxofMin << " ";
    }
}
void printKMax(int arr[], int N, int K) //uisng DeQue {O(N)}
{

   
    std::deque<int> Qi(K);

    /* Process first k (or first window)
     elements of array */
    int i;
    for (i = 0; i < K; ++i) {

        // For every element, the previous
        // smaller elements are useless so
        // remove them from Qi
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

            // Remove from rear
            Qi.pop_back();

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (int i=K; i < N; ++i) {

        // The element at the front of
        // the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << " ";

        // Remove the elements which
        // are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - K)

            // Remove from front of queue
            Qi.pop_front();

        // Remove all elements
        // smaller than the currently
        // being added element (remove
        // useless elements)
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        // Add current element at the rear of Qi
        Qi.push_back(i);
    }

    // Print the maximum element
    // of last window
    cout << arr[Qi.front()];
}



int main()
{

    int arr[] = { 10,20,30,50,10,70,30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxOrMin(arr,n);
    int k = 3;
    cout << endl;
    printKMax(arr, n, k);

    return 0;
}

