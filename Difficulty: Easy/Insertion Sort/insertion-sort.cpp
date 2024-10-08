//{ Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void swap (int arr[] , int high, int low){
        int temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;
    }
    
    void insert(int arr[], int i)
    {
        //code here
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr, j , j-1);
            j--;
    }
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for (int i = 0 ; i<= n-1; i++){
            
            insert(arr, i);
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends