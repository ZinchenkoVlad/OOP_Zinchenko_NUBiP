#include <iostream>
using namespace std;

class Cone
{
	float radius; // private variables
	float heigth;
	float result;

public:
	Cone();							  // Constructor without parameters
	Cone(float radius, float height); // Constructor with parameters
	~Cone();						  // Destructor

	void setHeight(float height);
	void setRadius(float radius);

	void calc();
	void getRadius();
	void getHeight();
	void getVolume();

	friend ostream &operator<<(ostream &t, Cone &obj);
	Cone operator+(Cone &op2);
	Cone operator++(int notused);
};

Cone::Cone()
{
	radius = heigth = 0;
	// cout << "Constructor without parameters\n"<<endl;
}

Cone::Cone(float r, float h)
{
	radius = r;
	heigth = h;
	result = 0;
	// cout << "\nConstructor with parameters\t" << r << "\t" << h << endl;
}

Cone::~Cone()
{
	// cout << "\nDestructor"<<endl;
}

void Cone::setHeight(float h)
{
	heigth = h;
}

void Cone::setRadius(float r)
{
	radius = r;
}

void Cone::calc()
{
	result = (radius * radius * heigth * 3.14 * 0.33333);
}

void Cone::getRadius()
{
	cout << "\nRadius\t" << radius << endl;
}

void Cone::getHeight()
{
	cout << "\nHeigth\t" << heigth << endl;
}

void Cone::getVolume()
{
	cout << "\nVolume\t" << result << endl;
}

ostream &operator<<(ostream &t, Cone &obj)
{
	obj.calc();

	t << "\nRadius\t" << obj.radius << "\nHeigth\t" << obj.heigth << "\nVolume\t" << obj.result;
	return t;
}


Cone Cone ::operator+(Cone &op2)
{
	Cone temp;
	temp.radius = radius + op2.radius; // Операції додавання цілочисельних
	temp.heigth = heigth + op2.heigth; // значень зберігають оригінальний
	return temp;
}

Cone Cone ::operator++(int notused)
{
	Cone temp = *this;
	radius++;
	heigth++;
	return temp;
}

int main()
{

	Cone a(1.2, 3);
	Cone b(1.5, 4);

	Cone c;

	cout << "-------------------------------------" << endl;
	c = a + b;

	cout << "c = a+b" << endl;
	c.getHeight();
	c.getRadius();
	cout << "-------------------------------------" << endl;

	cout << "a before ++" << endl;
	a.getHeight();
	a.getRadius();

	a++;
	cout << "\na++" << endl;
	a.getHeight();
	a.getRadius();
	cout << "-------------------------------------" << endl;

	cout << "a<<" << endl;

	cout << a;
}