#include<iostream>
using namespace std;

class mergesort
{
public:
	mergesort();
	~mergesort();
	void Mergesort(double *arr, int lowerindex, int higherindex);
private:
	void merge(double *arr, int lowerindex, int higherindex);
};
