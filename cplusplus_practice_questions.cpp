
#include <iostream>
#include <cstdio>

using namespace std;

void name(int x)
{
    switch (x) 
    {
        case 1:
            cout << "one"<<"\n";
            break;
        case 2:
            cout << "two"<<"\n";
            break;
        case 3:
            cout << "three"<<"\n";
            break;
        case 4:
            cout << "four"<<"\n";
            break;
        case 5:
            cout << "five"<<"\n";
            break;
        case 6:
            cout << "six"<<"\n";
            break;
        case 7:
            cout << "seven"<<"\n";
            break;
        case 8:
            cout << "eight"<<"\n";
            break;
        case 9:
            cout << "nine"<<"\n";
            break;
    }
}

void evenoddprint(int i)
{
    if (i%2 == 0)
    {
        cout<<"even"<<"\n";
    }else{
        cout<<"odd"<<"\n";
    }
}

void forlooper(int c,int d)
{
    for (int i=c;i<d+1;i++)
        {
            if (i>=1 && i<=9) 
            {
                name(i);
            }else if (i>9)
            {
                evenoddprint(i);
            } 
        }
}


int main() 
{
    //int a=8 , b=11; 
    int a,b;
    std::cin >> a ;
    std::cin >> b ;

    //std::cout <<"a is : "<<a<< std::endl;
    //std::cout <<"b is : "<<b<< std::endl;
    
    forlooper(a,b);
 
    return 0;
}
//-------------------------------------------------