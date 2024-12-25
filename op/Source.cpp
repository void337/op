#include "Header.h"

void clean() {
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "Error!" << endl;
}

void RAM::add()
{
	string n; int b;
	bool f = false;
	cout << "������� �������� ��������\n"; cin.get(); getline(cin, n);
	while (n == "" || n.find_first_not_of(' ') == string::npos) {
		cout << "������� �������� ��������\n"; cin.get(); getline(cin, n);
	}
	cout << "������� ���������� ���������� ������ ��������� (�������������� ����� > 0)\n"; cin >> b;
	while (!cin || cin.peek() != '\n' || b <= 0)
	{
		clean();
		cout << "������� ���������� ���������� ������ ��������� (�������������� ����� > 0)\n"; cin >> b;
	}
	for (int i = 0; i < massive.size(); i++) {
		Block bl = massive[i];
		if (bl.f == 0 && bl.bytes >= b) {
			Process P; P.bytes_process = b;
			P.name = n; P.addr = bl.addr; P.bytes_block = bl.bytes;
			bl.f = 1; bl.bytes = b; bl.Pr = P;
			Block bl2;
			bl2.addr = bl.addr + b; bl2.bytes = P.bytes_block - b;
			bl2.f = 0; bl2.ptr = bl.ptr;
			bl.ptr = bl2.addr;
			massive[i] = bl;
			if (bl2.bytes != 0)
				massive.insert(massive.begin() + i + 1, bl2);
			cout << "������� ������� ��������\n";
			f = true;
			break;
		}
	}
	if (!f) cout << "��� ���������� ����� � ����������� ������ :(\n���������� ���������� � ���������� ��������� � �������� ���� �� ���������...\n";
}

void RAM::del()
{
	cout << "������� ������ ��������, ������� �� ������ �������\n";
	int n; cin >> n;
	while (!cin || cin.peek() != '\n' || n < 0)
	{
		clean();
		cout << "������ - �������������� �����.\n"; cin >> n;
	}
	bool flag = false;
	bool fl = false;
	Process A;
	for (int i = 0; i < massive.size(); i++) {
		Block block = massive[i];
		if (block.addr == n && block.f == 1) {
			block.f = 0; block.Pr = A;
			cout << "������ ������� ������� �� ��������\n";
			flag = true;
			massive[i] = block;
			int j = i + 1;
			if (massive.size() != 1) {
				if (i != 0) {
					if (massive[i - 1].f == 0) {
						massive[i - 1].bytes += block.bytes;
						massive[i - 1].ptr = block.ptr;
						massive.erase(massive.begin() + i);
						j = i;
					}
				}
				if (i != massive.size()) {
					if (massive[j].f == 0) {
						massive[j - 1].bytes += massive[j].bytes;
						massive[j - 1].ptr = massive[j].ptr;
						massive.erase(massive.begin() + j);

					}
				}
			}
				break;
		}
	}
		if (!flag) cout << "������ �������� �� ����������.\n";	
}

void RAM::info_ram()
{
	cout << "***���������� �� ����������� ������***\n";
	cout << "����� | " << left << setw(3) << "��������� ����� | " << setw(3) << "�������� �������� |" << setw(3) << " ������ � ����� |" << setw(3) << " ����� ����� |" << setw(3) << " ��������� �� ��������� ���� " << endl;
	for (int i = 0; i < massive.size(); i++) {
		Block block = massive[i];
		cout << setw(8) << i + 1;
		(block.f == 0) ? cout << setw(40) << "���� �� �����" << setw(20) : cout << setw(20) << "���� �����" << setw(20) << block.Pr.name << setw(20);
		cout << block.bytes;
		cout << setw(15) << block.addr << setw(10);
		if (i + 1 != massive.size()) cout << setw(20) << block.ptr << setw(3);
		cout << "\n---------------------------------------------------------------------------------------------------------\n";
	}
}

void RAM::info_process()
{
	cout << "������� �������� ��������\n";
	string n;  cin.get();  getline(cin, n); int c = 0;
	for (Block block : massive) {
		if (block.Pr.name == n) {
			c++;
			cout << c << ". ���������� � ��������\n";
			cout << "�������� ��������: " << block.Pr.name << endl;
			cout << "������ ��������: " << block.Pr.bytes_process << endl;
			cout << "����������� ������ �����: " << block.Pr.bytes_block << endl;
			cout << "����� ��������: " << block.Pr.addr << endl << endl;
		}
	}
	if (c == 0) cout << "������� � ����� ������ �� ������\n";
}

RAM::RAM(int n)
{
	Block B1;
	B1.addr = 0; B1.bytes = n;
	B1.f = 0; B1.ptr = 0;
	massive.push_back(B1);
}