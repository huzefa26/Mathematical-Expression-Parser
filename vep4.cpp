#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

double Num();
double Add();
double Mul();

char *e;

double Num()
{
    double num1=0;
    if(*e>='a' && *e<='z' || *e>='A' && *e<='Z')
    {
        cout<<"Enter value of "<<*e<<" : ";
        cin>>num1;
        e++;

        if(*e=='!')
        {
            num1=int(num1);
            for(int i=(num1-1);i>1;i--)
            {
                num1*=i;
            }
        }
        else if(*e=='^')
        {
            e++;
            int i=num1,j=Num();
            if(j>=1)
                while(j>1)
                {
                    num1=num1*i;
                    j--;
                }
            else
                num1=1;
        }
    }
    else if(*e>='0' && *e<='9')
    {
        while(*e>='0' && *e<='9')
        {
            num1*=10;
            num1+=(*e++ - '0');
        }

        if(*e=='.')
        {
            e++;
            double dec_pnt=1;
            while(*e>='0' && *e<='9')
            {
                dec_pnt/=10;
                num1+=(*e++ - '0')*dec_pnt;
            }
        }

        else if(*e=='!')
        {
            for(int i=(num1-1);i>1;i--)
            {
                num1*=i;
            }
        }

        if(*e=='^')
        {
            e++;
            int i=num1,j=Num();
            if(j>=1)
                while(j>1)
                {
                    num1=num1*i;
                    j--;
                }
            else
                num1=1;
        }
    }

    else if(*e=='(')
    {
        e++;
        num1=Add();
        e++;
    }

    else
        cout<<"Incorrect format.";
    return num1;
}
double Add()
{
    double a=Mul();
    while(*e=='+' || *e=='-')
    {
        if(*e=='+')
        {
            e++;
            double b=Mul();
            a+=b;
        }
        else
        {
            e++;
            double b=Mul();
            a-=b;
        }
    }
    return a;
}
double Mul()
{
    double a=Num();
    while(*e=='*' || *e=='/')
    {
        if(*e=='*')
        {
            e++;
            double b=Num();
            a*=b;
        }
        else
        {
            e++;
            double b=Num();
            a/=b;
        }
    }
    return a;
}

int main()
{
    e=(char*)malloc(256);
    while(1)
    {
        cout<<"Enter your expression : ";
        scanf("%255s",e);
        cout<<Add()<<endl;
    }
}
