# include <iostream>
using namespace std;
struct Node3
{
    int data3;
    Node3 *next3;
} *head3, *rear3;
void createNode3CLL (int x)
{
    Node3 *temp3=new Node3 ();
    temp3->data3=x;
    temp3->next3=nullptr;
    if (head3==nullptr)
    {
        head3=temp3;
        rear3=temp3;
        head3->next3=head3;
    }
    else
    {
        rear3->next3=temp3;
        rear3=temp3;
        rear3->next3=head3;
    }
}
void displayListCLL ()
{
    if (head3==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node3 *temp3=head3;
        while (temp3->next3!=head3)
        {
            cout<<temp3->data3<<" -> ";
            temp3=temp3->next3;
        }
        cout<<temp3->data3<<endl;
    }
}
int getSizeCLL ()
{
    Node3 *temp3=head3;
    int num=0;
    while (temp3->next3!=head3)
    {
        num++;
        temp3=temp3->next3;
    }
    return (num+1);
}
void insert_firstCLL (int x)
{
    Node3 *temp3=new Node3 ();
    temp3->data3=x;
    temp3->next3=nullptr;
    if (head3==nullptr)
    {
        head3=temp3;
        rear3=temp3;
        head3->next3=head3;
    }
    else
    {
        temp3->next3=head3;
        head3=temp3;
        rear3->next3=head3;
    }
    cout<<"\nInserted new Node with data "<<x<<" at first\n";
}
void insert_lastCLL (int x)
{
    Node3 *temp3=new Node3();
    temp3->data3=x;
    temp3->next3=nullptr;
    if (head3==nullptr)
    {
        head3=temp3;
        rear3=temp3;
        head3->next3=head3;
    }
    else
    {
        rear3->next3=temp3;
        rear3=temp3;
        rear3->next3=head3;
    }
    cout<<"\nInserted new Node with data "<<x<<" at last\n";
}
void insert_specifiedCLL (int pos, int x)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for insertion";
    }
    else
    {
        int num=getSizeCLL ();
        if (pos==1)
        {
            insert_firstCLL (x);
        }
        else if (pos>1 && pos<=num)
        {
            Node3 *temp3=new Node3 (), *n=head3->next3, *p=head3;
            temp3->data3=x;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next3;
                i++;
            }
            p->next3=temp3;
            temp3->next3=n;
            cout<<"\nInserted new Node with data "<<x<<" at position "<<pos<<endl;
        }
        else if (pos==num+1)
        {
            insert_lastCLL (x);
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void delete_lastCLL ()
{
    if (head3==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head3->next3==head3)
    {
        delete head3;
        cout<<"\nDeleted head node\n";
        head3=nullptr;
        rear3=nullptr;
    }
    else
    {
        Node3 *temp3=head3;
        while (temp3->next3->next3!=head3)
        {
            temp3=temp3->next3;
        }
        Node3 *temp31=temp3->next3;
        int d=temp31->data3;
        temp3->next3=head3;
        if (temp31!=nullptr)
        {
            temp31->next3=nullptr;
            delete temp31;
            temp31=nullptr;
        }
        rear3=temp3;
        cout<<"\nDeleted last node with data "<<d<<endl;
    }
}
void delete_firstCLL ()
{
    if (head3==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head3->next3==head3)
    {
        delete head3;
        cout<<"\nDeleted head node\n";
        head3=nullptr;
        rear3=nullptr;
    }
    else
    {
        Node3 *temp3=head3;
        int d=temp3->data3;
        head3=head3->next3;
        rear3->next3=head3;
        delete temp3;
        temp3=nullptr;
        cout<<"\nDeleted first node with data "<<d<<endl;
    }
}
void delete_specifiedCLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for deletion of node\n";
    }
    else
    {
        Node3 *temp3, *p=head3, *n=head3->next3;
        int num=getSizeCLL ();
        if (pos==1)
        {
            delete_firstCLL ();
        }
        else if (pos>1 && pos<num)
        {
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next3;
                i++;
            }
            temp3=p->next3;
            p->next3=temp3->next3;
            int d=temp3->data3;
            delete temp3;
            temp3=nullptr;
            cout<<"\nDeleted node with data "<<d<<" at position "<<pos<<" successfully!\n";
        }
        else if (pos==num)
        {
            delete_lastCLL ();
        }
        else
        {
            cout<<"\nERROR : Position out of range!\n";
        }
    }
}
void searchNode3ByValCLL (int x)
{
    if (head3==nullptr)
    {
        cout<<"\nList is empty!\n";
    }
    else
    {
        Node3 *temp3=head3;
        int i=1;
        bool flag=0;
        while (temp3->next3!=head3)
        {
            if (temp3->data3==x)
            {
                cout<<"\nNode containing data "<<x<<" found at position "<<i<<endl;
                flag=1;
                break;
            }
            i++;
            temp3=temp3->next3;
        }
        if (rear3->data3==x)
        {
            flag=1;
            cout<<"\nNode containing data "<<x<<" found at position "<<getSizeCLL ()<<endl;
        }
        if (!flag)
        {
            cout<<"\nNode NOT found!\n";
        }
    }
}
void searchNode3ByPositionCLL (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (head3==nullptr)
        {
            cout<<"\nList is empty!\n";
        }
        else
        {
            int num=getSizeCLL ();
            if (pos>=1 && pos<=num)
            {
                Node3 *temp3=head3;
                int i=1;
                bool flag=0;
                while (temp3->next3!=head3 && temp3!=nullptr)
                {
                    if (pos==i)
                    {
                        cout<<"\nNode at position "<<pos<<" containing data "<<temp3->data3<<" found!\n";
                        flag=1;
                        break;
                    }
                    temp3=temp3->next3;
                    i++;
                }
                if (temp3==rear3)
                {
                    flag=1;
                    cout<<"\nNode at position "<<getSizeCLL ()<<" containing data "<<temp3->data3<<" found!\n";
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
void deleteNode3ByValueCLL (int x)
{
    if (head3==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete!\n";
    }
    else
    {
        Node3 *temp3=head3;
        int num=0;
        bool flag=0;
        while (temp3->next3!=head3)
        {
            num++;
            if (temp3->data3==x)
            {
                flag=1;
                delete_specifiedCLL (num);
                cout<<"\nNode at position "<<num<<" containing data "<<temp3->data3<<" deleted successfully!\n";
                break;
            }
            temp3=temp3->next3;
        }
        if (rear3->data3==x)
        {
            flag=1;
            delete_lastCLL ();
        }
        if (!flag)
        {
            cout<<"\nNode NOT found!\n";
        }
    }
}
void displayMenuCLL ()
{
    cout<<"\nMenu :-\n";
    cout<<"\n1.Create Node\t2.Display List\t3.Insert node at first\n";
    cout<<"4.Insert node at last\t5.Insert node at specified position\t";
    cout<<"6.Delete first node\n7.Delete last node\t8.Delete node at specified position\t";
    cout<<"9.Search node by value\n10.Search node by position\t11.Count Nodes\t";
    cout<<"12.Delete node by value\n13.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, d, pos;
    do
    {
        displayMenuCLL ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput data to be inserted in new Node : ";
            cin>>d;
            createNode3CLL (d);
            break;
        case 2:
            cout<<"\nCircular Linked list : ";
            displayListCLL ();
            break;
        case 3:
            cout<<"\nInput data to be inserted in first Node : ";
            cin>>d;
            insert_firstCLL (d);
            break;
        case 4:
            cout<<"\nInput data to be inserted in last Node : ";
            cin>>d;
            insert_lastCLL (d);
            break;
        case 5:
            cout<<"\nInput position at which node is to be inserted : ";
            cin>>pos;
            cout<<"\nInput data to be inserted : ";
            cin>>d;
            insert_specifiedCLL (pos, d);
            break;
        case 6:
            delete_firstCLL ();
            break;
        case 7:
            delete_lastCLL ();
            break;
        case 8:
            cout<<"\nInput position at which node is to be deleted : ";
            cin>>pos;
            delete_specifiedCLL (pos);
            break;
        case 9:
            cout<<"\nInput value of node to be searched : ";
            cin>>d;
            searchNode3ByValCLL (d);
            break;
        case 10:
            cout<<"\nInput position of node to be searched : ";
            cin>>pos;
            searchNode3ByPositionCLL (pos);
            break;
        case 11:
            cout<<"\nSize of linked list : "<<getSizeCLL ()<<endl;
            break;
        case 12:
            cout<<"\nInput value of node to be deleted : ";
            cin>>d;
            deleteNode3ByValueCLL (d);
            break;
        case 13:
            cout<<"\n======[Exiting the program...]======\n";
            exit(0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=13);
    return 0;
}
