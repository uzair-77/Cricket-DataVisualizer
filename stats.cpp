#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

void printArray(int arr[], int s) {
    for (int i = 0; i < s; ++i) {
        cout << "      " << i << " " << arr[i] << "\n";
    }
    cout << endl;
}

void betweentwoyear(const string span[], const string name[], int s, const string& y, const string& year, const int r[], const int av[]) {
    cout << "Player Name\t\t\tSPAN\tRuns\tAverage" << endl;
    for (int i = 0; i < s; i++) {
        if (span[i].substr(0, 4) >= y && span[i].substr(5, 4) <= year) {
            cout << name[i];
            int d = 30 - name[i].size();
            for (int j = 0; j < d; j++) {
                cout << " ";
            }
            cout << span[i] << "\t" << r[i] << "\t" << av[i] << endl;
        }
    }
}

void printArray(int s, const string arr[], const string sp[], const int ma[], const int in[], const int no[], const int ru[], const int hs[], const int av[], const int bf[], const int sr[], const int hn[], const int fi[], const int zr[]) {
    cout << "         Player Name                        SPAN            MAT     INN     NO   RUNS   HIS  AVE  BF     SR   HUN   FIF   ZERO" << endl;
    cout << endl;
    for (int i = 0; i < s; ++i) {
        cout << i << "  ";
        if (i < 10) cout << "     ";
        if (i < 100 && i >= 10) cout << "    ";
        if (i < 1000 && i >= 100) cout << "   ";
        if (i < 10000 && i >= 1000) cout << "  ";
        cout << arr[i] << "  ";

        for (int j = 0; j < (35 - arr[i].size()); j++) {
            cout << " ";
        }

        cout << sp[i] << "    ";
        if (i < 10) cout << "     ";
        if (i < 100 && i >= 10) cout << "    ";
        if (i < 1000 && i >= 100) cout << "   ";
        cout << "  " << ma[i] << "     " << in[i] << "     " << no[i] << "   " << ru[i] << "  " << hs[i] << "  " << av[i] << "  " << bf[i] << "   " << sr[i] << "    " << hn[i] << "    " << fi[i] << "    " << zr[i] << endl;
    }
    cout << endl;
}

void read_file(int firstcol[], string playerName[], string span[], int matches[], int inns[], int notOuts[], int runs[], int highestScore[], int average[], int ballsFaced[], int strikeRate[], int hundreds[], int fifties[], int zeros[]) {
    ifstream ip("ODI data.csv");

    if (!ip.is_open()) {
        cerr << "ERROR: File Open" << '\n';
        return;
    }

    string vfirstcol, vPlayer, vSpan, vMatches, vInns, vNotOuts, vRuns, vHS, vAvg, vBF, vSR, vHundred, vFifty, vZero;

    int index = 0;
    while (ip.good()) {
        getline(ip, vfirstcol, ',');
        getline(ip, vPlayer, ',');
        getline(ip, vSpan, ',');
        getline(ip, vMatches, ',');
        getline(ip, vInns, ',');
        getline(ip, vNotOuts, ',');
        getline(ip, vRuns, ',');
        getline(ip, vHS, ',');
        vHS.erase(remove(vHS.begin(), vHS.end(), '*'), vHS.end());
        getline(ip, vAvg, ',');
        getline(ip, vBF, ',');
        getline(ip, vSR, ',');
        getline(ip, vHundred, ',');
        getline(ip, vFifty, ',');
        getline(ip, vZero, '\n');

        try {
            firstcol[index] = stoi(vfirstcol);
            playerName[index] = vPlayer;
            span[index] = vSpan;
            matches[index] = stoi(vMatches);
            inns[index] = stoi(vInns);
            notOuts[index] = stoi(vNotOuts);
            runs[index] = stoi(vRuns);
            highestScore[index] = stoi(vHS);
            average[index] = stoi(vAvg);
            ballsFaced[index] = stoi(vBF);
            strikeRate[index] = stoi(vSR);
            hundreds[index] = stoi(vHundred);
            fifties[index] = stoi(vFifty);
            zeros[index] = stoi(vZero);
        } catch (const std::invalid_argument& e) {
            // Handle invalid argument exception
        }

        index++;
    }

    ip.close();
}

