#include<stdio.h>
#define MAX 50

using namespace std;

class Queue
{
private:
    int q[MAX];
    int f,r;
public:
    Queue()
    {
        f = -1;
        r = -1;
    }

    bool IsEmpty()
    {
        if(f==-1 && r==-1)
            return true;
        return false;
    }

    bool IsFull()
    {
        if(r==MAX-1)
            return true;
        return false;
    }

    void enq(int elem)
    {
        if(IsFull())
        {
            printf("\nqueue full!\n");
            return;
        }
        else if(IsEmpty())
        {
            f++;
            r++;
        }
        else r++;
        q[r] = elem;

    }
    void deq()
    {
        if(IsEmpty())
            printf("\nqueue empty!\n");
        else f++;
    }
    int peek()
    {
        if(IsEmpty())
            return -1;
        return q[f];
    }
    int sizeq()
    {
        if(IsEmpty())
            return 0;
        return r-f+1;
    }
    void display()
    {
        printf("Queue: ");
        for(int i=f;i<=r;i++)
            printf("%d",q[i]);
        printf("\n");
    }
};

int main()
{
    Queue q;
    int n,elem;
    printf("enter n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter elem: ");
        scanf("%d",&elem);
        q.enq(elem);
        q.display();
    }
    printf("\nDeque\n");
    for(int i=0;i<n;i++)
    {
        q.display();
        q.deq();
    }
    return 0;
}
