#include <bits/stdc++.h>
using namespace std;
 
void KMaxCombinations(int A[], int B[],
                      int N, int K)
{
    priority_queue<int> pq;
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pq.push(A[i] + B[j]);
 
    int count = 0;
    while (count < K) {
        cout << pq.top() << endl;
        pq.pop();
        count++;
    }
}
 
int main()
{
    int A[] = { 4, 2, 5, 1 };
    int B[] = { 8, 0, 5, 3 };
    int N = sizeof(A) / sizeof(A[0]);
    int K = 3;
   
    KMaxCombinations(A, B, N, K);
    return 0;
}