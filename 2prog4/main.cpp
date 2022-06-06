#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
char colors[] = { 'w', 'g', 'r', 'b', 'o', 'y' };
//кубик рубика
class Rubiks {
public:
	Rubiks()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				edges[i][j] = i;
			}
		}
	}
	Rubiks(vector<vector<int>>& cube2)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				edges[i][j] = cube2[i][j];
			}
		}
	}
	Rubiks(Rubiks const& other )
		:stick(other.stick), history(other.history), faces(other.faces)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				edges[i][j] = other.edges[i][j];
			}
		}
	}
	~Rubiks() = default;
	Rubiks& operator =(Rubiks const& other)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				edges[i][j] = other.edges[i][j];
			}
		}
		faces = other.faces;
		stick = other.stick;
		history = other.history;
		return *this;
	}
	bool operator <(Rubiks const& other) const
	{
		return stick < other.stick;
	}
	//подсчет неправильных стиков
	void Check()
	{
		stick = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (edges[i][j] != edges[i][4])
				{
					stick++;
				}
			}
		}
	}
	void Clear_History()
	{
		history = {};
	}
	//поворот граней
	void Clockwise(int color)
	{
		int num = int(color);
		int support[9], x = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 6; j >= i; j -= 3)
			{
				support[x] = edges[num][j];
				x++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			edges[num][i] = support[i];
		}
		vector<int> lala;
		switch (num)
		{
		case 0:
			lala = { 8, 5, 2, 6, 7, 8, 0, 3, 6, 2, 1, 0 };
			break;
		case 1:
			lala = { 6, 7, 8, 6, 7, 8, 6, 7, 8, 2, 1, 0 };
			break;
		case 2:
			lala = { 8, 5, 2, 8, 5, 2, 8, 5, 2, 8, 5, 2 };
			break;
		case 3:
			lala = { 2, 1, 0, 6, 7, 8, 2, 1, 0, 2, 1, 0 };
			break;
		case 4:
			lala = { 0, 3, 6, 0, 3, 6, 0, 3, 6, 0, 3, 6 };
			break;
		case 5:
			lala = { 0, 3, 6, 6, 7, 8, 8, 5, 2, 2, 1, 0 };
		}
		for (int i = 0; i < 3; i++)
		{
			support[i] = edges[adjacent[num][3]][lala[9 + i]];
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int val = edges[adjacent[num][i]][lala[i * 3 + j]];
				edges[adjacent[num][i]][lala[i * 3 + j]] = support[j];
				support[j] = val;
			}
		}
	}

	void Clockwise(string face)
	{
		Clockwise(faces[face]);
	}
	void Counterclockwise(string face)
	{
		for (int i = 0; i < 3; i++)
		{
			Clockwise(faces[face]);
		}
	}
	void Clockwise2(string face)
	{
		for (int i = 0; i < 2; i++)
		{
			Clockwise(faces[face]);
		}
	}
	//вращения куба
	void Rotate_x()
	{
		string support[] = { "FRONT", "UP", "BACK", "DOWN" };
		int val = faces["DOWN"];
		for (auto i : support)
		{
			int val2 = faces[i];
			faces[i] = val;
			val = val2;
		}
	}
	void Rotate_y()
	{
		string support[] = { "FRONT", "LEFT", "BACK", "RIGHT" };
		int val = faces["RIGHT"];
		for (auto i : support)
		{
			int val2 = faces[i];
			faces[i] = val;
			val = val2;
		}
	}
	void Rotate_z()
	{
		string support[] = { "UP", "RIGHT", "DOWN", "LEFT" };
		int val = faces["LEFT"];
		for (auto i : support)
		{
			int val2 = faces[i];
			faces[i] = val;
			val = val2;
		}
	}
	//основа
	void Main_Rotate(string rotate)
	{
		history.push_back(rotate);
		//по часовой
		if (rotate == "F")
		{
			Clockwise("FRONT");
		}
		if (rotate == "B")
		{
			Clockwise("BACK");
		}
		if (rotate == "R")
		{
			Clockwise("RIGHT");
		}
		if (rotate == "L")
		{
			Clockwise("LEFT");

		}
		if (rotate == "U")
		{
			Clockwise("UP");
		}
		if (rotate == "D")
		{
			Clockwise("DOWN");
		}
		//против часовой
		if (rotate == "F'")
		{
			Counterclockwise("FRONT");
		}
		if (rotate == "B'")
		{
			Counterclockwise("BACK");
		}
		if (rotate == "R'")
		{
			Counterclockwise("RIGHT");
		}
		if (rotate == "L'")
		{
			Counterclockwise("LEFT");

		}
		if (rotate == "U'")
		{
			Counterclockwise("UP");
		}
		if (rotate == "D'")
		{
			Counterclockwise("DOWN");
		}
		//поворот по часовой 2 раза
		if (rotate == "F2")
		{
			Clockwise2("FRONT");
		}
		if (rotate == "B2")
		{
			Clockwise2("BACK");
		}
		if (rotate == "R2")
		{
			Clockwise2("RIGHT");
		}
		if (rotate == "L2")
		{
			Clockwise2("LEFT");

		}
		if (rotate == "U2")
		{
			Clockwise2("UP");
		}
		if (rotate == "D2")
		{
			Clockwise2("DOWN");
		}
		if (rotate == "M")
		{
			Clockwise("RIGHT");
			Counterclockwise("LEFT");
			for (int i = 0; i < 3; i++)
			{
				Rotate_x();
			}
		}
		if (rotate == "M'")
		{
			Counterclockwise("RIGHT");
			Clockwise("LEFT");
			Rotate_x();
		}
		Check();
	}
	void Axis_Rotate(string axis)
	{
		history.push_back(axis);
		if (axis == "x")
		{
			Rotate_x();
		}
		if (axis == "y")
		{
			Rotate_y();
		}
		if (axis == "z")
		{
			Rotate_z();
		}

		if (axis == "x'")
		{
			for (int i = 0; i < 3; i++)
			{
				Rotate_x();
			}
		}
		if (axis == "y'")
		{
			for (int i = 0; i < 3; i++)
			{
				Rotate_y();
			}
		}
		if (axis == "z'")
		{
			for (int i = 0; i < 3; i++)
			{
				Rotate_z();
			}
		}

		if (axis == "x2")
		{
			for (int i = 0; i < 2; i++)
			{
				Rotate_x();
			}
		}
		if (axis == "y2")
		{
			for (int i = 0; i < 2; i++)
			{
				Rotate_y();
			}
		}
		if (axis == "z2")
		{
			for (int i = 0; i < 2; i++)
			{
				Rotate_z();
			}
		}
		Check();
	}
	void Scrambles(vector<string> scramble)
	{
		for (auto i : scramble)
		{
			if (i[0] == 'z' || i[0] == 'y' || i[0] == 'x')
			{
				Axis_Rotate(i);
			}
			else
			{
				Main_Rotate(i);
			}
		}
	}

	friend ostream& operator <<(ostream& os, Rubiks const& other);
	friend class genetic_algorithm;
	friend void input(string file, Rubiks& cube);
	friend void output(string file, Rubiks const& cube);
	vector<string> history = {};
