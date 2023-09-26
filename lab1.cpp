#include <iostream>
#include <Windows.h>
using namespace std;
void NumberAsBinary(int value)
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
/*void FloatToBInary(float value) {
	union {
		int integer = 127;
		float floatB;

	};
	for (int i = 0; i < order; i++) {
		cout << (integerA & mask) ? 1 : 0);
		integerA = integerA << 1;
		if (!i) { cout << ' '; }
	}
}*/
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


int main()
{
    showsize();
    cout<<"\n\n";
    int deg;
	cout << "\n" << "Enter non-digit to exit" << "\n" << "Enter integer" << "\n\n";
	cin >> deg;

	while (deg != NULL and deg < INT_MAX and deg > INT_MIN) {
		NumberAsBinary(deg);
		cout << "\n" << "Address: " << &deg << "\n\n";
		cin >> deg;
	}
	
}