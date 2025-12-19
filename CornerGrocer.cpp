#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Class to track item frequencies
class ItemTracker {
private:
    map<string, int> itemFrequency;  // Stores each item and its count

public:
    // Load items from input file
    void LoadItemsFromFile(const string& fileName) {
        ifstream inFile(fileName);
        if (!inFile.is_open()) {
            cout << "Error: Could not open input file: " << fileName << endl;
            return;
        }

        string item;
        while (inFile >> item) {
            itemFrequency[item]++;
        }
        inFile.close();
    }

    // Write backup frequency.dat file
    void WriteFrequencyFile(const string& fileName) const {
        ofstream outFile(fileName);
        if (!outFile.is_open()) {
            cout << "Error: Could not create output file: " << fileName << endl;
            return;
        }

        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

    // Get frequency of a single item
    int GetItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            return it->second;
        }
        return 0;
    }

    // Print all items and frequencies
    void PrintAllFrequencies() const {
        cout << "\nItem Frequencies:\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Print histogram using asterisks
    void PrintHistogram() const {
        cout << "\nItem Frequency Histogram:\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// Display menu options
void DisplayMenu() {
    cout << "\n================ Corner Grocer Menu ================\n";
    cout << "1. Look up frequency of a specific item\n";
    cout << "2. Print frequency of all items\n";
    cout << "3. Print histogram of item frequencies\n";
    cout << "4. Exit\n";
    cout << "====================================================\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    ItemTracker tracker;

    // Load file
    tracker.LoadItemsFromFile("CS210_Project_Three_Input_File.txt");

    // Create frequency.dat backup
    tracker.WriteFrequencyFile("frequency.dat");

    int choice;
    string item;

    while (true) {
        DisplayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number 1-4.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> item;
            cout << item << " appears " << tracker.GetItemFrequency(item) << " time(s).\n";
            break;

        case 2:
            tracker.PrintAllFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please enter 1-4.\n";
        }
    }
}
