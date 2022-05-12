#include <iostream>
#include <fstream>
using namespace std;
char g[10]{ 'a', 'e', 'o', 'u', 'i', 'A', 'O', 'U','I','E'}; // массив с гласными для сравнения

int main()
{
	ifstream Source; // создадим объект для чтения исходного файла
	ofstream Result; // объект для вывода результатов
	unsigned int symbols = 0, strs=0, glas=0, soglas=0, nums = 0; // Ряд переменных для хранения и записи информации с файл с результатом

	Source.open("c:\\1\\11.txt"); //откроем файл - источник
	if (Source.is_open()) // если удалось открыть исходный файл, то...
	{
		while (!Source.eof()) // идем до конца файла
		{
			char temp; // хранение считываемого символа
			Source.get(temp); // считываем по символу и считаем...
			symbols++; // колчество всех символов
			if (int(temp) < 58&&int(temp)>47) nums++; // если код символа находится среди цифр, то это цифра
			if ((int(temp) >= 65 && int(temp) <= 90) || (int(temp) >= 97 && int(temp) <= 122)) // составное условие "если символ нахожится среди букв"
			{
				for (int i = 0; i < 10; i++) // идем по массиву с гласными
				{
					if (temp == g[i]) glas++; // если среди букв, и среди массива - то гласная
					
				}
			soglas++; // иначе согласная
			}
			if (temp == '\n') strs++; // колмчесвир символов новой строки - количество строк
		}
		Source.close(); // закрываем
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
