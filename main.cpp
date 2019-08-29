#include<iostream>
#include<fstream>
#include"mergesort.h"

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
	mergesort sort(arr, 34100);
	sort.show();
	system("pause");
}
