#include <iostream>
#include <vector> // vector
#include <queue>    // priority queue
using namespace std;

typedef priority_queue<unsigned int, vector<unsigned int>> PQ;

int get_max_pieces(unsigned int n, PQ test){
    PQ Orig_pq = test;  // Copy the original PQ
   
    return 1; 
}

int solve_polycarpus(unsigned int n, unsigned int a, unsigned int b, unsigned int c){
    PQ test;
    test.emplace(a);
    test.emplace(b);
    test.emplace(c);

    return get_max_pieces(n, test);
}

int main(){
    unsigned int a,b,c,n;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << solve_polycarpus(n, a, b, c) << endl;
    return 0;
}
