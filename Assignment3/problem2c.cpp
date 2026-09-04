#include <iostream>
using namespace std;

class AudioClip{
    private:
    string name;
    double duration;
    
    public:
    AudioClip(const string &name , double duration):name(name),duration(duration){
        cout<<"[Audio Clip Loaded.]"<<endl;
    }
    ~AudioClip(){
        cout<<"[Audio Clip Unoaded.]"<<endl;

    }

    string getName() const{
        return name;
    }
    double getDuration() const{
        return duration;
    }

};

int main(){

    auto audio = make_shared<AudioClip>("explosion", 3.5);
    weak_ptr<AudioClip> observer = audio;

    if (auto clip = observer.lock()){
    cout << "Clip alive: " << clip->getName() << endl;
    }
    audio.reset();

    if(observer.expired()){
        cout << "Clip already unloaded." << endl;
    }

    return 0;
}