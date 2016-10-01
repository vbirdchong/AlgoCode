
#include <cstring>
#include <iostream>

using namespace std;

//Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.

void zero(int **a, int m, int n)
{
  int *row = new int [m];
  int *column = new int [n];

  memset(row, 0, sizeof(int)*m);
  memset(column, 0, sizeof(int)*n);
  
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (0 == a[i][j])
      {
        row[i] = 1;
        column[j] = 1;
      }
    }
  }

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (row[i] == 1 || column[j] == 1)
      {
        a[i][j] = 0;
      }
    }
  }

  delete [] row;
  delete [] column;
}


int main()
{
  int **a;
  int m = 3, n = 4;

  for (int i = 0; i < m; ++i)
  {
    a[i] = new int[n];
  }

  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
      cout << a[i][j] << " ";
    cout << endl;
  }

  cout << endl;
  zero(a, m, n);

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
      cout << a[i][j] << " ";
    cout << endl;
  }
  
  return 0;
}

