/*
FLIPKART online grocery zone offering best prices, and combo offers on a variety
of items. The store has N items which are been sold with a certian price per unit.

There are also combo offers, and each combo offer consists of one or more 
variety of items with a price tag. Each combo offer is represented in the form 
of a list, the last number represents the amount you need to pay for this combo 
offer, other values represents how many specific items you could get if you buy 
this offer. 

Customer can avail the combo offers as many times as they wanted.

Now you are been given pricelist of N items, K number of combo offers, and 
the number of items of each variety need to buy. 

Now it's your turn to find the lowest price you have to pay for to buy exactly 
certain items as given, where you could make optimal use of the combo offers.


Input Format:
-------------
Line-1: Two integers N and K, number of varieties, and number of Combo offers 
Line-2: N space seprated inteegrs, prices of N varieties.
Next K lines: 'N+1' space separated inteegrs, number of items of each variety and
              and last number is cost to buy all these variety of items.
Last Line: N space separated integers, number of items of each variety to buy.

Output Format:
--------------
Print an integer, lowest price to pay for items to buy.


Sample Input-1:
---------------
2 2
3 6
3 1 12
2 3 17
6 6

Sample Output-1:
----------------
40

Explanation:
------------
There are two variety of items, X and Y. Their prices are Rs.3 and Rs. 6 respectively.
In combo offer-1, you can pay Rs.12 for 3X and 1Y
In combo offer-2, you can pay Rs.17 for 2A and 3B.
You need to buy 6A and 6B, so you may pay Rs.34 for 4X and 6Y (combo offer-2), 
and Rs.6 for 2X. So Total of Rs.40


Sample Input-2:
---------------
3 2
1 2 3
1 2 0 4
2 1 2 8
3 4 2

Sample Output-2:
----------------
14
*/

#include<bits/stdc++.h>
using namespace std;
int price = 0, min_price= 10e7;

bool isSafe(vector<vector<int>>&combos, vector<int>&items)
{
    for(int i=0;i<items.size();i++){
        if(items[i] < combos[i])return false;
    }    
    return true;
}

void dfs(int n, int k, vector<int>&prices, vector<vector<int>>&combos, vector<int>&items, int x, int y, vector<int>&rem)
{
    if(x>=k or y>=n)return;
    
    for(int i=x;i<k;i++){
        if(isSafe(combos,items)){
            
        }
        price += combos[i][n];
        
        dfs(n,k,prices,combos,items,x+1,y,rem);
        
        min_price = min(min_price, price);
        price =  0;
        rem = items;
    }
}

int main(){
    int n, k; cin >> n >> k;
    vector<int> prices(n), items(n), rem;
    
    for(int &i:prices)cin >> i;
    
    vector<vector<int>> combos(k, vector<int>(n+1));
    
    for(int j=0;j<k;j++){
        vector<int> v(n+1);
        for(int i=0;i<n+1;i++){
            cin >> v[i];
        }
        combos.push_back(v);
    }
    
    for(int i=0;i<n;i++){
        cin >> items[i];
    }
    
    rem = items;
    
    dfs(n,k,prices,combos,items, 0, 0, items);
    
    for(int i=0;i<n;i++){
        price += rem[i]*prices[i];
    }
    
    cout << min_price << endl;
    return 0;
}