



#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    // L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back
    // into arr[l..r]
    // Initial index of first subarray
    i = 0;

    // Initial index of second subarray
    j = 0;

    // Initial index of merged subarray
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements
    // of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r); 
    } 
}

int isNull(int arr[],int a){
    for(int i=0;i<a;i++){
        if(arr[i]!=-1){
            return 0;
        }
    }
    return 1;
}


int value(int arr[],int a,int k){
    int temp[a];
    for(int i=0;i<a;i++){
        temp[i]=arr[i];
    }
    int flag=1;
    int c=0;
        for(int i=0;i<a;i++){
            if(temp[i]!=-1){
                for(int j=i+1;j<a;j++){
                    if(temp[i]+temp[j]==k){
                        temp[i]=-1;
                        temp[j]=-1;
                        c++;
                        break;
                    }
                }
            }
        }
    return c;
}

int main()
{
    int a;
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,a-1);
    int limit=arr[a-1]+arr[a-2];
    int max=0;
    for(int i=2;i<=limit;i++){
        int r=value(arr,a,i);
        if(r>max){
            max=r;
        };
    }
    printf("%d\n",max);
    
    return 0;

}
