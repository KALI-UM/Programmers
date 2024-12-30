#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    int diff= 'A'-'a';
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]+=diff;
        }
        else
        {
            str[i]-=diff;
        }
    }
    
    cout<<str;
    
    return 0;
}