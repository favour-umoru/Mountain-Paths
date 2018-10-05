#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;

// Create functions which will be used in file
int minMaxElevation(int mapRow, int mapColumns, istream& readFile, vector< vector<int> >& vectorMap)
{
    double minElevation = 90000, maxElevation = -90000;
    int temp = 0;
    while (!readFile.eof()) 
    {
    // Read from file into a nested loop
      for(int i = 0; i < mapRow; i++){
          for (int j = 0; j < mapColumns; j++){
              // Set the minElevation value to the vector of vector from the file.
              temp = vectorMap.at(i).at(j);
              if(temp > maxElevation)
              {
                   maxElevation = temp;
              }
              if(temp < minElevation)
              {
                  minElevation = temp;
              }
              
          }
      }
    }
}

void computeColor(int minElevation, int maxElevation, int mapRow, int mapColumns, istream& readFile, vector< vector<int> >& vectorMap)
{
    int shadeGray = 0;
    int elevationPoint = 0;
    vector< vector<int> > R(mapRow, vector<int> (mapColumns,0));
    vector< vector<int> > G(mapRow, vector<int> (mapColumns,0));
    vector< vector<int> > B(mapRow, vector<int> (mapColumns,0));
    
    for(int i = 0; i < mapRow; i++){
        for (int j = 0; j < mapColumns; j++){
          // Set the minElevation value to the vector of vector from the file.
            elevationPoint = vectorMap.at(i).at(j);
            shadeGray = ((elevationPoint - minElevation)/(maxElevation - minElevation)) * 255;
            
            // round to int 
            round(shadeGray);
            R.at(i).at(j) = shadeGray;
            G.at(i).at(j) = shadeGray;
            B.at(i).at(j) = shadeGray;
        }
    }    
}

int main()
{
  // Declare the variables
  ifstream readFile;
  ofstream finalOutput; // Output file stream
   
  int mapRow, mapColumns;
  int minElevation = 0, maxElevation = 0;
  vector <vector<int>> vectorMap;
  string filename, outputFilename; 
  
  // Ask the user for the input
  cout << "Enter the number of rows in the map: ";
  cin >> mapRow;
  cout << "Enter the number of col in the map: ";
  cin >> mapColumns;
  cout << "Enter the filename: ";
  cin >> filename;
  
  // initialize output file name
  outputFilename = filename + ".ppm";
  
  // Try to open files for input and output
   readFile.open(filename);
   finalOutput(outputFilename);
  
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
    minElevationmaxElevationElevation(mapRow, mapColumns, readFile, vectorMap);
    computeColor(minElevation, maxElevation, mapRow, mapColumns, readFile, vectorMap);
    
	
	while(!finalOutput.eof()) 
	{
		of << "P3" << endl;
		of << mapColumns << " " << mapRow << endl;
		of << "255" << endl;
		
		for(int i = 0; i < mapRow; i++){
          for (int j = 0; j < mapColumns; j++){
              finalOutput << R.at(i).at(j)<<" ";
			  finalOutput << G.at(i).at(j)<<" ";
			  finalOutput << B.at(i).at(j)<<" ";
          }
        }
		
	}
  // Done with file, close it
   readFile.close();
   finalOutput.close();
   
   return 0;
}
