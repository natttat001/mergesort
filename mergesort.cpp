#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void Merge(vector<int>& arr, int left, int mid, int right)
{
	int size1 = mid - left + 1;
	int size2 = right - mid;
	vector<int> temp1(size1); // left arr
	for (int i = 0; i < size1; ++i)
	{
		temp1[i] = arr[left + i];
	}
	vector<int> temp2(size2); //right arr
	for (int i = 0; i < size2; ++i)
	{
		temp2[i] = arr[mid + 1 + i];
	}
	int i = 0, ii = 0;
	int n = left;
	while (i < size1 && ii < size2)
	{
		if (temp1[i] <= temp2[ii])
		{
			arr[n] = temp1[i];
			i++;
		}
		else
		{
			arr[n] = temp2[ii];
			ii++;
		}
		n++;
	}
	while (i < size1)
	{
		arr[n] = temp1[i];
		i++;
		n++;
	}
	while (ii < size2)
	{
		arr[n] = temp2[ii];
		ii++;
		n++;
	}
}

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = (right - left) / 2 + left;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}
int main()
{
	vector <int> arr = { 10, 15, 12, 12, 25, 16, 20, 14, 28, 17 };
	MergeSort(arr, 0, arr.size()-1);
	for (const int& i : arr)
	{
		cout << i << " ";
	}
}
