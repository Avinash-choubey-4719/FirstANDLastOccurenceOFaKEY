#include<bits/stdc++.h>
using namespace std;

int lastOccurence(int arr[], int start, int end, int key){
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;

    if(arr[mid] == key && arr[mid + 1] == key){
        return lastOccurence(arr, mid + 1, end, key);
    }

    else if(arr[mid] == key && arr[mid + 1] != key){
        return mid;
    }

    else if(arr[mid] > key){
        return lastOccurence(arr, start, mid - 1, key);
    }

    else if(arr[mid] < key){
        return lastOccurence(arr, mid + 1, end, key);
    }
}

int firstOccrence(int arr[], int start, int end, int key){
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;

    if(arr[mid] == key && arr[mid - 1] == key){
        return firstOccrence(arr, start, mid - 1, key);
    }

    else if(arr[mid] == key && arr[mid - 1] != key){
        return mid;
    }

    else if(arr[mid] > key){
        return firstOccrence(arr, start, mid - 1, key);
    }

    else if(arr[mid] < key){
        return firstOccrence(arr, mid + 1, end, key);
    }
}

int main(){
    int arr[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    int start = 0;
    int end = 9;

    int key = 1;

    int first = firstOccrence(arr, start, end, key);
    int last = lastOccurence(arr, start, end, key);

    cout<<first<<endl;
    cout<<last<<endl;

    return 0;
}