#include <iostream>

using namespace std;

class Figure
{
	string opposingKing = "";
	string currentPosition = "";

public:
	virtual void checkWin()
	{
		cout << "Default Check" << endl;
	}

	void setOpposingKing(string temp){opposingKing = temp;};
	void getOpposingKing(){cout << "Opposing King is on " << opposingKing << endl;}

	void setCurrentPosition(string temp){currentPosition = temp;};
	void getCurrentPosition(){cout << "Current position is on " << currentPosition << endl;}
};

class Horse : public Figure
{
public:
	Horse(string temp1, string temp2){
		setOpposingKing(temp1);
		setCurrentPosition(temp2);
	}
	
	~Horse(){}

	void checkWin()
	{
		cout << "Horse can not kill King." << endl;
	}
};

class Elephant : public Figure
{
public:
	Elephant(string temp1, string temp2){
		setOpposingKing(temp1);
		setCurrentPosition(temp2);
	}
	
	~Elephant(){}

	void checkWin()
	{
		cout << "Elephant can not call King" << endl;
	}
};

class Rook : public Figure
{
public:
	Rook(string temp1, string temp2){
		setOpposingKing(temp1);
		setCurrentPosition(temp2);
	}
	
	~Rook(){}

	void checkWin()
	{
		cout << "Rock can kill King" << endl;
	}
};

class Queen : public Figure
{
public:
	Queen(string temp1, string temp2){
		setOpposingKing(temp1);
		setCurrentPosition(temp2);
	}
	
	~Queen(){}

	void checkWin()
	{
		cout << "Queen can kill King" << endl;
	}
};


int main()
{
	Figure* A[4];

	Horse one("g2", "h3");
	Elephant two("g2", "h3");
	Rook three("g2", "h3");
	Queen four("g2", "h3");

	A[0] = &one;
	A[1] = &two;
	A[2] = &three;
	A[3] = &four;

	cout << endl;
	for (int i = 0; i < 4; i++){
		A[i]->checkWin(); // поліморфний виклик!!!
	}
	cout << endl;
	return 0;
}