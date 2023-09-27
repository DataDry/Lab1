#include <iostream>
using namespace std;
void IntToBin(int value)
{
	unsigned int order = 32; // Количество разрядов
	unsigned int mask = 1 << order - 1; // Маска побитового сравнения
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0)
		{
			putchar('δ');
		}
		if (i % order - 1 == 0)
		{
			putchar('δ');
		}
	}
}

void showsize(){
    cout<< "Size of int: "<<sizeof(int)<< "\n";
    cout<< "Size of short int: "<<sizeof(short int)<< "\n";
    cout<< "Size of long int: "<<sizeof(long int)<< "\n";
    cout<< "Size of float: "<<sizeof(float)<< "\n";
    cout<< "Size of double: "<<sizeof(double)<< "\n";
    cout<< "Size of long double: "<<sizeof(long double)<< "\n";
    cout<< "Size of char: "<<sizeof(char)<< "\n";
    cout<< "Size of bool: "<<sizeof(bool)<< "\n";
}

void FloatToBin(float deg)
{
	union
	{
		float a;
		int b;
	};
	a = deg;
	unsigned int mask;
	unsigned int bites = 32; mask = 1 << bites - 1;
	for (int i = 1; i <= bites; i++)
	{
		putchar(b & mask ? '1' : '0');
		b <<= 1;
		if (i == 1 || i == 2 || i == 9)
			cout << "δ";
	}
}

void IntAction() {
	int deg;
	cout << "Enter non-digit to exit" << "\n" << "Enter integer" << "\n\n";
	cin >> deg;
	while (deg != NULL and deg < INT_MAX and deg > INT_MIN) {
		IntToBin(deg);
		cout << "\n" << "Address: " << &deg << "\n\n";
		cin >> deg;
	}
}
void FloatAction() {
	float deg;
	cout << "Enter non-digit to exit" << "\n" << "Enter float" << "\n\n";
	cin >> deg;
	while (deg != NULL and deg < INT_MAX and deg > INT_MIN) {
		FloatToBin(deg);
		cout << "\n" << "Address: " << &deg << "\n\n";
		cin >> deg;
	}
}

void ChoseAction() {
	cout << "\nChose the desired type of number:\n1. Integer\n2. Float\n\n";
	unsigned short int NumberTypeInput;
	cin >> NumberTypeInput;
	switch (NumberTypeInput) {
	case(1): system("cls"); IntAction(); break;
	case(2): system("cls"); FloatAction(); break;
	default: ChoseAction(); break;
	}
}

int main()
{
    showsize();
    cout<<"\n";
    
	ChoseAction();
}