//private:
	map<string, int> faces = { {"FRONT", 1 }, {"LEFT", 4 }, {"BACK", 3 }, {"RIGHT", 2 }, {"UP", 0 }, {"DOWN", 5 } };
	int adjacent[6][4] = { {4, 3, 2, 1}, {4, 0, 2, 5}, {0, 3, 5, 1}, {4, 5, 2, 0}, {5, 3, 0, 1}, {4, 1, 2, 3} };
	int edges[6][9];
	int stick = 0;
};
ostream& operator <<(ostream& os, Rubiks const& cube)
{
	int queue[] = { 4, 0, 2 };
	for (int i = 0; i < 3; i++)
	{
		cout << "      ";
		for (int j = 0; j < 3; j++)
		{
			cout << colors[cube.edges[3][i * 3 + j]] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << colors[cube.edges[queue[j / 3]][i * 3 + j % 3]] << " ";
		}
		cout << endl;
	}
	for (int z = 0; z < 2; z++)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "      ";
			for (int j = 0; j < 3; j++)
			{
				cout << colors[cube.edges[z * 4 + 1][i * 3 + j]] << " ";
			}
			cout << endl;
		}
	}
	return os;
}
//алгоритм
class genetic_algorithm {
public:
	genetic_algorithm(Rubiks& cube)
		:cube(cube)
	{}
	//генетический алгоритм
	void algorithm()
	{
		cout << "поиск решения" << endl;
		//перезапуск
		for (int z = 0; z < 10; z++)
		{
			vector<Rubiks> cubes;
			cubes.push_back(cube);
			//создание популяции
			for (int i = 1; i < 500; i++)
			{
				Rubiks support(cube);
				support.Main_Rotate(move[rand() % move.size()]);
				support.Main_Rotate(move[rand() % move.size()]);
				cubes.push_back(support);
			}
			//смена поколения
			for (int i = 0; i < 300; i++)
			{
				if ((i + 1) % 100 == 0)
				{
					cout << "прошло перезапусков = " << z << ". прошло поколений = " << i + 1 << endl;
				}
				sort(cubes.begin(), cubes.end());
				if (cubes[0].stick == 0)
				{
					cube = cubes[0];
					cout << "Решение найдено. прошло перезапусков = " << z << ". прошло поколений = " << i << endl;
					return;
				}
				for (int j = 0; j < 500; j++)
				{
					if (j >= 50)
					{
						int type = rand() % 6;
						cubes[j] = cubes[rand() % 50];
						if (type == 0)
						{
							cubes[j].Scrambles(permutations[rand() % permutations.size()]);
						}
						if (type == 1)
						{
							cubes[j].Scrambles(permutations[rand() % permutations.size()]);
							cubes[j].Scrambles(permutations[rand() % permutations.size()]);
						}
						if (type == 2)
						{
							cubes[j].Axis_Rotate(axis_xy[rand() % axis_xy.size()]);
							cubes[j].Scrambles(permutations[rand() % permutations.size()]);
						}
						if (type == 3)
						{
							cubes[j].Axis_Rotate(axis_z[rand() % axis_z.size()]);
							cubes[j].Scrambles(permutations[rand() % permutations.size()]);
						}
						if (type == 4)
						{
							cubes[j].Axis_Rotate(axis_xy[rand() % axis_xy.size()]);
							cubes[j].Axis_Rotate(axis_z[rand() % axis_z.size()]);
							cubes[j].Scrambles(permutations[rand() % permutations.size()]);
						}
						if (type == 5)
						{
							cubes[j].Axis_Rotate(axis_z[rand() % axis_z.size()]);
							cubes[j].Axis_Rotate(axis_xy[rand() % axis_xy.size()]);
							cubes[j].Scrambles(permutations[rand() % permutations.size()]);
						}
					}
				}
			}
		}
		cout << "не" << endl;
	}
	//основные скрамблы
	vector<vector<string>> permutations = {
		{"F'", "L'", "B'", "R'", "U'", "R", "U'", "B", "L", "F", "R", "U", "R'", "U"},
		{"F", "R", "B", "L", "U", "L'", "U", "B'", "R'", "F'", "L'", "U'", "L", "U'"},
		{"U", "U", "B", "U", "U", "B'", "R", "R", "F", "R'", "F'", "U", "U", "F'", "U", "U", "F", "R'"},
		{"U", "U", "R", "U", "U", "R'", "F", "F", "L", "F'", "L'", "U", "U", "L'", "U", "U", "L", "F'"},
		{"U'", "B", "B", "D", "D", "L'", "F", "F", "D", "D", "B", "B", "R'", "U'"},
		{"U", "B", "B", "D", "D", "R", "F", "F", "D", "D", "B", "B", "L", "U"},
		{"D'", "R'", "D", "R", "R", "U'", "R", "B", "B", "L", "U'", "L'", "B", "B", "U", "R", "R"},
		{"D", "L", "D'", "L", "L", "U", "L'", "B", "B", "R'", "U", "R", "B", "B", "U'", "L", "L"},
		{"R'", "U", "L'", "U", "U", "R", "U'", "L", "R'", "U", "L'", "U", "U", "R", "U'", "L", "U'"},
		{"L", "U'", "R", "U", "U", "L'", "U", "R'", "L", "U'", "R", "U", "U", "L'", "U", "R'", "U"},
		{"F'", "U", "B", "U'", "F", "U", "B'", "U'"},
		{"F", "U'", "B'", "U", "F'", "U'", "B", "U"},
		{"L'", "U", "U", "L", "R'", "F", "F", "R"},
		{"R'", "U", "U", "R", "L'", "B", "B", "L"},
		{"M", "M", "U", "M", "M", "U", "U", "M", "M", "U", "M", "M"}
	};
	//повороты
	vector<string> move{ "F", "F'", "R", "R'", "L", "L'", "B", "B'", "U", "U'", "D", "D'" };
	//повороты по осям
	vector<string> axis_xy{ "x", "x'", "y", "y'"};
	vector<string> axis_z{ "z", "z'"};
	//начальный кубик
	Rubiks cube;
};
//рандом
void Random_Cube(Rubiks& cube)
{
	vector<string> move{ "F", "F'", "R", "R'", "L", "L'", "B", "B'", "U", "U'", "D", "D'" };
	for (int i = 0; i < 20; i++)
	{
		cube.Main_Rotate(move[rand() % move.size()]);
	}
}
//ввод из файла
void input(string file, Rubiks& cube)
{
	ifstream fin(file);
	int x;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fin >> x;
			cube.edges[i][j] = x;
		}
	}
	fin.close();
}
//вывод в файл
void outnput(string file, Rubiks const& cube)
{
	ofstream fin(file);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fin << cube.edges[i][j];
		}
	}
	fin.close();
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//ввод кубика
	string scramble, rotate = "";
	vector<string> input;
	getline(cin, scramble);
	for (int i = 0; i < scramble.size(); i++)
	{
		if (scramble[i] == ' ')
		{
			input.push_back(rotate);
			rotate = "";
			continue;
		}
		rotate += scramble[i];
	}
	input.push_back(rotate);
	Rubiks cube;
	cube.Scrambles(input);
	//Random_Cube(cube);
	cout << cube << endl;
	//нахождение решения кубика
	genetic_algorithm solve(cube);
	solve.algorithm();
	cout << solve.cube;
	for (auto i : solve.cube.history)
	{
		cout << i << " ";
	}
	return 0;
}