#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    for(int i=0; i<genres.size(); i++)
    {
        string gen = genres[i];
        m[gen] += plays[i];
    }
    vector<pair<string,int>> v;
    map<string,int>::iterator iter;
    
    for(iter = m.begin(); iter!=m.end(); iter++)
        v.push_back(make_pair(iter->first, iter->second));
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++)
    {
        int f=0, fn=0, s=0, sn=0;
        for(int j=0; j<genres.size(); j++)
        {
            if(v[i].first == genres[j])
            {
                if(plays[j] > fn)
                {
                    s = f;
                    sn = fn;
                    f = j;
                    fn = plays[j];
                }
                else if(plays[j] > sn)
                {
                    sn = plays[j];
                    s = j;
                }
            }
        }
        answer.push_back(f);
        if(sn>0)
        {
            answer.push_back(s);
        }
    }
    return answer;
}