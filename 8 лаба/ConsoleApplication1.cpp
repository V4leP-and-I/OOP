#include <iostream>

using namespace std;

class Error_B : public exception // ввод недопустимой размерности матрицы B
{
public:
    Error_B(const char* msg) : exception(msg) {}
};
class Error_Null : public exception // ввод размерности равной нулю
{
public:
    Error_Null(const char* msg) : exception(msg) {}
};
class Error_Number : public exception // ввод недопустимого числа
{
public:
    Error_Number(const char* msg) : exception(msg) {}
};

class Error // клас обрабатывающий исключения
{
    int a_2;
public:
    void getA(int& x, int& y) // функция для вода и проверки размерности матрицы A
    {
        while (1)// пока не будет введён правильный символ
        { //программа будет запрашиваеть его бесконечное число раз
            try
            {
                cin >> x >> y;
                a_2 = y;
                if (cin.fail())
                    throw Error_Number("Вы ввели недопустимое значение.");
                if (x == 0 || y == 0)
                    throw Error_Null("Строки и столбцы не могут быть равны нулю");
                cout << endl;
                break;
            }
            catch (Error_Number& ex)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << ex.what() << endl; 
                cout << "Введите размерность матрицы A: ";
            }
            catch (Error_Null& ex)
            {
                cout << ex.what() << endl;
                cout << "Введите размерность матрицы A: ";
            }
        }
    }
    void getB(int& x, int& y)// функция для вода и проверки размерности матрицы B
    {
        while (1)// пока не будет введён правильный символ
        { //программа будет запрашиваеть его бесконечное число раз
            try
            {
                cin >> x >> y;
                if (cin.fail())
                    throw Error_Number("Вы ввели недопустимое значение.");
                if (x == 0 || y == 0)
                    throw Error_Null("Строки и столбцы не могут быть равны нулю");
                if (a_2 != x)
                    throw Error_B("Матрицу этой размерности нельзя умножить на матрицу A");
                cout << endl;
                break;
            }
            catch (Error_Number& ex)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << ex.what() << endl;
                cout << "Введите размерность матрицы B: ";
            }
            catch (Error_Null& ex)
            {
                cout << ex.what() << endl;
                cout << "Введите размерность матрицы B: ";
            }
            catch (Error_B& ex)
            {
                cout << ex.what() << endl;
                cout << "Введите размерность матрицы B: ";
            }
        }
    }
    void getX(float& x)// функция для вода и проверки числа
    {
        while (1) // пока не будет введён правильный символ
        { //программа будет запрашиваеть его бесконечное число раз
            try
            {
                cin >> x;
                if (cin.fail()) 
                    throw Error_Number("Вы ввели недопустимое значение.");
                //cout << endl;
                break;
            }
            catch (Error_Number& ex)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << ex.what() << endl;
                //cout << "Введите число: ";
            }
        }
    }
};

class Matrica
{
private:
    int c1, c2;
    float** mas; //объявление массива и размерности

public:
    Matrica()
    {
        c1 = 0;
        c2 = 0;
        mas = 0;
    }

