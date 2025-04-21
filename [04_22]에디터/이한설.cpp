#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    
    string init;
    cin >> init;

    list<char> editor;
    for (char c : init) {
        editor.push_back('#');
        editor.push_back(c);
    }
    editor.push_back('#');

    auto cursor = prev(editor.end());

    int M;
    cin >> M;
    for (int idx = 0; idx < M; idx++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            auto it = cursor;
            if (it != editor.begin()) {
                it--;
                if (it != editor.begin()) {
                    cursor = prev(it);
                }
            }
        }
        else if (cmd == 'D') {

            auto next1 = next(cursor);
            if (next1 != editor.end()) {
                auto next2 = next(next1);
                if (next2 != editor.end()) {
                    cursor = next2;
                }
            }
        }
        else if (cmd == 'B') {
            
            auto it = cursor;
            if (it != editor.begin()) {
                it--;
                if (it != editor.begin()) {
                    auto it_hash = prev(it);
 
                    auto tmp = editor.erase(it_hash);
                    editor.erase(tmp);
                }
            }
        }
        else if (cmd == 'P') {
            char ch;
            cin >> ch;
            editor.insert(cursor, '#');
            editor.insert(cursor, ch);
        }
    }

    for (char c : editor) {
        if (c != '#') cout << c;
    }
    return 0;
}
