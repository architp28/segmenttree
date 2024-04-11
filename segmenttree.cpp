#include<bits/stdc++.h>
using namespace std;

void build(vector<int>& seg , vector<int>& arr , int i , int l , int h){
    if(l == h){
        seg[i] = arr[l];
        return;
    }
    int m = (l+h)/2;
    build(seg , arr , 2*i+1 , l , m);
    build(seg , arr , 2*i+2 , m+1 , h);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}
int query( int i ,int l , int h , int l1 , int h1 , vector<int>&seg){
    if(h1 < l || l1 > h) return 0;
    if(l >= l1 && h <= h1) return seg[i];

    int m = (l+h)/2;
    int a = query(2*i+1 , l , m , l1 , h1 , seg);
    int b = query(2*i+2 , m+1 , h , l1 , h1 , seg);
    return a+b;
}
void update(vector<int>& seg ,int ind , int l , int h , int i , int val){
    if(l == h){
        seg[ind] = val;
        return;
    }
    int mid = (l+h)/2;
    if(i <= mid) update(seg , 2*ind+1 , l , mid , i , val);
    else update(seg , 2*ind+2 , mid+1 , h ,i , val);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
}