#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int *arr,int s,int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int *left = new int[len1];
    int *right = new int[len2];
    int  k=s;
    for(int i=0;i<len1;i++){
       left[i]=arr[k++];
    }
    k=mid+1;
    for(int j=0;j<len2;j++){
        right[j]=arr[k++];
    }
   int i=0,j=0;
   k=s;
   while(i<len1 && j<len2){
        if(left[i]>right[j]){
            arr[k++]=right[j];
            j++;
        }
        else{
            arr[k++]=left[i];
            i++;
        }
   }
   while(i<len1){
    arr[k++]=left[i++];
   }
   while(j<len2){
    arr[k++]=right[j++];
   }

}
void mergeSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int n=10;
    printArray(arr,n);
    mergeSort(arr,0,n-1); 
    printArray(arr,n);

}