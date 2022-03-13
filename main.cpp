/**
 * Author: Nadav Moyal
 */
#include "mat.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;
#include "mat.cpp"

int main() {
int col;
int row;
char c;
char d;
cout<<"Enter an odd column number :"<<endl;
cin>>col;
cout<<"Enter an odd row number :"<<endl;
cin>>row;
cout<<"Insert the first char :"<<endl;
cin>>c;
cout<<"Insert the second char :"<<endl;
cin>>d;
cout<<"This is the design of the requested mat is:"<<endl;
cout<< mat(col,row,c,d)<<endl;
return 0;
}