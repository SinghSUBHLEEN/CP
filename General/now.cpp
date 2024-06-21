#include<iostream>

using namespace std;

int main()
{
    int n = 0, lastDigit = 0;
 
    cout<<"Please enter the number: "<<endl;
    cin>>n;
    
    if(n<0) n = -1*n;

    lastDigit = n%10;
   
    while(n>=10)
        n = n/10;

    cout<<"Sum of first and last digit is:"<<(lastDigit+n);

    return 0;
}