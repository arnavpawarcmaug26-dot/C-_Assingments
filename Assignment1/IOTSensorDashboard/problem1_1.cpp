#include<iostream>
using namespace std;

int statusCode(double temperature){
    int statusCode;
    if(temperature<0){
        statusCode = -1;
        return statusCode;
    }
    else if(temperature>=0 && temperature<=29){
        statusCode = 0;
        return statusCode;
    }
    else if(temperature>=30 && temperature<=44){
        statusCode = 1;
        return statusCode;
    }
    else if(temperature>=45 && temperature<=59){
        statusCode = 2;
        return statusCode;
    }
    else{
        statusCode = 3;
        return statusCode;
    }
}


double celsiusTofarenhite(double temperature){
    double farenhite = ((temperature*9)/5) + (32);
    return farenhite;
}

int main(){
    double temperature;
    cout<<"Temperature: "<<endl;
    cin>>temperature;
    cout<<"Temperature: "<<temperature<<" C"<<" "<<celsiusTofarenhite(temperature)<<" F"<<endl;


    int status = statusCode(temperature);
    // cout<<"Status: "<<status<<endl;
    if(status==-1){
        cout<<"Status: "<<"SENSOR_ERROR"<<endl;
    }
    else if(status==0){
        cout<<"Status: "<<"NORMAL"<<endl;
    }
    else if(status==1){
        cout<<"Status: "<<"WARNING"<<endl;
    }
    else if(status==2){
        cout<<"Status: "<<"CRITICAL"<<endl;
    }
    else if(status==3){
        cout<<"Status: "<<"SHUTDOWN"<<endl;
    }

    switch(status){
        case -1:
        cout<<"Action: "<<"Sensor Fault - check wiring."<<endl;
        break;
        case 0:
        cout<<"Action: "<<"No action required"<<endl;
        break;
        case 1:
        cout<<"Action: "<<"Alert sent to supervisor."<<endl;
        break;
        case 2:
        cout<<"Action: "<<"Cooling system triggered."<<endl;
        break;
        case 3:
        cout<<"Action: "<<"Emergency Shutdown initiated."<<endl;
        break;
        default:
        cout<<"Invalid Status"<<endl;

    }

    string reading = (temperature>=25)?"Above Average":"Below Average";
    cout<<"Reading: "<<reading<<endl;

    return 0;
    
}