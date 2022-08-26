class Node{
    public:
        int val;
        Node* next;
    
    Node(int d){
        val = d;
        next = NULL;
    }
    Node(int d,Node* next){
        this->val = d;
        this->next = next;
    }
    
    
    ~Node(){};
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        Node* cur = head;
        while(cur != NULL && index > 0) {
            cur = cur->next;
            index--;
        }
        return cur ? cur->val : -1;
    }
    
    void addAtHead(int val) {
        Node* newhead = new Node(val,head);
        head = newhead;
        
        if(tail==NULL)
            tail = head;
    }
    
    void addAtTail(int val) {
        Node* newtail = new Node(val);
        if (tail != NULL) {
            tail->next = newtail;
            tail = newtail;
        }
        else {
            tail = newtail;
            head = tail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        Node* cur = head;
        while(cur!=NULL && index > 1) {
            cur = cur->next;
            index--;
        }
        if (cur != NULL) {
            Node* newnode = new Node(val);
            newnode->next = cur->next;
            cur->next = newnode;
            if (cur == tail){
                tail = newnode;
            }   
        }
    }
  void deleteAtIndex(int index) {
        Node* cur = head;
        Node* prev = nullptr;
        while(index > 0 && cur) {
            prev = cur;
            cur = cur->next;
            index--;
        }
        if (cur) {
            if (cur == tail) {
                if (prev) prev->next = nullptr;
                tail = prev;
            }
            if (cur == head) {
                head = head->next;
            }
            else
                prev->next = cur->next;
        }

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */