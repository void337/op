#include "Header.h"
#include <iostream>
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите количество памяти в ОП\n";
	int n;
	cin >> n;
	while (!cin || cin.peek() != '\n' || n <= 0)
	{
		clean();
		cout << "Память в ОП больше нуля\n"; cin >> n;
	}
	RAM RAM1(4096);
	int choise;
	while (true) {
		cout << "Выберите действие\n1 - Добавить процесс\n2 - Освободить процесс\n3 - Информация об оперативной памяти\n4 - Информация о процессе\n5 - Выйти из программы\n";
		cin >> choise;
		while (!cin || cin.peek() != '\n')
		{
			clean();
			cout << "Выберите действие\n1 - Добавить процесс\n2 - Освободить процесс\n3 - Информация об оперативной памяти\n4 - Информация о процессе\n5 - Выйти из программы\n";
			cin >> choise;
		}
		switch (choise)
		{
		case 1:
			RAM1.add();
			break;
		case 2:
			RAM1.del();
			break;
		case 3:
			RAM1.info_ram();
			break;
		case 4:
			RAM1.info_process();
			break;
		case 5:
			cout << "Хорошего Вам дня :)\n";
			return 0;
		default:
			cout << "Напишите одно из чисел, чтобы выбрать действие\n";
			break;
		}
	}
}