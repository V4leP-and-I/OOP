#include<iostream>
#include<string>
#include<fstream>

using namespace std;

static string loc = "C:\\Users\\�������\\Desktop\\���� �����\\���\\7 ����\\Project1\\Project1\\x64\\Debug\\doc.txt"; //���� ������������ ���� ��� ������/������
fstream fs;

class EventSave {//����� ��� ������/������ ������� �� �����
protected:
	void EventAdd(string s) { //���������� ������ �������
		fs.open(loc, fstream::in | fstream::app);
		fs << s;
		fs.close();
	}
public:
	static void EventOut() {//����� ���� �������
		fs.open(loc, fstream::out | fstream::in | fstream::app);
		string s = "";
		while (!fs.eof()) {
			s = "";
			getline(fs, s);
			cout << s << '\n';
		}
		fs.close();
	}

	static void Draw() {//����������� ������� "�����"
		string s = "����� �������, ���� ��������� ������\n";
		cout << s;
		fs.open(loc, fstream::in | fstream::app);
		fs << s;
		fs.close();
	}

	static void EventClear() {//������� ������� ������� (������� �����)
		fstream clear_file(loc, ios::out);
		clear_file.close();
	}
};

class EventCall : EventSave {//������������� ����� � ���������� ��������� ��������� ����� � ����������� ����������
protected:
	void Win(string s) {//����������� ����������, ����� ��������� � ��� ������ � ����
		string win = "������ ������� " + s + " �����!\n";
		cout << win;
		EventAdd(win);
	}

	void Damage(string s, int damage) {//����������� �����, ����� ��������� � ��� ������ � ����
		string ss;
		if (s == "�������")
			ss = "��������";
		else
			ss = "��������";
		s += " ����� ���� " + to_string(damage) + " ����� " + ss + " ������!\n";
		cout << s;
		EventAdd(s);
	}

};

class Player : EventCall { //�����
private:
	int hitPoints; //����� ������
	string name; //��� ������ (�����/�������)
public:
	const string redName = "�������"; //����� �� ���������, public ��� ������� � ������ RoomGame
	const string blueName = "�����"; //const, ����� ������ ���� �������� � ������ �����

	Player() {
		hitPoints = 100;
		name = "noname";
	}

	Player(const Player& A) {//����������� �����������
		this->name = A.name;
		this->hitPoints = A.hitPoints;
	}

	bool Attac(Player& A) {//������� �����, ����������� ���� (�� ������ 50), �������� �����, ���������� ������� � ������� ���
		int attac = rand() % 50; //bool ��� ����, ����� ����������, ����������� ������ ���-�� ������� ��� �� ���
		A.hitPoints -= attac;
		Damage(A.name, attac);
		if (A.hitPoints <= 0)//�������� �� ����������, ����� ����� ������ �� ������� �������������
		{
			string ss;
			if (A.name == redName)
				ss = redName;
			else
				ss = blueName;
			Win(ss);
			return true;
		}
		return false;
	}

	void NewHP() {//����������� ����� �� 100
		hitPoints = 100;
	}

	void Name(const string& s) {//���������� ����� (�� ���������)
		this->name = s;
	}

	Player& operator=(const Player& right) {
		this->hitPoints = hitPoints;
		this->name = name;
		return *this;
	}

};

class RoomGame {//������� � 2 ��������
public:
	RoomGame(Player& red, Player& blue) { //����������� �� ���������, ������������� ���������� ������ �������, ����������� ����� �� ��������� � ������� ��������� � ������ ����
		this->red = &red;
		this->blue = &blue;
		red.Name(red.redName);
		blue.Name(blue.blueName);
		cout << "!!!���� ��������!!!\n";
	}

	void NewGame() {//������ ����� ����
		this->red->NewHP();
		this->blue->NewHP();
		system("cls");
	}

private:
	Player* red;
	Player* blue;
};


int main() {
	setlocale(LC_ALL, "ru");
	Player one, two;
	RoomGame forest(one, two);
	while (true) {//���� ��� ���������� ���
		forest.NewGame();//����������� �����, ���� ���� �������� ������

		for (int i = 0; i < 100; i++) {
			if (one.Attac(two)) break;;
			if (two.Attac(one)) break;
			if (i == 100) {//���� ���� ������ ������ 100 ������� �������, �� �����
				EventSave::Draw;
				break;
			}
		}

		cout << "���� ������ ���������� ������ ������� - ������� 2, ���� �� ������ - ����� ������ ������:\n";
		string bb;
		cin >> bb;
		bool a = true;
		if (bb != "2")
			a = false;

		if (a)
		{
			EventSave::EventOut();//����� ���������� � ����� �������
		}

		bool flag = false;

		cout << "���� ������ ���������� ���� - ������� 1, ���� ������ ��������� ���� - ������� ����� ������:\n";
		cin >> bb;
		if (bb != "1") {
			flag = true;

			cout << "���� ������ �������� ������� � ����� - ������� 1, ���� ������ ��������� ���� � ��������� ������� - ������� ����� ������:\n";
			cin >> bb;
			if (bb == "1") {
				EventSave::EventClear();
			}
		}

		if (flag) break;
	}
}