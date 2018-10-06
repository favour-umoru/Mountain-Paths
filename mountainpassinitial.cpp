#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;

// Create functions which will be used in file

int main()
{
	// Declare the variables
	ifstream readFile;
	ofstream finalOutput; // Output file stream

	int mapRow, mapColumns;
	int shadeGray = 0;
    int elevationPoint = 0;
    int temp = 0;
	cout << "check point -1" << endl;
	vector <vector<int>> vectorMap;
	
	string filename, outputFilename; 
	cout << "check point 0" << endl;
	// Ask the user for the input
	cout << "Enter the number of rows in the map: ";
	cin >> mapRow;
	cout << "Enter the number of col in the map: ";
	cin >> mapColumns;
	cout << "Enter the filename: ";
	cin >> filename;
	
	if(mapRow < 0 || mapColumns < 0)
	{
		cout << "Error: Invalid Input";
		return 1;
	}
	
	// Declare after.
	vector <vector<int>> R(mapRow, vector<int> (mapColumns,0));
	vector <vector<int>> G(mapRow, vector<int> (mapColumns,0));
	vector <vector<int>> B(mapRow, vector<int> (mapColumns,0));
	
	// initialize output file name
	outputFilename = filename + ".ppm";

	// Try to open files for input and output
	readFile.open(filename);
	finalOutput.open(outputFilename);

	// If the file does not open
	if (!readFile.is_open()) 
	{
	  cout << "Error: Could not open file " << filename << endl;
	  return 1;
	}
	if (!finalOutput.is_open()) 
	{
	  cout << "Error: Could not open file " << outputFilename << endl;
	  return 1;
	}

	if (cin.fail()) 
	{
	  cout << "Error: wrong data type" << filename << endl;
	  return 1;
	}
	// Read from a file into a vector using a while loop
	while (!readFile.eof()) 
	{
	// Read from file into a nested loop
	  for(int i = 0; i < mapRow; i++){
		  vector<int> temp;
		  for (int j = 0; j < mapColumns; j++){
			  int value;
			  readFile >> value;
			  temp.push_back(value);
			}
		  vectorMap.push_back(temp);
		  
	  }
	    
	}

	// call the function to find the minElevation and maxElevation value
   
    // Read from file into a nested loop
	int minElevation = vectorMap.at(0).at(0);
	int maxElevation = vectorMap.at(0).at(0);
	
	for(int i = 0; i < mapRow; i++){
	  for (int j = 0; j < mapColumns; j++){
		  // Set the minElevation value to the vector of vector from the file.
		  temp = vectorMap.at(i).at(j);
		  
		  if(temp < minElevation)
		  {
			  minElevation = temp;
		  }
		  if(temp > maxElevation)
		  {
			   maxElevation = temp;
		  }
		  
	  }
	}
	cout << minElevation << endl;
	cout << maxElevation;

    for(int i = 0; i < mapRow; i++){
        for (int j = 0; j < mapColumns; j++){
          // Set the minElevation value to the vector of vector from the file.
            elevationPoint = vectorMap.at(i).at(j);
		
            shadeGray = round(((elevationPoint - static_cast<double>(minElevation))/(maxElevation - minElevation)) * 255);
            
			R.at(i).at(j) = shadeGray;
            G.at(i).at(j) = shadeGray;
			B.at(i).at(j) = shadeGray;
        }
    }    

	finalOutput << "P3" << endl;
	finalOutput << mapColumns << " " << mapRow << endl;
	finalOutput << "255" << endl;
	
	for(int i = 0; i < mapRow; ++i){
	  for (int j = 0; j < mapColumns; ++j){
		  finalOutput << R.at(i).at(j)<<" ";
		  finalOutput << G.at(i).at(j)<<" ";
		  finalOutput << B.at(i).at(j)<<" ";
	  }
	}

	// Done with file, close it
	readFile.close();
	finalOutput.close();
	
	return 0;
}
