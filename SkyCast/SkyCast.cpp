#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int numDigits( int number)
{
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

bool comp(int a, int b)
{
	return (a < b);
}

int main() {
    int low , high ;
	cin>>low>>high;
	std::vector<int> v(high -low +1) ; // vector with 100 ints.
    std::iota (std::begin(v), std::end(v), low); // Fill with 0, 1, ..., 99.
    int numofblocked;
    cin>>numofblocked;
    vector<int>::iterator it;
    for (int i=0; i<numofblocked; i++)
    {
        int  a;
        cin>>a;
        v.erase(std::remove(v.begin(), v.end(), a), v.end());
    }
    for (int n : v) // the initializer may be an array
        std::cout << n << ' ';
    int numofChannels ,backChannel, currChannel,min_pos,max_pos;
    min_pos = 0; max_pos =v.size()-1;
    cin>>numofChannels;
    int resultSum = 0; ; 
    cin>>backChannel ;
    resultSum=numDigits(backChannel);
    cin>>currChannel;
    int backpos = find(v.begin(), v.end(), backChannel) - v.begin();
    int currpos = find(v.begin(), v.end(), currChannel) - v.begin();
    resultSum+=std::min({ numDigits(currChannel) , abs(currpos - backpos),
    (abs(min_pos -backpos) + abs(max_pos - currpos) +1),
            (abs(max_pos -backpos) + abs(min_pos - currpos) +1)
        
    }
    , comp);
    cout<<endl<<resultSum<<endl;
    for(int i=0; i<numofChannels -2 ; i++)
    { 
      int nextChannel;
      cin >> nextChannel;
      int nextpos = find(v.begin(), v.end(), nextChannel) - v.begin();
      cout<<"backpos :"<<backpos<<" currpos : "<<currpos<<" nextpos : "<<nextpos
      <<" nextChannel :"<<nextChannel<<endl;
      
      int a = std::min({numDigits(nextChannel),abs(nextpos - currpos),
            abs(nextpos - backpos) + 1 , 
            (abs(min_pos -currpos) + abs(max_pos - nextpos) +1),
            (abs(max_pos -currpos) + abs(min_pos - nextpos) +1)
      },comp);
      resultSum+=a;
      cout<<a<<endl;
      backpos = currpos;
      currpos = nextpos;
    }
    cout<<"Result is "<<resultSum<<endl;
	return 0;
}
