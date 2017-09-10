/*rth number after decimal point in N/D*/

#include<iostream>
using namespace std;
int digitatR(int n,int d,int r)
{
    while(r-- >0)
    {
    n=n%d;
    
    n=n*10;
    
    }

return n/d;

}
