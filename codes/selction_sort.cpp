#include<bits/stdc++.h>
using namespace std;
void sel(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
    }
    cout << "After selection sort: " << "\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sel(arr,n);
    return 0;
}