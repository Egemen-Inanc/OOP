#include <iostream>
#include <cstdlib>
using namespace std;

class my_List;
void make_node(my_List*, int);
class my_List
{
public:
    
    struct Node{
        int data;
        Node* next;
    }*head;
    
    
    my_List()
    {
        head = 0;
    }
    
    
    int Size()
    {
        int count = 0;
        Node * tmp1 = head;
        while(tmp1 != 0)
        {
            count++;
            tmp1 = tmp1->next;
        }
        return count;
    }


    
    void addNode(int x,int y)// x is position, y is the data
        {
            if (x < 1 || x > Size()+ 1)
            {
                cout << "Invalid position entered!" << endl;
                terminate();
            }    
        
            else if(x == 1)
            {
                Node *tmp = new Node;
                tmp -> data = y;
                tmp -> next = head;
                head = tmp;
            }
            else
            {
                Node *prev = head;
                Node * tmp1 = head;
                for(int i = 2; i< x; i++)
                {
                    prev = prev->next;
                }
                for(int i = 1; i< x; i++)
                {
                    tmp1 = tmp1->next;
                }
                Node* tail = new Node;
                tail->data = y;
                prev->next = tail;
                tail->next = tmp1;
            }
            
        }
        

    
    void Display()
    {
        Node* tmp1 = head;
        while(tmp1 != 0)
        {
            cout<<tmp1->data<<"\n";
            tmp1 = tmp1->next;
        }
        if (tmp1 == 0) {
            cout<<"End Of List"<< endl;
        }
    }
};

void make_node(my_List* list, int n)
   {
    
    my_List::Node* tmp = new my_List::Node;
       tmp->data = n;
       tmp->next = 0;
    my_List::Node* tmp1 = list->head;

       if(list->head == 0)
       {
           list->head = tmp;
           return;
       }
        while(tmp1->next != 0)
        {
            tmp1 = tmp1->next;
        }
        tmp1->next=tmp;
   }

int main()
{
    my_List test;
    make_node(&test, 3);
    make_node(&test, 2);
    make_node(&test, 3);
    make_node(&test, 9);
    make_node(&test, 3);
    make_node(&test, 3);
    test.Display();
    test.addNode(1, 1692);
    test.Display();
    test.addNode(-1, 12);
    test.Display();
    test.Display();
    test.addNode(22, 30);
    test.Display();
    test.addNode(3, 1692);
    test.Display();
}