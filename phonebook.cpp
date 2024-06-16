#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct node //build node structure
{
    string name, number;
    node *next;
};

node *head = NULL, *newnode, *temp;
void Cre_node() //create new node
{
    newnode = new node;
    cout<<"Enter Name ";
    cin>>newnode->name;
    cout<<"Enter Number ";
    cin>>newnode->number;
    cout<<"\n";
    newnode->next  = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }

}

 int length =0;

void display()
{

    if(head==NULL){
        cout<<"Contact list is empty ";
    }
    else{
        node *trav = head;
        while(trav != NULL)
        {
            cout<<"\n\t\tFull name "<<trav->name<<endl;
            cout<<"\t\tPhone number "<<trav->number<<endl;
            cout<<"\n";
            trav = trav->next;
            length++;

        }
        cout<<"Total contact in list = "<<length<<endl;
        cout<<"\n";
    }
}

void at_given()
{
    int pos;
    node *next_node;
    temp = head;
    cout<<"Enter desired position to delete contact "<<endl;
    cin>>pos;
    if(head == NULL)
    {
        cout<<"Position is empty "<<endl;
    }
    else if(pos > length)
    {
        cout<<"Invalid Position "<<endl;
    }
    else if(pos==0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout<<"contact has been deleted "<<endl;
    }
    else{
        for(int i=1;i<pos;i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"contact has been deleted "<<endl;
    }
}

void menu()
{
    cout<<"Enter 1 to add contact "<<endl;
    cout<<"Enter 2 to display all contact "<<endl;
    cout<<"Enter 3 to search contact "<<endl;
    cout<<"Enter 4 to delete contact "<<endl;
    cout<<"Enter 5 to clear all contact \n\n"<<endl;
}

void search_con()
{
    node *search_node = head;
    string srch;
    int count = 1;
    cout<<"Enter your desired contact ";
    cin>>srch;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nList is empty"<<endl;
    }
    else{
        while(search_node != NULL)
        {
            if(srch == search_node->name || srch == search_node->number)
            {
                cout<<"\n\t\tFull name: "<<search_node->name<<endl;;
                cout<<"\t\tPhone Number: "<<search_node->number<<endl;
                found = true;
                break;
            }
            search_node = search_node->next;
            count++;
        }
    }
    if(found==true)
    {

        cout<<"\t\tIndex of contact: "<<count<<endl;
    }

    else{
        cout<<"desired contact not found "<<endl;
    }
}

void clr_all()
{
    if(head==NULL){
        cout<<"Contact list is empty ";
    }
    else{
        temp = head;
        while(head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"\n\tAll contact list has been deleted "<<endl;
    }
}

int main()
{
    int op;
    while(true)
    {
        menu();
        cin>>op;
        switch(op)
        {
        case 1:
            Cre_node();
            break;
        case 2:
            length = 0;
            display();
            break;
        case 3:
            search_con();
            break;
        case 4:
            at_given();
            break;
        case 5:
            clr_all();
            break;
        default:
            cout<<"Invalid Option "<<endl;
        }
    }
}

















