#include <iostream>
#include <vector> // vector
#include <queue>    // priority queue
#include <algorithm>    // all_off
using namespace std;

typedef priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> PQ;

pair <unsigned int, unsigned int> calcDivision(unsigned int n, unsigned int d){
    unsigned int div = n / d;
    unsigned int remainder = n % d;

    //cout << n << "/" << d << " == " << div << "; R=" << remainder << endl;
    return make_pair(div, remainder);
}

int get_max_pieces(unsigned int n, vector<unsigned int> piece_lengths){
    auto untried_lengths = piece_lengths;  // Copy the original
    unsigned int ret_num_ribbons = 0, R = 0;    // Number of ribbons, and remaining ribbon    
    unsigned int piece_l; //piece length to consider
    pair < unsigned int, unsigned int> res; // result of division


    // Continue looking:
    //  1) As long as there is still ribon left AND
    //  2) The remaining untried_lengths are longer than the remaining ribbon
    bool ribon_left = true;
    bool cutting_options = true; 
    do{
        piece_l = untried_lengths.back();  //piece length to consider
        untried_lengths.pop_back();
       
        res = calcDivision(n, piece_l);
        ret_num_ribbons = res.first;   // Calculate number of ribbons
        R = res.second; // Calculate remainder

        ribon_left = (R != 0);
        cutting_options = all_of(piece_lengths.begin(), piece_lengths.end(), [R] (unsigned int i){return i > R;});

    } while (ribon_left && cutting_options);
    
    if(R == 0){
        return ret_num_ribbons;
    }
    else{
        return ret_num_ribbons + get_max_pieces(R, piece_lengths);
    }
}

int solve_polycarpus(unsigned int n, unsigned int a, unsigned int b, unsigned int c){
    vector<unsigned int> piece_lengths;
    piece_lengths.emplace_back(a);
    piece_lengths.emplace_back(b);
    piece_lengths.emplace_back(c);

    std::sort(piece_lengths.begin(), piece_lengths.end(), greater<unsigned int>());
    return get_max_pieces(n, piece_lengths);
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
