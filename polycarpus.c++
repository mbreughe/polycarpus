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
    pair < unsigned int, unsigned int> res; // result of division

    // Get current length to try out
    unsigned int curr_length = untried_lengths.back();
    untried_lengths.pop_back();
    
    // If the smallest length is larger than the remaining ribbon return -1
    if (curr_length > n){
        return -1;
    }
    
    res = calcDivision(n, curr_length);
    unsigned int num_curr_pieces = res.first;
    unsigned int remaining_length = res.second;

    // Return if there is no ribbon remaining
    if (remaining_length == 0){
        return num_curr_pieces;
    }
    
    // Stop looking if there are no pieces to try out anymore    
    if (untried_lengths.size() == 0){
            return -1;
    }
   
    // Reduce num_curr_pieces until solution is found
    while (true) {
        //cout << "Cutting " << n << " with " << curr_length << ": " << num_curr_pieces << endl;

        unsigned int num_new_pieces = get_max_pieces(remaining_length, untried_lengths);

        // Did we find a solution?
        if (num_new_pieces != -1){
            return num_new_pieces + num_curr_pieces;
        }

        // If we reached here, all options have been exhausted.
        if (num_curr_pieces == 0){
            break;
        }
        --num_curr_pieces;
        remaining_length += curr_length;
    }
       
    return -1; 
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
