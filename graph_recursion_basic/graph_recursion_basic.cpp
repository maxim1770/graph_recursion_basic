#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

//const int N=12; // Количество вершин графа.
//typedef struct zveno *graph;
//
//typedef struct zveno
//{
//	 int Key; //Вершина графа.
//	 graph Sled; // Указатель на след. смежную вершину.
//	
//} Leader;
//graph beg[N]; // Описание типа списков смежности.
//
//void AddGraph(int x, int y, graph beg[N])
//{
//	graph ukzv, uzel; //Рабочие указатели.
//	if (beg[x] != NULL)
//		{ Poisk(beg[x],y,&ukzv);
//	 if (ukzv == NULL)
//		{ // Добавление элемента в конец списка, заданного указателем beg[x].
//		 uzel = new (Leader);
//	(*uzel).Key = y; (*uzel).Sled = NULL; ukzv = beg[x];
//	 while ((*ukzv).Sled != NULL)
//		 ukzv = (*ukzv).Sled;
//	(*ukzv).Sled = uzel; } }
//		 else {
//		beg[x] = new (zveno);
//		(*beg[x]).Key = y; (*beg[x]).Sled = NULL;
//	}
//}
//
//void MakeGraph(graph beg[N]) // Построение списков смежности beg графа.
//{ 
//	int x,y;
//	graph ukzv,uzel; //Рабочие указатели.
//	cout << "Введите начало дуги: ";
//	cin >> x;
//	while (x != 0)
//	{
//		cout << "Введите конец дуги: ";
//		cin >> y;
//		AddGraph(x,y,beg);
//		cout << "Введите начало дуги: "; 
//		cin >> x; 
//	} 
//}
//
// void PrintGraph(svqz beg[N])
// {
//	int i;
//	graph pointer; //Рабочий указатель.
//	for (i = 1; i<N; i++)
//	{ 
//		cout << i << " ...";
//		pointer = beg[i];
//		if (pointer == NULL) cout << "Пустой список!\n";
//		else 
//		{
//			while (pointer != NULL)
//			{ 
//				cout << (*pointer).Key;
//				pointer = (*pointer).Sled; 
//			}
//			cout << endl;
//		} 
//	}
//}



//const int n = 6;
//int matrix[n][n] =
//{
//	0,0,0,1,1,1,
//	0,0,0,1,1,1,
//	0,0,0,1,1,1,
//	1,1,1,0,0,0,
//	1,1,1,0,0,0,
//	1,1,1,0,0,0
//};

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

//void Vyvod(int w, int l)
// // (рекурсивный алгоритм). *w - указатель на корень дерева.
//
//{
//	 int i;
// if (w != NULL)
//{ Vyvod(&((w).Right),l + 1);
// for (i = 1; i <= l; i++) cout << " ";
// cout << (w).Key << endl;
// Vyvod(&((w).Left),l + 1); } 
//}

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