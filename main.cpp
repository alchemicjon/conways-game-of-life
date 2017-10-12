// main.cpp

#include "game_of_life.h"
using namespace std;

int main()
{
  char world[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

  welcome();
  fillArray(world);
  display(world);

  for(int i = 0; i < 1; i++)
  {
    generation(world);
    display(world);
    waitForInput();
  }

  goodbye();

  return 0;
}
