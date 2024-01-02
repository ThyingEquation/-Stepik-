#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// полезная ссылка https://www.cyberforum.ru/cpp-beginners/thread3081406.html

int main() {

    int bufSize;
    int nums;
    int arvl;
    int drtn;

    queue <int> FIFO;

    int numPos = 0;
    int realPos = 0;

    cin >> bufSize;
    cin >> nums;

    if (nums == 0) { return 0; }

    for (int i = 0; i < nums; ++i) {

        cin >> arvl >>drtn;

        // выясняем, когда на самом деле можно стартовать пакет
        realPos = max(numPos, arvl);

        // Извлекаем из очереди пакеты, которые обработаны на ТЕКУЩИЙ МОМЕНТ
        while (!FIFO.empty() && FIFO.front() <= arvl) {
            FIFO.pop();
        }

        if (FIFO.size() < bufSize) {
            // если на момент старта есть места в очереди, стартуем
            cout << realPos << endl;
            numPos = realPos + drtn; // окончание обработки
            FIFO.push(numPos);
        }
        else {
            // Очередь полна, пакет не может быть обработан
            cout << -1 << endl;
        }

    }

    return 0;
}