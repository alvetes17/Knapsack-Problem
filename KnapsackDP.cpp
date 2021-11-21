//0/1 version of the knsapsack problem:
//You can only take or not take each item as a whole
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Function prototypes
int knapsack(int[], int[], int, int, vector<vector<int>>);
int maximumval(int, int);

int main()
{
	char choice; //Sentinel
	do
	{
		int size; //Holds number of items
		cout << "Please, enter number of items: ";
		cin >> size; 
		int* weight = new int[size]; //Array that holds the weight of the items
		int* val = new int[size]; //Array that holds the value the items
		int capacity; //Holds capacity of knapsack
		cout << "Enter capacity of the knaspsack: ";
		cin >> capacity;
		vector<vector<int>> t(size + 1, vector<int>(capacity + 1)); //Holds the table
		cout << endl;

		//Initialize weight
		cout << "Please, enter the weight for each item on the knapsack: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Item " << i + 1 << ": ";
			cin >> weight[i];
		}
		cout << "\nPlease, enter the value for each item on the knapsack: " << endl;

		//Initialize value
		for (int i = 0; i < size; i++)
		{
			cout << "Item " << i + 1 << ": ";
			cin >> val[i];
		}

		//Calls function knapsack, which returns maximum value that fits in the knapsack
		cout << knapsack(weight, val, capacity, size, t) << endl;
		cout << endl;
		cout << "Do you wish to repeat the program?(y/n):"<<endl;
		cin >> choice;

	} while (choice != 'n');

	system("PAUSE");
	return 0;
}

//Function that returns maximum optimal value 
int knapsack(int weight[], int val[], int cap, int size, vector<vector<int>>t)
{
	//i holds rows
	//j holds columns
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= cap; j++)
		{
			//Base case
			if (i == 0 || j == 0)
			{
				t[i][j] = 0;
			}

			/*If i can't contribute to j, which is the weight,
			 then we pick the value of the top cell*/
			else if (j + 1 <= weight[i - 1])
			{
				t[i][j] = t[i - 1][j];
			}

			/*If i can contribute to j then we pick the maximum value
			between the cell on top or the top cell - the weight of the 
			item cells to the left*/
			else if (j + 1 > weight[i - 1])
			{
				t[i][j] = maximumval(t[i - 1][j],val[i - 1] + t[i - 1][j - weight[i - 1]] );
			}
		}

	}
	cout << endl;

	//Displays the table
	for (int i = 0; i <= size; i++)
	{
		cout << " ";
		for (int j = 0; j <= cap; j++)
		{

			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "The maximum optimum value is: ";
	return t[size][cap];
}

//Returns the maximum value
int maximumval(int a, int b)
{
	return (a < b) ? b : a;
}