#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Data {
    double x, y;
    char category;
};

// Calculate distance
double distance(Data a, Data b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

// KNN classification
char predict(Data test, vector<Data> train) {

    double minDistance = 999999;
    char result = '?';

    // Find the closest data point
    for (int i = 0; i < train.size(); i++) {

        double d = distance(test, train[i]);

        if (d < minDistance) {
            minDistance = d;
            result = train[i].category;
        }
    }

    return result;
}

int main() {

    int n;

    cout << "====================================\n";
    cout << "       AI DATA CLASSIFICATION\n";
    cout << "====================================\n\n";

    // Number of data points
    cout << "How many data points do you want to enter? ";
    cin >> n;

    vector<Data> data(n);

    // Input data
    cout << "\nEnter your data:\n";
    cout << "Example: 2.5 3.0 A\n\n";

    for (int i = 0; i < n; i++) {

        cout << "Data " << i + 1 << ": ";

        cin >> data[i].x
            >> data[i].y
            >> data[i].category;
    }

    // Training / Testing split
    int trainingSize = n * 0.7;

    vector<Data> trainingData;
    vector<Data> testingData;

    for (int i = 0; i < n; i++) {

        if (i < trainingSize)
            trainingData.push_back(data[i]);
        else
            testingData.push_back(data[i]);
    }

    cout << "\n------------------------------------\n";
    cout << "Training Data : " << trainingData.size() << endl;
    cout << "Testing Data  : " << testingData.size() << endl;
    cout << "------------------------------------\n";

    // Test the model
    int correct = 0;

    cout << "\nTesting the AI model...\n\n";

    for (int i = 0; i < testingData.size(); i++) {

        char prediction =
            predict(testingData[i], trainingData);

        cout << "Actual      : "
             << testingData[i].category << endl;

        cout << "Prediction  : "
             << prediction << endl;

        if (prediction == testingData[i].category) {
            cout << "Result      : Correct\n";
            correct++;
        }
        else {
            cout << "Result      : Wrong\n";
        }

        cout << "--------------------------\n";
    }

    // Accuracy
    double accuracy =
        (double)correct / testingData.size() * 100;

    cout << "\n====================================\n";
    cout << "           RESULT\n";
    cout << "====================================\n";

    cout << "Accuracy: " << accuracy << "%\n";

    // New data prediction
    char choice;

    cout << "\nDo you want to classify new data? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {

        Data newData;

        cout << "\nEnter Feature 1: ";
        cin >> newData.x;

        cout << "Enter Feature 2: ";
        cin >> newData.y;

        char answer =
            predict(newData, trainingData);

        cout << "\n====================================\n";
        cout << "Predicted Category: " << answer << endl;
        cout << "====================================\n";
    }

    cout << "\nThank you for using the program!\n";

    return 0;
}