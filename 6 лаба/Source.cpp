#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <boost\archive\xml_iarchive.hpp> // ���������� ��� ������ � xml ������� (����)
#include <boost\archive\xml_oarchive.hpp> // ���������� ��� ������ � xml ������� (�����)

using namespace std;

class Machine // ������� ����������� ����� - ������
{
public:
	string type; // ��� ����
	string batch; // �����
	int number; // �����
	string type_gasoline; // ��� �������
	void add_machine()// ������� �����
	{
		cout << "������� ����� ����������: ";
		cin >> batch;
		cout << endl << "������� ����� ����������: ";
		cin >> number;
		cout << endl << "������� ��� �������: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, type_gasoline);
		cout << endl;
	}

	void show_machine()// ������� ������
	{
		cout << "��� ������: " << type << endl;
		cout << "C���� ����������: " << batch << endl;
		cout << "����� ����������: " << number << endl;
		cout << "��� �������: " << type_gasoline << endl;
	}
	void change_machine()// ������� ���������
	{
		cout << "��� �� ������ ��������" << endl;
		cout << "1.C���� ����������"<< endl;
		cout << "2.����� ����������"<< endl;
		cout << "3.��� �������" << endl;
	}
};

class Transport : public Machine // ����� - ���������, ����������� �� ������ - ������
{
public:
	int count_wheel; // ���������� ����
	string season; // �����
	string deterioration_wheel; // ��������� ����
	int p = 0;
	pair <string, string> W = make_pair("����", "� ������");
	pair <string, string> S = make_pair("����", "��� �����");

	void add_transport()// ������� �����
	{
		add_machine();

		cout << "������� ���������� ����: ";
		cin >> count_wheel;
		cout << endl << "����� ������ �����:";
		while (p != 1 && p != 2)
		{
			cout << endl << "1. ����";
			cout << endl << "2. ����" << endl;
			cin >> p;
		}
		if (p == 1) season = "����";
		else season = "����";

		p = 0;
		cout << endl << "������� ��� ���: ";
		while (p != 1 && p != 2)
		{
			cout << endl << "1. � ������";
			cout << endl << "2. ��� �����" << endl;
			cin >> p;
		}
		if (p == 1) deterioration_wheel = "� ������";
		else deterioration_wheel = "��� �����";

		if (season == W.first && deterioration_wheel != W.second)
			cout << endl << "�������� �������� ���� ����, �� ������� ����� ��������";
		else if (season == S.first && deterioration_wheel != S.second)
			cout << endl << "�������� �������� ���� ����, �� ������� ��� ����� ������� ��";
		cout << endl;
	}
	void show_transport()// ������� ������
	{
		show_machine();

		cout << "���������� ����: " << count_wheel << endl;
		cout << "��� ����: " << deterioration_wheel << endl;
		cout << "����� ����: " << season << endl;
	}

	void change_transport()// ������� ���������
	{
		change_machine();
		cout << "4.���������� ����"<< endl;
		cout << "5.��� ����"<< endl;
		cout << "6.����� ����" << endl;
	}
};

class Automobile : public Transport // ����� - ����������, ����������� �� ������ - ���������
{
public:
	int seating_capacity; // ��������� �����
	void add_autho()// ������� �����
	{
		add_transport();

		cout << "������� ���������� ������������ ����: ";
		cin >> seating_capacity;
		cout << endl;
		type = "����������";
	}

	void show_autho()// ������� ������
	{
		show_transport();
		cout << "���������� ������������ ����: " << seating_capacity << endl;
	}

	void change_auto()// ������� ���������
	{
		change_transport();
		cout << "8.���������� ������������ ����: " << endl;
	}
	// ������� ������������
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



class Autospectechnics : public Transport // ����� - ���������������, ����������� �� ������ - ���������
{
public:
	int tonnage; // ������

