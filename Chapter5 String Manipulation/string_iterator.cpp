#include <iostream>
#include <string>
using namespace std;
 
int main ()
{
  string MyString = "Learn C++";
  string::iterator it;

  it = MyString.begin();
  cout<<*it<<" ";
  it++;
  cout<<*it<<" ";
  it++;
  cout<<*it<<" ";
  return 0;
}
