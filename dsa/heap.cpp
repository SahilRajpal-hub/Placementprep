// *** => Perfomance of Heap compared to other DS


			    Insertion      Search      Find_Min      Delete_Min

Unsorted Array     O(1)  	   O(N)  	   O(N) 	     O(N)	                                              

Sorted Array       O(N)  	   O(logN)     O(1) 	     O(N)                                                    

Unsorted LL        O(1)  	   O(N)  	   O(N) 	     O(N)                                                       

Sorted LL          O(1)  	   O(logN)     O(1) 	     O(1)  

Min Heap           O(logN)     O(N)        O(1)          O(logN)


HEAP => 1. Tree DS
	  2. Complete Binary Tree
	  3. Heap property (keep track of max/min element at root).
	  4. are of two types (max and min).


Max-Heap => Root should always be maximum and same goes for all sub trees.
Min-Heap => Root should always be minimum and same goes for all sub trees.

Heap Representation => Node -> i
			     parent -> floor(i-1/2)
			     left child -> 2*i + 1
			     right child -> 2*i + 2 	

Insertion In Heap => First insert element at last and then swap with parent till the heap property is satisfied

Deletion in heap => first delete the root element from heap and then put last element at root and swap with children till the 
			  heap property is satisfied.

Heapify => An algorithm to make the heap from regular array having time complexity of O(n). Traverse array from the end(n/2) since leaf are bound 
	     to be heap and check if the current node is forming a heap, if not then swap with the max(leftchild, rightchild) else continue.

Heapsort => Takes O(NlogN). Delete the element from heap N times.

Heap in cpp stl => 1. Max Heap -> priority_queue<d_type>, push , pop, top , size, empty.
			 2. Min Heap -> priority_queue<int, vector<int>, greater<int>>

Question Identification => Kth + `Smalles/Largest`
                                      |      |
                                     Max    Min
                                    Heap    Heap
                    
                        => Question could be solvable by sorting(NlogN) and then can be improved by heap(NlogK or N).

=> Questions


// ? 1.  Kth Largest Element in an Array -> Given an integer array nums and an integer k, return the kth largest element in the array.
// code => 
 int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<nums.size(); i++){    // O(n)
        pq.push(nums[i]);                // O(logK)
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
}


// ? 2.  Kth Smallest Element in an Array -> Given an integer array nums and an integer k, return the kth Smallest element in the array.
// code => 
int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    for(int i=l; i<=r; i++){
        pq.push(arr[i]);
        
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
}

// ? 3. Sort a Nearly sorted array
vector <int> nearlySorted(int arr[], int n, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()==k+1){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// ? 4.  Find K Closest Elements to x
vector<int> findClosestElements(vector<int>& nums, int k, int x) {
    priority_queue<pair<int,int>> pq;
    vector<int> ans;
    
    for(int i=0; i<nums.size(); i++){
        pq.push({abs(nums[i]-x),nums[i]});
        
        if(pq.size()==k+1){
            auto p = pq.top();
            pq.pop();
        }
    }
    
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        ans.push_back(p.second);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// ? 5. Frequency sort
vector<int> frequencySort(vector<int>& nums) {
    map<int,int> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        pq.push({it->second,it->first});
    }
    
    vector<int> ans;
    while(!pq.empty()){
        int f = pq.top().first;
        int v = pq.top().second;
        while(f--)
            ans.push_back(v);
        pq.pop();
    }
    return ans;
}

// ? 6. Top K Frequent element
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        pq.push({it->second,it->first});
        
        if(pq.size()>k) pq.pop();
    }
    
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
} 

// ? 7. K Closest Points to Origin
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<long long int,vector<int>>> pq;
    
    for(auto v:points){
        int d1 = v[0];
        d1 = d1*d1;
        int d2 = v[1]; 
        d2 = d2*d2;
        long long int distance = d1+d2;
        pq.push({distance,v});
        
        if(pq.size()>k){
            cout<<pq.top().first<<endl;
            pq.pop();
        }
    }
    
    vector<vector<int>> ans;
    while(!pq.empty()){
        auto v = pq.top().second;
        pq.pop();
        ans.push_back(v);
    }
    
    return ans;
}

// ? 8. Minimum Cost of ropes
long long minCost(long long arr[], long long n) {
    long long ans = 0;
    if(n==0) return 0;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(long long i=0; i<n; i++){
        pq.push(arr[i]);
    }
    
    while(pq.size()!=1){
        long long r1 = pq.top();
        pq.pop();
        long long r2 = pq.top();
        pq.pop();
        ans += (r1+r2);
        // cout<<r1<<" "<<r2<<" "<<ans<<endl;
        pq.push(r1+r2);
    }
    
    return ans;
}

