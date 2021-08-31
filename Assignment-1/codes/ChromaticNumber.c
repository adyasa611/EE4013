#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
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
 
// Function to create the graph in the form of Adjacency List
struct Graph* createGraph(struct Edge edges[], int n)
{

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    for (int i = 0; i < N; i++) 
    {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++) //We add all the edges in this part.
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
void calculateChromaticNumber(struct Graph* graph)
{
    int allot[N];
    allot[0]  = 0; // We allot the first color to vertex 0
 
    for (int i = 1; i < N; i++) //The remaining colors are marked as unassigned
    {
        allot[i] = -1;
    }
    
    bool check[N];  // False means color is not assigned to an adjacent vertex.
    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 1; i < N; i++) // Start checking from vertex 1.
    {
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            if(allot[ptr->destination]!=-1)
            {
                check[allot[ptr->destination]]=true;
            }
            ptr = ptr->next;
        }
        int j;
        for (j = 0; j < N; j++)
            if (check[j] == false)
                break;
 
        allot[i] = j; 

        ptr = graph->head[i];
        while (ptr != NULL)
        {
            if(allot[ptr->destination]!=-1)
            {
                check[allot[ptr->destination]]=false;
            }
            ptr = ptr->next;
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

// Main Function 
int main(void)
{
    // Defining the edges in the graph
    struct Edge edges[] =
    {
        { 0, 1 }, {0,2}, {0,4}, {1,0}, {1,2}, {1,3}, {1,5}, {2,0}, {2,1}, {2,3}, {2,4}, {3,2}, {3,1}, {3,5}, {4,0}, {4,2}, {4,5}, {5,1}, {5,3}, {5,4}
    };
    // Number of edges
    int n = sizeof(edges)/sizeof(edges[0]); 
    struct Graph *graph = createGraph(edges, n);
    calculateChromaticNumber(graph);
    return 0;
}
