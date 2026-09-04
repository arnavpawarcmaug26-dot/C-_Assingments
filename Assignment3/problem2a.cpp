#include <iostream>
#include <memory>
using namespace std;

class Texture{
private:

    string name;
    int width;
    int height;

public:
    Texture(const string& name, int width, int height)
        : name(name), width(width), height(height) {
        cout << "[Texture Loaded]" << endl;
    }

    ~Texture() {
        cout << "[Texture Released]" << endl;
    }

    void display() const{
        cout<<name<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
    }


};

int main(){
    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);
    tex1->display();
    
    // unique_ptr<Texture> tex2 = tex1; unique_ptr disables its copy constructor to enforce exclusive ownership. No sharing allowed.

    unique_ptr<Texture> tex2 = std::move(tex1);
    cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;

    return 0;
}