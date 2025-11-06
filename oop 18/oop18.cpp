#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Car {
private:
	string model;
	int year;
	double price;
public:
	Car(string m, int y, double p) : model(m), year(y), price(p)
	{}

	void displayInfo()
	{
		cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;

	}

	void Print()
	{
		cout << model << "," << year << "," << price << endl;

	}

	void SaveFile(string filename)
	{
		ofstream write;
		write.open(filename, ios::out);
		write << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
		write.close();

	}

	void LoadFile()
	{
		ifstream read;
		string line;
		read.open("car_info.txt");
		while (getline(read, line))
		{
			cout << line << endl;
		}
		read.close();
	}
};

int main() {
	
	Car car1("Toyota Camry", 2020, 24000.50);
	car1.displayInfo();
	car1.Print();
	car1.SaveFile("car_info.txt");
	car1.LoadFile();
	return 0;
}