class Solution
{
   private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
              tail = newNode;
        }
        else
        {
            tail -> next = newNode;
               tail = newNode;
        }
    }  
    void print(Node* head) {
        while(head != NULL) {
            cout << head -> data << " ";
   head = head -> next;
        }cout << endl;
    }
    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->arb != NULL) {
                cout << " head random data" << head -> arb ->data;
            }
            else
            {
             cout << " head random data: NULL";
            }
            head = head -> next;
        cout << endl;
        }
    }
    public:
    Node *copyList(Node *head)
    {

        Node* cloneHead = NULL;
     Node* cloneTail = NULL;
        
        Node* temp = head;
     while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
             temp = temp -> next;
        }
        Node* originalNode = head;
        Node* cloneNode = cloneHead;        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
    originalNode = next;
            
            next = cloneNode -> next;
         cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        originalNode = head;
       cloneNode = cloneHead;      
 while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else
    {
                cloneNode -> arb  = NULL;
            }
            cloneNode = cloneNode -> next;
    originalNode = originalNode -> next;
        }
        Node* original = head;
        Node* copy = cloneHead; 
         while (original && copy)
            {
                original->next =
        original->next? original->next->next : original->next;
         
        copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
            copy = copy->next;
            }
        return cloneHead;
    }
};