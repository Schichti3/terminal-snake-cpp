#include <vector>
class Field
{
 public:
  Field(int width, int height);
  void PrintField();
  void SpawnFruit(std::pair <int, int> snakeHead);

  int GetWidth();
  int GetHeight();
  void SetWidth(int width);
  void SetHeight(int height);

  std::vector<std::vector<char> > Cells;

  std::pair<int, int> FruitPos; 
 private:

  int Width;
  int Height;    
};