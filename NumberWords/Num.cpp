// Welcome to the Interactive C++ Tutorial.
// Start by choosing a chapter and
// write your code in this window.

#include <iostream>
using namespace std;

char arr[10][7] = {"Zero","One","Two","Three","Four", "Five", "Six","Seven","Eight","Nine"};
char arr2[10][15] = {"Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen", "Sixtenn","Seventeen","Eighteen","Nineteen"};
char arr3[10][15] = {"Ten","Twenty","Thirty","Fourty", "Fifty", "Sixty","Seventy","Eighty","Ninety","Hundred"};
int countDigits(int n )
{
    int count =0;
    while (n != 0)
    {
       n/=10;    // n = n/10
       count++;
    }
    return count;
}

int unitPlace(int n )
{
    return n%10;
}

int tenthPlace(int n )
{
     n/=10;
    return n%10;
}

int main() {
    int a;
    char ch = 'y';
    while (ch == 'y')
    {
    cout<<"Enter:"<<endl;
    cin>>a;
    int numDigits =  countDigits(a);
    cout<<numDigits<<endl;
    if(numDigits == 1)
    {
    cout<<arr[a]<<endl;
    }
    else if(numDigits == 2)
    {
        int u = unitPlace(a);
        int t = tenthPlace(a);
        if(t == 1 )
        {
            cout<<arr2[u]<<endl;
        }
        else
        {
            if(u != 0)
            {
            cout<<arr3[t-1]<<" "<<arr[u]<<endl;
            }
            else
            {
                 cout<<arr3[t-1]<<endl;
            }
        }
    }
    cout<<"continue ?";
    cin>>ch;
    }
    return 0;
}


