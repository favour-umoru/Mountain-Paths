#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Create functions which will be used in file
double minElevation()
{
    
}

double minElevation()
{
  
}

void computeColor(int )
{
  int shadeGray = 0;
  
  shadeGray = (elevationP
}

void main()
{
  // Declare the variables
  ifstream readFile;
  int mapRow, mapColumns;
  
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
      cout << "Error " << filename << endl;
      return 1;
   }
  
  // Read from a file into a vector using a while loop
  while (!readFile.eof()) 
  {
    // Read from file into a nested loop
      for(int i = 0; i < mapRow; i++){
          for (int j = 0; j < mapColumns; j++){
              filename  >> vectorMap[i][j];
          }
      }
  }
  
  // Done with file, close it
   readFile.close();
}
