#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int tree[MAX] = {0};
int lazy[MAX] = {0};

void updateRangeUtil(int seg_index, int seg_start, int seg_end, int update_start, int update_end, int diff) {
    // Propagate lazy stuff first
    if(lazy[seg_index] != 0) {
        tree[seg_index] += (seg_end - seg_start + 1) * lazy[seg_index];

        if(seg_start != seg_end) {
            lazy[2*seg_index+1] += lazy[seg_index];
            lazy[2*seg_index+2] += lazy[seg_index];
        }

        lazy[seg_index] = 0;
    }

    // Out of range ==> leave
    if(seg_start > seg_end || update_end < seg_start || seg_end < update_start) return;

    // Update range then
    if(update_start <= seg_start && seg_end <= update_end) {
        tree[seg_index] += (seg_end - seg_start + 1) * diff;

        if(seg_start != seg_end) {
            lazy[2*seg_index+1] += diff;
            lazy[2*seg_index+2] += diff;
        }

        return;
    }

    // Recursion
    int middle = (seg_start + seg_end)  / 2;
    updateRangeUtil(2*seg_index, seg_start, middle, update_start, update_end, diff);
    updateRangeUtil(2*seg_index,middle+1, seg_end, update_start, update_end, diff);

    tree[seg_index] = tree[2*seg_index+1] + tree[2*seg_index+2];
}

void updateRange(int n, int us, int ue, int diff)
{
    updateRangeUtil(0, 0, n-1, us, ue, diff);
}

int getSumUtil(int seg_start, int seg_end, int update_start, int update_end, int current) {
    if(lazy[current] != 0) {
        // Update and reset lazy parameter
        tree[current] += (seg_end - seg_start + 1) * lazy[current];

        // Propagate lazy parameter
        if(seg_start != seg_end) {
            lazy[2*current+1] += lazy[current];
            lazy[2*current+2] += lazy[current];
        }

        lazy[current] = 0;
    }

    // Invalid range ==> continue
    if(seg_start > seg_end || seg_end < update_start || update_end < seg_start) return 0;

    // Full range ==> return
    if(update_start <= seg_start && seg_end <= update_end) return tree[current];

    int mid = (seg_start + seg_end) / 2;
    return getSumUtil(seg_start, mid, update_start, update_end, 2*current+1) + getSumUtil(mid+1,seg_end, update_start, update_end, 2*current+2);
}

void buildTree(int arr[], int from, int to, int current) {
    if(from > to) return;
    if(from == to){
        tree[current] = arr[from];
        return;
    }

    int mid = (from + to) / 2;
    buildTree(arr, from, mid, 2*current+1);
    buildTree(arr, mid+1, to, 2*current+2);
    tree[current] = tree[2*current+1] + tree[2*current+2];
}

int n;
void debug() {
    for(int i = 0; i < n;i++) cout << getSumUtil(0,n-1, i, i, 0) << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    n = sizeof(arr)/sizeof(arr[0]);

    //constructST(arr, n);
    buildTree(arr, 0, 5, 0);

    debug();

    cout <<"Sum of values in given range = " << getSumUtil(0, n-1, 1, 3,0);

    updateRange(n, 1, 5, 10);

    cout <<"\nUpdated sum of values in given range = " << getSumUtil( 0, n-1, 1, 3, 0) << endl;

    return 0;
}
