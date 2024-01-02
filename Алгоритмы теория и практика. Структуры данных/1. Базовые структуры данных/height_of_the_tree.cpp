#include <algorithm>
#include <iostream>
#include <vector>

// ПОЛЕЗНАЯ ССЫЛКА https://www.geeksforgeeks.org/find-height-binary-tree-represented-parent-array/

using namespace std;

void findLength (vector<int>& p, int i, vector<int>& arrD)
{
    // если для этого узла уже найдена высота, выходим

    if (arrD[i] != 0) {

        return;
    }


    // если данный узел является корневым, то его высота всегда равна 1

    if (p[i] == -1) {

        arrD[i] = 1;

        return;
    }

   // если для предка данного корня неизвестна его высота, переходим в рекурсию для поиска высота предка  

    if (arrD[p[i]] == 0) {

        findLength(p, p[i], arrD);
    }

    // высота данного узла равна высота предка + 1 

    arrD[i] = arrD[p[i]] + 1;
}

int main() {
	
    int arrS;

    cin >> arrS;

    vector <int> arr(arrS);
    vector <int> arrD(arrS, 0);

   // -1 0 3 0 3

    for (int i = 0; i < arrS; i++) {
        cin >> arr[i];
    }

        // нахождение в цикле высоты для каждого элмента массива (каждого корня)

        for (int i = 0; i < arrS; i++) {

            findLength (arr, i, arrD);

        }

        // нахождение максимальной высоты дерева

        int height = arrD[0];
        for (int i = 1; i < arrS; i++)
            if (height < arrD[i])
                height = arrD[i];

        cout << height;

    return 0;
}

