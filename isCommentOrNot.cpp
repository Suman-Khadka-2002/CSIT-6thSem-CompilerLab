// Program to simulate DFA for the language over alphabet={0, 1} starting with 0 and ending with 1.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char string[100], start_state = 'A';
    cout<<"Enter the input string: ";
    cin>>string;

    for (int i=0 ; string[i]!= '\0' ; i++)
    {
        switch(start_state) 
        {
            case 'A':
                if (string[i] == '0')
                    start_state = 'B';
                else if(string[i] == '1')
                    start_state = 'D';
                break;

            case 'B':
                if (string[i] == '0')
                    start_state = 'B';
                else if (string[i] == '1')
                    start_state = 'C';
                break;

            case 'C':
                if (string[i] == '0')
                    start_state = 'B';
                else if (string[i] == '1')
                    start_state = 'C';
                break;
            
            case 'D':
                if (string[i] == '0' || string[i] == '1')
                    start_state = 'D';
                break;
        }

    }
        if(start_state == 'C')
            cout<<"The given string "<<string<< " is accepted.";
        else
            cout<<"The input string "<<string<<" is not accepted.";
        return 0;
}