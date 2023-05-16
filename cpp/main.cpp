#include <iostream>

using namespace std;

// Scratch code for testing recursion

struct node
{
    int data;
    node * next;
};

void add_node(node * head, node * & new_node)
{
    if (!head)
        return;
    if (!head->next)
    {
        new_node->data = rand() % 10 + 1;
        new_node->next = nullptr;
        head->next = new_node;
    }
    return add_node(head->next, new_node);
}

int display_LLL(node * head)
{
   if (!head)
       return 0;
   cout << head->data << " ";
   if (!head->next)
       return 0;
   return display_LLL(head->next);
}

//int same as last(node * head)
//{
//   if (!head)
//       return 0;
//    if (!head->next)
//        //TODO
//        break;
//    return recursive_test(head->next);
//}

int main()
{
    // Populate testing array

    node * head = new node;
    head->data = rand() % 10 + 1;
    head->next = nullptr;

    for (int i=0; i < 100; i++)
    {
        node * new_node = new node;
        add_node(head, new_node);
    }

    display_LLL(head);

    return 0;
    
}
