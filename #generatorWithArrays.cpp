#include <iostream>

using namespace std;

int main()
{
  int line = 10;
  int column = 10;

  for (int i = 0; i < line; i++)
  {
    for (int j = 0; j < column; j++)
    {
      if (i == j)
      {
        cout << "#";
      }
      else if (i + j == (column - 1))
      {
        cout << "#";
      }
      else if (i == 0 || i == (column - 1))
      {
        cout << "#";
      }
      else if (j == 0 || j == (column - 1))
      {
        cout << "#";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}