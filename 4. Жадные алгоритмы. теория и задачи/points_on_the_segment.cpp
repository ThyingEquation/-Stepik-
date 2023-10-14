#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int segments_count;

typedef std::pair <int, int> Segment;

vector <int> get_covering_set(vector <Segment> segments) {
    vector <int> result;

    for (int a = 0; a <= (segments_count - 2); a++) {
        for (int a = 0; a <= (segments_count - 2); a++) {
            if (segments[a].second > segments[a + 1].second) {
                int temp2 = segments[a + 1].second;
                int temp1 = segments[a + 1].first;
                segments[a + 1].second = segments[a].second;
                segments[a + 1].first = segments[a].first;
                segments[a].second = temp2;
                segments[a].first = temp1;
            }
        }
    }

    vector <int> arr;
    arr.push_back(segments[0].second);

    int x = 0;

    for (int a = 0; a <= (segments_count - 2); a++) {

        if (arr[x] >= segments[a + 1].first) {
            
            continue;
        }
        else {
            arr.push_back(segments[a + 1].second);
            ++x;
        }

    }

    cout << arr.size() << endl;

    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return result;

}

int main(void) {
    
    cin >> segments_count;
    vector <Segment> segments(segments_count);
    for (int i = 0; i < segments_count; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector <int> points = get_covering_set(segments);

}