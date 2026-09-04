#include <iostream>
#include <memory>
using namespace std;

class Shader{
  private:
  string name;
  string type;  

  public:

  Shader(const string &name , const string &type ): name(name),type(type){
    cout<<"Shader Compiled"<<endl;

  }
  ~Shader(){
    cout<<"[Shader Destroyed]"<<endl;
  }


  int getReferenceCount(shared_ptr<int> ptr) {
    return ptr.use_count();
  }



};

int main(){
    auto shader = make_shared<Shader>("main_vert", "vertex");
    cout << "Ref count: " << shader.use_count() << endl;

    {
        auto rendererRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;

        auto editorRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;
    }

    cout << "Ref count: " << shader.use_count() << endl;
    
    return 0;
}