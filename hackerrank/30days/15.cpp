      Node* insert(Node *head,int data)
      {
          //Complete this method
          if (head == NULL) {
              head = new Node(data);
          } else {
              Node *next = head;
              while (next->next) {
                  next = next->next;
              }
              next->next = new Node(data);
          }
          return head;
      }
