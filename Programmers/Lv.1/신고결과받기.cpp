#include <string>
#include <vector>
#include<iostream>
#include <sstream>
using namespace std;

//신고 내역을 넣어주면 신고자, 신고받은자 를 리턴함
vector<int> find_name(vector<string> id_list, string report)
{
    vector<int> names = { 0,0 };
    stringstream ss(report);
    vector<string> words;
    string word;
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        if (words[0] == id_list[i])
        {
            names[0] = i;
        }
        if (words[1] == id_list[i])
        {
            names[1] = i;
        }
    }
    return names;
}


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<int> names = { 0,0 };
    vector<bool> stop_people;
    for (int i = 0; i < id_list.size(); i++)
    {
        stop_people.push_back(false);
    }
    vector<vector<int>> reports(id_list.size(),vector<int>(id_list.size(),0)); // 2차원으로 신고 수 저장

    int report_count = report.size();
    for (int i = 0; i < report_count; i++)
    {
        names = find_name(id_list, report[i]);
        reports[names[0]][names[1]]++;
    }
    //정지먹은 목록 구하기
    for (int i = 0; i < id_list.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < id_list.size(); j++)
        {
            if (reports[j][i] != 0)
            {
                cnt++;
            }
        }
        if (cnt >= k)
        {
            stop_people[i] = true;
        }
    }
    //신고와 정지 체크하기
    for (int i = 0; i < id_list.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < id_list.size(); j++)
        {
            if (reports[i][j] != 0)
            {
                if (stop_people[j] == true)
                {
                    cnt++;
                }
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}
