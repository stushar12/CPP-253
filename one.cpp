Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    
    while(curr != NULL)
    {
        Node *next = curr->next;
        
        curr->next = prev;
        prev = curr;
        
        curr = next;
    }
    
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first=reverse(first);
    second=reverse(second);
    
    int carry = 0, sum = 0;

    Node* start = NULL;
    Node* end = NULL;

while(first != NULL || second != NULL)
{
int a = (first != NULL)?first -> data:0;
int b = (second != NULL)?second -> data:0;

sum = carry + (a + b);
carry = (sum >= 10)?1:0;
sum = sum % 10;

if(start == NULL)
{
start = new Node(sum);
end = start;
}
else
{
end -> next = new Node(sum);
end = end -> next;
}

if(first != NULL)
first = first -> next;

if(second != NULL)
second = second -> next;
}

if(carry > 0)
end -> next = new Node(carry);

start = reverse(start);

return start;
}