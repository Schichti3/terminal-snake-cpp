#include "field.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h> 


Field::Field(int width, int height)
{
 Width = width;
 Height = height;
 char borderCharTopBottom = 'X';
 char borderCharLeftRight = 'X';

 for (int i = 0; i < Height; i++)
 {
  std::vector<char> row;
  for (int a = 0; a < Width; a++)
  {
   if (i == 0 || i == Height-1)
   {
    row.push_back(borderCharTopBottom);
   }
   else if (a == 0 || a == Width-1)
   {
    row.push_back(borderCharLeftRight);
   }
   else
   {
    row.push_back(' ');
   }
  }
  Cells.push_back(row); 
 } 
}


void Field::PrintField()
{
 Cells[FruitPos.second][FruitPos.first] = 'O';
 for (int i = 0; i < Height; i++)
 {
  for (int a = 0; a < Width; a++)
  {
   std::cout << Cells[i][a];  
   if (a == Width-1)
   {
    std::cout << std::endl;
   }
  }
 }   
}

void Field::SpawnFruit(std::pair <int, int> snakeHead)
{
 srand(time(NULL));
 int row = (rand() % Height);
 int col = (rand() % Width);
 if (row == 0) row = 1;
 if (row == Height) row = Height-1;
 if (col == 0) col = 1;
 if (col == Width) col = Width-1;

 std::pair<int, int> fruidCoords = {col, row};


 while(fruidCoords == snakeHead)
 {
  int row = (rand() % Height-1);
  int col = (rand() % Width-1);
  if (row == 0) row = 1;
  if (col == 0) col = 1;
  fruidCoords = {col, row};  
 }
 FruitPos = fruidCoords;

 Cells[row][col] = 'O';
}

int Field::GetWidth()
{
 return Width;
}
int Field::GetHeight()
{
 return Height;
}
void Field::SetWidth(int width)
{
 Width = width;   
 //TODO Adjust Cells vector
}
void Field::SetHeight(int height)
{
 Height = height; 
 //TODO Adjust Cells vector
}