int main() {
    const int data_size = 2490;

    int firstcol[data_size];
    string playerName[data_size];
    string span[data_size];
    int matches[data_size];
    int inns[data_size];
    int notOuts[data_size];
    int runs[data_size];
    int highestScore[data_size];
    int average[data_size];
    int ballsFaced[data_size];
    int strikeRate[data_size];
    int hundreds[data_size];
    int fifties[data_size];
    int zeros[data_size];

    read_file(firstcol, playerName, span, matches, inns, notOuts, runs, highestScore, average, ballsFaced, strikeRate, hundreds, fifties, zeros);

    int show = 0;

    cout << "Press 1 for Searching Of Players On The Basis Of Highest Score :\n";
    cout << "Press 2 For Searching Specific Name Of Player :\n";
    cout << "Press 3 For Players Record That Have Started Their Career :\n";
    cout << "Press 4 for Total Hundreds, Fifties, and Zeros Of A specific Country :\n";
    cout << "Press 5 For Searching Player Names In A Specific Country In Alphabetical Order :\n";
    cout << "Press 6 For Searching Specific Name Of Player From Specific Country :\n";
    cout << "Press 7 For Searching Players Record Started Their Career Specific In A Country :\n";
    cout << "Press 9 For Searching Best Player On Basis Of Runs :\n";

    while (show != 10) {
        cout << "What you want To Search: ";
        cin >> show;

        switch (show) {
            case 1: {
                for (int a = 0; a < data_size; a++) {
                    for (int b = a + 1; b < data_size; b++) {
                        if (runs[b] > runs[a]) {
                            swap(runs[a], runs[b]);
                            swap(playerName[a], playerName[b]);
                            swap(span[a], span[b]);
                            swap(matches[a], matches[b]);
                            swap(inns[a], inns[b]);
                            swap(notOuts[a], notOuts[b]);
                            swap(highestScore[a], highestScore[b]);
                            swap(average[a], average[b]);
                            swap(ballsFaced[a], ballsFaced[b]);
                            swap(strikeRate[a], strikeRate[b]);
                            swap(hundreds[a], hundreds[b]);
                            swap(fifties[a], fifties[b]);
                            swap(zeros[a], zeros[b]);
                        }
                    }
                }

                int count = 0;
                char choice;
                while (choice != 'N') {
                    count += 20;
                    cout << "Enter Y to see data of next 20 players and N to quit.\n";
                    cin >> choice;
                    if (choice == 'Y') {
                        cout << "                 Player Name             SPAN         MAT   INN   NO   RUNS   HIS  AVE  BF  SR   HUN   FIF   ZERO" << endl;
                        for (int i = count - 20; i < count; i++) {
                            cout << i + 1 << "\t" << left << setw(30) << playerName[i] << "\t" << span[i] << "\t" << matches[i] << "\t" << inns[i] << "\t" << notOuts[i] << "\t" << runs[i] << "\t" << highestScore[i] << "\t" << average[i] << "\t" << ballsFaced[i] << "\t" << strikeRate[i] << "\t" << hundreds[i] << "\t" << fifties[i] << "\t" << zeros[i] << endl;
                        }
                    }
                }
                break;
            }
            case 2: {
                string player;
                cout << "Enter Specific Player:" << endl;
                cin >> player;
                cout << "         Player Name            SPAN         MAT     INN   NO   RUNS   HIS  AVE  BF  SR   HUN   FIF   ZERO" << endl;

                for (int i = 0; i < data_size; i++) {
                    if (playerName[i] == player) {
                        cout << i + 1 << "\t" << left << setw(30) << playerName[i] << "\t" << span[i] << "\t" << matches[i] << "\t" << inns[i] << "\t" << notOuts[i] << "\t" << runs[i] << "\t" << highestScore[i] << "\t" << average[i] << "\t" << ballsFaced[i] << "\t" << strikeRate[i] << "\t" << hundreds[i] << "\t" << fifties[i] << "\t" << zeros[i] << endl;
                    }
                }
                break;
            }
            case 3: {
                string startYear, endYear;
                cout << "Enter Starting Year: ";
                cin >> startYear;
                cout << "Enter Ending Year: ";
                cin >> endYear;

                betweentwoyear(span, playerName, data_size, startYear, endYear, runs, average);
                break;
            }
            case 4: {
                string country;
                cout << "Enter Country: ";
                cin >> country;

                int hundredsTotal = 0;
                int fiftiesTotal = 0;
                int zerosTotal = 0;

                for (int i = 0; i < data_size; i++) {
                    if (playerName[i].find(country) != string::npos) {
                        hundredsTotal += hundreds[i];
                        fiftiesTotal += fifties[i];
                        zerosTotal += zeros[i];
                    }
                }

                cout << "Total Hundreds: " << hundredsTotal << endl;
                cout << "Total Fifties: " << fiftiesTotal << endl;
                cout << "Total Zeros: " << zerosTotal << endl;
                break;
            }
            case 5: {
                string country;
                cout << "Enter Country: ";
                cin >> country;

                string names[data_size];
                int count = 0;

                for (int i = 0; i < data_size; i++) {
                    if (playerName[i].find(country) != string::npos) {
                        names[count++] = playerName[i];
                    }
                }

                sort(names, names + count);
                cout << "Players from " << country << " in Alphabetical Order:" << endl;
                for (int i = 0; i < count; i++) {
                    cout << names[i] << endl;
                }
                break;
            }
            case 6: {
                string player;
                string country;
                cout << "Enter Player Name: ";
                cin >> player;
                cout << "Enter Country: ";
                cin >> country;

                cout << "         Player Name            SPAN         MAT     INN   NO   RUNS   HIS  AVE  BF  SR   HUN   FIF   ZERO" << endl;

                for (int i = 0; i < data_size; i++) {
                    if (playerName[i] == player && playerName[i].find(country) != string::npos) {
                        cout << i + 1 << "\t" << left << setw(30) << playerName[i] << "\t" << span[i] << "\t" << matches[i] << "\t" << inns[i] << "\t" << notOuts[i] << "\t" << runs[i] << "\t" << highestScore[i] << "\t" << average[i] << "\t" << ballsFaced[i] << "\t" << strikeRate[i] << "\t" << hundreds[i] << "\t" << fifties[i] << "\t" << zeros[i] << endl;
                    }
                }
                break;
            }
            case 7: {
                string country, startYear, endYear;
                cout << "Enter Country: ";
                cin >> country;
                cout << "Enter Starting Year: ";
                cin >> startYear;
                cout << "Enter Ending Year: ";
                cin >> endYear;

                cout << "         Player Name            SPAN         MAT     INN   NO   RUNS   HIS  AVE  BF  SR   HUN   FIF   ZERO" << endl;
                for (int i = 0; i < data_size; i++) {
                    if (playerName[i].find(country) != string::npos && span[i].substr(0, 4) >= startYear && span[i].substr(5, 4) <= endYear) {
                        cout << i + 1 << "\t" << left << setw(30) << playerName[i] << "\t" << span[i] << "\t" << matches[i] << "\t" << inns[i] << "\t" << notOuts[i] << "\t" << runs[i] << "\t" << highestScore[i] << "\t" << average[i] << "\t" << ballsFaced[i] << "\t" << strikeRate[i] << "\t" << hundreds[i] << "\t" << fifties[i] << "\t" << zeros[i] << endl;
                    }
                }
                break;
            }
            case 9: {
                int count = 0;
                char choice;
                while (choice != 'N') {
                    count += 20;
                    cout << "Enter Y to see data of next 20 players and N to quit.\n";
                    cin >> choice;
                    if (choice == 'Y') {
                        cout << "                Player Name                SPAN         MAT   INN   NO   RUNS   HIS  AVE  BF  SR   HUN   FIF   ZERO" << endl;
                        for (int i = count - 20; i < count; i++) {
                            cout << i + 1 << "\t" << left << setw(30) << playerName[i] << "\t" << span[i] << "\t" << matches[i] << "\t" << inns[i] << "\t" << notOuts[i] << "\t" << runs[i] << "\t" << highestScore[i] << "\t" << average[i] << "\t" << ballsFaced[i] << "\t" << strikeRate[i] << "\t" << hundreds[i] << "\t" << fifties[i] << "\t" << zeros[i] << endl;
                        }
                    }
                }
                break;
            }
        }
    }

    return 0;
}
