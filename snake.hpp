#include <vector>
#include "field.hpp"

struct BodyPart
{
 char body;
 int x;
 int y;
 BodyPart* nextBodyPart;
};

class Snake
{
 public:
  Snake(Field* field, int length, int startX, int startY, int speed);

  void PlaceSnake();
  void Move();
  void AddHead(int startX, int startY);
  void AddBodyPart(int startX, int startY);
  void AddNewBodyPart();

  int GetLength();
  
  void ChangeSpeed(int addedSpeed);

  bool MovingRight;
  bool MovingLeft;
  bool MovingUp;
  bool MovingDown;

  int Speed;

  std::pair<int, int> HeadPos;
  std::vector<BodyPart*> Body;
 private:   
  Field* FieldArea;
  int Length;
};