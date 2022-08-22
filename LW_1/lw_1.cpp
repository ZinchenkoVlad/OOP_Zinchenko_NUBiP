#include <iostream>
using namespace std;

class cone {
    float radius;   // private variables
    float height;
    float result;

    public:
    cone(); // Constructor without parameters
    cone(float radius, float height); // Constructor with parameters
    ~cone(); // Destructor
    void Set(float radius, float height);
    void Calc();
    void Print_val();
};

cone::cone (){
    radius = height = 0;
    cout << "Constructor without parameters\n"<<endl;
}

cone::cone (float r, float h){
    radius = r;
    height = h;
    result = 0;
    cout << "\nConstructor with parameters\t" << r << "\t" << h << endl;
}

cone::~cone (){
    cout << "\nDestructor"<<endl;
}

void cone::Set(float r, float h)
{
    radius = r;
    height = h;
}

void cone::Calc(){
    result = (radius * radius * height * 3.14 * 0.33333);
    cout << "\nVolume = \t" << result << endl;
}

void cone::Print_val()
{
    cout << "\nRadius\t" << radius << "\tHeight\t" << height << "\tvolume\t" << result << endl;
}



int main(){
    if(true){
        cone a;             // Constructor without parameters static
        // cone a(1.2, 3)   // Constructor with parameters static

        // cone *P = new cone[2];   // dynamic
        // P->Set(19, 50.9);
        // (P + 1)->Set(18, 25.5);


        a.Set(1.5, 3);      // виклик функції SET
        a.Calc();
        a.Print_val();
    }
}
