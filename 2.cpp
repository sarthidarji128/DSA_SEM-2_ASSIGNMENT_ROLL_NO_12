
#include<iostream>
#include<string>
using namespace std;

class Stack
{
    private:
        int top;
        int arr[100];
    public:
        Stack ()
        {
            top=-1;
            for(int i=0;i<5;i++)
            {
                arr[i]=0;
            }
        }

        bool isEmpty()
        {
            if(top==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull()
        {
            if(top==4)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        void push(int value)
        {
            if(isFull())
            {
                cout<<"Stack Is Full\n";
            }
            else
            {
                top++;
                arr[top]=value;
            }
        }

        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack Is Empty\n";
                return 0;
            }
            else
            {
                int popvalue=arr[top];
                arr[top]=0;
                top--;
                return popvalue;
            }

        }

        int count()
        {
            return (top+1);
        }

        int peek(int pos)
        {
            if(isEmpty())
            {
                cout<<"Stack Is Empty\n";
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }

        void Change(int pos, int val)
        {
            arr[pos]=val;
            cout<<"Value changed at location "<<pos<<endl;
        }

        void Display()
        {
            cout<<"\nAll value in the stack are\n";
            for(int i=4;i>=0;i--)
            {
                cout<<arr[i]<<endl;
            }
        }

};

int main()
{
    Stack s;
    int option,position,value;
    do{
        cout<<"\nSelect Options, Enter 0 to Exit\n";
        cout<<"1.push\n";
        cout<<"2.pop\n";
        cout<<"3.isEmpty\n";
        cout<<"4.isFull\n";
        cout<<"5.peek\n";
        cout<<"6.count\n";
        cout<<"7.change\n";
        cout<<"8.display\n\n";

        cin>>option;
        switch (option)
        {

        case 0:
            break;    
        case 1:
            cout<<"Enter an item to push in the stack\n";
            cin>>value;
            s.push(value);
            break;
        
        case 2:
            cout<<"Pop is done "<<s.pop()<<endl;
            break;
        case 3:
            if(s.isEmpty())
            {
                cout<<"Stack is empty\n";
            }
            else
            {
                cout<<"Stack is not empty\n";
            }
            break;

        case 4:
            if(s.isFull())
            {
                cout<<"Stack is full\n";
            }
            else
            {
                cout<<"Stack is not full\n";
            }
            break;

        case 5:
            cout<<"Enter position of item you want to peek\n";
            cin>>position;
            cout<<"Peek function is called \n"<<s.peek(position)<<endl;
            break;

        case 6:
            cout<<"Total count :"<<s.count()<<endl;
            break;

        case 7:
            cout<<"Change function called \n";
            cout<<"Enter position of the item you want to change :";
            cin>>position;
            cout<<endl;
            cout<<"Enter the value :";
            cin>>value;
            s.Change(position,value);
            break;
        
        case 8:
            s.Display();
            break;


        default:
            cout<<"Enter proper option number \n";
        }
    }
    while(option!=0);
    return 0;
}

