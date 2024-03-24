#include "snake.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h> 


Snake::Snake(Field* field, int length, int startX, int startY, int speed)
{
 MovingRight = true;
 MovingLeft = false;
 MovingUp = false;
 MovingDown = false;

 Speed = speed;

 FieldArea = field;
 Length = length;

 for (int i = 0; i < Length; i++)
 {
  if (i == 0)
  {
   AddHead(startX, startY); 
  }    
  else
  {
   AddBodyPart(startX, startY);    
  }
 }

}

void Snake::ChangeSpeed(int addedSpeed)
{
 int maxSpeed = 30;
 int minSpeed = 200;

 if (Speed+addedSpeed < maxSpeed || Speed+addedSpeed > minSpeed)
 {
  return;
 }
 else
 {
  Speed = Speed+addedSpeed;  
 }
}

int Snake::GetLength()
{
 return Length;
}

void Snake::PlaceSnake()
{
 int lastPosX = (*(Body.end()-1))->x;
 int lastPosY = (*(Body.end()-1))->y;

 for (int i = 0; i < Body.size();i++)
 {
  FieldArea->Cells[Body[i]->y][Body[i]->x] = Body[i]->body;  
 }
 FieldArea->Cells[lastPosY][lastPosX] = ' ';  
}

void Snake::Move()
{
 if (MovingRight)
 {
  int prevX = Body[0]->x;
  int prevY = Body[0]->y;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = ' ';
  Body[0]->x = Body[0]->x+1;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = Body[0]->body;
  HeadPos.first = Body[0]->x;
  HeadPos.second = Body[0]->y;
  for (int i = 1; i < Body.size();i++)
  {
   int savedPosX = Body[i]->x;
   int savedPosY = Body[i]->y; 
   FieldArea->Cells[Body[i]->y][Body[i]->x] = ' ';
   Body[i]->x = prevX;
   Body[i]->y = prevY;
   FieldArea->Cells[prevY][prevX] = Body[i]->body;
   prevX = savedPosX;
   prevY = savedPosY;
  }
 }
 else if (MovingLeft)
 {
  int prevX = Body[0]->x;
  int prevY = Body[0]->y;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = ' ';
  Body[0]->x = Body[0]->x-1;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = Body[0]->body;
  HeadPos.first = Body[0]->x;
  HeadPos.second = Body[0]->y;
  for (int i = 1; i < Body.size();i++)
  {
   int savedPosX = Body[i]->x;
   int savedPosY = Body[i]->y; 
   FieldArea->Cells[Body[i]->y][Body[i]->x] = ' ';
   Body[i]->x = prevX;
   Body[i]->y = prevY;
   FieldArea->Cells[prevY][prevX] = Body[i]->body;
   prevX = savedPosX;
   prevY = savedPosY;
  }
 }
 else if (MovingUp)
 {
  int prevX = Body[0]->x;
  int prevY = Body[0]->y;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = ' ';
  Body[0]->y = Body[0]->y-1;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = Body[0]->body;
  HeadPos.first = Body[0]->x;
  HeadPos.second = Body[0]->y;
  for (int i = 1; i < Body.size();i++)
  {
   int savedPosX = Body[i]->x;
   int savedPosY = Body[i]->y; 
   FieldArea->Cells[Body[i]->y][Body[i]->x] = ' ';
   Body[i]->x = prevX;
   Body[i]->y = prevY;
   FieldArea->Cells[prevY][prevX] = Body[i]->body;
   prevX = savedPosX;
   prevY = savedPosY;
  }
 }
 else if (MovingDown)
 {
  int prevX = Body[0]->x;
  int prevY = Body[0]->y;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = ' ';
  Body[0]->y = Body[0]->y+1;
  FieldArea->Cells[Body[0]->y][Body[0]->x] = Body[0]->body;
  HeadPos.first = Body[0]->x;
  HeadPos.second = Body[0]->y;
  for (int i = 1; i < Body.size();i++)
  {
   int savedPosX = Body[i]->x;
   int savedPosY = Body[i]->y; 
   FieldArea->Cells[Body[i]->y][Body[i]->x] = ' ';
   Body[i]->x = prevX;
   Body[i]->y = prevY;
   FieldArea->Cells[prevY][prevX] = Body[i]->body;
   prevX = savedPosX;
   prevY = savedPosY;
  }
 }   
}


void Snake::AddHead(int startX, int startY)
{
 BodyPart* newBodyPart = new BodyPart;
 newBodyPart->body = '%';
 newBodyPart->x = startX;
 newBodyPart->y = startY;
 newBodyPart->nextBodyPart = NULL;
 Body.push_back(newBodyPart);
}

void Snake::AddBodyPart(int startX, int startY)
{
 BodyPart* newBodyPart = new BodyPart;
 newBodyPart->body = '#';
 newBodyPart->x = startX;
 newBodyPart->y = startY;
 newBodyPart->nextBodyPart = NULL;
 Body.push_back(newBodyPart);
}


void Snake::AddNewBodyPart()
{
 if (MovingRight)
 {
  BodyPart* newBodyPart = new BodyPart;
  newBodyPart->body = '#';
  newBodyPart->x = (*(Body.end()-1))->x - 1;
  newBodyPart->y = (*(Body.end()-1))->y;
  newBodyPart->nextBodyPart = (*(Body.end()-1));
  Body.push_back(newBodyPart);
 }
 else if (MovingLeft)
 {
  BodyPart* newBodyPart = new BodyPart;
  newBodyPart->body = '#';
  newBodyPart->x = (*(Body.end()-1))->x + 1;
  newBodyPart->y = (*(Body.end()-1))->y;
  newBodyPart->nextBodyPart = (*(Body.end()-1));
  Body.push_back(newBodyPart);
 }
 else if (MovingUp)
 {
  BodyPart* newBodyPart = new BodyPart;
  newBodyPart->body = '#';
  newBodyPart->x = (*(Body.end()-1))->x;
  newBodyPart->y = (*(Body.end()-1))->y + 1;
  newBodyPart->nextBodyPart = (*(Body.end()-1));
  Body.push_back(newBodyPart);
 }
 else if (MovingDown)
 {
  BodyPart* newBodyPart = new BodyPart;
  newBodyPart->body = '#';
  newBodyPart->x = (*(Body.end()-1))->x;
  newBodyPart->y = (*(Body.end()-1))->y - 1;
  newBodyPart->nextBodyPart = (*(Body.end()-1));
  Body.push_back(newBodyPart);
 }
}