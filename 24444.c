    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    typedef struct node
    {
        int data;
        struct node* next;
    } node;

    typedef struct queue
    {
        struct node* first;
        struct node* last;
    } queue;

    node graph[100001];
    queue que;
    int visited[100001] = {0, };

    void initQueue(queue* q)
    {
        q->first = NULL;
        q->last = NULL;
    }

    void enqueue(queue* q, int data)
    {
        node* temp;
        temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        if (q->first == NULL)
        {
            q->first = temp;
            q->last = temp;
        }
        else
        {
            q->last->next = temp;
            q->last = temp;
        }
    }

    int isEmpty(queue* q)
    {
        if (q->first == NULL)
        {
            return 1;
        }
        return 0;
    }

    int dequeue(queue* q)
    {
        node* temp;
        temp = q->first;
        int data = temp->data;
        q->first = temp->next;
        free(temp);

        return data;
    }

    void pushGraph(node* graphNode, int a)
    {
        node* cur;
        cur = graphNode;

        node* temp = (node*)malloc(sizeof(node));
        temp->data = a;
        temp->next = NULL;
        
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }

    void sortGraph(node* graphNode)
    {
        int length = -1;
        int temp;
        node* cur;
        cur = graphNode;
        
        while(cur != NULL)
        {
            cur = cur->next;
            length++;
        }
        cur = graphNode;
        for (int i = 0; i < length; i++)
        {
            if (cur->next == NULL)
            {       
                break;
            }
            for (int j  = 0; j < length-1; j++) 
            {
                if (cur->data > cur->next->data)
                {
                    temp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = temp;
                }
                cur = cur->next;
            }
            cur = graphNode->next;
        }
    }

    void bfs(node graph[100001], int R, int N, int* visited, queue* q)
    {
        int visited_order[100001] = {0, };
        int cnt = 1;
        for (int v = 1; v <= N; v++)
        {
            if (v != R)
            {
                visited[v] = 0;
            }
            else
            {
                visited[v] = 1;
                visited_order[v] = cnt;
                cnt++;
                break;
            }
        }
        enqueue(q, R);
        int u = 0;
        int v = 0;
        node* cur;
        while(!isEmpty(q))
        {
            u = dequeue(q);
            cur = &graph[u];
            cur = cur->next;
            while (cur != NULL)
            {
                v = cur->data;
                if (visited[v] == 0)    // If not visited
                {
                    visited[v] = 1; // Then visit
                    visited_order[v] = cnt;
                    cnt++;
                    enqueue(q, v);
                }
                cur = cur->next;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            printf("%d\n", visited_order[i]);
        }
    }

    int main(void)
    {
        int N = 0;
        int M = 0;
        int R = 0;
        scanf("%d %d %d", &N, &M, &R);

        int col = 0;
        int row = 0;
        for (int i = 0; i < M; i++)
        {
            scanf(" %d %d", &row, &col);
            pushGraph(&graph[row], col);
            pushGraph(&graph[col], row);
        }
        
        for (int i = 1; i <= N; i++)
        {   
            sortGraph(&graph[i]);
        }
        
        initQueue(&que);
        
        bfs(graph, R, N, visited, &que);

        return 0;
    }