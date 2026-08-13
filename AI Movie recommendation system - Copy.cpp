
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Movie
{
    string name;
    int action;
    int comedy;
    int horror;
    int romance;
    int score;
};

int main()
{
    // Movie database
    Movie movies[10] =
    {
        {"Avengers", 1, 0, 0, 0, 0},
        {"Fast and Furious", 1, 1, 0, 0, 0},
        {"Mr. Bean", 0, 1, 0, 0, 0},
        {"The Conjuring", 0, 0, 1, 0, 0},
        {"Titanic", 0, 0, 0, 1, 0},
        {"Deadpool", 1, 1, 0, 0, 0},
        {"The Notebook", 0, 0, 0, 1, 0},
        {"Jumanji", 1, 1, 0, 0, 0},
        {"IT", 0, 0, 1, 0, 0},
        {"Inception", 1, 0, 0, 0, 0}
    };

    char choice;

    int action;
    int comedy;
    int horror;
    int romance;

    cout << "========================================\n";
    cout << "      AI MOVIE RECOMMENDATION SYSTEM\n";
    cout << "========================================\n";

    cout << "\nAnswer the following questions.\n";
    cout << "Enter Y for Yes and N for No.\n\n";

    // Get user preferences
    cout << "Do you like Action movies? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        action = 1;
    else
        action = 0;

    cout << "Do you like Comedy movies? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        comedy = 1;
    else
        comedy = 0;

    cout << "Do you like Horror movies? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        horror = 1;
    else
        horror = 0;

    cout << "Do you like Romance movies? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        romance = 1;
    else
        romance = 0;

    // Calculate similarity score
    for (int i = 0; i < 10; i++)
    {
        movies[i].score = 0;

        if (movies[i].action == action)
            movies[i].score++;

        if (movies[i].comedy == comedy)
            movies[i].score++;

        if (movies[i].horror == horror)
            movies[i].score++;

        if (movies[i].romance == romance)
            movies[i].score++;
    }

    // Sort movies by score
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (movies[j].score > movies[i].score)
            {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }

    // Display recommendations
    cout << "\n========================================\n";
    cout << "          MOVIE RECOMMENDATIONS\n";
    cout << "========================================\n\n";

    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        if (movies[i].score >= 3 && count < 5)
        {
            double percentage =
                (movies[i].score / 4.0) * 100;

            cout << count + 1 << ". "
                 << left << setw(20)
                 << movies[i].name;

            cout << "Match: "
                 << fixed << setprecision(0)
                 << percentage << "%\n";

            count++;
        }
    }

    if (count == 0)
    {
        cout << "No strong recommendations found.\n";
    }

    cout << "\n========================================\n";
    cout << "             YOUR PREFERENCES\n";
    cout << "========================================\n";

    cout << "Action  : "
         << (action ? "Yes" : "No") << endl;

    cout << "Comedy  : "
         << (comedy ? "Yes" : "No") << endl;

    cout << "Horror  : "
         << (horror ? "Yes" : "No") << endl;

    cout << "Romance : "
         << (romance ? "Yes" : "No") << endl;

    cout << "\n========================================\n";
    cout << "Thank you for using the system!\n";
    cout << "========================================\n";

    return 0;
}

