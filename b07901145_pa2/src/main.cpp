// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2019 fall Algorithm PA1]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include "maxPlanarSubset.h"

using namespace std;

void help_message() {
    cout << "usage: mps <input_filepath> <output_filepath>" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 3) {
       help_message();
       return 0;
    }

    //////////// read the input file /////////////
    
    string s;
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    map<int, int> pairs;
    getline(fin, s);
    int N = stoi(s);
    for (int i = 0; i < N / 2; i++)
    {
        getline(fin, s);
        size_t pos = s.find_first_of(' ');
        int n1 = stoi(s.substr(0, pos));
        int n2 = stoi(s.substr(pos + 1));
        pairs.insert(make_pair(n1, n2));
        pairs.insert(make_pair(n2, n1));
    }
    fin.close();
    //////////// set up MPS matrix //////////   
    vector< vector<int> > mps_table(N, vector<int>(N, 0));
    //by default all values are 0
    set<p_int> case1;
    //////////// the dp part ////////////////
    MPS mps;
    mps.findMPS(pairs, mps_table, case1, N);
    //////////// release unused memory /////
    for (size_t i = 0; i < mps_table.size(); i++)
    {
        vector<int>().swap(mps_table[i]);
    }
    vector< vector<int> >().swap(mps_table);
    //////////// find output chords ////////
    mps.findChords(pairs, case1, 0, N - 1);
    int output_size = mps.output.size();
    //////////// write the output file ///////////
    fout << output_size << endl;
    for (size_t i = 0; i < output_size; i++)
    {
        fout << mps.output[i].first << ' ' << mps.output[i].second << endl;
    }
    fout.close();
    return 0;
}
