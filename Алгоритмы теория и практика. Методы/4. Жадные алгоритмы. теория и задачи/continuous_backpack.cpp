#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;
int itemCount = 0;
double volume = 0;
double result = 0;

typedef pair <double, double> priceVolume;


int main(void) {

    cin >> itemCount >> volume;
    vector <priceVolume> segments(itemCount);
    for (int i = 0; i < itemCount; i++) {
        cin >> segments[i].first >> segments[i].second;
        segments[i].first = segments[i].first / segments[i].second;
    }

    for (int a = 0; a <= (itemCount - 2); a++) {
        for (int a = 0; a <= (itemCount - 2); a++) {
            if (segments[a].first > segments[a + 1].first) {
                double temp2 = segments[a + 1].second;
                double temp1 = segments[a + 1].first;
                segments[a + 1].second = segments[a].second;
                segments[a + 1].first = segments[a].first;
                segments[a].second = temp2;
                segments[a].first = temp1;
            }
        }
    }

    while (segments.size() > 0) {

        if (volume > segments[segments.size() - 1].second) {
            result = result + segments[segments.size() - 1].second * segments[segments.size() - 1].first;
            volume = volume - segments[segments.size() - 1].second;
            segments.pop_back();

        }
        else if (volume <= segments[segments.size() - 1].second) {
            result = result + (volume * segments[segments.size() - 1].first);
            volume = volume - segments[segments.size() - 1].second;
            break; 
        }

    }

    cout << fixed << setprecision(3) << result << endl;

}