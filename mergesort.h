#include<iostream>
using namespace std;

class mergesort
{
public:
	mergesort();
	mergesort(double *array, int size);
	~mergesort();
	void show();
private:
    double* arr;
	int lowerindex;
	int higherindex;
	int size;
	void merge(double *arr, int lowerindex, int higherindex);
	void Mergesort(double *arr, int lowerindex, int higherindex);
};
