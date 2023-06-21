#include<iostream>
#include<string>

using namespace std;
class Calculator
{
	int counter;
	double x, y;
public:
	Calculator() :x(0), y(0) { counter++; };
	static double Plus(double x, double y) { return x + y; };
	static double Minus(double x, double y) { return x - y; };
	static double Devide(double x, double y) { return x / y; };
	static double Multi(double x, double y) { return x * y; };
	//int getCounter() { return counter; };

};
//подсчет колличества объектов класса
class objectCounter
{
	
public:
	static int _counter;
	objectCounter() { _counter ++; }
	int getCounter() { return _counter; };
	static void MethodStatic() { cout << "Method static" << endl; };
};

int objectCounter::_counter = 0;

int main()
{
	objectCounter o1;
	objectCounter o2;
	objectCounter o3;


	cout << o3.getCounter()<<endl;//3
	cout << objectCounter::_counter << endl;//3
	objectCounter::MethodStatic();

	system("pause");
	return 0;
}