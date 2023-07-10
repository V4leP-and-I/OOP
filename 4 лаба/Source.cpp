#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Complex // класс дл€ матрицы комплексного типа
{
	double a, b;
public:
	static Complex load() // статическа€ функци€ ввода элементов матрицы
	{
		Complex val;
		double a1, b1;
		cin >> a1 >> b1;
		val.a = a1;
		val.b = b1;
		return val;
	}

	Complex operator *(double b) // перегрузка оператора умножени€
	{
		Complex val;
		val.a = this->a * b;
		val.b = this->b * b;
		return val;
	}
	void print() // функци€ вывода комплексного числа
	{
		cout <<"(" <<a << "+" << b << "*i)   ";
	}
};

class Polar // класс дл€ матрицы пол€рного типа
{
	double r, p;
	double x, y;
public:
	static Polar load() // статическа€ функци€ ввода элементов матрицы
	{
		Polar val;
		double a1, b1;
		cin >> a1 >> b1;
		val.r = a1;
		val.p = b1;
		return val;
	}

	Polar operator *(double b) // перегрузка оператора умножени€
	{
		Polar val;
		x = this->r * cos(this->p*M_PI/180) * b; // перевод в декартову систему координат
		y = this->r * sin(this->p*M_PI/180) * b; // и умножение на вещественное число b

		val.p = atan((x / y) * M_PI / 180); // обратный перевод в пол€рную систему координат
		val.r = x / cos(val.p * M_PI / 180);
		return val;
	}

	void print() // функци€ вывода радиуса и угла
	{
		cout << "(" << r << ", " << p << ")   ";
	}
};

template<class T> //создание шаблона класса, хран€щего матрицу из объектов типа T
class Matrix
{
	T m[3][3]; // создание массива элементов типа T
public:
	void Load() // функци€ записи элементов матрицы
	{
		int cnt = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << cnt << ") ";
				m[i][j] = T::load(); // вызов статической функции записи элементов из конкретного типа данных
				cnt++;
			}
		}
	}

	Matrix operator *(double b) // перегрузка операции умножени€ 
	{
		Matrix<T> val;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				val.m[i][j] = this->m[i][j] * b;
			}
		}
		return val;
	}
	void print() // функци€ вывода матрицы на экран
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m[i][j].print(); // вызов функции вывода элементов из конкретного типа данных
			}
			cout << "\n";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "¬ведите 1, если матрица размерности 3 будет состо€ть из комплексных чисел" << endl;
	cout << "¬ведите 2, если матрица размерности 3 будет состо€ть из пол€рных координат" << endl;
	cin >> n;

	double b;

	if (n == 1)
	{
		Matrix<Complex> A;
		cout << "¬ведите значени€ a и b комплексной формы (a + b*i):" << endl;
		A.Load();

		cout << "¬ведите число дл€ умножени€ матрицы: " << endl;
		cin >> b;

		Matrix<Complex> C = A * b;

		cout << "»сходна€ матрица:\n";
		A.print();
		cout << "ѕроизводна€ матрица:\n";
		C.print();
	}
	if (n == 2)
	{
		Matrix<Polar> A;
		cout << "¬ведите параметры длины r и угла phi:" << endl;
		A.Load();
		cout << "¬ведите число дл€ умножени€ матрицы: " << endl;
		cin >> b;

		Matrix<Polar> C = A * b;

		cout << "»сходна€ матрица в пол€рной системе (r, phi):\n";
		A.print();
		cout << "ѕроизводна€ матрица в пол€рной системе (r, phi):\n";
		C.print();
	}
}