#include <iostream>
#include <string>
using namespace std;

int main()
{
  string a, b, c, d;
  long int a_b, c_d; //ab, cd
  cin >> a >> b >> c >> d;

  a_b = stol(a+b); //ab를 long int형으로 바꿈
  c_d = stol(c+d); //cd를 long int형으로 바꿈

  cout << a_b+c_d; //ab+cd
}