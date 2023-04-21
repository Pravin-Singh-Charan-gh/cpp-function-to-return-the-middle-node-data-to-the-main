#include <iostream>
using namespace std;

class linklist
{
private :
    struct node {
        int data;
        node *next;
    }*head;

public:
    linklist()
    {
        head=NULL;
    }

    void append(int num)
    {
        node *t=head,*temp;
        if(head==NULL) {
            t=new node;
            t->data=num;
            t->next=NULL;
            head=t;
        }

        else {
            while(t->next!=NULL)
                t=t->next;

            temp=new node;
            temp->data=num;
            temp->next=NULL;
            t->next=temp;
        }
    }
    int getmid()
    {
        node *slow=head,*fast;
        if(head==NULL)
            return -1;
        int i;

        for( fast =head ,i=1 ; fast!=NULL ; fast=fast->next ,i++) {
            if(i%2==0)
                slow=slow->next;
        }
        return slow->data;
        if(i-1%2==0)
            return slow->next->data;
        else return slow->data;
    }

    void display()
    {
        node *t=head;
        while(t!=NULL) {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    ~linklist()
    {
        node *t;
        while(head!=NULL) {
            t=head->next;
            delete head;
            head=t;
        }
    }
};

int main()
{
    linklist A;
    A.append(5);
    A.append(9);
    A.append(46);
    A.append(11);
    A.append(53);
    A.append(45);
    cout<<"Linked List:\n";
    A.display();
    cout<<"Middle Term: "<<A.getmid();
}
