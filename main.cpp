#include <iostream>
#include <windows.h>
//#include "field.hpp"
#include "snake.hpp"
#include <thread>



void KeyInput(Snake* snake)
{   
 while(true)
 { 
 // std::cout << GetKeyState(0x57) << std::endl;
  if ((GetKeyState(0x57)/*w*/ < 0 && !snake->MovingDown) || (GetKeyState(0x26)/*UP*/ < 0 && !snake->MovingDown)) 
  {
   snake->MovingLeft = false; 
   snake->MovingRight = false;
   snake->MovingDown = false;
   snake->MovingUp = true;
  }   
  else if ((GetKeyState(0x41)/*a*/ < 0 && !snake->MovingRight) || (GetKeyState(0x25)/*LEFT*/ < 0 && !snake->MovingRight))
  {
   snake->MovingLeft = true; 
   snake->MovingRight = false;
   snake->MovingDown = false;
   snake->MovingUp = false;
  } 
  else if ((GetKeyState(0x53)/*s*/ < 0 && !snake->MovingUp) || (GetKeyState(0x28)/*DOWN*/ < 0 && !snake->MovingUp))
  {
   snake->MovingLeft = false; 
   snake->MovingRight = false;
   snake->MovingDown = true;
   snake->MovingUp = false;
  } 
  else if ((GetKeyState(0x44)/*d*/ < 0 && !snake->MovingLeft) || (GetKeyState(0x27)/*RIGHT*/ < 0 && !snake->MovingLeft))
  {
   snake->MovingLeft = false; 
   snake->MovingRight = true;
   snake->MovingDown = false;
   snake->MovingUp = false;
  }
  else if (GetKeyState(0xBB)/*+*/ < 0)
  {
   snake->ChangeSpeed(-10);
  }
  else if (GetKeyState(0xBD)/*-*/ < 0)
  {
   snake->ChangeSpeed(10);
  }
  Sleep(1);  
 }    
}

void SnakeMovement(Field* field, Snake* snake, bool* hitSomething)
{
 while(true)
 {
  snake->Move();
  if (snake->HeadPos.first == 0 || snake->HeadPos.first == field->GetWidth()-1)
  {
   *hitSomething = true;
  }
  if (snake->HeadPos.second == 0 || snake->HeadPos.second == field->GetHeight()-1)
  {
   *hitSomething = true;
  }

  for (int i = 1; i < snake->GetLength(); i++)
  {
   if (snake->HeadPos.first == snake->Body[i]->x && snake->HeadPos.second == snake->Body[i]->y)
   {
    *hitSomething = true;
   }
  }

  if (snake->HeadPos.first == field->FruitPos.first && snake->HeadPos.second == field->FruitPos.second)
  {
   snake->AddNewBodyPart();
   field->SpawnFruit(snake->HeadPos);
  }
  Sleep(snake->Speed);
 }
}



int main()
{
    
    Field field = Field(60,20);
    Snake snake = Snake(&field, 5, 10, 10, 100);
    field.SpawnFruit(snake.HeadPos);
    field.PrintField();

    bool hitSomething = false;
    int snakeSpeed = 100;

    std::thread keyPressThread (KeyInput, &snake);
    std::thread snakeThread (SnakeMovement, &field, &snake, &hitSomething);
    

    while (true)
    {
     if (hitSomething)
     {
      system("cls");
      field.PrintField(); 
      std::cout << "hitSomething";
      break;
     }   
     system("cls");
     field.PrintField(); 
     Sleep(5);
    }
    
    return 0;
}