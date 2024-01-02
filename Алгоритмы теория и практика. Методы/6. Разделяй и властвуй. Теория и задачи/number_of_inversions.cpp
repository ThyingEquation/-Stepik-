#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

unsigned long int result = 0;

vector<unsigned long int> arr;

void merge(int l, int m, int r)
{

	int lengthEA1 = (m - l) + 1;
	int lengthEA2 = r - m;
	vector<int> EA1(lengthEA1);
	vector<int> EA2(lengthEA2);

	for (int a = 0; a < lengthEA1; a++)
	{
		EA1[a] = arr[l + a];
	}

	for (int a = 0; a < lengthEA2; a++)
	{
		EA2[a] = arr[m + 1 + a];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < lengthEA1 && j < lengthEA2)
	{


		if (EA1[i] <= EA2[j])
		{
			
			arr[k] = EA1[i];

			i++;
		}

		else
		{
	
	result += (m-l+1) - i;
			arr[k] = EA2[j];
			j++;
		}
		k++;
	}

	while (i < lengthEA1)
	{
		arr[k] = EA1[i];
		i++;
		k++;
	}


	while (j < lengthEA2)
	{
		arr[k] = EA2[j];
		j++;
		k++;
	}

}

void mergeSort(int l, int r)
{

	if (l < r) {

		int m = (l + ((r - l) /2));

		mergeSort(l, m);
		mergeSort(m + 1, r);

		merge(l, m, r);
	}
}

int main()
{
	int arrB;

	int arrSize;

	cin >> arrSize;

	for (int x = 0; x < arrSize; x++)
	{
		cin >> arrB;
		arr.push_back(arrB);
	}

	mergeSort(0, arrSize - 1);

	cout << result;
}