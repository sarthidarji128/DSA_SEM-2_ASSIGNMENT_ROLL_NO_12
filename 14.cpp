#include<iostream>
using namespace std;

void bubblesortaccsend(int arr[],int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nElement "<<i+1<<" :"<<arr[i];
    }
}


void bubblesortdescend(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] < arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
  }
  
  for (int i = 0; i < n; i++) {
    cout << "\nElement " << i + 1 << ": " << arr[i];
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
    cout<<"\nArray in accending order :";
    bubblesortaccsend(arr,n);
    cout<<"\nArray in decending order :";
    bubblesortdescend(arr,n);
}