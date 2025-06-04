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
    cout<<"\n=========================";
    cout<<"\nSingly Linear LL Menu :-\n";
    cout<<"\n1.Create Node\t2.Display List\t3.Insert node at first\n";
    cout<<"4.Insert node at last\t5.Insert node at specified position\t";
    cout<<"6.Delete node at first\n7.Delete node at last\t";
    cout<<"8.Delete node at specified position\t9.Search Node by Value\n";
    cout<<"10.Search node by position\t11.Display Size of list\t12.Exit\n";
    cout<<"\nInput choice : ";
}
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
    cout<<"\n=========================";
    cout<<"\nDoubly Linear LL Menu :-\n";
    cout<<"\n1.Create Node\t2.Display List (Forward)\t";
    cout<<"3.Display List (Backward)\n4.Insert node at first\t";
    cout<<"5.Insert node at last\t6.Insert node at specified position\n";
    cout<<"7.Delete first node\t8.Delete last node\t9.Delete node at specified position\n";
    cout<<"10.Search Node by Value\t11.Search node by position\t";
    cout<<"12.Count Nodes\n13.Delete node by value\t14.Exit\n";
    cout<<"\nInput choice : ";
}
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
    cout<<"\n============================";
    cout<<"\nSimple Circular LL Menu :-\n";
    cout<<"\n1.Create Node\t2.Display List\t3.Insert node at first\n";
    cout<<"4.Insert node at last\t5.Insert node at specified position\t";
    cout<<"6.Delete first node\n7.Delete last node\t8.Delete node at specified position\t";
    cout<<"9.Search node by value\n10.Search node by position\t11.Count Nodes\t";
    cout<<"12.Delete node by value\n13.Exit\n";
    cout<<"\nInput choice : ";
}
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
    cout<<"\n============================";
    cout<<"\nDoubly Circular LL Menu :-\n";
    cout<<"\n1.Create Node\t2.Display List (Forward)\t";
    cout<<"3.Display List (Backward)\n4.Insert Node at first\t";
    cout<<"5.Insert Node at last\t6.Insert Node at specified position\n";
    cout<<"7.Delete first node\t8.Delete last node\t9.Delete specified node\n";
    cout<<"10.Search Node by Value\t11.Search Node by position\t12.Count Nodes\n";
    cout<<"13.Delete node by value\t14.Exit\n";
    cout<<"\nInput choice : ";
}
void displayAllListMenu ()
{
    cout<<"\nAll List Menu :-\n";
    cout<<"\n1.Singly Linear Linked List\t2.Doubly Linear Linked List\n3.Simple Circular Linked List\t4.Doubly Circular Linked List\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int choice;
    displayAllListMenu ();
    cin>>choice;
    switch (choice)
    {
    case 1:
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
        break;
    }
    case 2:
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
        break;
    }
    case 3:
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
        break;
    }
    case 4:
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
        break;
    }
    default:
        cout<<"\nInput valid choice!\n";
    }
    return 0;
}
