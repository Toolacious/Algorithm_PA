#ifndef _MAXPLANARSUBSET_H
#define _MAXPLANARSUBSETL_H

#include<vector>
#include<map>
#include<set>
using namespace std;

typedef pair<int, int> p_int;
class MPS {
    public:
        MPS(); // constructor
        void findMPS(map<int, int>&, vector<vector< int > >&, set<p_int>&, int);
        void findChords(map<int, int>&, set<p_int>&, int, int);
        vector<p_int> output;
};

#endif