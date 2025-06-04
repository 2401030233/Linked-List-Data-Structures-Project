# include <iostream>
using namespace std;
struct Node4
{
    Node4 *prev4;
    int data4;
    Node4 *next;
} *head4, *rear4;
void createNode4DCLL (int x)
{
    Node4 *temp4=new Node4 ();
    temp4->data4=x;
    temp4->next=nullptr;
    temp4->prev4=nullptr;
    if (head4==nullptr)
    {
        head4=temp4;
        rear4=temp4;
        head4->next=rear4;
        rear4->prev4=head4;
    }
    else
    {
        rear4->next=temp4;
        temp4->prev4=rear4;
        rear4=temp4;
        rear4->next=head4;
        head4->prev4=rear4;
    }
}
int getSizeDCLL ()
{
    Node4 *temp4=head4;
    int num=0;
    while (temp4->next!=head4)
    {
        num++;
        temp4=temp4->next;
    }
    return num+1;
}
void displayListForwardDCLL ()
{
    if (head4==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node4 *temp4=head4;
        while (temp4->next!=head4)
        {
            cout<<temp4->data4<<" -> ";
            temp4=temp4->next;
        }
        cout<<temp4->data4<<endl;
    }
}
void displayListBackwardDCLL ()
{
    if (head4==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node4 *temp4=rear4;
        while (temp4->prev4!=rear4)
        {
            cout<<temp4->data4<<" -> ";
            temp4=temp4->prev4;
        }
        cout<<temp4->data4<<endl;
    }
}
void insert_firstDCLL (int x)
{
    Node4 *temp4=new Node4 ();
    temp4->data4=x;
    temp4->next=nullptr;
    temp4->prev4=nullptr;
    if (head4==nullptr)
    {
        head4=temp4;
        rear4=temp4;
        rear4->next=head4;
        head4->prev4=rear4;
        head4=rear4;
    }
    else
    {
        temp4->next=head4;
        head4->prev4=temp4;
        head4=temp4;
        rear4->next=head4;
        head4->prev4=rear4;
    }
    cout<<"\nNode with data "<<x<<" inserted at first position\n";
}
void insert_lastDCLL (int x)
{
    Node4 *temp4=new Node4 ();
    temp4->data4=x;
    temp4->next=nullptr;
    if (head4==nullptr)
    {
        head4=temp4;
        rear4=temp4;
        head4->next=head4;
        rear4->prev4=head4;
    }
    else
    {
        rear4->next=temp4;
        temp4->prev4=rear4;
        rear4=temp4;
        head4->prev4=rear4;
        rear4->next=head4;
    }
    cout<<"\nNode with data "<<x<<" inserted at last position\n";
}
void insert_specifiedDCLL (int pos, int d)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        int num=getSizeDCLL ();
        if (pos==1)
        {
            insert_firstDCLL (d);
        }
        else if (pos>1 && pos<=num)
        {
            Node4 *temp4=new Node4 (), *p=head4, *n=head4->next;
            temp4->data4=d;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next;
                i++;
            }
            p->next=temp4;
            temp4->prev4=p;
            temp4->next=n;
            n->prev4=temp4;
            cout<<"\nNode with data "<<temp4->data4<<" inserted successfully at position "<<pos<<endl;
        }
        else if (pos==num+1)
        {
            insert_lastDCLL (d);
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void delete_firstDCLL ()
{
    if (head4==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head4->next==head4)
    {
        delete head4;
        cout<<"\nDeleted head node!\n";
        head4=nullptr;
        rear4=nullptr;
    }
    else
    {
        Node4 *temp4=head4;
        head4=head4->next;
        int d=temp4->data4;
        delete temp4;
        head4->prev4=rear4;
        rear4->next=head4;
        temp4=nullptr;
        cout<<"\nDeleted first node with data "<<d<<endl;
    }
}
void delete_lastDCLL ()
{
    if (head4==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else if (head4->next==head4)
    {
        delete head4;
        cout<<"\nDeleted head node!\n";
        head4=nullptr;
        rear4=nullptr;
    }
    else
    {
        Node4 *temp4=rear4->prev4;
        Node4 *temp41=rear4;
        int d=temp41->data4;
        temp4->next=rear4->next;
        head4->prev4=rear4->prev4;
        rear4=temp4;
        delete temp41;
        temp41=nullptr;
        cout<<"\nDeleted last node with data"<<d<<endl;
    }
}
void delete_specifiedDCLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        int num=getSizeDCLL ();
        if (pos==1)
        {
            delete_firstDCLL ();
        }
        else if (pos>1 && pos<num)
        {
            Node4 *temp4, *n=head4->next, *p=head4;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next;
                i++;
            }
            temp4=p->next;
            p->next=temp4->next;
            temp4->next->prev4=p;
            int d=temp4->data4;
            delete temp4;
            temp4=nullptr;
            cout<<"\nDeleted node with data "<<d<<" at position "<<pos<<" successfully!\n";
        }
        else if (pos==num)
        {
            delete_lastDCLL ();
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void searchNode4ByValDCLL (int d)
{
    if (head4==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node4 *temp4=head4;
        bool flag=0;
        int i=0;
        while (temp4->next!=head4 && temp4!=nullptr)
        {
            if (temp4->data4==d)
            {
                flag=1;
                cout<<"\nNode with data "<<temp4->data4<<" found at position "<<i+1<<endl;
                break;
            }
            i++;
            temp4=temp4->next;
        }
        if (rear4->data4==d)
        {
            flag=1;
            temp4=rear4;
            cout<<"\nNode with data "<<rear4->data4<<" found at position "<<getSizeDCLL ()<<endl;
        }
        if (!flag)
        {
            cout<<"\nNode NOT found!\n";
        }
    }
}
void searchNode4ByPositionDCLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        int num=getSizeDCLL ();
        if (pos>=1 && pos<=num)
        {
            Node4 *temp4=head4;
            int i=1;
            bool flag=0;
            while (temp4->next!=head4 && temp4!=nullptr)
            {
                if (i==pos)
                {
                    flag=1;
                    cout<<"\nNode at position "<<pos<<" containing data "<<temp4->data4<<" found!\n";
                    break;
                }
                i++;
                temp4=temp4->next;
            }
            if (pos==num)
            {
                flag=1;
                cout<<"\nNode at position "<<getSizeDCLL ()<<" containing data "<<temp4->data4<<" found!\n";
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
void deleteNode4ByValDCLL (int x)
{
    if (head4==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        int num=getSizeDCLL (), i=1;
        bool flag=0;
        Node4 *temp4=head4;
        while (temp4->next!=head4 && temp4!=nullptr)
        {
            if (temp4->data4==x)
            {
                flag=1;
                delete_specifiedDCLL (i);
                break;
            }
            temp4=temp4->next;
            i++;
        }
        if (rear4->data4==x)
        {
            delete_lastDCLL ();
            flag=1;
        }
        if (!flag)
        {
            cout<<"\nNode NOT found!\n";
        }
    }
}
void displayMenuDCLL ()
{
    cout<<"\nMenu :-\n";
    cout<<"\n1.Create Node\t2.Display List (Forward)\t";
    cout<<"3.Display List (Backward)\n4.Insert Node at first\t";
    cout<<"5.Insert Node at last\t6.Insert Node at specified position\n";
    cout<<"7.Delete first node\t8.Delete last node\t9.Delete specified node\n";
    cout<<"10.Search Node by Value\t11.Search Node by position\t12.Count Nodes\n";
    cout<<"13.Delete node by value\t14.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, pos, d;
    do
    {
        displayMenuDCLL ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput data to be inserted in new Node : ";
            cin>>d;
            createNode4DCLL (d);
            break;
        case 2:
            cout<<"\nForward : ";
            displayListForwardDCLL ();
            break;
        case 3:
            cout<<"\nBackward : ";
            displayListBackwardDCLL ();
            break;
        case 4:
            cout<<"\nInput data to be inserted in first node : ";
            cin>>d;
            insert_firstDCLL (d);
            break;
        case 5:
            cout<<"\nInput data to be inserted in last node : ";
            cin>>d;
            insert_lastDCLL (d);
            break;
        case 6:
            cout<<"\nInput position at which node is to be inserted : ";
            cin>>pos;
            cout<<"\nInput data to be inserted : ";
            cin>>d;
            insert_specifiedDCLL (pos, d);
            break;
        case 7:
            delete_firstDCLL ();
            break;
        case 8:
            delete_lastDCLL ();
            break;
        case 9:
            cout<<"\nInput position of node to be deleted : ";
            cin>>pos;
            delete_specifiedDCLL (pos);
            break;
        case 10:
            cout<<"\nInput data of node to be searched : ";
            cin>>d;
            searchNode4ByValDCLL (d);
            break;
        case 11:
            cout<<"\nInput position of node to be searched : ";
            cin>>pos;
            searchNode4ByPositionDCLL (pos);
            break;
        case 12:
            cout<<"\nSize of linked list : "<<getSizeDCLL ()<<endl;
            break;
        case 13:
            cout<<"\nInput data of node to be deleted : ";
            cin>>d;
            deleteNode4ByValDCLL (d);
            break;
        case 14:
            cout<<"\n======[Exiting the program...]======\n";
            exit(0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=14);
    return 0;
}
