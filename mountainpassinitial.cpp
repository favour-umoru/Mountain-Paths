#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Create functions which will be used in file


void main()
{
  // Declare the variables
  double mapRow, mapColumns;
  vector <vector<int>> vectorMap;
  string filename; 
  
  // Ask the user for the input
  cout << "Enter the number of rows in the map" << endl;
  cin >> mapRow;
  cout << "Enter the number of col in the map" << endl;
  cin >> mapColumns;
  cout << "Enter the filename" << endl;
  cin >> filename;
  
   if (!vectorMap.is_open()) 
   {
      cout << "Could not open file " << filename << endl;
      return 1;
   }
  
  // Read from a file into a vector
  vectorMap >> 
  
  // Done with file, close it
   inFS.close();
}
