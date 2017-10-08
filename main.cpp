// main.cpp

#include <iostream>
#include "game_of_life.h"
using namespace std;

const int NUMBER_OF_COLUMNS = 80;
const int NUMBER_OF_ROWS = 20;

void generation(char world[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]);

void display(const char world[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]);

void fillArray(char world[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]);

void welcome();

void goodbye();

void waitForInput();

int main()
{
  char[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] world;

  welcome();
  fillArray(world);
  display(world);

  for(int i = 0; i < 20; i++)
  {
    generation(world);
    display(world);
    waitForInput();
  }

  goodbye();

  return 0;
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
