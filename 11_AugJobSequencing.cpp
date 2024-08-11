//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
bool static cmp(Job j1, Job j2)
    {
        return j1.profit > j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //sorting Job object in descending order based on profit
        sort(arr, arr+n , cmp);
        
        int maxD = INT_MIN; // maximum deadline
        
        for(int i=0;i<n;i++)
            maxD = max(maxD, arr[i].dead);
            
        int profit = 0, count=0;
        int place;
        
        vector<bool> filled(maxD, 0);// array used to know which place is filled or empty
        
        for(int i=0;i<n;i++)
        {
            place = arr[i].dead;
            while(filled[place] == 1) // if place is filled try to find empty place lesser then its deadline
            place--;
            
            if(place <= 0) // if no empty place find skip that job
            continue;
            
            else // if empty place is available fill it
            {
                filled[place] = 1;
                profit += arr[i].profit;
                count++;
            }
        }
        return {count, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends