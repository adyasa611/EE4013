#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


 
// Number of vertices in the graph
#define N 6

// Structure to define Graph
struct Graph
{
    struct Node* head[N];
};

// Structure to define vertices
struct Node
{
    int destination;
    struct Node* next;
};

// Structure to define the edge 
struct Edge 
{
    int source, destination;
};

 
// Function to create the graph
struct Graph* createGraph(struct Edge edges[], int n)
{

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    for (int i = 0; i < N; i++) 
    {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int source = edges[i].source;
        int destination = edges[i].destination;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->destination = destination;
        newNode->next = graph->head[source];

        graph->head[source] = newNode;
    }
 
    return graph;
}

// Function to calculate Chromatic Number
void calculateChromaticNumber(int A[N][N])
{
    int allot[N];
    allot[0]  = 0;
 
    for (int i = 1; i < N; i++)
    {
        allot[i] = -1;
    }
    
    bool check[N];
    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 1; i < N; i++)
    {
        for(int j=0;j<N;j++)
        {
            if(A[i][j]==1)
            {
                if(allot[j]!=-1)
                {
                    check[allot[j]]=true;
                }
            }
        }
        int x;
        for (x = 0; x < N; x++)
            if (check[x] == false)
                break;
 
        allot[i] = x; 

        for(int j=0;j<N;j++)
        {
            if(A[i][j]==1)
            {
                if(allot[j]!=-1)
                {
                    check[allot[j]]=false;
                }
            }
        }
    }


    int count=0;
    int temp[N];
    for (int i = 0; i < N; i++)
    {
        temp[i]=-1;
    }
    for(int i=0;i<N;i++)
    {
        int k=allot[i];
        temp[k]++;
    }
    for(int i=0;i<N;i++)
    {
        if(temp[i]!=-1)
        {
            count++;
        }
    }
    printf("Chromatic Number: %d \n",count); // Print the Chromatic Number

}

void makeGraph(int A[N][N],int n, struct Edge edges[])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        A[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
        int source=edges[i].source;
        int destination =edges[i].destination;
        A[source][destination]=1;
    }
}
// Main Function 
int main(void)
{
    // Defining the edges in the graph
    struct Edge edges[] =
    {
        { 0, 1 }, {0,2}, {0,4}, {1,0}, {1,2}, {1,3}, {1,5}, {2,0}, {2,1}, {2,3}, {2,4}, {3,2}, {3,1}, {3,5}, {4,0}, {4,2}, {4,5}, {5,1}, {5,3}, {5,4}
    };

    clock_t begin = clock();

    // Number of edges
    int n = sizeof(edges)/sizeof(edges[0]); 
    int disp[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            disp[i][j]=0;
        }
    }
    makeGraph(disp,n,edges);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",disp[i][j]);
            // printf(" ");
        }
        printf("\n");
    }
    struct Graph *graph = createGraph(edges, n);
    calculateChromaticNumber(disp);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf(" \n %f", time_spent);
    printf("\n");
    return 0;
}