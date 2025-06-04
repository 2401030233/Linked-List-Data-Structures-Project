# include <iostream>
using namespace std;
struct Node1
{
    int data1;
    Node1 *next1;
} *head1, *rear1;
void createNode1SLL (int x)
{
    Node1 *temp1=new Node1 ();
    temp1->data1=x;
    temp1->next1=nullptr;
    if (head1==nullptr)
    {
        head1=temp1;
        rear1=temp1;
    }
    else
    {
        rear1->next1=temp1;
        rear1=temp1;
    }
    cout<<"\nCreated node with data "<<x<<endl;
}
int getSizeSLL ()
{
    Node1 *temp1=head1;
    int num=0;
    while (temp1!=nullptr)
    {
        temp1=temp1->next1;
        num++;
    }
    return num;
}
void displayListSLL ()
{
    if (head1==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node1 *temp1=head1;
        while (temp1!=nullptr)
        {
            cout<<temp1->data1<<" -> ";
            temp1=temp1->next1;
        }
        cout<<"NULL\n";
    }
}
void insert_firstSLL (int x)
{
    Node1 *temp1=new Node1();
    temp1->data1=x;
    temp1->next1=nullptr;
    if (head1==nullptr)
    {
        head1=temp1;
        rear1=temp1;
    }
    else
    {
        temp1->next1=head1;
        head1=temp1;
    }
    cout<<"\nInserted node with data "<<x<<" at first..\n";
}
void insert_lastSLL (int x)
{
    Node1 *temp1=new Node1();
    temp1->data1=x;
    temp1->next1=nullptr;
    if (head1==nullptr)
    {
        head1=temp1;
        rear1=temp1;
    }
    else
    {
        rear1->next1=temp1;
        rear1=temp1;
    }
    cout<<"\nInserted node with data "<<x<<" at last..\n";
}
void insert_specifiedSLL (int pos, int x)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Position invalid!\n";
    }
    else
    {
        Node1 *temp1=new Node1();
        temp1->data1=x;
        int num=getSizeSLL();
        if (pos==1)
        {
            insert_firstSLL (x);
        }
        else if (pos<=num)
        {
            Node1 *n=head1, *p=head1;
            int i=1, num=getSizeSLL();
            while (i<=pos-1)
            {
                p=n;
                n=n->next1;
                i++;
            }
            p->next1=temp1;
            temp1->next1=n;
        }
        else if (pos==num+1)
        {
            insert_lastSLL (x);
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void delete_firstSLL ()
{
    if (head1==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head1->next1==nullptr)
    {
        delete head1;
        cout<<"\nDeleted head node!\n";
        head1=nullptr;
        rear1=nullptr;
    }
    else
    {
        int x;
        x=head1->data1;
        Node1 *temp1=head1;
        head1=head1->next1;
        delete temp1;
        temp1=nullptr;
        cout<<"\nFirst Node with data "<<x<<" deleted successfully!\n";
    }
}
void delete_lastSLL ()
{
    if (head1==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head1->next1==nullptr)
    {
        delete head1;
        cout<<"\nDeleted head node!\n";
        head1=nullptr;
        rear1=nullptr;
    }
    else
    {
        Node1 *temp1=head1;
        while (temp1->next1->next1!=nullptr)
        {
            temp1=temp1->next1;
        }
        Node1 *temp11=temp1->next1;
        int d=temp11->data1;
        temp1->next1=nullptr;
        delete temp11;
        temp11=nullptr;
        rear1=temp1;
        cout<<"\nDeleted last node with data "<<d<<endl;
    }
}
void delete_specifiedSLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Position invalid!\n";
    }
    else
    {
        int num=getSizeSLL();
        if (pos==1)
        {
            delete_firstSLL ();
        }
        else if (pos>1 && pos<num)
        {
            Node1 *n=head1, *p=head1, *temp1;
            n=n->next1;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next1;
                i++;
            }
            temp1=p->next1;
            int d=temp1->data1;
            p->next1=temp1->next1;
            delete temp1;
            temp1=nullptr;
            cout<<"\nNode with data "<<d<<" at position "<<pos<<" deleted successfully!\n";
        }
        else if (pos==num)
        {
            delete_lastSLL ();
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void findNode1ByValSLL (int x)
{
    if (head1==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        int num=0;
        bool flag=0;
        Node1 *temp1=head1;
        while (temp1!=nullptr)
        {
            num++;
            if (temp1->data1==x)
            {
                cout<<"\nNode with data "<<x<<" found at position "<<num<<endl;
                flag=1;
                break;
            }
            temp1=temp1->next1;
        }
        if (!flag)
        {
            cout<<"\nNode NOT found!\n";
        }
    }
}
void findNode1ByPositionSLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nInvalid position entered by user!\n";
    }
    else
    {
        if (head1==nullptr)
        {
            cout<<"\nList is empty!\n";
        }
        else
        {
            if (pos==1)
            {
                cout<<"\nData at position 1 : "<<head1->data1<<endl;
            }
            else
            {
                int num=getSizeSLL(), i=1;
                bool flag=0;
                if (pos<=num)
                {
                    Node1 *temp1=head1;
                    while (temp1!=nullptr)
                    {
                        if (pos==i)
                        {
                            cout<<"\nData "<<temp1->data1<<" found at position "<<i<<endl;
                            flag=1;
                            break;
                        }
                        i++;
                        temp1=temp1->next1;
                    }
                    if (!flag)
                    {
                        cout<<"\nNode NOT found!\n";
                    }
                }
                else
                {
                    cout<<"\nERROR : Position out of range!\n";
                }
            }
        }
    }
}
void displayMenuSLL ()
{
    cout<<"\nMenu :-\n";
    cout<<"\n1.Create Node\t2.Display List\t3.Insert node at first\n";
    cout<<"4.Insert node at last\t5.Insert node at specified position\t";
    cout<<"6.Delete node at first\n7.Delete node at last\t";
    cout<<"8.Delete node at specified position\t9.Search Node by Value\n";
    cout<<"10.Search node by position\t11.Display Size of list\t12.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, pos, d;
    do
    {
        displayMenuSLL ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput data to be inserted in new Node : ";
            cin>>d;
            createNode1SLL (d);
            break;
        case 2:
            cout<<"\nList : ";
            displayListSLL ();
            break;
        case 3:
            cout<<"\nInput data to be inserted in first Node : ";
            cin>>d;
            insert_firstSLL (d);
            break;
        case 4:
            cout<<"\nInput data to be inserted in last Node : ";
            cin>>d;
            insert_lastSLL (d);
            break;
        case 5:
            cout<<"\nInput position at which node is to be inserted : ";
            cin>>pos;
            cout<<"\nInput data to be inserted : ";
            cin>>d;
            insert_specifiedSLL (pos, d);
            break;
        case 6:
            delete_firstSLL ();
            break;
        case 7:
            delete_lastSLL ();
            break;
        case 8:
            cout<<"\nInput position of node for deletion : ";
            cin>>pos;
            delete_specifiedSLL (pos);
            break;
        case 9:
            cout<<"\nInput data of the node to be searched : ";
            cin>>d;
            findNode1ByValSLL (d);
            break;
        case 10:
            cout<<"\nInput position of node to be searched : ";
            cin>>pos;
            findNode1ByPositionSLL (pos);
            break;
        case 11:
            cout<<"\nSize of linked list : "<<getSizeSLL ()<<endl;
            break;
        case 12:
            cout<<"\n======[Exiting the program...]======\n";
            exit(0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=12);
    return 0;
}
