//#define CURL_STATICLIB
//#include<iostream>
//#include<curl/curl.h>
//#include<nlohmann/json.hpp>
//#include<string>
//int const VAR = 1;
//using namespace std;
//using json = nlohmann::json;
//size_t write(void* data, size_t size, size_t nmemb, void* buffer)
//{
//	size_t res = 0;
//	if (buffer != NULL)
//	{
//		((std::string*)buffer)->append((char*)data, 0, size * nmemb);
//		res = size * nmemb;
//	}
//	return res;
//}
//json get()
//{
//	std::string result;
//	CURL* curl;
//	curl = curl_easy_init();
//	if (curl)
//	{
//		curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
//		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
//		curl_easy_perform(curl);
//		curl_easy_cleanup(curl);
//	}
//	json j_complete = json::parse(result);
//	return j_complete;
//}
//class lala {
//public:
//	lala()
//	{
//		json js = get();
//		int i = 0;
//		for (auto el : js["Valute"])
//		{
//			val[i] = double(int(double(el["Value"]) * 100)) / 100;
//			average[i] = el["Value"];
//			num[i] = 0;
//			for (int j = 0; j < 100 * 2 * VAR; j++)
//			{
//				med[i][j] = 0;
//			}
//			i++;
//		}
//	}
//	void period()
//	{
//		json js = get();
//		int i = 0;
//		for (auto el : js["Valute"])
//		{
//			average[i] = (average[i] * num[i] + double(el["Value"])) / (num[i] + 1);
//			med[i][int((val[i] - double(el["Value"]) + VAR) * 100)] ++;
//			num[i]++;
//			i++;
//		}
//	}
//	void print()
//	{
//		cout << "average and median value" << endl;
//		json js = get();
//		int i = 0;
//		for (auto el : js["Valute"])
//		{
//			cout << el["CharCode"] << ": " << average[i] << " ";
//			int per = 0;
//			for (int j = 0; j < 100 * 2 * VAR; j++)
//			{
//				per += med[i][j];
//				if (per >= num[i] / 2 + num[i] % 2)
//				{
//					cout << double(j) / 100 - VAR + val[i] << endl;
//					break;
//				}
//			}
//			i++;
//		}
//	}
//private:
//	double val[100];
//	int med[100][100 * 2 * VAR];
//	double average[100];
//	int num[100];
//};
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	struct lala* per = new lala();
//	int a;
//	while (true)
//	{
//		json j_complete = get();
//		for (auto el : j_complete["Valute"])
//		{
//			cout << el["CharCode"] << ": " << el["Value"] << endl;
//		}
//		per->period();
//		cout << endl;
//		Sleep(3000);
//	}
//	per->print();
//	return 0;
//}