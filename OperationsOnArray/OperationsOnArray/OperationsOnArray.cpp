// tablica_jednowymiarowa_C.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define L_ELEMENTS 4


void insert_data(int arr[])
{
	int temp = 0;
	for (int element = 0; element < L_ELEMENTS; element++)
	{
		printf("Enter value [%d]: ", element);
		scanf_s("%d", &temp);
		arr[element] = temp;
	}
}

void enter_random_data(int arr[])
{
	int temp = 0;
	for (int element = 0; element < L_ELEMENTS; element++)
	{
		temp = rand();
		arr[element] = (temp % 100) + 1;
	}
}

void display_data(int arr[])
{
	int temp = 0;
	for (int element = 0; element < L_ELEMENTS; element++)
	{
		printf("%4d", arr[element]);
	}
	printf("\n");
}

float average(int arr[])
{
	float sum = 0;
	for (int element = 0; element < L_ELEMENTS; element++)
	{
		sum += arr[element];
	}

	return (sum / L_ELEMENTS);
}

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

float median(int arr[], int arr_sort[])
{
	for (int element = 0; element < L_ELEMENTS; element++)
	{
		arr_sort[element] = arr[element];
	}
	qsort(arr_sort, L_ELEMENTS, sizeof(arr_sort[0]), cmpfunc);
	return ((float)(arr_sort[(L_ELEMENTS - 1) / 2] + arr_sort[(L_ELEMENTS) / 2]) / 2);
}

void change_min_max(int arr[])
{
	int w_min = arr[0], w_max = arr[0];

	for (int element = 0; element < L_ELEMENTS; element++)
	{
		if (arr[element] < w_min) w_min = arr[element];
		if (arr[element] > w_max) w_max = arr[element];
	}

	for (int element = 0; element < L_ELEMENTS; element++)
	{
		if (arr[element] == w_min) arr[element] = w_max;
		else if (arr[element] == w_max) arr[element] = w_min;
	}
}

void menu(void)
{
	printf("\n");
	printf("1 - insert data\n");
	printf("2 - display data\n");
	printf("3 - compute average and median\n");
	printf("4 - change values min with max\n");
	printf("5 - generate random value\n");
	printf("k - exit\n");
	printf("\n");
}

int main()
{
	int array[L_ELEMENTS] = { 0 };
	int arr_sort_temp[L_ELEMENTS] = { 0 };
	char option = 0;

	while (option != 'k')
	{
		menu();
		option = _getch();
	

		switch (option)
		{
		case '1':
			insert_data(array);
			break;

		case '2':
			display_data(array);
			break;

		case '3':

			printf("Average value of values in array is: %f\n", average(array));
			printf("Median of values in array is: %f\n", median(array, arr_sort_temp));
			break;

		case '4':
			change_min_max(array);
			printf("Changed value max with min.\n");
			break;

		case '5':
			enter_random_data(array);
			printf("Generated random value.\n");
			break;

		case 'k':
			//zakonczenie programu
			break;

		default:
			printf("Choose option.\n\n");
			break;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

