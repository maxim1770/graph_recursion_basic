#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

const int n = 6;
int matrix[n][n] =
{
	0,0,1,1,0,1,
	0,0,1,1,1,0,
	1,1,0,0,0,0,
	1,1,0,0,1,0,
	0,1,0,1,0,1,
	1,0,0,0,1,0
};


int stroke_number[n];   // номер хода, на котором посещается вершина
int path[n]; // номера посещаемых вершин
int vertex = 4;    // начальная вершина

void print_answer(void)
{
	int p;
	for (p = 0; p < n; p++)
		cout << path[p] + 1 << "->";
	cout << path[0] + 1;
	cout << "\n";
}

int check(int k)
{
	int i, flag = 0;
	for (i = 0; i < n && !flag; i++)
	{
		if (matrix[i][path[k - 1]] || matrix[path[k - 1]][i])
		{
			if (k == n && i == vertex) flag = 1;
			else if (stroke_number[i] == -1)
			{
				stroke_number[i] = k;
				path[k] = i;
				flag = check(k + 1);
				if (!flag) stroke_number[i] = -1;
			}
		}
	}
	return flag;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int j, i;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	cout << "Маршрут:\n";
	for (j = 0; j < n; j++)
		stroke_number[j] = -1;
	path[0] = vertex;
	stroke_number[vertex] = vertex;
	if (check(1)) print_answer();
	else cout << "Нет маршрутов\n";
	return 0;
}