//Fractional version of the knapsack problem:
//You can cut each item and take any fraction of it. 
//Using greedy algorithm to achieve an optimal solution
#include <iostream>
#include <algorithm>
#include<utility>
using namespace std;

double knapsack(double[], double[], int, int); //Function prototype

int main()
{
	char choice; //Sentinel
	do
	{
		int size; //Holds number of items in the knapsack
		cout << "Please, enter the number of items in the knapsack: ";
		cin >> size;
		const int a = size;
		int cap; //Holds capacity of the knapsack
		cout << "Please, enter the capacity of the kapsack: ";
		cin >> cap;
		double* weight = new double[a]; //Array that holds the weight
		double* val = new double[a]; //Array that holds the value
		cout << endl;
		cout << "Please, enter the weight of each item: "<<endl;

		//Intializes weight
		for (int i = 0; i < a; i++)
		{
			cout << "Item " << i + 1 << ": ";
			cin >> weight[i];
		}
		cout << endl;

		//Initializes value
		cout << "Please, enter the value of each item: " << endl;
		for (int i = 0; i < a; i++)
		{
			cout << "Item " << i + 1 << ": ";
			cin >> val[i];
		}
		cout << endl;

		//Calls knapsack function, which returns max value of items fitting in the knapsack
		cout<<knapsack(weight, val, cap, a)<<endl;
		cout << endl;
		
		cout << "Do you wish to repeat the program?: (y/n) " << endl;
		cout << endl;
		cin >> choice;

	} while (choice != 'n');

	system("PAUSE");
	return 0;
}

double knapsack(double weight[], double val[], int cap, int size)
{
	int knapw = 0; //Holds knapsack weight
	double total=0.0; //Holds total value
	double* arr = new double[size]; //Holds ratio array (weight/value)
	double* arr2 = new double[size]; //Holds the same values as arr

	/*Calculates and displays the 
	values for arr (ratio), which is
	the weight divided by the value*/
	cout << "Ratio: value/weight: " << endl; 
	for (int i = 0; i < size; i++)
	{
		arr[i] = val[i] / weight[i];
		cout << arr[i] << " ";
	}
	
	//Copies the values from arr into arr2
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	
	/*Sorts the value array
	in terms of the ratio (arr)*/
	pair<double, double>* pairt;
	pairt = new pair<double, double>[size];
	for (int i = 0; i < size; i++)
	{
		pairt[i].first = arr[i];
		pairt[i].second = val[i];
	}
	sort(pairt, pairt+size);
	
	for (int i = 0; i < size; i++)
	{
		arr[i] = pairt[i].first;
		val[i] = pairt[i].second;
	}

	/*Sorts the weight array
	in terms of the ratio (arr2)*/
	pair<double, double>* pairtt;
	pairtt = new pair<double, double>[size];
	for (int i = 0; i < size; i++)
	{
		pairtt[i].first = arr2[i];
		pairtt[i].second = weight[i];
	}
	sort(pairtt, pairtt + size);

	for (int i = 0; i < size; i++)
	{
		arr2[i] = pairtt[i].first;
		weight[i] = pairtt[i].second;
	}
	cout << endl;
	cout << endl;

	//Displays sorted ratio
	cout << "Sorted ratio: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	cout << endl;

	//Displays sorted values in terms of ratio
	cout << "Sorted value in terms of ratio:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << val[i]<<" ";
		
	}
	cout << endl;
	cout << endl;

	//Displays sorted weight in terms of ratio
	cout << "Sorted weight in terms of ratio" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << weight[i] << " ";
	}
	
	cout << endl;

	/*Since we sort the ratio array in increasing
	order we loop backwards picking the highest 
	value each time*/
	for (int i=size-1; i>=0; i--)
	{	
		/*If the weight of the knapsack plus the item weight
		is less than the capacity of the knapsack we add i to 
		the weight and we add up the value of the item*/
		if ( knapw+weight[i]<=cap)
		{
			knapw += weight[i];
			total += val[i];
		}

		/*If the weight of the knapsack plus the item is 
		greater than the capacity of the knapsack we multiply
		the value of the item times the reminder and we divide
		by the item weight*/
		else
		{
			total += (val[i] * (cap - knapw)) / weight[i];

			/*When the total value is calculated
			we break, avoiding the loop to iterate
			an extra time*/
			break; 
		}
		
	}
	cout << endl;
	cout << "The maximum optimal value is: ";
	return total;
}

