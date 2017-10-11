#include<iostream>
#include<fstream>
using namespace std;

const int NUMBER_OF_COLUMNS = 20;
const int NUMBER_OF_ROWS = 20;

void generation(char world[][NUMBER_OF_COLUMNS]);

void display(const char world[][NUMBER_OF_COLUMNS]);

void fillArray(char world[][NUMBER_OF_COLUMNS]);

void welcome();

void goodbye();

void waitForInput();

void generation(char world[][NUMBER_OF_COLUMNS])
{

}

void display(const char world[][NUMBER_OF_COLUMNS])
{
  for(int i = 0; i < NUMBER_OF_ROWS; i++)
  {
    for(int j = 0; j < NUMBER_OF_COLUMNS; j++)
    {
      cout << world[i][j];
    }
    cout << endl;
  }
}

void fillArray(char world[][NUMBER_OF_COLUMNS])
{
  string fileName, line;
  fstream inputStream;
  cout << "Please enter the file name: ";
  cin >> fileName;
  cout << endl << "Thanks!" << endl;
  inputStream.open(fileName);
  int row = 0;
  while(getline(inputStream, line) && row < NUMBER_OF_ROWS)
  {
    int columns = line.length();
    // prevent line.length() exceeding NUMBER_OF_COLUMNS
    if (columns > NUMBER_OF_COLUMNS)
    {
      columns = NUMBER_OF_COLUMNS;
    }
    for(int i = 0; i < columns; i++)
    {
      world[row][i] = line[i];
    }
    row++;
  }



  inputStream.close();
}

void welcome()
{
  cout << "Welcome to Conway's Game of Life!" << endl;
  cout << "You may progress through each generation by pressing the Enter key" << endl;
}

void goodbye()
{
  cout << "Fin." << endl;
}

void waitForInput()
{
  cin.get();
}
