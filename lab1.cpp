#include <iostream>
using namespace std;

//
// Пункт 1. Вывод того, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без
// Для этого используется функция ShowSize, вызываемая в main
//

void ShowSize() {
	cout << "Size of int: " << sizeof(int) << "\n";
	cout << "Size of short int: " << sizeof(short int) << "\n";
	cout << "Size of long int: " << sizeof(long int) << "\n";
	cout << "Size of float: " << sizeof(float) << "\n";
	cout << "Size of double: " << sizeof(double) << "\n";
	cout << "Size of long double: " << sizeof(long double) << "\n";
	cout << "Size of char: " << sizeof(char) << "\n";
	cout << "Size of bool: " << sizeof(bool) << "\n";
}

//
// Пункт 2. Вывод на экран двоичного представления в памяти целого числа (все разряды)
// Пункт 3. Вывод на экран двоичное представление в памяти типа float (все разряды)
// Для этого используются функции IntToBin и FloatToBin соответсвенно, вызываемые в main
//

void IntToBin(int value)
{
	unsigned int order = 32; // Количество разрядов
	unsigned int mask = 1 << order - 1; // Маска побитового сравнения
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0 || i % order - 1 == 0)
		{
			putchar('δ'); // Разделитель
		}
	}
}

void FloatToBin(float deg)
{
	union
	{
		float valuefloat;
		int value;
	};
	valuefloat = deg;
	unsigned int order = 32; // Количество разрядов 
	unsigned int mask = 1 << order - 1;// Маска побитового сравнения
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1; // Побитовый сдвиг числа
		if (i == 1 || i == 2 || i == 9)
			putchar('δ'); // Разделитель
	}
}

//
// Action функции, используемые для создания меню и упрощения функции main
//
void IntAction() {
	int deg;
	cout << "Enter non-digit to exit" << "\n" << "Enter valid integer" << "\n\n";
	cin >> deg;
	while (deg != NULL and deg < INT_MAX and deg > INT_MIN) { // Цикл выполняется, пока deg - валидное целочисленное
		IntToBin(deg);
		cout << "\n" << "Address: " << &deg << "\n\n";
		cin >> deg;
	}
}
void FloatAction() { 
	float deg;
	cout << "Enter non-digit to exit" << "\n" << "Enter valid float" << "\n\n";
	cin >> deg;
	while (deg != NULL and deg < INT_MAX and deg > INT_MIN) { // Цикл выполняется, пока deg - валидное вещественное
		FloatToBin(deg);
		cout << "\n" << "Address: " << &deg << "\n\n";
		cin >> deg;
	}
}
void ChoseAction() {
	Chosequestion:
	cout << "Chose one of the following options:\n1. Show size on data types\n2. Integer to RAM view\n3. Float to RAM view\nX. Exit\n"; // Вывод меню
	char NumberTypeInput;
	cin >> NumberTypeInput;
	switch (NumberTypeInput) { // При вводе корректного варианта консоль очищается и вызывается соответствующая функция, иначе снова предлагается выбор
	case('1'): system("cls"); ShowSize(); break;
	case('2'): system("cls"); IntAction(); break;
	case('3'): system("cls"); FloatAction(); break;
	case('x'): system("cls"); break;
	case('X'): system("cls"); break;
	/*case('q'): system("cls"); break; Добавить выход по q?
	case('Q'): system("cls"); break;*/
	default: goto Chosequestion; break;
	}
}
//
// Функция main, в которой вызываются вышеописанные функции
//
int main()
{
	Mainstart:
	ChoseAction(); // Вывод меню с выбором последующего действия
	cout << "\n" << "Do you want to exit the program?\nType in y/Y to exit, otherwise n/N\n";
	char ExitTypeInput;
	Exitquestion:
	cin >> ExitTypeInput;
	switch (ExitTypeInput) {
	case('y'): break;
	case('Y'): break;
	case('n'): system("cls"); goto Mainstart;  break;
	case('N'): system("cls"); goto Mainstart;  break;
	default: cout << "Enter valid option [y/Y] [n/N]\n"; goto Exitquestion;
	}
}