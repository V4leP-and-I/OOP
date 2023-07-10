#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Complex // ����� ��� ������� ������������ ����
{
	double a, b;
public:
	static Complex load() // ����������� ������� ����� ��������� �������
	{
		Complex val;
		double a1, b1;
		cin >> a1 >> b1;
		val.a = a1;
		val.b = b1;
		return val;
	}

	Complex operator *(double b) // ���������� ��������� ���������
	{
		Complex val;
		val.a = this->a * b;
		val.b = this->b * b;
		return val;
	}
	void print() // ������� ������ ������������ �����
	{
		cout <<"(" <<a << "+" << b << "*i)   ";
	}
};

class Polar // ����� ��� ������� ��������� ����
{
	double r, p;
	double x, y;
public:
	static Polar load() // ����������� ������� ����� ��������� �������
	{
		Polar val;
		double a1, b1;
		cin >> a1 >> b1;
		val.r = a1;
		val.p = b1;
		return val;
	}

	Polar operator *(double b) // ���������� ��������� ���������
	{
		Polar val;
		x = this->r * cos(this->p*M_PI/180) * b; // ������� � ��������� ������� ���������
		y = this->r * sin(this->p*M_PI/180) * b; // � ��������� �� ������������ ����� b

		val.p = atan((x / y) * M_PI / 180); // �������� ������� � �������� ������� ���������
		val.r = x / cos(val.p * M_PI / 180);
		return val;
	}

	void print() // ������� ������ ������� � ����
	{
		cout << "(" << r << ", " << p << ")   ";
	}
};

template<class T> //�������� ������� ������, ��������� ������� �� �������� ���� T
class Matrix
{
	T m[3][3]; // �������� ������� ��������� ���� T
public:
	void Load() // ������� ������ ��������� �������
	{
		int cnt = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << cnt << ") ";
				m[i][j] = T::load(); // ����� ����������� ������� ������ ��������� �� ����������� ���� ������
				cnt++;
			}
		}
	}

	Matrix operator *(double b) // ���������� �������� ��������� 
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
	void print() // ������� ������ ������� �� �����
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m[i][j].print(); // ����� ������� ������ ��������� �� ����������� ���� ������
			}
			cout << "\n";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "������� 1, ���� ������� ����������� 3 ����� �������� �� ����������� �����" << endl;
	cout << "������� 2, ���� ������� ����������� 3 ����� �������� �� �������� ���������" << endl;
	cin >> n;

	double b;

	if (n == 1)
	{
		Matrix<Complex> A;
		cout << "������� �������� a � b ����������� ����� (a + b*i):" << endl;
		A.Load();

		cout << "������� ����� ��� ��������� �������: " << endl;
		cin >> b;

		Matrix<Complex> C = A * b;

		cout << "�������� �������:\n";
		A.print();
		cout << "����������� �������:\n";
		C.print();
	}
	if (n == 2)
	{
		Matrix<Polar> A;
		cout << "������� ��������� ����� r � ���� phi:" << endl;
		A.Load();
		cout << "������� ����� ��� ��������� �������: " << endl;
		cin >> b;

		Matrix<Polar> C = A * b;

		cout << "�������� ������� � �������� ������� (r, phi):\n";
		A.print();
		cout << "����������� ������� � �������� ������� (r, phi):\n";
		C.print();
	}
}