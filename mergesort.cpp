#include"sort.h"
#include<iostream>
#include<fstream>

using namespace std;



mergesort::mergesort()
{
	cout << "a mergesort class has been made!\n";
}

mergesort::~mergesort()
{
	cout << "mergesort class has been destructed!\n";
}

void mergesort::merge(double *arr, int lowerindex, int higherindex)
{
	double *temp = new double[higherindex - lowerindex + 1];
	int i = lowerindex;
	int mid = (lowerindex + higherindex)/2;
	int k = lowerindex;
	int j = mid + 1;
	int m = 0;
	while (i <= mid && j <= higherindex)
	{
		if (*(arr + i) <= *(arr + j))
		{
			*(temp + m) = *(arr + i);
			m++;
			i++;
		}
		else
		{
			*(temp + m) = *(arr + j);
			m++;
			j++;
		}
	}
	while (i <= mid)
	{
		*(temp + m) = *(arr + i);
		i++;
		m++;
	}
	while (j <= higherindex)
	{
		*(temp + m) = *(arr + j);
		j++;
		m++;
	}
	for (int a = 0; a < higherindex-lowerindex+1; a++)
	{
		*(arr + k) = *(temp + a);
		k++;
	}
	delete temp;
}

void mergesort::Mergesort(double *arr, int lowerindex, int higherindex)
{
	if (lowerindex < higherindex)
	{
		int mid = lowerindex + (higherindex - lowerindex) / 2;
		Mergesort(arr, lowerindex, mid);
		Mergesort(arr, mid + 1, higherindex);
		merge(arr, lowerindex, higherindex);
	}
	else
	{
		return;
	}

}

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


	mergesort sort;
	sort.Mergesort(arr, 0, sizeof(arr)/sizeof(double)-1);
	int length = sizeof(arr) / sizeof(double);
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}