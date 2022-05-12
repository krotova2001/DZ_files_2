#include <iostream>
#include <fstream>
using namespace std;
char g[5] { 'a', 'e', 'o', 'u', 'i'}; // массив с гласными для сравнения

int main()
{
	ifstream Source; // создадим объект для чтения исходного файла
	ofstream Result; // объект для вывода результатов
	unsigned int symbols = 0, strs=1, glas=0, soglas=0, nums = 0; // Ряд переменных для хранения и записи информации с файл с результатом

	Source.open("c:\\1\\11.txt"); //откроем файл - источник
	if (Source.is_open()) // если удалось открыть исходный файл, то...
	{
		while (!Source.eof()) // идем до конца файла
		{
			char temp; // хранение считываемого символа
			Source.get(temp); // считываем по символу и считаем...
			symbols++; // колчество всех символов
			if (int(temp) < 40&&int(temp)>29) nums++; // если код символа находится среди цифр, то это цифра
			for (int i = 0; i < 5; i++) // идем по массиву с гласными
			{
				if ((temp >= 'A' && temp <= 'z') && (temp = g[i])) glas++; // если символ среди букв, и среди массива - то гласная
				else soglas++; // иначе согласная
			}
			if (temp == '\n') strs++;
		}
		Source.close();
	}
	else
	{
		cout << "Can not  open file c:\\1\\11.txt";
	}
	
	// теперь запишем результаты в файл

	Result.open("c:\\1\\results.txt", ios::out ); // откроем файл на запись и запишем
	if (Result.is_open())
	{
		Result << "Symbols - " << symbols;
		Result << "\nNums - " << nums;
		Result << "\nGlas - " << glas;
		Result << "\nSoglas - " << soglas;
		Result << "\nStrings - " << strs;
		Result.close();
	}
	else
	{
		cout << "Can not write c:\\1\\results.txt";
	}

}
