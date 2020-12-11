#include<iostream>
#include<ctime>
void initArray(int [], size_t);
void printArray(int[], size_t);
void initArrayAuto(int[], size_t);
void bubblesort(int[], size_t);
void insertSort(int[], size_t);
void _1_searchMax(int[], int[], size_t);
int _2_searchOddNum(int[], size_t);
int _3_searchMaxMult(int[], size_t);
int _4_countNullZones(int[], size_t);
void _5_swapMaxAndLast(int[], int[], size_t);
void hard_multiSorting(int[], size_t, int);
int main()
{
	{
		const size_t SIZE = 10;
		int A[SIZE], B[SIZE], C[10];
		int k = 0;
		srand(time(0));
		// 1. Enter two arrays of integers A and B. Find max element of the A array which doesn't belong to B array
		initArrayAuto(A, SIZE);
		bubblesort(A, SIZE);
		printArray(A, SIZE);
		initArrayAuto(B, SIZE);
		bubblesort(B, SIZE);
		printArray(B, SIZE);
		_1_searchMax(A, B, SIZE);
		// 2. Given array of integers, in which all numbers except one encounter even number of times, one number encounters one time. Find this number.
		initArray(A, SIZE);
		std::cout << _2_searchOddNum(A, SIZE) << std::endl;
		// 3. Choose from the sequence three numbers whose product is maximum.
		if (_3_searchMaxMult(A, SIZE) == A[0])
			std::cout << A[0] << "  " << A[1] << "  " << A[2] << std::endl;
		else	std::cout << A[SIZE - 1] << "  " << A[SIZE - 2] << "  " << A[0] << std::endl;
		// 4. Given onedimension array. Count number of zero zones.
		std::cout << _4_countNullZones(A, SIZE) << std::endl;
		//5. Поменять местами максимальный элемент массива и последний.При этом сформировать новый массив.Вывести оба массива.
		// 5. Change places of max element and last element of the array. Wherein create a new array. Print both arrays.
		_5_swapMaxAndLast(A, B, SIZE);

	}
	system("pause");
	return 0;
}
void initArray(int A[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << "Enter array [" << i << "]= ";
		std::cin >> A[i];
	}
	system("cls");
}
void printArray(int A[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}
void initArrayAuto(int A[], size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		A[i] = rand()%100;
	}
}
void bubblesort(int A[], size_t SIZE)
{
	for (size_t i = SIZE - 1; i > 0; i--) //marker moving
	{
		for (size_t j = 0; j < i; j++) //cycles through elements
		{
			if (A[j] < A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}
void insertSort(int A[], size_t SIZE)
{
	int temp, j;
	for (size_t i = 1; i < SIZE; i++)
	{
		temp = A[i];
		for (j = i - 1; j >= 0 && temp < A[j]; j--)
		{
			A[j + 1] = A[j];
		}
		A[j + 1] = temp;
	}
}
void _1_searchMax(int A[], int B[], size_t SIZE)
{
	bool flag;
	for (size_t i = 0; i < SIZE; i++) //search through A array
	{
		flag = true;
		for (size_t j = 0; j < i; j++) //search through B array
		{
			if (A[i] == B[j])
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			std::cout << A[i] << std::endl;
			return;
		}
		if (flag == false)
		{
			std::cout << "No such element\n";
		}
	}
}
int _2_searchOddNum(int A[], size_t SIZE)
{
	int count = 1;
	bubblesort(A, SIZE);
	for (size_t i = 0; i < SIZE - 1; i++)
	{
		if (A[i] == A[i + 1])
			count++;
		else {
			if (count % 2 != 0)
				return A[i];
			count = 1;
		}
	}
}
int _3_searchMaxMult(int A[], size_t SIZE)
{
	initArrayAuto(A, SIZE);
	bubblesort(A, SIZE);
	printArray(A, SIZE);
	if (A[0] * A[1] * A[2] > A[SIZE - 1] * A[SIZE - 2] * A[0])
		return A[0];
	else return A[SIZE - 1];
}
int _4_countNullZones(int A[], size_t SIZE)
{
	initArray(A, SIZE);
	int count = 0;
	for (size_t i = 0; i < SIZE; i++)
	{
		if (A[i] == A[i + 1] == 0) continue;
		if (A[i] == 0)
			count++;
	}
	return count;
}
void _5_swapMaxAndLast(int A[], int B[], size_t SIZE)
{
	initArrayAuto(A, SIZE);
	std::cout << "This is the original array:\n";
	printArray(A, SIZE);
	for (size_t i = 0; i < SIZE; i++) B[i] = A[i];
	bubblesort(A, SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		if (B[i] == A[0]) B[i] = B[9];
	}
	B[9] = A[0];
	std::cout << "This is the result array:\n";
	printArray(B, SIZE);
}
void hard_multiSorting(int A[], size_t SIZE, int k)
{
	int remainder, numOfCElements = 0;
	int C[10];
	std::cout << "Enter K:\n";
	std::cin >> k;
	for (remainder = 0; remainder <= k - 1; remainder++)
	{
		int j;
		int countIndex = -1;
		int B[10];
		for (size_t i = 0, j = 0; i < SIZE; i++)
		{
			if (A[i] % remainder != 0) continue;	//loading B array with even to K elements
			B[j] = A[i];
			j++;
		}
		for (size_t i = 9; i > 0; i--)	//sorting B array by element's digits difference
		{
			for (size_t j = 0; j < i; j++)
			{
				int minDigit, maxDigit, BJdiff, BJ1diff;
				for (size_t i = 0; i < 10; i++)	//finding minimal digit of B[j] array element
				{
					for (B[j]; B[j] > 0; B[j]--)
					{
						if (B[j] % 10 == i)
							minDigit = i;
						B[j] /= 10;
					}
				}
				for (size_t i = 9; i > 0; i--)	//finding maximum digit of B[j] array element
				{
					for (B[j]; B[j] > 0; B[j]--)
					{
						if (B[j] % 10 == i)
							maxDigit = i;
						B[j] /= 10;
					}
				}
				BJdiff = maxDigit - minDigit;
				for (size_t i = 0; i < 10; i++)	//finding minimal digit of B[j+1] array element
				{
					for (B[j + 1]; B[j + 1] > 0; B[j + 1]--)
					{
						if (B[j + 1] % 10 == i)
							minDigit = i;
						B[j + 1] /= 10;
					}
				}
				for (size_t i = 9; i > 0; i--)	//finding maximum digit of B[j+1] array element
				{
					for (B[j + 1]; B[j + 1] > 0; B[j + 1]--)
					{
						if (B[j + 1] % 10 == i)
							maxDigit = i;
						B[j + 1] /= 10;
					}
				}
				BJ1diff = maxDigit - minDigit;
				if (BJdiff < BJ1diff)
				{
					int temp = B[j];
					B[j] = B[j + 1];
					B[j + 1] = temp;
				}
			}
		}
		for (size_t i = 0; i < 10; i++) C[i] = B[i];
	}
}



