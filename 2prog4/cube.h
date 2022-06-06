#pragma once
class Rubiks;
//FRONT = 1
//LEFT = 4
//BACK = 3
//RIGHT = 2
//TOP = 0
//BOTTOM = 5


//white - 0
//red - 1
//blue - 2
//orange - 3
//green - 4
//yellow - 5

	//ввод
	//while (1)
	//{
	//	string scramble, rotate = "";
	//	vector<string> input;
	//	getline(cin, scramble);
	//	for (int i = 0; i < scramble.size(); i++)
	//	{
	//		if (scramble[i] == ' ')
	//		{
	//			input.push_back(rotate);
	//			rotate = "";
	//			continue;
	//		}
	//		rotate += scramble[i];
	//	}
	//	input.push_back(rotate);
	//	Rubiks lala;
	//	lala.Scrambles(input);
	//	cout << lala;
	//	for (auto i : lala.faces)
	//	{
	//		cout << i.first << ' ' << colors[i.second]<<  "    ";
	//	}
	//	cout << endl;
	//}



//string scramble, rotate = "";
//vector<string> input;
//getline(cin, scramble);
//for (int i = 0; i < scramble.size(); i++)
//{
//	if (scramble[i] == ' ')
//	{
//		input.push_back(rotate);
//		rotate = "";
//		continue;
//	}
//	rotate += scramble[i];
//}
//input.push_back(rotate);
//Rubiks lala;
//lala.Scrambles(input);