	void add_spec()// ������� �����
	{
		add_transport();
		cout << "������� ������: ";
		cin >> tonnage;
		cout << endl;
	}
	void show_spec()// ������� ������
	{
		show_transport();

		cout << "������: " << tonnage << endl;
	}
	void change_spec()// ������� ���������
	{
		change_transport();
		cout << "7.������ " << endl;
	}

};

class Bus : public Automobile // ����� - �������, ����������� �� ������ - ����������
{
public: 
	string place_of_departure; // ����� �������
	string arrival_point; // ����� ��������
	void add_bus() // ������� �����
	{
		add_autho();

		cout << "����� �������: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin,place_of_departure);
		cout << endl << "����� ��������: ";
		cin.clear();
		getline(cin,arrival_point);
		cout << endl;
		type = "�������";
	}

	template<class Archive>// ������� ������������
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

	void show_bus()// ������� ������
	{
		show_autho();
		cout << "����� �������: " << place_of_departure << endl;
		cout << "����� ��������: " << arrival_point << endl;
	}

	void change_bus()// ������� ���������
	{
		change_auto();
		cout << "8.����� �������" << endl;
		cout << "9.����� ��������" << endl;
	}
};

class Truck : public Autospectechnics // ����� - ��������, ����������� �� ������ - ���������������
{
public:
	string cargo_type; // ��� �����
	void add_truck() // ������� ����� 
	{
		add_spec();
		cout << "������� ��� �����: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, cargo_type);
		cout << endl;
		type = "��������";
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

	void show_truck()// ������� ������
	{
		show_spec();
		cout << "����������� ����: " << cargo_type << endl;
	}

	void change_truck()// ������� ��������� ������
	{
		change_spec();
		cout << "8.����������� ���� " << endl;
	}
};

class Concrete_Mixer_truck : public Autospectechnics // ����� - ����������������� ������, ����������� �� ������ - ���������������
{
public:
	string amount_of_concrete; // ����������� �������
	void add_mix() // ������� ����� 
	{
		add_spec();
		cout << "������� ����������� �������: ";
		cin >> amount_of_concrete;
		cout << endl;
		type = "�������������";
	}

	template<class Archive> // ������� ������������
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
	void show_mix() // ������� ������
	{
		show_spec();
		cout << "����� �������: " << amount_of_concrete << endl;
	}
	void change_mix() // ������� ��������� ������
	{
		change_spec(); 
		cout << "8.����� �������" << endl;
	}
};

class Serialize // ����� ��� ������������ ������
{
public:

	int constant = 0;

	friend class boost::serialization::access; // ��� ������ � boost
	Concrete_Mixer_truck mixer; // ������ - �������������
	Truck truck; // ������ - ��������
	Bus bus; // ������ - �������
	Automobile autho; // ������ - ����������
	string Typ; // ������ - ���������

	template<class Archive> // ��������� ������� ��� ������������ ������
	void serialize(Archive& ar, const unsigned int version)
	{
		if (Typ == "����������" || autho.type == "����������")
		{
			ar& BOOST_SERIALIZATION_NVP(autho);
			constant = 1;
		}
		else if (Typ == "�������" || bus.type == "�������")
		{
			ar& BOOST_SERIALIZATION_NVP(bus);
			constant = 2;
		}
		else if (Typ == "��������" || truck.type == "��������")
		{
			ar& BOOST_SERIALIZATION_NVP(truck);
			constant = 3;
		}
		else if (Typ == "�������������" || mixer.type == "�������������")
		{
			ar& BOOST_SERIALIZATION_NVP(mixer);
			constant = 4;
		}
	}

	void menu_add() // ������� ���� ��� ����������� ����� ������
	{
		char m = 0;
		while (m != '5')
		{
			cout << "\t����� ��� ������ � ����� ������������:" << endl;
			cout << "1. ����������" << endl;
			cout << "2. �������" << endl;
			cout << "3. ��������" << endl;
			cout << "4. ����������������� ������" << endl;
			cout << "5. ���������" << endl;
			cin >> m;

			if (m == '1')
			{
				autho.add_autho(); // ����� ������� ���������� ������ �� ����������
				constant = 1;
				Typ = autho.type;
				break;
			}
			if (m == '2')
			{
				bus.add_bus(); // ����� ������� ���������� ������ �� ��������
				constant = 2;
				Typ = bus.type;
				break;
			}
			if (m == '3')
			{
				truck.add_truck(); // ����� ������� ���������� ������ �� ���������
				constant = 3;
				Typ = truck.type;
				break;
			}
			if (m == '4')
			{
				mixer.add_mix(); // ����� ������� ���������� ������ �� �������������
				constant = 4;
				Typ = mixer.type;
				break;
			}
		}
	}

