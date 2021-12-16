#include<iostream>
#include<cstdlib>
#include <math.h>

using namespace std;

class Polynomial;
class Term
{
public:
    Term(float c=0,int e=0);
    void Set(float c,int e);
    friend Polynomial;

private:
    float coef;     //coefficient
    int exp;    //exponent
};


class Polynomial
{
public:
    Polynomial Add(Polynomial b);

    int ins=0;
    int getDegree();
    float Eval(float b);
    void NewTerm(float theCoeff,int theExp);
    void print();
    int maxterm(int,int);

private:
    Term termArray[5];
    int terms = 0;
};



void Term::Set(float c,int e)
{
    coef=c;
    exp=e;
}


Term::Term(float c,int e)
{
    coef=c;
    exp=e;
}



void Polynomial::NewTerm(float theCoeff,int theExp)
{


    termArray[ins].Set(theCoeff,theExp);
    ins++;
    terms=ins;
}
int Polynomial::maxterm(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;

}

float Polynomial::Eval(float b)
{

    Polynomial A = *this ;
    int evaluation;
    for(int i=0 ; i<A.terms ;i++)
    {
       evaluation=evaluation + (A.termArray[i].coef) * (pow(b,A.termArray[i].exp));

    }
    return evaluation;

}

int Polynomial::getDegree()
{
    int d = 0;
    for ( int i = 0; i < 5; i++ )
    {
        if (termArray[i].coef!= 0 )
        {
            d = termArray[i].exp;
        }
    }
    return d;
}


Polynomial Polynomial::Add(Polynomial b)
{

        Polynomial A = *this ;
        Polynomial C;
        float arrco[10]={0};
        int arrexp[10]={0};

         for(int i=0 ;i<A.terms+b.terms; i++)
        {
            if(i<A.terms)
            {
                 arrco[i] += A.termArray[i].coef;
                 arrexp[i]+= A.termArray[i].exp;
            }
            else{
                 arrco[i]+= b.termArray[i-A.terms].coef;
                arrexp[i]+= b.termArray[i-A.terms].exp;
            }

        }

        for(int i=0;i<A.terms+b.terms;i++)
        {
            for(int j=i+1;j<A.terms+b.terms;j++)
            {

                if(arrexp[i] == arrexp[j])
                {
                        arrco[i] =  arrco[i]+arrco[j];
                        arrco[j]=0;
                        arrexp[j]=0;
                }

            }
        }
        int counting=0;
        for(int i=0;i<5;i++)
        {
            if(arrco[i]!=0)
            {
                C.NewTerm(arrco[i],arrexp[i]);
                counting++;
            }
        }
        cout<<"A.Add(B):"<<endl;
        bool op=true;
        for(int k=4;k>=0;k--)
        {
            if ( C.termArray[k].coef !=0 )
            {
                if(C.termArray[k].exp == 0)
                {
                    cout <<"+"<< C.termArray[k].coef<<" ";

                }

                else
                {

                        if(op){
                            op = false;
                        }
                        else{
                            cout<<"+";
                        }



                    cout<<C.termArray[k].coef<< "x^"<<C.termArray[k].exp << " ";
                }
            }

        }
        cout<<endl;
}



void Polynomial::print()
{
    for( int i=0; i<5; i++ )
    {
        if ( termArray[i].coef !=0 )
        {
            if(termArray[i].exp == 0 && i==0)
            {
                cout << termArray[i].coef <<" ";

            }

            else
            {
                if(i!=0)
                {
                    cout<<"+";
                }

                cout <<termArray[i].coef<< "x^" << termArray[i].exp << " ";
            }

        }


    }
    cout<<endl;
}




int main()
{
    int term1,term2,i;
    float coefficient;
    int exponent;
    Term termArray[5];

    Polynomial A;
    Polynomial B;
    Polynomial C;


    cout<<"input Polynomial A:"<<endl;
    cout<<"number of terms you want to enter:"<<endl;
    cin>>term1;
    for(i=0;i<term1;i++)
    {
        cout<<"input term coef and power (please enter in form of descending power):"<<endl;
        cin>>coefficient;
        cin>>exponent;
        A.NewTerm(coefficient,exponent);
    }






    cout<<"input Polynomial B:"<<endl;
    cout<<"number of terms you want to enter:"<<endl;
    cin>>term2;
    for(i=0;i<term2;i++)
    {
        cout<<"input term coef and power (please enter in form of descending power):"<<endl;
        cin>>coefficient;
        cin>>exponent;
        B.NewTerm(coefficient,exponent);
    }


    cout<<endl;
    cout<<"A:"<<endl;
    A.print();
    cout<<"B:"<<endl;
    B.print();
    cout<<endl;


    A.Add(B);
    cout<<endl;

    cout<<"A.Eval(2):"<<endl;
    cout<<A.Eval(2)<<endl;
    cout<<endl;
    cout<<"A.getDegree():"<<endl;
    cout<<A.getDegree()<<endl;



}


