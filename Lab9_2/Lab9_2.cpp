#include <iostream>
#include <cstring>

using namespace std;

// Пошук усіх конкатенацій слів словника
void task2()
{
    char text[10][501];
    char words[30][51];
    int lines, n, k;
    cout << "\nTASK 23.2" << endl;
    cout << "Number of text lines (1-10): ";
    cin >> lines;
    if (lines < 1 || lines > 10)
    {
        cout << "Incorrect number of lines" << endl;
        return;
    }
    cin.ignore(10000, '\n');
    for (int i = 0; i < lines; i++)
    {
        cout << "Enter line " << i + 1 << ": ";
        cin.getline(text[i], 501);
    }
    cout << "Number of dictionary words (1-30): ";
    cin >> n;
    if (n < 1 || n > 30)
    {
        cout << "Incorrect dictionary size" << endl;
        return;
    }
    cout << "Enter dictionary words:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin.width(51);
        cin >> words[i];
    }
    int wordLength = (int)strlen(words[0]);
    if (wordLength == 0)
    {
        cout << "Words must not be empty" << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if ((int)strlen(words[i]) != wordLength)
        {
            cout << "All dictionary words must have equal length" << endl;
            return;
        }
    }
    cout << "How many words in one group (1-" << n << "): ";
    cin >> k;
    if (k < 1 || k > n)
    {
        cout << "Incorrect group size" << endl;
        return;
    }
    int totalLength = k * wordLength;
    cout << "\nStarting indexes (count from 0):" << endl;
    for (int line = 0; line < lines; line++)
    {
        int length = (int)strlen(text[line]);
        bool first = true;
        cout << "Line " << line + 1 << ": [";
        for (int i = 0; i + totalLength <= length; i++)
        {
            bool used[30] = { false };
            bool good = true;
            // Перевірка кожного слова в групі
            for (int j = 0; j < k; j++)
            {
                int found = -1;
                for (int w = 0; w < n; w++)
                {
                    if (!used[w] &&
                        strncmp(text[line] + i + j * wordLength,
                            words[w], wordLength) == 0)
                    {
                        found = w;
                        break;
                    }
                }
                if (found == -1)
                {
                    good = false;
                    break;
                }
                used[found] = true;
            }
            if (good)
            {
                if (!first)
                    cout << ", ";
                cout << i;
                first = false;
            }
        }
        cout << "]" << endl;
    }
}

int main()
{
    cout << "Laboratory work 9, variant 23" << endl;
    cout << "Student: Sarzhevskyi Daniil Oleksandrovych" << endl;
    cout << "Group: IPZ-12(6)" << endl;
    task2();
    return 0;
}