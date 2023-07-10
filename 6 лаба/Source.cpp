#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <boost\archive\xml_iarchive.hpp> // библиотека для работы с xml фаилами (ввод)
#include <boost\archive\xml_oarchive.hpp> // библиотека для работы с xml фаилами (вывод)

using namespace std;

class Machine // главный наследуемый класс - машина
{
public:
	string type; // тип авто
	string batch; // серия
	int number; // номер
	string type_gasoline; // тип бензина
	void add_machine()// функция ввода
	{
		cout << "Введите серию автомобиля: ";
		cin >> batch;
		cout << endl << "Введите номер автомобиля: ";
		cin >> number;
		cout << endl << "Введите тип бензина: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, type_gasoline);
		cout << endl;
	}

	void show_machine()// функция вывода
	{
		cout << "Тип машины: " << type << endl;
		cout << "Cерия автомобиля: " << batch << endl;
		cout << "Номер автомобиля: " << number << endl;
		cout << "Тип бензина: " << type_gasoline << endl;
	}
	void change_machine()// функция изменения
	{
		cout << "Что вы хотите изменить" << endl;
		cout << "1.Cерию автомобиля"<< endl;
		cout << "2.Номер автомобиля"<< endl;
		cout << "3.Тип бензина" << endl;
	}
};

class Transport : public Machine // класс - транспорт, наследуется от класса - машина
{
public:
	int count_wheel; // количество колёс
	string season; // сезон
	string deterioration_wheel; // состояние колёс
	int p = 0;
	pair <string, string> W = make_pair("Зима", "С шипами");
	pair <string, string> S = make_pair("Лето", "Без шипов");

	void add_transport()// функция ввода
	{
		add_machine();

		cout << "Введите количество колёс: ";
		cin >> count_wheel;
		cout << endl << "Какой сейчас сезон:";
		while (p != 1 && p != 2)
		{
			cout << endl << "1. Зима";
			cout << endl << "2. Лето" << endl;
			cin >> p;
		}
		if (p == 1) season = "Зима";
		else season = "Лето";

		p = 0;
		cout << endl << "Введите тип шин: ";
		while (p != 1 && p != 2)
		{
			cout << endl << "1. С шипами";
			cout << endl << "2. Без шипов" << endl;
			cin >> p;
		}
		if (p == 1) deterioration_wheel = "С шипами";
		else deterioration_wheel = "Без шипов";

		if (season == W.first && deterioration_wheel != W.second)
			cout << endl << "Советуем заменить шины колёс, на дорогах может заносить";
		else if (season == S.first && deterioration_wheel != S.second)
			cout << endl << "Советуем заменить шины колёс, на дорогах уже давно растаял лёд";
		cout << endl;
	}
	void show_transport()// функция вывода
	{
		show_machine();

		cout << "Количество колёс: " << count_wheel << endl;
		cout << "Тип колёс: " << deterioration_wheel << endl;
		cout << "Сезон года: " << season << endl;
	}

	void change_transport()// функция изменения
	{
		change_machine();
		cout << "4.Количество колёс"<< endl;
		cout << "5.Тип колёс"<< endl;
		cout << "6.Сезон года" << endl;
	}
};

class Automobile : public Transport // класс - автомобиль, наследуется от класса - транспорт
{
public:
	int seating_capacity; // свободные места
	void add_autho()// функция ввода
	{
		add_transport();

		cout << "Введите количество пассажирских мест: ";
		cin >> seating_capacity;
		cout << endl;
		type = "Автомобиль";
	}

	void show_autho()// функция вывода
	{
		show_transport();
		cout << "Количество пассажирских мест: " << seating_capacity << endl;
	}

	void change_auto()// функция изменения
	{
		change_transport();
		cout << "8.Количество пассажирских мест: " << endl;
	}
	// функция сериализации
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(type);
		ar& BOOST_SERIALIZATION_NVP(batch);
		ar& BOOST_SERIALIZATION_NVP(number);
		ar& BOOST_SERIALIZATION_NVP(type_gasoline);
		ar& BOOST_SERIALIZATION_NVP(count_wheel);
		ar& BOOST_SERIALIZATION_NVP(deterioration_wheel);
		ar& BOOST_SERIALIZATION_NVP(season);
		ar& BOOST_SERIALIZATION_NVP(seating_capacity);
	}
};



