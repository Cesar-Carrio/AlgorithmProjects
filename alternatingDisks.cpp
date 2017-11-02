//Alternating disks problem, left-to-right algorithm
//Cesar Carrillo
//Given 2n alternating disks (dark,light) the program reads the number of single color disks
//(Light or dark), arranges the disks in the correct order and outputs the number of swaps
//INPUT: a positive integer n and a list of 2n disks of alteranting colors dark-light, starting with dark
//OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark,
//and an integer m the number of moves to move the dark one after the light



#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
void print_disks(int n, char *disks);
//function to print the list of disks, given the number of single color disks and the actiual list
//n represents the number of single color disks
//disks represents the list of disks(index 0 being the first disk) where
//0 = a light color disks
//1 = a dark color disks
int main()
{
	int n, m, k, i;
	char *disks;
	//display the header
	cout << "The alternating disks problem: left-to-right algorithm" << endl;
	cout << "Enter the number of single color disks (light or dark)" << endl;
	//read the number of disks
	cin >> n;
	//allocate space for the disks
	disks = new char[2 * n];
	//set the initial configurations for the disks to alternate 
	for (i = 0; i < 2*n; i++)
	{
		disks[2 * i] = 1;
		disks[2 * i + 1] = 0;
	}
	
	//Print the initial configuration of the list of disks
	cout << "Initial Configuration" << endl;
	cout << "List of disks\n";
	print_disks(n, disks);
	
	//loop to push light one before the dark ones
	m = 0;
	for (k = 0; k < 2*n; k++)
	{
		for (int j = 0; j < 2*n; j++)
		{
			if (disks[j] > disks[j + 1])
			{
				swap(disks[j+1], disks[j]);
				m++;
			}
		}	
	}
	
	//after shuffling them
	cout << "After moving darker ones to the right" << endl;
	print_disks(n, disks);
	//print the total number of moves
	cout << "Number of swaps is " << m << endl;
	//de-allocate the dynamic memory space
	delete[] disks;
	return EXIT_SUCCESS;
}


void print_disks(int n, char *disks)
{
	for (int i = 0; i < 2*n; i++)
	{
		if (disks[i] == 0)
		{
			cout << 'l';
		}
		else if (disks[i] == 1)
		{
			cout << 'd';
		}
	}
	cout << endl;
}

