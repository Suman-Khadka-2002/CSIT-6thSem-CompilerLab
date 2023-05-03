// program to identify a given line is a comment or not.

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string line;
    int i = 2, flag = 0;

    cout<<"Enter the input string: ";
    cin>>line;

    if (line[0] == '/' && line[1] == '/') {
            cout<<"the input string is a single line comment.";
            flag = 1;
    }

    for (int i=0 ; i<line.length() ; i++) {
        if ((line[0] == '/' && line[1] == '*') && (line[i] == '*' && line[i+1] == '/')) {
            cout<<"The input string is a multi-line comment.";
            flag = 1;
            
        }
    }

    if (flag == 0) {
        cout<<"the input string is not a comment.";
    }
    return 0;
}