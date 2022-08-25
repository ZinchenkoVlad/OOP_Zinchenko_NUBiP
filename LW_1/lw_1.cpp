#include <iostream>
using namespace std;

class Cone {
    float radius;   // private variables
    float height;
    float result;

    public:
    Cone(); // Constructor without parameters
    Cone(float radius, float height); // Constructor with parameters
    ~Cone(); // Destructor

    void setHeight(float height);
    void setRadius(float radius);
    
    void calc();
    void getRadius();
    void getHeight();
    void getVolume();
};

Cone::Cone (){
    radius = height = 0;
    cout << "Constructor without parameters\n"<<endl;
}

Cone::Cone (float r, float h){
    radius = r;
    height = h;
    result = 0;
    cout << "\nConstructor with parameters\t" << r << "\t" << h << endl;
}

Cone::~Cone (){
    cout << "\nDestructor"<<endl;
}

void Cone::setHeight(float h)
{
    height = h;
}

void Cone::setRadius(float r)
{
    radius = r;
}

void Cone::calc(){
    result = (radius * radius * height * 3.14 * 0.33333);
}


void Cone::getRadius()
{
    cout << "\nRadius\t" << radius << endl;
}

void Cone::getHeight()
{
    cout << "\nHeight\t" << height << endl;
}

void Cone::getVolume()
{
    cout << "\nVolume\t" << result << endl;
}



int main(){
    
    Cone a;             // Constructor without parameters static
    // cone a(1.2, 3)   // Constructor with parameters static

    // cone *P = new cone[2];   // dynamic
    // P->Set(19, 50.9);
    // (P + 1)->Set(18, 25.5);


    a.setHeight(3);
    a.setRadius(1.5);

    a.calc();

    a.getHeight();
    a.getRadius();
    a.getVolume();
}