class Autospectechnics : public Transport // класс - автоспецтехника, наследуется от класса - транспорт
{
public:
	int tonnage; // тоннаж

	void add_spec()// функция ввода
	{
		add_transport();
		cout << "Введите тоннаж: ";
		cin >> tonnage;
		cout << endl;
	}
	void show_spec()// функция вывода
	{
		show_transport();

		cout << "Тоннаж: " << tonnage << endl;
	}
	void change_spec()// функция изменения
	{
		change_transport();
		cout << "7.Тоннаж " << endl;
	}

};

class Bus : public Automobile // класс - автобус, наследуется от класса - автомобиль
{
public: 
	string place_of_departure; // место отбытия
	string arrival_point; // место прибытия
	void add_bus() // функция ввода
	{
		add_autho();

		cout << "Место отбытия: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin,place_of_departure);
		cout << endl << "Место прибытия: ";
		cin.clear();
		getline(cin,arrival_point);
		cout << endl;
		type = "Автобус";
	}

	template<class Archive>// функция сериализации
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(type);
		ar& BOOST_SERIALIZATION_NVP(batch);
		ar& BOOST_SERIALIZATION_NVP(number);
		ar& BOOST_SERIALIZATION_NVP(type_gasoline);
		ar& BOOST_SERIALIZATION_NVP(count_wheel);
		ar& BOOST_SERIALIZATION_NVP(deterioration_wheel);
		ar& BOOST_SERIALIZATION_NVP(season);
		ar& BOOST_SERIALIZATION_NVP(seating_capacity);
		ar& BOOST_SERIALIZATION_NVP(place_of_departure);
		ar& BOOST_SERIALIZATION_NVP(arrival_point);
	}

	void show_bus()// функция вывода
	{
		show_autho();
		cout << "Место отбытия: " << place_of_departure << endl;
		cout << "Место прибытия: " << arrival_point << endl;
	}

	void change_bus()// функция изменения
	{
		change_auto();
		cout << "8.Место отбытия" << endl;
		cout << "9.Место прибытия" << endl;
	}
};

class Truck : public Autospectechnics // класс - грузовик, наследуется от класса - автоспецтехника
{
public:
	string cargo_type; // тип груза
	void add_truck() // функция ввода 
	{
		add_spec();
		cout << "Введите тип груза: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, cargo_type);
		cout << endl;
		type = "Грузовик";
	}

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(type);
		ar& BOOST_SERIALIZATION_NVP(batch);
		ar& BOOST_SERIALIZATION_NVP(number);
		ar& BOOST_SERIALIZATION_NVP(type_gasoline);
		ar& BOOST_SERIALIZATION_NVP(count_wheel);
		ar& BOOST_SERIALIZATION_NVP(deterioration_wheel);
		ar& BOOST_SERIALIZATION_NVP(season);
		ar& BOOST_SERIALIZATION_NVP(tonnage);
		ar& BOOST_SERIALIZATION_NVP(cargo_type);
	}

	void show_truck()// функция вывода
	{
		show_spec();
		cout << "Перевозимый груз: " << cargo_type << endl;
	}

	void change_truck()// функция изменения данных
	{
		change_spec();
		cout << "8.Перевозимый груз " << endl;
	}
};

class Concrete_Mixer_truck : public Autospectechnics // класс - бетономешательная машина, наследуется от класса - автоспецтехника
{
public:
	string amount_of_concrete; // вместимость миксера
	void add_mix() // функция ввода 
	{
		add_spec();
		cout << "Введите вместимость миксера: ";
		cin >> amount_of_concrete;
		cout << endl;
		type = "Бетономешалка";
	}

	template<class Archive> // функция сериализации
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(type);
		ar& BOOST_SERIALIZATION_NVP(batch);
		ar& BOOST_SERIALIZATION_NVP(number);
		ar& BOOST_SERIALIZATION_NVP(type_gasoline);
		ar& BOOST_SERIALIZATION_NVP(count_wheel);
		ar& BOOST_SERIALIZATION_NVP(deterioration_wheel);
		ar& BOOST_SERIALIZATION_NVP(season);
		ar& BOOST_SERIALIZATION_NVP(tonnage);
		ar& BOOST_SERIALIZATION_NVP(amount_of_concrete);
	}
	void show_mix() // функция вывода
	{
		show_spec();
		cout << "Объем миксера: " << amount_of_concrete << endl;
	}
	void change_mix() // функция изменения данных
	{
		change_spec(); 
		cout << "8.Объем миксера" << endl;
	}
};

