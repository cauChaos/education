#include<iostream>
#include<list>
#include<string>
 
using namespace std;
 
string temp;
int num;
list<char> arr;
int main()
{
   cin >> temp;
   for(int i =0 ;i < temp.size(); i++)
   {
      arr.push_back(temp[i]);
   }
   cin >> num;
   list<char>::iterator it = arr.end();
   for(int i = 0 ; i < num ; i++)
   {
      char op;
      cin >> op;
      if(op == 'P')
      {
         char c;
         cin >> c;
         arr.insert(it,c);
      }
      else if( op == 'L')
      {
         if(it != arr.begin())--it;
      }
      else if(op == 'D')
      {
         if(it != arr.end())++it;
      }
      else if(op == 'B')
      {
         if(it != arr.begin())
         {
            --it;
         }
         else continue;
         it = arr.erase(it);
      }
   }
   for(list<char>::iterator iit = arr.begin() ; iit != arr.end() ; iit++)
   {
      cout << *iit;
   }
   cout <<endl;
}
