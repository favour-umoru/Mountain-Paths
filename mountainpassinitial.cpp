#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;

// Create functions which will be used in file
int minElevationmaxElevationElevation(int mapRow, int mapColumns, istream& readFile, vector< vector<int> >& vectorMap)
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
  ofstream finalOutput;
   
  int mapRow, mapColumns;
  int minElevation = 0, maxElevation = 0;
  vector <vector<int>> vectorMap;
  string filename; 
  
  // Ask the user for the input
  cout << "Enter the number of rows in the map" << endl;
  cin >> mapRow;
  cout << "Enter the number of col in the map" << endl;
  cin >> mapColumns;
  cout << "Enter the filename" << endl;
  cin >> filename;
  
  // Try to open file
   readFile.open(filename);
  
  // If the file does not open
   if (!readFile.is_open()) 
   {
      cout << "Error: Could not open file " << filename << endl;
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

      for(int i = 0; i < mapRow; i++){
		  //cout<<"i:"<<i;
          for (int j = 0; j < mapColumns; j++){
			  //cout<<"j:"<<j;
              cout<< vectorMap.at(i).at(j)<<",";
          }
		  //cout<<endl;
      }
  cout<<endl<<"done"<<endl;
  
  // call the function to find the minElevation and maxElevation value
    minElevationmaxElevationElevation(mapRow, mapColumns, readFile, vectorMap);
    computeColor(minElevation, maxElevation, mapRow, mapColumns, readFile, vectorMap);
    
    
  // Done with file, close it
   readFile.close();
   
   return 0;
}