	void menu_change() // ������� �������������� ������
	{
		int x;
		if (Typ == "")
		{
			cout << "��� ����� ����" << endl;
			return;
		}
		else if (Typ == "����������") // ��� ������ - ����������
		{
			autho.change_auto(); // ����� ������� ��������� ������ ����������
			cin >> x;
			cout << "�������: ";
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
		else if (Typ == "��������")
		{
			truck.change_truck(); // ����� ������� ��������� ������ ���������
			cin >> x;
			cout << "�������: ";
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
		else if (Typ == "�������")
		{
			bus.change_bus();// ����� ������� ��������� ������ ��������
			cin >> x;
			cout << "�������: ";
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
		else if (Typ == "�������������")
		{
			mixer.change_mix();// ����� ������� ��������� ������ �������������
			cin >> x;
			cout << "�������: ";
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

	void show() // ������� ������ ������
	{
		if (constant == 0)
		{
			cout << "������ ���" << endl;
		}
		else if (constant == 1)
		{
			autho.show_autho(); // ����� ������ ����������
		}
		else if (constant == 2)
		{
			bus.show_bus(); // ����� ������ ��������
		}
		else if (constant == 3)
		{
			truck.show_truck(); // ����� ������ ���������
		}
		else if (constant == 4)
		{
			mixer.show_mix(); // ����� ������ ����������������� ������
		}
	}
};

class serT // ����� ��� ������������ ��������� ������
{
public:
	string Type;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(Type);
	}
};

// ��������� ������� ������������

template<typename T> //���������� ���������(����) ������
void save_type(T data) {
	ofstream fout("saveT.xml");
	boost::archive::xml_oarchive oa(fout);
	oa << BOOST_SERIALIZATION_NVP(data);
}

template<typename T> // �������� ���������(����) ������
void load_type(T& data) {
	ifstream fin("saveT.xml");
	boost::archive::xml_iarchive ia(fin);
	ia& BOOST_SERIALIZATION_NVP(data);
}

template<typename T>  //���������� ������
void save(T data) {
	ofstream fout("save.xml");
	boost::archive::xml_oarchive oa(fout);
	oa << BOOST_SERIALIZATION_NVP(data);
	cout << "������� ���������!" << endl;
}

template<typename T>  // �������� ������
void load(T& data) {
	ifstream fin("save.xml");
	boost::archive::xml_iarchive ia(fin);
	ia& BOOST_SERIALIZATION_NVP(data);
	cout << "������� ���������!" << endl;
}


int main()
{
	vector <pair<pair<string, string>, string>> vec;
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Serialize _xml; // �������� ������� ������ ��� ������������
	serT typ; // �������� ������� ��������� ������ ��� ������������

	char k = 0;

	while (k != '6')
	{
		cout << "\t�����" << endl;
		cout << "1. ���������� ������" << endl;
		cout << "2. ��������� ������" << endl;
		cout << "3. ��������� ������" << endl;
		cout << "4. �������� ������" << endl;
		cout << "5. ������������� ������" << endl;
		cout << "6. ����� �� ������" << endl;

		cin >> k;

		if (k == '1')
		{
			_xml.show(); // ����� ������� ������ ������ �� �����
		}
		else if (k == '2')
		{
			load_type(typ); // ����� ��������� ������� �������� ��������� ������
			_xml.Typ = typ.Type;
			load(_xml); // ����� ��������� ������� �������� ������
		}
		else if (k == '3')
		{
			typ.Type = _xml.Typ; // ����� ��������� ������� ���������� ��������� ������
			save_type(typ);
			save(_xml);// ����� ��������� ������� ���������� ������
		}
		else if (k == '4')
		{
			_xml.menu_add(); // ����� ������� ���� ��� ���������� ����� ������
		}
		else if (k == '5')
		{
			_xml.menu_change(); // ����� ������� ���� ��� �������������� ������
		}
	}
	
}