/*
*   Author:- Rahul Malhotra
*   Source:- Programming Vidya
*   Description:- Program to implement stack and queue using pure virtual functions:- store and retrieve
*   Website:- www.programmingvidya.com
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head=NULL,*tail=NULL;

class List
{
    public:
    void view()
    {
        node *n = head;
        if(head==NULL)
        {
            cout<<"\n No elements found...";
        }
        else
        {
            cout<<" ";
            while(n!=NULL)
            {
                if(n->next==NULL)
                {
                    cout<<n->data;
                }
                else
                {
                    cout<<n->data<<"->";
                }
                n = n->next;
            }
        }
    }
    virtual void store(int n)=0;
    virtual int retrive()=0;
};

class Stack :public List
{
    public:
    void store(int n)
    {
        node *n1 = new node();
        n1->data = n;
        n1->next=NULL;
        if((head==NULL)&&(tail==NULL))
        {
            head = n1;
            tail = n1;
        }
        else
        {
            tail->next = n1;
            tail = n1;
        }
    }
    int retrive()
    {
        if((tail==NULL)&&(head==NULL))
        {
            return -1;
        }
        else
        {
            int n = tail->data;
            node *n1 = head;
            while((n1->next!=tail)&&(head!=tail))
            {
                n1 = n1->next;
            }
            n1->next = NULL;
            free(tail);
            if(head!=tail)
            {
                tail = n1;
            }
            else
            {
                tail=NULL;
                head=NULL;
            }
            return n;
        }
    }
};

class Queue:public List
{
    public:
    void store(int n)
    {
        node *n1 = new node();
        n1->data = n;
        n1->next=NULL;
        if((head==NULL)&&(tail==NULL))
        {
            head = n1;
            tail = n1;
        }
        else
        {
            tail->next = n1;
            tail = n1;
        }
    }
    int retrive()
    {
        if((tail==NULL)&&(head==NULL))
        {
            return -1;
        }
        else
        {
            int n = head->data;
            if(head==tail)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->next;
            }
            return n;
        }
    }
};

int main()
{
    Stack s1;
    int ch;
    while(1)
    {
        system("cls");
        cout<<"\n\n Program to implement stack and queue using pure virtual functions store and retrieve";
        cout<<"\n ^^^^^^^ ^^ ^^^^^^^^^ ^^^^^ ^^^ ^^^^^ ^^^^^ ^^^^ ^^^^^^^ ^^^^^^^^^ ^^^^^ ^^^ ^^^^^^^^";
        cout<<"\n\n Menu";
        cout<<"\n ^^^^";
        cout<<"\n\n 1. Stack";
        cout<<"\n 2. Queue";
        cout<<"\n 3. Exit";
        cout<<"\n\n Enter your choice - ";
        cin>>ch;
        if(ch==1)
        {
            Stack s1;
            int ch1;
            while(1)
            {
                system("cls");
                cout<<"\n\n Stack Menu";
                cout<<"\n ^^^^^ ^^^^";
                cout<<"\n 1. Push Element";
                cout<<"\n 2. Pop Element";
                cout<<"\n 3. View Stack";
                cout<<"\n 4. Exit";
                cout<<"\n\n Enter your choice - ";
                cin>>ch1;
                if(ch1==1)
                {
                    int element;
                    cout<<"\n Enter the element you want to push - ";
                    cin>>element;
                    s1.store(element);
                    cout<<"\n Element Pushed";
                }
                else if(ch1==2)
                {
                    int element=0;
                    element = s1.retrive();
                    if(element==-1)
                    {
                        cout<<"\n Stack is Empty";
                    }
                    else
                    {
                        cout<<"\n Element Popped = "<<element;
                    }
                }
                else if(ch1==3)
                {
                    cout<<"\n Elements in stack from bottom to top:- ";
                    s1.view();
                }
                else if(ch1==4)
                {
                    break;
                }
                else
                {
                    cout<<"\n\n Wrong choice";
                }
                getch();
            }
        }
        else if(ch==2)
        {
            Queue q1;
            int ch1;
            while(1)
            {
                system("cls");
                cout<<"\n\n Queue Menu";
                cout<<"\n ^^^^^ ^^^^";
                cout<<"\n 1. Push Element";
                cout<<"\n 2. Pop Element";
                cout<<"\n 3. View Queue";
                cout<<"\n 4. Exit";
                cout<<"\n\n Enter your choice - ";
                cin>>ch1;
                if(ch1==1)
                {
                    int element;
                    cout<<"\n Enter the element you want to push - ";
                    cin>>element;
                    q1.store(element);
                    cout<<"\n Element Pushed";
                }
                else if(ch1==2)
                {
                    int element=0;
                    element = q1.retrive();
                    if(element==-1)
                    {
                        cout<<"\n Queue is Empty";
                    }
                    else
                    {
                        cout<<"\n Element Popped = "<<element;
                    }
                }
                else if(ch1==3)
                {
                    cout<<"\n Elements in queue from front to rear:- ";
                    q1.view();
                }
                else if(ch1==4)
                {
                    break;
                }
                else
                {
                    cout<<"\n\n Wrong choice";
                }
                getch();
            }
        }
        else if(ch==3)
        {
            exit(0);
        }
        else
        {
            cout<<"\n\n Wrong Choice";
        }
        getch();
    }
    return 0;
}