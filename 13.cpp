#include <iostream>
using namespace std;
void binarySearch(int arr[], int n, int target) {
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return; 
    } else if (arr[mid] < target) {
      low = mid + 1; 
    } else {
      high = mid - 1; 
  }
  }
}

int main()
{
  int n;
  cout<<"Enter the array size :";
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cout<<"\nEnter the element "<<i+1<<" :";
    cin>>arr[i];
  }
  int target;
  cout<<"Enter the target :";
  cin>>target;
  binarySearch(arr, n, target);
}