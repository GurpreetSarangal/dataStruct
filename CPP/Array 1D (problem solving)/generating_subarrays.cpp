#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;

    int arr[1000];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Generate all subarrays
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<",";
            }
            cout<<"\n";
        }
    }
    return 0;
}
