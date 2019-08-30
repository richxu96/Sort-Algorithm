#include"sort.h"
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

sort::sort()
{
	double array[21] = { 3,2,5,5,3,9.9,4,66,9,52,3669,5,2,6,7,0,3,5.0,0.7,3,0.2 };
	this->arr = array;
	this->size = 21;
	this->lowerindex = 0;
	this->higherindex = this->size - 1;
    cout << "a default mergesort class has been made!\n";
}

sort::sort(double *array, int Size)
{
	this->arr = array;
	this->size = Size;
	this->lowerindex = 0;
	this->higherindex = this->size-1;
}

sort::~sort()
{
        cout << "mergesort class has been destructed!\n";
}

void sort::merge(double *arr, int lowerindex, int higherindex)
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

void sort::mergesort(double *arr, int lowerindex, int higherindex)
{
        if (lowerindex < higherindex)
        {
                int mid = lowerindex + (higherindex - lowerindex) / 2;
                mergesort(arr, lowerindex, mid);
                mergesort(arr, mid + 1, higherindex);
                merge(arr, lowerindex, higherindex);
        }
        else
        {
                return;
        }

}

void sort::swap(double *x, double *y)
{
	double temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort::bubblesort(double *arr, int size)
{
	for (int i = 0; i < size-2; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				this->swap(arr + j, arr + j + 1);
			}
		}
	}
}

void sort::Bubblesort()
{
	this->bubblesort(this->arr, this->size);
}

void sort::Mergesort()
{
	mergesort(this->arr, 0, this->size - 1);
}


