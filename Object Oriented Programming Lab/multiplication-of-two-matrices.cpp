/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Program for Multiplication of two matrices using OOP
*   Website:- www.programmingvidya.com
*/
#include <iostream>
#include <iomanip>
using namespace std;

class matrix
{
    int **a,l1,l2;
    public:
    void initialize_matrix(int m,int n)
    {
        l1=m;
        l2=n;
        a = new int*[m];
        for(int p=0;p<m;p++)
        {
            a[p] = new int[n];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=0;
            }
        }
    }

    void display_matrix()
    {
        for(int i=0;i<l1;i++)
        {
            cout<<" ";
            for(int j=0;j<l2;j++)
            {
                cout<<a[i][j]<<setw(5);
            }
            cout<<"\n";
        }
    }

    void enter_matrix()
    {
        for(int i=0;i<l1;i++)
        {
            for(int j=0;j<l2;j++)
            {
                cin>>a[i][j];
            }
        }
    }

    int multiply_matrix(matrix m1, matrix m2)
    {
        if(m1.l2!=m2.l1)
        {
            cout<<"\n\n Matrix multiplication not possible\n";
            return 0;
        }
        else
        {
            for(int i=0;i<m1.l1;i++)
            {
                for(int j=0;j<m2.l2;j++)
                {
                    for(int k=0;k<m1.l2;k++)
                    {
                        a[i][j]+=m1.a[i][k]*m2.a[k][j];
                    }
                }
            }
            return 1;
        }
    }
};

int main()
{
    cout<<"\n\n Program for multiplication of two matrices using oop";
    cout<<"\n ^^^^^^^ ^^^ ^^^^^^^^^^^^^^ ^^ ^^^ ^^^^^^^^ ^^^^^ ^^^";

    matrix m1,m2,m3;
    int row1,col1,row2,col2;

    cout<<"\n\n Enter the rows and columns of first matrix - ";
    cin>>row1>>col1;
    m1.initialize_matrix(row1,col1);

    cout<<"\n Enter the rows and columns of second matrix - ";
    cin>>row2>>col2;
    m2.initialize_matrix(row2,col2);

    cout<<"\n Enter the elements of first matrix - ";
    m1.enter_matrix();

    cout<<"\n Enter the elements of second matrix - ";
    m2.enter_matrix();

    cout<<"\n First Matrix - \n\n";
    m1.display_matrix();

    cout<<"\n Second Matrix - \n\n";
    m2.display_matrix();

    cout<<"\n\n Multiplying both matrices...";
    m3.initialize_matrix(row1,col2);

    if(m3.multiply_matrix(m1,m2))
    {
        cout<<"\n\n Resultant matrix - \n\n";
        m3.display_matrix();
    }

    return 0;
}