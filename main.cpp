#include<iostream>
#include<fstream>
#include"sort.h"
#include<time.h>

using namespace std;


int main()
{
	ifstream read;
	read.open("data.txt");
	char ch[30];
	double arr[34100];
	int i = 0;
	while (read.getline(ch, 10))
	{
		arr[i] = atof(ch);
		i++;
	}
	read.close();
	sort sort(arr, 34100);
	clock_t start, end;
	start = clock();
	sort.Mergesort();
	end = clock();
	cout << "�鲢�����㷨����ʱ��Ϊ��" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	start = clock();
	sort.Bubblesort();
	end = clock();
	cout << "ð�������㷨����ʱ��Ϊ��" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	//sort.mergesort_show();
	system("pause");
}
