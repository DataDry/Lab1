#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;
bool isFloat( string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail(); 
}
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

void IntToBin(int value,int customMove)
{
	unsigned int order = sizeof(int)*8; // Количество разрядов
	unsigned int mask = 1 << order - 1; // Маска побитового сравнения
	if (customMove != 0);
		int maxint = INT_MAX;
		value = value & maxint;
		value >>= customMove;
		maxint = -INT_MAX;
		value = value | maxint;
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		mask >>= 1; // Побитовый сдвиг числа
		if (i % 8 == 0 || i % order - 1 == 0)
		{
			putchar('δ'); // Разделитель
		}
	}
}

void FloatToBin(float deg, int customMove)
{
	unsigned int order = 32; // Количество разрядов 
	unsigned int mask = 1 << order - 1;// Маска побитового сравнения
	union
	{
		float valuefloat;
		int value;
	};
	valuefloat = deg;

	if (customMove != 0);
		int maxint = INT_MAX;
		value = value & maxint;
		value >>= customMove;
		maxint = -INT_MAX;
		value = value | maxint;
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		mask >>= 1; // Побитовый сдвиг числа
		if (i == 1 || i == 2 || i == 9)
			putchar('δ'); // Разделитель
	}
}

//
// Action функции, используемые для создания меню и упрощения функции main
//
int IntAction() {
	string deg;
	char strbuffer[_MAX_ITOSTR_BASE10_COUNT];
	int intI;
	int customMove;
	string customMoveInput;
	//Input Number
	cout << "Enter X to exit" << "\n" << "Enter valid integer" << "\n\n";
	intAsk:
	cin >> deg;
	intI = atoi(deg.c_str());
	if (deg == "x" || deg == "X") { return(0); }
	if (deg != _itoa(intI, strbuffer, 10)) { cout << "\nInvalid integer entered, try again: \n"; goto intAsk; }
	//Input customMove
	BitwiseMoveAsk:
	cout << "Enter valid custom bitwise move number\n";
	cin >> customMoveInput;
	customMove = atoi(customMoveInput.c_str());
	if (customMoveInput == "x" || customMoveInput == "X") { return(0); }
	if (customMoveInput != _itoa(customMove, strbuffer, 10)) { cout << "\nInvalid bitwise move number entered, try again: \n"; goto BitwiseMoveAsk; }
	while (intI != NULL and intI <= INT_MAX and intI >= INT_MIN) { // Цикл выполняется, пока deg - валидное целочисленное
		IntToBin(intI, customMove);
		cout << "\n" << "Address: " << &intI << "\n\n";
		loopintAsk:
		cin >> deg;
		intI = atoi(deg.c_str());
		if (deg == "x" || deg == "X") { return(0); }
		if (deg != to_string(intI)) { cout << "\nInvalid integer entered, try again: \n\n"; goto loopintAsk; }
		loopBitwiseMoveAsk:
		cin >> customMoveInput;
		customMove = atoi(customMoveInput.c_str());
		if (customMoveInput == "x" || customMoveInput == "X") { return(0); }
		if (customMoveInput != _itoa(customMove, strbuffer, 10)) { cout << "\nInvalid bitwise move number entered, try again: \n"; goto loopBitwiseMoveAsk; }
	}
}

int FloatAction() { 
	string deg;
	char strbuffer[_MAX_ITOSTR_BASE10_COUNT];
	float floatF;
	int customMove;
	string customMoveInput;
	//Input Number
	cout << "Enter X to exit" << "\n" << "Enter valid float" << "\n\n";
	floatAsk:
	cin >> deg;
	floatF = stof(deg.c_str());
	if (deg == "x" || deg == "X") { return(0); }
	if (!isFloat(deg)) { cout << "\nInvalid float entered, try again: \n\n"; goto floatAsk; }
	//Input customMove
	BitwiseMoveAsk:
	cout << "Enter valid custom bitwise move number\n";
	cin >> customMoveInput;
	customMove = atoi(customMoveInput.c_str());
	if (customMoveInput == "x" || customMoveInput == "X") { return(0); }
	if (customMoveInput != _itoa(customMove, strbuffer, 10)) { cout << "\nInvalid bitwise move number entered, try again: \n"; goto BitwiseMoveAsk; }
	while (floatF != NULL and floatF <= INT_MAX and floatF >= INT_MIN) { // Цикл выполняется, пока deg - валидное вещественное
		FloatToBin(floatF, customMove);
		cout << "\n" << "Address: " << &floatF << "\n\n";
		loopfloatAsk:
		cin >> deg;
		floatF = atof(deg.c_str());
		if (deg == "x" || deg == "X") { return(0); }
		if (!isFloat(deg)) { cout << "\nInvalid float entered, try again: \n"; goto loopfloatAsk; }
		loopBitwiseMoveAsk:
		cin >> customMoveInput;
		customMove = atoi(customMoveInput.c_str());
		if (customMoveInput == "x" || customMoveInput == "X") { return(0); }
		if (customMoveInput != _itoa(customMove, strbuffer, 10)) { cout << "\nInvalid bitwise move number entered, try again: \n"; goto loopBitwiseMoveAsk; }
	}
}
void ChoseAction() {
	Chosequestion:
	cout << "Chose one of the following options:\n1. Show size of the data types\n2. Integer to RAM view\n3. Float to RAM view\nX. Exit\n\n"; // Вывод меню
	char NumberTypeInput;
	NumberTypeInput = _getch();
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
	cout << "\nDo you want to exit the program?\nType in y/Y to exit, otherwise n/N\n\n";
	char ExitTypeInput;
	Exitquestion:
	ExitTypeInput = _getch();
	switch (ExitTypeInput) {
	case('y'): break;
	case('Y'): break;
	case('n'): system("cls"); goto Mainstart;  break;
	case('N'): system("cls"); goto Mainstart;  break;
	default: cout << "Enter valid option [y/Y] [n/N]\n\n"; goto Exitquestion;
	}
}
