/*
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.
*/

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        Node* temp = head, *nex = head;
        while(temp && nex)
        {
            for(int i=1; temp && i<M; ++i)
                temp = temp->next;
                
            nex = temp;
            for(int i=0; nex && i<=N; ++i)
                nex = nex->next;
            if(temp)
                temp->next = nex;
            temp = nex;
        }
    }
};