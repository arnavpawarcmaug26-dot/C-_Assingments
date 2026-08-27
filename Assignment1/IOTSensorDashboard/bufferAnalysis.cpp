#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter amount of readings: "<<endl;
    cin>>n;
    double arr[n];
    cout<<"Enter readings: "<<endl;
    for (int i=0 ; i<n; i++){
        cin>>arr[i];

    }
    cout<<"Readings entered: "<<n<<endl;
    cout<<"Valid Readings: "<<" ";
    int skipped = 0;
    for(int i=0 ; i<n; i++){
        if(arr[i]<0){
            // cout<<"inside less than 0"<<endl;
            skipped += 1; 
            continue;
        }
        else{
            cout<<arr[i] <<" ";
        }
        
    }
    cout<<"Skipped(errors): "<<skipped<<endl;

    for(int i = 0; i<=n; i++){
        if(arr[i]>=45){
            cout<<"Index "<<i+1<<" "<<arr[i]<<" C"<<endl;
            break;
        }
    }

    double min = arr[0];
    double max = 0;
    double avg;

    for(int i=0 ; i<n ; i++){
        if(arr[i]<0){
            skipped += 1; 
            continue;
        }
        if(arr[i]<min){
            min = arr[i];
        }
        if(arr[i]>max){
            max = arr[i];
        }
        double total;
        total += arr[i];
        avg = total/n; 
    }
    
    cout<<"Min: "<<min<<" ";
    cout<<"Max: "<<max<<" ";
    cout<<"Avg: "<<avg<<" "<<endl;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for(int i=0 ; i<n ; i++){
        if(arr[i]>0 &&arr[i]<=29){
            normal += 1;

        }
        else if(arr[i]>=30 &&arr[i]<=44){
            warning += 1;

        }
        else if(arr[i]>=45 &&arr[i]<=59){
            critical += 1;

        }
        else if(arr[i]>=60){
            shutdown += 1;

        }
    }

    cout<<"Normal: "<<normal<<" ";
    cout<<"Warning: "<<warning<<" ";
    cout<<"Shutdown: "<<shutdown<<" ";
    

    return 0;
}