class Serialize // класс для сериализации данных
{
public:

	int constant = 0;

	friend class boost::serialization::access; // для работы с boost
	Concrete_Mixer_truck mixer; // объект - бетономешалка
	Truck truck; // объект - грузовик
	Bus bus; // объект - автобус
	Automobile autho; // объект - автомобиль
	string Typ; // объект - заголовок

	template<class Archive> // шаблонная функция для сериализации данных
	void serialize(Archive& ar, const unsigned int version)
	{
		if (Typ == "Автомобиль" || autho.type == "Автомобиль")
		{
			ar& BOOST_SERIALIZATION_NVP(autho);
			constant = 1;
		}
		else if (Typ == "Автобус" || bus.type == "Автобус")
		{
			ar& BOOST_SERIALIZATION_NVP(bus);
			constant = 2;
		}
		else if (Typ == "Грузовик" || truck.type == "Грузовик")
		{
			ar& BOOST_SERIALIZATION_NVP(truck);
			constant = 3;
		}
		else if (Typ == "Бетономешалка" || mixer.type == "Бетономешалка")
		{
			ar& BOOST_SERIALIZATION_NVP(mixer);
			constant = 4;
		}
	}

	void menu_add() // функция меню для доьбавления новых данных
	{
		char m = 0;
		while (m != '5')
		{
			cout << "\tКакой тип машины в вашем распоряжении:" << endl;
			cout << "1. Автомобиль" << endl;
			cout << "2. Автобус" << endl;
			cout << "3. Грузовик" << endl;
			cout << "4. Бетономешательная машина" << endl;
			cout << "5. Вернуться" << endl;
			cin >> m;

			if (m == '1')
			{
				autho.add_autho(); // вызов функции добавления данных об автомобиле
				constant = 1;
				Typ = autho.type;
				break;
			}
			if (m == '2')
			{
				bus.add_bus(); // вызов функции добавления данных об автобусе
				constant = 2;
				Typ = bus.type;
				break;
			}
			if (m == '3')
			{
				truck.add_truck(); // вызов функции добавления данных об грузовике
				constant = 3;
				Typ = truck.type;
				break;
			}
			if (m == '4')
			{
				mixer.add_mix(); // вызов функции добавления данных об бетономешалке
				constant = 4;
				Typ = mixer.type;
				break;
			}
		}
	}

