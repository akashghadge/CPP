/*
Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

Examples:

Input: N = 10, E = 13, Below is the given graph:



Output: 1 1 2 2 2 3 4 5 2 6
Explanation:
Start the jobs 1 and 2 at the beginning and complete them at 1 unit of time.
Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for jobs 3, 4, and 5 and 2nd job for job 9). So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly,
Job 6 can only be done after 3rd and 4th jobs are done. So, start it at 2nd unit of time and complete it at 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at 3rd unit of time and complete it at 4th unit of time.
Job 8 can only be done after 4th, 5th, and 7th jobs are done. So, start it at 4th unit of time and complete it at 5th unit of time.
Job 10 can only be done after the 8th job is done. So, start it at 5th unit of time and complete it at 6th unit of time.

Input: N = 7, E = 7, Below is the given graph:



Output: 1 2 3 3 3 4 4
Explanation:
Start the Job 1 at the beginning and complete it at 1st unit of time.
The job 2 can only be done after 1st Job is done. So, start it at 1st unit of time and complete it at 2nd unit of time.
Since, Job 3, 4, and 5 have the only dependency on 2nd Job. So, start these jobs at 2nd unit of time and complete these at 3rd unit of time.
The Job 6 can only be done after the 3rd and 4th Job is done. So, start it at 3rd unit of time and complete it at 4th unit of time.
The Job 7 can only be done after the 5th Job is done. So, start it at 3rd hour and complete it at 4th unit of time.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach: The job can be started only if all the jobs that are prerequisites of the job that are done. Therefore, the idea is to use Topological Sort for the given network. Below are the steps:

Finish the jobs that are not dependent on any other job.
Create an array inDegree[] to store the count of the dependent node for each node in the given network.
Initialize a queue and push all the vertex whose inDegree[] is 0.
Initialize the timer to 1 and store the current queue size(say size) and do the following:
Pop the node from the queue until the size is 0 and update the finishing time of this node to the timer.
While popping the node(say node U) from the queue decrement the inDegree of every node connected to it.
If inDegree of any node is 0 in the above step then insert that node in the queue.
Increment the timer after all the above steps.
Print the finishing time of all the nodes after we traverse every node in the above step.
Below is the implementation of the above approach:


*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

// Adjacency List to store the graph
vector<int> graph[maxN];

// Array to store the in-degree of node
int indegree[maxN];

// Array to store the time in which
// the job i can be done
int job[maxN];

// Function to add directed edge
// between two vertices
void addEdge(int u, int v)
{
    // Insert edge from u to v
    graph[u].push_back(v);

    // Increasing the indegree
    // of vertex v
    indegree[v]++;
}

// Function to find the minimum time
// needed by each node to get the task
void printOrder(int n, int m)
{
    // Find the topo sort order
    // using the indegree approach

    // Queue to store the
    // nodes while processing
    queue<int> q;

    // Pushing all the vertex in the
    // queue whose in-degree is 0

    // Update the time of the jobs
    // who don't require any job to
    // be completed before this job
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            job[i] = 1;
        }
    }

    // Iterate until queue is empty
    while (!q.empty())
    {

        // Get front element of queue
        int cur = q.front();

        // Pop the front element
        q.pop();

        for (int adj : graph[cur])
        {

            // Decrease in-degree of
            // the current node
            indegree[adj]--;

            // Push its adjacent elements
            if (indegree[adj] == 0)
            {
                job[adj] = job[cur] + 1;
                q.push(adj);
            }
        }
    }

    // Print the time to complete
    // the job
    for (int i = 1; i <= n; i++)
        cout << job[i] << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    // Given Nodes N and edges M
    int n, m;
    n = 10;
    m = 13;

    // Given Directed Edges of graph
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    // Function Call
    printOrder(n, m);
    return 0;
}
