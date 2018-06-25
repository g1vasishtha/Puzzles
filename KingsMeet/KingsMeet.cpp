#include<iostream>
#include<algorithm>
using namespace std;

bool comp(int x , int y)
{
	return x>y;
}
int main()
{
 int numofKings , numofMeet;
 cin>>numofKings>>numofMeet;
 int kingsCordinates[2*numofKings] , meetCordinates[2*numofMeet];
 for(int i=0; i<2*numofKings ; i++)
 cin>>kingsCordinates[i];
 for(int i=0; i<2*numofMeet; i++)
 cin>>meetCordinates[i];
 int  result;
 for(int i=0; i<2*numofMeet; i+=2)
    {
    	result = 0;
 	for(int j=0; j<2*numofKings; j+=2)
 	    {
    	   result += max({abs(kingsCordinates[j] - meetCordinates[i]),
    	   abs(kingsCordinates[j+1] - meetCordinates[i+1])
   	        }, comp);
 	    }
	cout<<result<<endl;  	   	
	    
    }
return 0;	
}