    Matrica(float** massiv, int n1, int n2)//конструктор с параметрами
    { //создаёт обрабатываемую матрицу
        {  
            c1 = n1; 
            c2 = n2;
            mas = new float* [n1]; 
            for (int i = 0; i < n1; i++)
            {
                mas[i] = new float[n2];
            }
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    mas[i][j] = massiv[i][j];
                }
            }
        }
    }

    Matrica(const Matrica& matricaA) // Конструктор копирования
    {
        c1 = matricaA.c1;
        c2 = matricaA.c2;
        mas = new float* [c1];
        for (int i = 0; i < c1; i++)
        {
            this->mas[i] = new float[c2];
        }
        for (int i = 0; i < c1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                this->mas[i][j] = matricaA.mas[i][j];
            }
        }
    }

    friend Matrica operator* (Matrica& A, Matrica& B);
    friend Matrica operator+ (Matrica& A, float& X);
    friend Matrica operator- (Matrica& A, float& X);
    friend Matrica operator* (Matrica& A, float& X);

    Matrica& operator=(const Matrica& ravno) //оператор присваивания 
    { // присваевает матрице C результат перемножения матриц A и B
        this->c1 = ravno.c1;
        this->c2 = ravno.c2;
        this->mas = new float* [c1];
        for (int i = 0; i < c1; i++)
        {
            this->mas[i] = new float[c2];
        }
        for (int i = 0; i < c1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                this->mas[i][j] = ravno.mas[i][j];
            }
        }
        return *this;

    }

    void vivod(string stroka)//функция выводит матрицу
    { 
        cout << endl << stroka << endl; 
        for (int i = 0; i < c1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << mas[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrica()//деструктор 
    { // очищает массив
        for (int i = 0; i < c2; i++) 
        { 
            delete[] mas[i];
        }
        delete[] mas;

    }
};
Matrica operator-(Matrica& A, float& X)// Перегрузка оператора для вычитания из матрицы A вещественного числа
{
    float** N = new float* [A.c1];

    for (int i = 0; i < A.c1; i++)
    {
        N[i] = new float[A.c2];
        for (int j = 0; j < A.c2; j++)
        {
            N[i][j] = 0;
            N[i][j] += A.mas[i][j] - X;
        }
    }
    Matrica new_C(N, A.c1, A.c2); //для дальнейшего вывода матрицы на экран используем конструктор с параметрами
    cout << endl << "Операция разности";
    new_C.vivod("Матрица C:"); // вызываем функцию вывода матрицы
    for (int i = 0; i < A.c2; i++)
    {
        delete[] N[i];
    }
    delete[] N;
    return new_C;
}
Matrica operator*(Matrica& A, float& X)// Перегрузка оператора для умножения матрицы A на вещественное число
{
    float** N = new float* [A.c1];

    for (int i = 0; i < A.c1; i++)
    {
        N[i] = new float[A.c2];
        for (int j = 0; j < A.c2; j++)
        {
            N[i][j] = 0;
            N[i][j] += A.mas[i][j] * X;
        }
    }
    Matrica new_C(N, A.c1, A.c2); //для дальнейшего вывода матрицы на экран используем конструктор с параметрами
    cout << endl << "Операция умножения на число";
    new_C.vivod("Матрица C:"); // вызываем функцию вывода матрицы
    for (int i = 0; i < A.c2; i++)
    {
        delete[] N[i];
    }
    delete[] N;
    return new_C;
}

Matrica operator+ (Matrica& A, float& X)// Перегрузка оператора для сложения матрицы A и вещественного числа
{
    float** N = new float* [A.c1];

    for (int i = 0; i < A.c1; i++)
    {
        N[i] = new float[A.c2];
        for (int j = 0; j < A.c2; j++)
        {
            N[i][j] = 0;
            N[i][j] += A.mas[i][j] + X;
        }
    }
    Matrica new_C(N, A.c1, A.c2); //для дальнейшего вывода матрицы на экран используем конструктор с параметрами
    cout << endl << "Операция сложения";
    new_C.vivod("Матрица C:"); // вызываем функцию вывода матрицы
    for (int i = 0; i < A.c2; i++)
    {
        delete[] N[i];
    }
    delete[] N;
    return new_C;
}

Matrica operator* (Matrica& A, Matrica& B) // Перегрузка оператора для умножения матрицы A на матрицу B
{
    //производим умножение
    float** N = new float* [A.c1];

    for (int i = 0; i < A.c1; i++)
    {
        N[i] = new float[B.c2];
        for (int j = 0; j < B.c2; j++)
        {
            N[i][j] = 0;
            for (int k = 0; k < A.c2; k++)
            {
                N[i][j] += A.mas[i][k] * B.mas[k][j];
            }
        }
    }
    Matrica new_C(N, A.c1, B.c2); //для дальнейшего вывода матрицы на экран используем конструктор с параметрами
    cout << endl << "Операция умножения";
    new_C.vivod("Матрица C:"); // вызываем функцию вывода матрицы
    for (int i = 0; i < B.c2; i++)
    {
        delete[] N[i];
    }
    delete[] N;
    return new_C;
}

int main()
{
    setlocale(LC_ALL, "rus");

    float** mas1;
    float** mas2;

    Error* error = new Error;
    int a1, a2, b1, b2;
    float x;

    int a;
    cout << "Выберите операцию:" << endl;
    cout << "1. Произведение матриц" << endl;
    cout << "2. Умножение матрицы на число" << endl;
    cout << "3. Разность матрицы и числа" << endl;
    cout << "4. Сложение матрицы и числа" << endl;
    cin >> a;
    if (a == 1)
    {
        cout << "Введите размерность матрицы A: ";
        error->getA(a1, a2);
        mas1 = new float* [a1];
        for (int i = 0; i < a1; i++) //создание первого массива 
        {
            mas1[i] = new float[a2];
        }
        cout << "Введите элементы матрицы A: " << endl;
        for (int i = 0; i < a1; i++)
        {
            for (int j = 0; j < a2; j++)
            {
                float k;
                error->getX(k);// проверка элемента массива
                mas1[i][j] = k;
            }
        }

        cout << "Введите размерность матрицы B: ";
        error->getB(b1, b2);

        mas2 = new float* [b1];
        for (int i = 0; i < b1; i++) //создание второго массива 
        {
            mas2[i] = new float[b2];
        }
        cout << "Введите элементы матрицы B: " << endl;
        for (int i = 0; i < b1; i++)
        {
            for (int j = 0; j < b2; j++)
            {
                float k;
                error->getX(k);// проверка элемента массива
                mas2[i][j] = k;
            }
        }

        Matrica C;
        Matrica A(mas1, a1, a2);
        Matrica B(mas2, b1, b2);
        A.vivod("Матрица A");
        B.vivod("Матрица B");

        C = A * B;
    }
    if (a == 2)
    {
        cout << "Введите размерность матрицы A: ";
        error->getA(a1, a2);
        mas1 = new float* [a1];
        for (int i = 0; i < a1; i++) //создание первого массива 
        {
            mas1[i] = new float[a2];
        }
        cout << "Введите элементы матрицы A: " << endl;
        for (int i = 0; i < a1; i++)
        {
            for (int j = 0; j < a2; j++)
            {
                float k;
                error->getX(k);// проверка элемента массива
                mas1[i][j] = k;
            }
        }

        cout << "Введите число: ";
        error->getX(x);// проверка числа

        Matrica C;
        Matrica A(mas1, a1, a2);
        A.vivod("Матрица A");
        cout << "Число: " << x << endl;

        C = A * x;
    }
    if (a == 3)
    {
        cout << "Введите размерность матрицы A: ";
        error->getA(a1, a2);
        mas1 = new float* [a1];
        for (int i = 0; i < a1; i++) //создание первого массива 
        {
            mas1[i] = new float[a2];
        }
        cout << "Введите элементы матрицы A: " << endl;
        for (int i = 0; i < a1; i++)
        {
            for (int j = 0; j < a2; j++)
            {
                float k;
                error->getX(k);// проверка элемента массива
                mas1[i][j] = k;
            }
        }

        cout << "Введите число: ";
        error->getX(x);// проверка числа

        Matrica C;
        Matrica A(mas1, a1, a2);
        A.vivod("Матрица A");
        cout << "Число: " << x << endl;

        C = A - x;
    }
    if (a == 4)
    {
        cout << "Введите размерность матрицы A: ";
        error->getA(a1, a2);
        mas1 = new float* [a1];
        for (int i = 0; i < a1; i++) //создание массива 
        {
            mas1[i] = new float[a2];
        }
        cout << "Введите элементы матрицы A: " << endl;
        for (int i = 0; i < a1; i++)
        {
            for (int j = 0; j < a2; j++)
            {
                float k;
                error->getX(k); // проверка элемента массива
                mas1[i][j] = k;
            }
        }

        cout << "Введите число: ";
        error->getX(x); // проверка числа

        Matrica C;
        Matrica A(mas1, a1, a2);
        A.vivod("Матрица A");
        cout << "Число: " << x << endl;

        C = A + x;
    }

    
}
