#include <string>
#include <vector>
#include <queue>

using namespace std;

int isOneDiff(string a, string b) 
{
    int diff = 0;
    for (int i = 0; i < a.length(); i++) 
    {
        if (a[i] != b[i]) 
        {
            diff++;
        }
        if(diff > 1)
        {
            diff = 2;
            break;
        }
    }
    return diff;
}

int solution(string begin, string target, vector<string> words) 
{
    bool target_exists = 0;
    for (int i = 0; i < words.size(); i++) 
    {
        if (words[i] == target) 
        {
            target_exists = 1;
            break;
        }
    }
    
    if (target_exists == 0) 
        return 0;

        

    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), 0);

    q.push({begin, 0});

    while (!q.empty()) 
    {
        string current_word = q.front().first;
        int current_steps = q.front().second;
        q.pop();

        if (current_word == target) 
            return current_steps;


        for (int i = 0; i < words.size(); i++) 
        {
            if (visited[i] == 0 && isOneDiff(current_word, words[i]) == 1) 
            {
                visited[i] = true;
                q.push({words[i], current_steps + 1});
            }
        }
    }

    return 0;
}
