#include <iostream>
#include<vector>
using namespace std;


int main()
{
    string str= "ADBCGHIEFKJLADTVDERFSWVGHQWCNOPENSMSJWIERTFB";
    int length = 26 , i =0;
    std::vector<int> v(length, 0);
    for(char& c : str) 
    v[c-65]++;
    for(char& c : str) 
    {
       if(v[c-65]==1)
         {
           cout<<i<<endl;
           break;
         } 
       i++;
    }
    return 0;
}
