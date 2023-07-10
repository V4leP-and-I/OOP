#include<iostream>
#include<vector>

using namespace std;

class VectorFuncia {// Базовый класс, являющийся интерфейсом для производного класса Funkcia
protected:
	int N;//размер вектор-функции
	double x;
	int n;
	vector <double> funcElems;//вектор для хранения значений вектор-функции
	double coefs[3];

public:
	void Funcia() {//функция для определения размерности вектор-функции и значения х
		cout << "Введите размерность вектор-функции: ";
		cin >> N;
		funcElems.resize(N);//переопределение размера массива значений вектор-функции
		cout << endl;
	}

	void Cout() {//Вывод значений вектор-функции
		for (int i = 0; i < N; i++)
			cout << funcElems[i] << endl;
	}

	virtual void elems() = 0; //виртуальная функция для заполнения вектора элементами вектор-функции
	virtual void calculate(double x) = 0;//Объявление виртуальной функции, которая делает расчёт элементов вектор-функции
};

class Funkcia : public VectorFuncia {//класс наследуемый методы и функции класса VectorFuncia
public:
	void elems() override
	{
		cout << "Выберите функцию:" << endl << "1, если a* sin(b * x)" << endl << "2, если a* lg(b * x) + c" << endl;
		cin >> n;
		int i = 0;
		if (n == 1)
		{
			cout << endl << "Введите a и b для " << i + 1 << " функции: ";
			cin >> coefs[0] >> coefs[1];
			cout << endl;
			i++;
		}
		else
		{
			cout << endl << "Введите a, b и c для" << i + 1 << " функции: ";
			cin >> coefs[0] >> coefs[1] >> coefs[2];
			cout << endl;
			i++;
		}

	}
	void calculate(double x) override 
	{	
		for (int i = 0; i < N; i++)
		{
			elems();
			//вычисление значения i-й строки вектор функции
			if (n == 1)
			{
				funcElems[i] = coefs[0] * sin(coefs[1] * x);
			}

			else
			{
				funcElems[i] = coefs[0] * log10(coefs[1] * x) + coefs[2];
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	
	Funkcia A;
	A.Funcia();
	cout << "Введите скалярный аргумент X: ";
	int x;
	cin >> x;
	A.calculate(x);
	A.Cout();
	
}

