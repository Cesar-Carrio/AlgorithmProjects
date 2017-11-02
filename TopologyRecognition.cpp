//Topology recognition problem
//Cesar Carrillo
//Given a network with n>3 nodes and a weight matrix W[0..n-1,0..n-1] of
//positive integers, of a weighted, connected undirected graph modeling 
//a network, decide whether the network is one of the topologies, if any:
//ring, star, fully connected mesh. Note: represent infinity by the value 100.
//INPUT: a positive integer n and a list of n^2 positive values
//OUTPUT: message "ring" or "star" or "complete" or "neither"


#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

using namespace std;

int main()
{
	//for loop integers
	//n = nodes; i = node being checked; j = checking connections on a node;
	int n = 0, i = 0, j = 0;
	//count = size of degree; center = for star
	int count = 0, center = 0;
	//2d matirx
	int W[100][100];
	//array for keeping track of degrees for a node.
	int degreesOfNodes[100];
	bool cond;

	// display the header                                                         
	cout << endl << "CPSC 335-01 - Programming Assignment #2" << endl;
	cout << "Topology recognition algorithm" << endl;
	cout << "Enter the number of nodes in the topology" << endl;
	// read the number of nodes                                                   
	cin >> n;
	// read the weight matrix                                                     
	cout << "Enter the positive weights, 100 for infinity" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> W[i][j];
		}
	}


	

	cout << "The topology is" << endl;
	
	// Start the chronograph to time the execution of the algorithm               
	auto start = chrono::high_resolution_clock::now();
	//===========================================================================================
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (W[i][j] > 0 && W[i][j] != 100)
			{
				count++;
			}
			degreesOfNodes[i] = count;
		}
		count = 0;
	}
	// End the chronograph to time the execution of the algorithm                                                                                                                      
	auto end = chrono::high_resolution_clock::now();
	// Print the elapsed time in seconds and fractions of seconds
	// Displaying the output is NOT part of the algorithm so the timer ends before displaying the output                                                                                                                                       
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = microseconds / 1E6;
	

	//===========================================================================================
	// loop to check whether the topology is a ring  
	cond = true;
	for (i = 0; i < n; i++)
	{
		if (degreesOfNodes[i] != 2)
		{
			cond = false;
		}
	}
	if (cond)
	{
		cout << "ring" << endl;
		cout << "elapsed time: " << seconds << " seconds" << endl;
		return EXIT_SUCCESS;
	}
	
	//===========================================================================================
	// loop to check whether the topology is a star  
	cond = true;    
	for (i = 0; i < n; i++)
	{
		if (degreesOfNodes[i] == (n - 1))
		{
			center++;
		}

		if (center > 1)
		{
			cond = false;
		}
	}
	if (cond && (center == 1)) 
	{
		cout << "star" << endl;
		cout << "elapsed time: " << seconds << " seconds" << endl;
		return EXIT_SUCCESS;
	}
	//===========================================================================================

	cond = true;
	// loop to check whether the topology is a fully connected mesh               
	for (int i = 0; i < n; i++)
	{
		if (degreesOfNodes[i] != (n - 1))
		{
			cond = false;
		}
	}

	if (cond)
	{
		cout << "fully connected mesh" << endl;
		cout << "elapsed time: " << seconds << " seconds" << endl;
	}
	else
	{
		cout << "neither" << endl;
		cout << "elapsed time: " << seconds << " seconds" << endl;
	}

	return EXIT_SUCCESS;

	
}


