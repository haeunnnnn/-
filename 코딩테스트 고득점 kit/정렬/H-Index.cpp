#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int j=1; j<=citations.back(); j++)
    {
        int hIndex = j;
        int h=0, l=0;
        for(int i=0; i<citations.size(); i++)
        {
            if(hIndex <= citations[i])
                h++;
            if(hIndex >= citations[i])
                l++;
        }
        if(l<=hIndex && h>=hIndex)
            answer = hIndex;
    }
    return answer;
}