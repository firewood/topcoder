#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int d) {
            data=d;
            next=NULL;
        }
};

class Solution {
    public:
          Node* removeDuplicates(Node *head)
          {
            //Write your code here
              Node *prev = head;
              while (head != NULL) {
                  Node *n = head;
                  while (n->next != NULL) {
                      if (head->data == n->next->data) {
                          n->next = n->next->next;
                      } else {
                          n = n->next;
                      }
                  }
                  head = head->next;
              }
              return prev;
          }
          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL) {
                   head=p;  

               }
               else if(head->next==NULL) {
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL) {
                       start=start->next;
                   }
                   start->next=p;

               }
                return head;
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};
