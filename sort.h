#include<iostream>
using namespace std;

class sort
{
public:
	sort();
	sort(double *array, int size);
	~sort();
	void Mergesort();
	void Bubblesort();
private:
    double* arr;
	int lowerindex;
	int higherindex;
	int size;
	void merge(double *arr, int lowerindex, int higherindex);
	void mergesort(double *arr, int lowerindex, int higherindex);
	void bubblesort(double *arr, int size);
	void swap(double *x, double *y);
};
