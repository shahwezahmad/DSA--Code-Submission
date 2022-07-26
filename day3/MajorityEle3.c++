#include <bits/stdc++.h>

using namespace std;
vector < int > majorityElement(int arr[], int n) {
  vector < int > ans;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] == arr[i])
        cnt++;
    }

    if (cnt > (n / 3)) 
      ans.push_back(arr[i]);
  }

  return ans;
}