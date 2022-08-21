#include <iostream>
using namespace std;

class cone {
    float radius;
    float height;
    float result;

    public:
    cone(); // конструктор без параметрів
    cone(float radius, float height); // конструктор з параметрами
    ~cone(); // деструктор
    void Set(float radius, float height);
    void Calc();
    void Print_val();
};

void cone::Calc(){
    result = (radius * radius * height * 3.14 * 0.33333);
    cout << "\nVolume = \t" << result << endl;
}



cone::cone (){
    radius = height = 0;
    cout << "Конструктор без параметрів\n"<<endl;
}

cone::cone (float r, float h){
    radius = r;
    height = h;
    result = 0;
    cout << "\nКонструктор з параметрами\t" << r << "\t" << h << endl;
}

cone::~cone (){
    cout << "\nДеструктор"<<endl;
}

void cone::Set(float r, float h)
{
    radius = r;
    height = h;
}

void cone::Print_val()
{
    cout << "\nRadius\t" << radius << "\tHeight\t" << height << "\tvolume\t" << result << endl;
}



int main(){
    if(true){
        cone a;

        a.Set(1.5, 3);
        a.Calc();
        a.Print_val();
    }
}
