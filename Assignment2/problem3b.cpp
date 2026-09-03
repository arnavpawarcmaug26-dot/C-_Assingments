#include <iostream>
using namespace std;


namespace Physics{
     double clamp(double val, double min, double max){
        if (val < min) return min;
        if (val>min) return max;
        return val;
     }
     
     double lerp(double a, double b, double t){
        return a + t * (b - a);
     }
}

namespace GameMath{
    int clamp(int val, int min, int max){
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }
    double lerp(double a, double b, double t){
         return a + t * (b - a);
    }
}

int main(){

    double rawVelocity = 150.5;
    double maxVelocity = 120.0;
    double cappedVelocity = Physics::clamp(rawVelocity, 0.0, maxVelocity);
    cout << "Capped Velocity: " << cappedVelocity <<endl;

    int currentHealth = -15;
    int cappedHealth = GameMath::clamp(currentHealth, 0, 100);
    std::cout << "Capped Health: " << cappedHealth << endl;

    using namespace GameMath;

    double uiAlpha = lerp(0.0, 1.0, 0.5); 
    int playerLevel = clamp(105, 1, 99); 

    cout << "UI Alpha Lerp: " << uiAlpha << endl;
    cout << "Player Level: " << playerLevel << endl;


    return 0;
}