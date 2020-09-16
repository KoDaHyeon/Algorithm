#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> matrix;

int main()
{
   vector<int> list[4];
   list[1].emplace_back(5);
   list[2].emplace_back(6);

   cout << (list[1])[0] << '\n';
   cout << (list[0])[0] << '\n';
}