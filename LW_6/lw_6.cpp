#include <iostream>
using namespace std;

class Organisation
{

	string name;
	string adress;

public:
	void setName(string temp) { name = temp; }
	void getName() { cout << "organisation name\t" << name << endl; }
};

class InsuranceCompany : public Organisation
{
	string name2;

public:
	InsuranceCompany(string temp) { name2 = temp; };
	~InsuranceCompany(){};
	void getName2() { cout << "insurcomp name2\t\t" << name2 << endl; }
};

class ConstructionCompany : public Organisation
{
protected:
	int projectsAtAll;

public:
	void setProjects(int temp) { projectsAtAll = temp; }
	void getProjects() { cout << "projects at all\t\t" << projectsAtAll << endl; }
};

class MetroBuilding : public ConstructionCompany
{
protected:
	int justVariable;

public:
	MetroBuilding(int temp) { justVariable = temp; };
	~MetroBuilding(){};
	void setJustVariable(int temp) { justVariable = temp; }
	void getJustVariable() { cout << "justVariable\t\t" << justVariable << endl; }
};

int main()
{
	cout << "-------------------------------------" << endl;
	cout << "Creating Insurance Company\n"<< endl;

	InsuranceCompany a("Olegovich");
	a.setName("Aligator");
	a.getName();
	a.getName2();

	cout << "\n-------------------------------------" << endl;
	cout << "Creating MetroBuilding\n"<< endl;

	MetroBuilding b(205);
	b.setName("OOP_METRO_BUILD");
	b.setProjects(15);

	b.getName();
	b.getProjects();
	b.getJustVariable();
	cout << "-------------------------------------" << endl;

}
