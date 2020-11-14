#include "maxPlanarSubset.h"
#include<iostream>

// Constructor
MPS::MPS() {}

void MPS::findMPS(map<int, int>& pairs, vector<vector< int > >& table, set < p_int >& case1, int length) {
    for (size_t l = 1; l < length; l++)
	{		
		for (size_t i = 0; i < length - l; i++)
        {
            int j = i + l;
            int k = pairs[j];

            // case1: k not in [i,j-1]
            if(k >= i && k <= j - 1)
            {
                if (table[i][k-1] + 1 + table[k+1][j-1] > table[i][j-1])
                {
                    table[i][j] = table[i][k-1] + 1 + table[k+1][j-1];
                    case1.insert(make_pair(i,j));
                    //cout << '(' << i << " , " << j << "): case1\n"; 
                }
                else
                {
                    table[i][j] = table[i][j-1];
                    //cout << '(' << i << " , " << j << "): case2\n";
                }
            }
            else
            {
                table[i][j] = table[i][j-1];
                //cout << '(' << i << " , " << j << "): case3\n";
            }
        }	
	}
}

void MPS::findChords(map<int, int>& pairs, set<p_int>& case1, int i, int j)
{
    int k = pairs[j];
    if ((i - j) < 0)
    { 
        if (case1.find(make_pair(i, j)) != case1.end())
        {
            findChords(pairs, case1, i, k - 1);
            output.push_back(make_pair(k, j));
            findChords(pairs, case1, k + 1, j - 1);
        }
        else
        {
            findChords(pairs, case1, i, j - 1);
        }    
    }
}