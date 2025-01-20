/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(head1==NULL){return head2;}
        if(head2==NULL){return head1;}
        struct Node*temp1,*temp2;
        temp1=head1;
        temp2=head2;
        struct Node*head,*list;
        head=NULL;
        list=NULL;
        if(temp1->data<=temp2->data){
            head=list=temp1;
            temp1=temp1->next;
        }
        else{
            head=list=temp2;
            temp2=temp2->next;
        }
        while(temp1&&temp2){
            if(temp1->data<=temp2->data){
                list->next=temp1;
                list=temp1;
                temp1=temp1->next;
            }
            else{
                list->next=temp2;
                list=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1){list->next=temp1;}
        else{list->next=temp2;}
        return head;
    }
};