	void menu_change() // функция редактирования данных
	{
		int x;
		if (Typ == "")
		{
			cout << "Ваш гараж пуст" << endl;
			return;
		}
		else if (Typ == "Автомобиль") // тип данных - автомобиль
		{
			autho.change_auto(); // вызов функции изменения данных автомобиля
			cin >> x;
			cout << "Введите: ";
			switch (x)
			{
			case 1:
				cin >> autho.batch;
				break;
			case 2:
				cin >> autho.number;
				break;
			case 3:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, autho.type_gasoline);
				break;
			case 4:
				cin >> autho.count_wheel;
				break;
			case 5:
				cin >> autho.deterioration_wheel;
				break;
			case 6:
				cin >> autho.season;
				break;
			case 7:
				cin >> autho.seating_capacity;
				break;
			}
		}
		else if (Typ == "Грузовик")
		{
			truck.change_truck(); // вызов функции изменения данных грузовика
			cin >> x;
			cout << "Введите: ";
			switch (x)
			{
			case 1:
				cin >> truck.batch;
				break;
			case 2:
				cin >> truck.number;
				break;
			case 3:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, truck.type_gasoline);
				break;
			case 4:
				cin >> truck.count_wheel;
				break;
			case 5:
				cin >> truck.deterioration_wheel;
				break;
			case 6:
				cin >> truck.season;
				break;
			case 7:
				cin >> truck.tonnage;
				break;
			case 8:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, truck.cargo_type);
				break;
			}
		}
		else if (Typ == "Автобус")
		{
			bus.change_bus();// вызов функции изменения данных автобуса
			cin >> x;
			cout << "Введите: ";
			switch (x)
			{
			case 1:
				cin >> bus.batch;
				break;
			case 2:
				cin >> bus.number;
				break;
			case 3:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, bus.type_gasoline);
				break;
			case 4:
				cin >> bus.count_wheel;
				break;
			case 5:
				cin >> bus.deterioration_wheel;
				break;
			case 6:
				cin >> bus.season;
				break;
			case 7:
				cin >> bus.seating_capacity;
				break;
			case 8:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, bus.place_of_departure);
				break;
			case 9:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, bus.arrival_point);
				break;
			}
		}
		else if (Typ == "Бетономешалка")
		{
			mixer.change_mix();// вызов функции изменения данных бетономешалки
			cin >> x;
			cout << "Введите: ";
			switch (x)
			{
			case 1:
				cin >> mixer.batch;
				break;
			case 2:
				cin >> mixer.number;
				break;
			case 3:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, mixer.type_gasoline);
				break;
			case 4:
				cin >> mixer.count_wheel;
				break;
			case 5:
				cin >> mixer.deterioration_wheel;
				break;
			case 6:
				cin >> mixer.season;
				break;
			case 7:
				cin >> mixer.tonnage;
				break;
			case 8:
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, mixer.amount_of_concrete);
				break;
			}
		}
	}

	void show() // функция вывода данных
	{
		if (constant == 0)
		{
			cout << "Данных нет" << endl;
		}
		else if (constant == 1)
		{
			autho.show_autho(); // вывод данных автомобиля
		}
		else if (constant == 2)
		{
			bus.show_bus(); // вывод данных автобуса
		}
		else if (constant == 3)
		{
			truck.show_truck(); // вывод данных грузовика
		}
		else if (constant == 4)
		{
			mixer.show_mix(); // вывод данных бетономешательной машины
		}
	}
};

class serT // класс для сериализации заголовка данных
{
public:
	string Type;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(Type);
	}
};

// шаблонные функции сериализации

template<typename T> //сохранение заголовка(типа) данных
void save_type(T data) {
	ofstream fout("saveT.xml");
	boost::archive::xml_oarchive oa(fout);
	oa << BOOST_SERIALIZATION_NVP(data);
}

template<typename T> // загрузка заголовка(типа) данных
void load_type(T& data) {
	ifstream fin("saveT.xml");
	boost::archive::xml_iarchive ia(fin);
	ia& BOOST_SERIALIZATION_NVP(data);
}

template<typename T>  //сохранение данных
void save(T data) {
	ofstream fout("save.xml");
	boost::archive::xml_oarchive oa(fout);
	oa << BOOST_SERIALIZATION_NVP(data);
	cout << "Успешно сохранено!" << endl;
}

template<typename T>  // загрузка данных
void load(T& data) {
	ifstream fin("save.xml");
	boost::archive::xml_iarchive ia(fin);
	ia& BOOST_SERIALIZATION_NVP(data);
	cout << "Успешно загружено!" << endl;
}


int main()
{
	vector <pair<pair<string, string>, string>> vec;
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Serialize _xml; // создание объекта данных для сериализации
	serT typ; // создание объекта заголовка данных для сериализации

	char k = 0;

	while (k != '6')
	{
		cout << "\tГараж" << endl;
		cout << "1. Посмотреть данные" << endl;
		cout << "2. Загрузить данные" << endl;
		cout << "3. Сохранить данные" << endl;
		cout << "4. Добавить данные" << endl;
		cout << "5. Редактировать данные" << endl;
		cout << "6. Выйти из гаража" << endl;

		cin >> k;

		if (k == '1')
		{
			_xml.show(); // вызов функции вывода данных на экран
		}
		else if (k == '2')
		{
			load_type(typ); // вызов шаблонной функции загрузки заголовка данных
			_xml.Typ = typ.Type;
			load(_xml); // вызов шаблонной функции загрузки данных
		}
		else if (k == '3')
		{
			typ.Type = _xml.Typ; // вызов шаблонной функции сохранения заголовка данных
			save_type(typ);
			save(_xml);// вызов шаблонной функции сохранения данных
		}
		else if (k == '4')
		{
			_xml.menu_add(); // вызов функции меню для добавления новых данных
		}
		else if (k == '5')
		{
			_xml.menu_change(); // вызов функции меню для редактирования данных
		}
	}
	
}