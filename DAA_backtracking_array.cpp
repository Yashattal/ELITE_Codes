/*
Ganesh is working on numbers,
He is given a list of integers 1,2,3,...,N, the list is indexed from 1 to N.

Now he can shuffle the list in whatever way he want.
Shuffled list is said to be valid, if one of the following is true for 
i-th position in the list.
	- The integer at the i-th position is divisible by i.
	- 'i' is divisible by the integer at the i-th position.

Now your task is to find out, How many valid shuffles can Ganesh do?

Input Format:
-------------
An integer N, where N<=20.

Output Format:
--------------
Print an integer, number of ways ganesh can shuffle.


Sample Input:
---------------
2

Sample Output:
----------------
2

Explanation:
------------
The first shuffled list is [1, 2]:
Integer at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
Integer at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second shuffled list is [2, 1]:
Integer at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
Integer at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.

*/

/*
#include<bits/stdc++.h>
using namespace std;

int checkArray(vector<int> &v,int count,int N)
{
    for(int i=N;i>=1;i++){
        if(v[i]==0){
            if(i%N==0 or N%i==0){
                v[i] = N;
            }
            if(v[i]==0){
                v[i-1] = 0;
                if(i%N==0 or N%i==0){
                    v[i] = N;
                }       
            }
            N--;
        }
        count += 1;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n+1,0);
    int count =0;
    
    cout << checkArray(v,count,n) << endl;
    
    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;

int checkArray(vector<int> &v,int N)
{
    if(N==0)return 1;
    int count = 0;
    for(int i=1;i<v.size();i++){
        if(v[i]==0 and (i%N==0 or N%i==0)){
            v[i] = N;
            count += checkArray(v,N-1);
            v[i] = 0;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n+1,0);
    cout << checkArray(v,n) << endl;
    
    return 0;
}

// sort an array according to other program
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];

    map<int,int> mp;
    vector<int> v;

    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(int i=0;i<m;i++)
    {
        while(mp[b[i]]!=0){
            v.push_back(b[i]);
            mp[b[i]]--;
        }
        mp.erase(b[i]);
    }

    for(auto x:mp)
    {
        while(x.second!=0){
            v.push_back(x.first);
            x.second--;
        }
    }

    for(auto x:v)cout << x << " ";
    return 0;
}
*/

