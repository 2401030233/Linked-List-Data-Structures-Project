# include <iostream>
using namespace std;
struct Node2
{
    Node2 *prev2;
    int data2;
    Node2 *next2;
} *head2, *rear2;
void createNode2DLL (int x)
{
    Node2 *temp2=new Node2();
    temp2->data2=x;
    temp2->next2=nullptr;
    temp2->prev2=nullptr;
    if (head2==nullptr)
    {
        head2=temp2;
        rear2=temp2;
    }
    else
    {
        rear2->next2=temp2;
        temp2->prev2=rear2;
        rear2=temp2;
    }
}
void displayListForwardDLL ()
{
    if (head2==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node2 *temp2=head2;
        while (temp2!=nullptr)
        {
            cout<<temp2->data2<<" -> ";
            temp2=temp2->next2;
        }
        cout<<"NULL\n";
    }
}
void displayListBackwardDLL ()
{
    if (head2==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node2 *temp2=rear2;
        while (temp2!=nullptr)
        {
            cout<<temp2->data2<<" -> ";
            temp2=temp2->prev2;
        }
        cout<<"NULL\n";
    }
}
void insert_firstDLL (int x)
{
    Node2 *temp2=new Node2 ();
    temp2->data2=x;
    temp2->next2=nullptr;
    temp2->prev2=nullptr;
    if (head2==nullptr)
    {
        head2=temp2;
        rear2=temp2;
    }
    else
    {
        temp2->next2=head2;
        head2->prev2=temp2;
        head2=temp2;
    }
    cout<<"\nInserted node with data "<<x<<endl;
}
void insert_lastDLL (int x)
{
    Node2 *temp2=new Node2 ();
    temp2->data2=x;
    temp2->next2=nullptr;
    temp2->prev2=nullptr;
    if (head2==nullptr)
    {
        head2=temp2;
        rear2=temp2;
    }
    else
    {
        rear2->next2=temp2;
        temp2->prev2=rear2;
        rear2=temp2;
    }
    cout<<"\nInserted node with data "<<x<<endl;
}
int getSizeDLL ()
{
    Node2 *temp2=head2;
    int num=0;
    while (temp2!=nullptr)
    {
        num++;
        temp2=temp2->next2;
    }
    return num;
}
void insert_specifiedDLL (int pos, int x)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        int num=getSizeDLL ();
        if (pos==1)
        {
            insert_firstDLL (x);
        }
        else if (pos>1 && pos<=num)
        {
            Node2 *temp2=new Node2(), *n=head2, *p=head2;
            int i=1;
            n=n->next2;
            while (i<pos-1 && n!=nullptr)
            {
                p=n;
                n=n->next2;
                i++;
            }
            p->next2=temp2;
            temp2->next2=n;
            temp2->prev2=p;
            n->prev2=temp2;
            cout<<"\nInserted node with data "<<x<<" at position "<<pos<<endl;
        }
        else if (pos==num+1)
        {
            insert_lastDLL (x);
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void delete_firstDLL ()
{
    if (head2==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete!\n";
    }
    else if (head2->next2==nullptr)
    {
        int d=head2->data2;
        delete head2;
        cout<<"\nDelete head node with data "<<d<<"!\n";
        head2=nullptr;
        rear2=nullptr;
    }
    else
    {
        Node2 *temp2=head2;
        int d=head2->data2;
        head2=head2->next2;
        delete temp2;
        head2->prev2=nullptr;
        cout<<"\nDeleted first node with data "<<d<<endl;
    }
}
void delete_lastDLL ()
{
    if (head2==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete!\n";
    }
    else if (head2->next2==nullptr)
    {
        int d=head2->data2;
        delete head2;
        cout<<"\nDeleted head node with data "<<d<<" !\n";
        head2=nullptr;
        rear2=nullptr;
    }
    else
    {
        int d=rear2->data2;
        Node2 *temp2=rear2;
        rear2=rear2->prev2;
        delete temp2;
        temp2=nullptr;
        rear2->next2=nullptr;
        cout<<"\nDeleted last node with value "<<d<<endl;
    }
}
void delete_specifiedDLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        int num=getSizeDLL ();
        if (pos==1)
        {
            delete_firstDLL ();
        }
        else if (pos>1 && pos<num)
        {
            Node2 *temp2, *n=head2, *p=head2;
            int i=1;
            n=n->next2;
            while (i<pos-1 && n!=nullptr)
            {
                p=n;
                n=n->next2;
                i++;
            }
            temp2=p->next2;
            int d=temp2->data2;
            p->next2=temp2->next2;
            if (temp2->next2!=nullptr)
            {
                temp2->next2->prev2=p;
            }
            delete temp2;
            temp2=nullptr;
            cout<<"\nDeleted node with data "<<d<<" at position "<<pos<<endl;
        }
        else if (pos==num)
        {
            delete_lastDLL ();
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void searchNode2ByValDLL (int n)
{
    if (head2==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node2 *temp2=head2;
        int pos=0;
        bool flag=0;
        while (temp2!=nullptr)
        {
            pos++;
            if (temp2->data2==n)
            {
                cout<<"\nNode with data "<<n<<" found at position "<<pos<<endl;
                flag=1;
                break;
            }
            temp2=temp2->next2;
        }
        if (!flag)
        {
            cout<<"\nNode NOT found!\n";
        }
    }
}
void SearchNode2ByPositionDLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position!\n";
    }
    else
    {
        int num=getSizeDLL ();
        if (pos>=1 && pos<=num)
        {
            int i=0;
            bool flag=0;
            Node2 *temp2=head2;
            while (temp2!=nullptr)
            {
                i++;
                if (pos==i)
                {
                    cout<<"\nNode found with position "<<i<<" and data "<<temp2->data2<<"\n";
                    flag=1;
                    break;
                }
                temp2=temp2->next2;
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
void deleteNode2ByValueDLL (int x)
{
    if (head2==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else
    {
        Node2 *temp2=head2;
        int i=0;
        bool flag=0;
        while (temp2!=nullptr)
        {
            i++;
            if (temp2->data2==x)
            {
                flag=1;
                delete_specifiedDLL (i);
            }
            temp2=temp2->next2;
        }
        if (!flag)
        {
            cout<<"\nNode NOT found for deletion!\n";
        }
    }
}
void displayMenuDLL ()
{
    cout<<"\nMenu :-\n";
    cout<<"\n1.Create Node\t2.Display List (Forward)\t";
    cout<<"3.Display List (Backward)\n4.Insert node at first\t";
    cout<<"5.Insert node at last\t6.Insert node at specified position\n";
    cout<<"7.Delete first node\t8.Delete last node\t9.Delete node at specified position\n";
    cout<<"10.Search Node by Value\t11.Search node by position\t";
    cout<<"12.Count Nodes\n13.Delete node by value\t14.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, d, pos;
    do
    {
        displayMenuDLL ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput data to be inserted in new Node : ";
            cin>>d;
            createNode2DLL (d);
            break;
        case 2:
            cout<<"\nForward : ";
            displayListForwardDLL ();
            break;
        case 3:
            cout<<"\nBackward : ";
            displayListBackwardDLL ();
            break;
        case 4:
            cout<<"\nInput data to be inserted in first node : ";
            cin>>d;
            insert_firstDLL (d);
            break;
        case 5:
            cout<<"\nInput data to be inserted in last node : ";
            cin>>d;
            insert_lastDLL (d);
            break;
        case 6:
            cout<<"\nInput position at which node is to be inserted : ";
            cin>>pos;
            cout<<"\nInput data to be inserted : ";
            cin>>d;
            insert_specifiedDLL (pos, d);
            break;
        case 7:
            delete_firstDLL ();
            break;
        case 8:
            delete_lastDLL ();
            break;
        case 9:
            cout<<"\nInput position of node for deletion : ";
            cin>>pos;
            delete_specifiedDLL (pos);
            break;
        case 10:
            cout<<"\nInput data of node to be searched : ";
            cin>>d;
            searchNode2ByValDLL (d);
            break;
        case 11:
            cout<<"\nInput position of node to be searched : ";
            cin>>pos;
            SearchNode2ByPositionDLL (pos);
            break;
        case 12:
            cout<<"\nSize of linked list : "<<getSizeDLL ()<<endl;
            break;
        case 13:
            cout<<"\nInput data of node to be deleted : ";
            cin>>d;
            deleteNode2ByValueDLL (d);
            break;
        case 14:
            cout<<"\n======[Exiting the program...]======\n";
            exit(0);
            break;
        default:
            cout<<"\nInput valid choice : ";
        }
    }
    while (ch!=14);
    return 0;
}
