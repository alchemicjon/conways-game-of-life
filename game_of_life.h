#include<iostream>
#include<fstream>
using namespace std;

const int NUMBER_OF_COLUMNS = 20;
const int NUMBER_OF_ROWS = 20;
const char LIVE_CELL = '@';
const char DEAD_CELL = '#';

void generation(char world[][NUMBER_OF_COLUMNS]);

void display(const char world[][NUMBER_OF_COLUMNS]);

void fillArray(char world[][NUMBER_OF_COLUMNS]);

int getNeighborCount(char world[][NUMBER_OF_COLUMNS], int row, int column);

void welcome();

void goodbye();

void waitForInput();

void generation(char world[][NUMBER_OF_COLUMNS])
{
  // for each cell, determine if it lives or dies.
  // 0, 1, 4+ neighbors: cell dies
  // 2, 3 neighbors: cell lives
  // 3 neighbors and cell is dead: birth of new cell
  // # is grass (no cell), @ is live cell
  // need to make sure change is instantaneous - that is, cannot change one cell
  // at a time

  char world_copy[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
  for (int i = 0; i < NUMBER_OF_ROWS; i++)
  {
    for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
    {
      int neighborCount = getNeighborCount(world, i, j);
      //cout << "Index: " << i << "," << j << " - Neighbors: " << neighborCount << endl;
      switch (neighborCount) {
        case 0:
        case 1:
          world_copy[i][j] = DEAD_CELL;
          break;
        case 2:
          world_copy[i][j] = world[i][j];
          break;
        case 3:
          world_copy[i][j] = LIVE_CELL;
          break;
        default:
          world_copy[i][j] = DEAD_CELL;
      }
    }
  }
  for (int i = 0; i < NUMBER_OF_ROWS; i++)
  {
    for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
    {
      world[i][j] = world_copy[i][j];
    }
  }
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
  cout << endl;
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

int getNeighborCount(char world[][NUMBER_OF_COLUMNS], int row, int column)
{
  // ensure that we don't access indices below 0
  int count = 0;
  int row_min = row - 1;
  int column_min = column - 1;
  int row_max = row + 1;
  int column_max = column + 1;
  if (row_min < 0)
  {
    row_min = 0;
  }
  if (column_min < 0)
  {
    column_min = 0;
  }
  if (row_max >= NUMBER_OF_ROWS)
  {
    row_max = NUMBER_OF_ROWS - 1;
  }
  if (column_max >= NUMBER_OF_COLUMNS)
  {
    column_max = NUMBER_OF_COLUMNS - 1;
  }

  for (int i = row_min; i <= row_max; i++)
  {
    for (int j = column_min; j <= column_max; j++)
    {
      if ((i == row && j == column) == false && world[i][j] == LIVE_CELL)
      {
        count++;
      }
    }
  }
  return count;
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
