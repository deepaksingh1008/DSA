#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printArray(int *arr,int n){
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int *arr,int i,int j){
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int *arr,int low,int high){
    int pivot = arr[low];
    int count=0;
    for(int i=low+1;i<=high;i++){
         if(arr[i]<=pivot){
            count++;
         }
    }
    int p_index = low+count;
    swap(arr,low,p_index);
    
    int i=low;
    int j=high;
    while(i<p_index && j>p_index){
       while(arr[i]<pivot){
           i++;
       }
       while(arr[j]>pivot){
        j--;
       }
      if(i<p_index && j>p_index){
         swap(arr,i,j);
      }
    }
    return p_index;
 
}

void quickSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int p_index =  partition(arr,s,e);
    quickSort(arr,s,p_index-1);
    quickSort(arr,p_index+1,e);
}

int main(){
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int n=9;
    printArray(arr,n);
    quickSort(arr,0,n); 
    printArray(arr,n);

}