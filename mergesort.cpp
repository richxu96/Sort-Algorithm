#include"mergesort.h"
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

mergesort::mergesort()
{
	double array[21] = { 3,2,5,5,3,9.9,4,66,9,52,3669,5,2,6,7,0,3,5.0,0.7,3,0.2 };
	this->arr = array;
	this->size = 21;
	this->lowerindex = 0;
	this->higherindex = this->size - 1;
    cout << "a default mergesort class has been made!\n";
}

mergesort::mergesort(double *array, int Size)
{
	this->arr = array;
	this->size = Size;
	this->lowerindex = 0;
	this->higherindex = this->size-1;
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

void mergesort::show()
{
	Mergesort(this->arr, 0, this->size - 1);
	int length = this->size;
	for(int i = 0; i<length; i++)
	{
		cout << arr[i] << endl;
	}
}


