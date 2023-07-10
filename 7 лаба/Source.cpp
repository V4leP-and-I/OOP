#include<iostream>
#include<string>
#include<fstream>

using namespace std;

static string loc = "C:\\Users\\Валерия\\Desktop\\ЛАБЫ ПРОГА\\ООП\\7 лаба\\Project1\\Project1\\x64\\Debug\\doc.txt"; //путь расположения файл для записи/чтения
fstream fs;

class EventSave {//класс для записи/чтения событий из файла
protected:
	void EventAdd(string s) { //добавление одного события
		fs.open(loc, fstream::in | fstream::app);
		fs << s;
		fs.close();
	}
public:
	static void EventOut() {//вывод всех событий
		fs.open(loc, fstream::out | fstream::in | fstream::app);
		string s = "";
		while (!fs.eof()) {
			s = "";
			getline(fs, s);
			cout << s << '\n';
		}
		fs.close();
	}

	static void Draw() {//добавлвения события "ничьи"
		string s = "Время истекло, игра завершена ничьей\n";
		cout << s;
		fs.open(loc, fstream::in | fstream::app);
		fs << s;
		fs.close();
	}

	static void EventClear() {//Очистка истории событий (очистка файла)
		fstream clear_file(loc, ios::out);
		clear_file.close();
	}
};

class EventCall : EventSave {//Промежуточный класс с требуемыми событиями нанесения урока и определения победителя
protected:
	void Win(string s) {//определения победителя, вывод сообщения и его запись в файл
		string win = "Победу одержал " + s + " игрок!\n";
		cout << win;
		EventAdd(win);
	}

	void Damage(string s, int damage) {//определение урона, вывод сообщения и его запись в файл
		string ss;
		if (s == "красный")
			ss = "голубому";
		else
			ss = "красному";
		s += " игрок нанёс " + to_string(damage) + " урона " + ss + " игроку!\n";
		cout << s;
		EventAdd(s);
	}

};

class Player : EventCall { //Игрок
private:
	int hitPoints; //жизнь игрока
	string name; //имя игрока (синий/красный)
public:
	const string redName = "красный"; //имена по умолчанию, public для доступа в классе RoomGame
	const string blueName = "синий"; //const, чтобы нельзя было поменять в другом месте

	Player() {
		hitPoints = 100;
		name = "noname";
	}

	Player(const Player& A) {//конструктор копирования
		this->name = A.name;
		this->hitPoints = A.hitPoints;
	}

	bool Attac(Player& A) {//функция атаки, расчитывает урон (не больше 50), отнимает жизнь, записывает событие и выводит его
		int attac = rand() % 50; //bool для того, чтобы определить, закончилась партия чей-то победой или же нет
		A.hitPoints -= attac;
		Damage(A.name, attac);
		if (A.hitPoints <= 0)//проверка на победителя, когда жизнь одного из игроков заканчивается
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

	void NewHP() {//восполнение жизни до 100
		hitPoints = 100;
	}

	void Name(const string& s) {//присвоение имени (по умолчанию)
		this->name = s;
	}

	Player& operator=(const Player& right) {
		this->hitPoints = hitPoints;
		this->name = name;
		return *this;
	}

};

class RoomGame {//комната с 2 игроками
public:
	RoomGame(Player& red, Player& blue) { //конструктор по умолчанию, присваивающий указателям данные объекты, присваивает имена по умолчанию и выводит сообщение о начале игры
		this->red = &red;
		this->blue = &blue;
		red.Name(red.redName);
		blue.Name(blue.blueName);
		cout << "!!!Игра началась!!!\n";
	}

	void NewGame() {//начало новой игры
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
	while (true) {//цикл для нескольких игр
		forest.NewGame();//восполнения жизни, если игра началась заново

		for (int i = 0; i < 100; i++) {
			if (one.Attac(two)) break;;
			if (two.Attac(one)) break;
			if (i == 100) {//если игра длится больше 100 событий каждого, то ничья
				EventSave::Draw;
				break;
			}
		}

		cout << "Если хотите посмотреть список событий - введите 2, если не хотите - любой другой символ:\n";
		string bb;
		cin >> bb;
		bool a = true;
		if (bb != "2")
			a = false;

		if (a)
		{
			EventSave::EventOut();//вывод записанных в файле событий
		}

		bool flag = false;

		cout << "Если хотите продолжить игру - введите 1, если хотите завершить игру - введите любой символ:\n";
		cin >> bb;
		if (bb != "1") {
			flag = true;

			cout << "Если хотите очистить историю и выйти - введите 1, если хотите завершить игру и сохранить историю - введите любой символ:\n";
			cin >> bb;
			if (bb == "1") {
				EventSave::EventClear();
			}
		}

		if (flag) break;
	}
}