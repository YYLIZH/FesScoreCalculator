#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <tuple>

#include <algorithm>

#include <map>

using namespace std;

tuple < vector < char > , vector < char > , vector < string > , vector < int > > coin(string rate) {
    vector < char > combos;
    vector < char > goals;
    vector < string > levels;
    vector < int > scores;
    ifstream ifs(rate, ios:: in );
    if (!ifs.is_open()) {
        cout << "Failed to open file\n.";
    } else {
        char combo;
        char goal;
        string level;
        int score;
        while (ifs >> combo >> goal >> level >> score) {
            combos.push_back(combo);
            goals.push_back(goal);
            levels.push_back(level);
            scores.push_back(score);
        }
        ifs.close();
    }
    ifs.close();
    return {
        combos,
        goals,
        levels,
        scores
    };
}

tuple < vector < int > , vector < char > , vector < char > , vector < string > , vector < int > > pros(string rate) {
    vector < int > magnifications;
    vector < char > combos;
    vector < char > goals;
    vector < string > levels;
    vector < int > scores;
    ifstream ifs(rate, ios:: in );
    if (!ifs.is_open()) {
        cout << "Failed to open file\n.";
    } else {
        int magnification;
        char combo;
        char goal;
        string level;
        int score;
        while (ifs >> magnification >> combo >> goal >> level >> score) {
            magnifications.push_back(magnification);
            combos.push_back(combo);
            goals.push_back(goal);
            levels.push_back(level);
            scores.push_back(score);
        }
        ifs.close();
    }
    ifs.close();
    return {
        magnifications,
        combos,
        goals,
        levels,
        scores
    };
}



tuple < int, vector < int > > leastScores(vector < int > scores, int amount) {
    vector < int > dp(amount + 1, amount + 1);
    vector < int > p(amount + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < scores.size(); j++) {
            if (scores[j] <= i) {
                if (dp[i] > dp[i - scores[j]] + 1) {
                    dp[i] = dp[i - scores[j]] + 1;
                    p.at(i) = scores.at(j);
                }

            }
        }
    }
    if (dp[amount] > amount) {
        vector < int > wrong;
        return {
            -1,
            wrong
        };
    } else {
        return {
            dp[amount],
            p
        };
    }

}

int find_index(vector < int > array, int target) {
    for (int i = 0; i < array.size(); i++) {
        if (array.at(i) == target) {
            return i;
        }
    }
    return -1;
}

void coin_game(string);
void pros_game(string);

int main() {
    cout << "This is caculator to calculate score" << endl;
    cout << "Thanks for wl01780813's contribution" << endl;
    int type_first, type_second, hand_light;
    cout << "1) coin" << "   " << "2) pros" << endl;
    cout << "Please input type of the game: " << endl;
    cin >> type_first;
    switch (type_first) {
        case 1: {
            cout << "1) Yes" << "  " << "2) No" << endl;
            cout << "Do you have hand light?" << endl;
            cin >> hand_light;
            switch (hand_light) {
                case 1: 
                    {
                        cout << "1) 0 " << "2) 10 " << "3) 20 " << "4) 40 " << "5) 70 " << endl;
                        cout << "Please input your bonus: " << endl;
                        cin >> type_second;
                        switch (type_second) {
                            case 1:
                                coin_game("coin_50_0.txt");
                                break;
                            case 2:
                                coin_game("coin_50_10.txt");
                                break;
                            case 3:
                                coin_game("coin_50_20.txt");
                                break;
                            case 4:
                                coin_game("coin_50_40.txt");
                                break;
                            case 5:
                                coin_game("coin_50_70.txt");
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 2: 
                    {
                        cout << "1) 0 " << "2) 10 " << "3) 20 " << endl;
                        cout << "4) 40 " << "5) 70 " << endl;
                        cout << "Please input your bonus: " << endl;
                        cin >> type_second;
                        switch (type_second) {
                            case 1:
                                coin_game("coin_0.txt");
                                break;
                            case 2:
                                coin_game("coin_10.txt");
                                break;
                            case 3:
                                coin_game("coin_20.txt");
                                break;
                            case 4:
                                coin_game("coin_40.txt");
                                break;
                            case 5:
                                coin_game("coin_70.txt");
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        break;
        case 2: 
            {
                cout << "1) Yes" << "  " << "2) No" << endl;
                cout << "Do you have hand light?" << endl;
                cin >> hand_light;
                switch (hand_light) {
                    case 1: 
                        {
                            cout << "1) 0 " << "2) 10 " << "3) 20 " << "4) 40 " << "5) 70 " << endl;
                            cout << "Please input your bonus: " << endl;
                            cin >> type_second;
                            switch (type_second) {
                                case 1:
                                    coin_game("pros_50_0.txt");
                                    break;
                                case 2:
                                    pros_game("pros_50_10.txt");
                                    break;
                                case 3:
                                    pros_game("pros_50_20.txt");
                                    break;
                                case 4:
                                    pros_game("pros_50_40.txt");
                                    break;
                                case 5:
                                    pros_game("pros_50_70.txt");
                                    break;
                                default:
                                    break;
                            }
                        }
                        break;
                    case 2: 
                        {
                            cout << "1) 0 " << "2) 10 " << "3) 20 " << endl;
                            cout << "4) 40 " << "5) 70 " << endl;
                            cout << "Please input your bonus: " << endl;
                            cin >> type_second;
                            switch (type_second) {
                                case 1:
                                    pros_game("pros_0.txt");
                                    break;
                                case 2:
                                    pros_game("pros_10.txt");
                                    break;
                                case 3:
                                    pros_game("pros_20.txt");
                                    break;
                                case 4:
                                    pros_game("pros_40.txt");
                                    break;
                                case 5:
                                    pros_game("pros_70.txt");
                                    break;
                                default:
                                    break;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
    }
    return 0;
}

void coin_game(string rate) {
    int now_score, target_score;
    cout << "Input present score: ";
    cin >> now_score;
    cout << "Input target score: ";
    cin >> target_score;
    int target = target_score - now_score;
    vector < char > goals;
    vector < char > combos;
    vector < string > levels;
    vector < int > scores;
    tie(combos, goals, levels, scores) = coin(rate);
    int ans;
    vector < int > result_array;
    tie(ans, result_array) = leastScores(scores, target);

    if (ans == -1) {
        cout << "Impossible to reach the goal" << endl;
    } else {
        map < int, int > score_result;
        map < int, int > ::iterator iter;
        cout << "Times needed to play: " << ans << endl;
        vector < int > score_result_index;
        cout << "------------------" << endl;
        int index;
        while (target > 0) {
            index = find_index(scores, result_array[target]);
            iter = score_result.find(index);
            if (iter != score_result.end()) {
                iter -> second += 1;
            } else {
                score_result.insert(pair < int, int > (index, 1));
            }
            target = target - result_array[target];
        }
        for (iter = score_result.begin(); iter != score_result.end(); ++iter) {
            cout << "Combo " << combos.at(iter -> first) << " Score " << goals.at(iter -> first) << " Level " << levels.at(iter -> first) << " " << iter -> second << " times" << endl;

        }

    }
}

void pros_game(string rate) {
    int now_score, target_score;
    cout << "Input present score: ";
    cin >> now_score;
    cout << "Input target score: ";
    cin >> target_score;
    int target = target_score - now_score;
    vector < int > magnification; //倍率
    vector < char > goals; //分數
    vector < char > combos;
    vector < string > levels; //難度
    vector < int > scores;
    tie(magnification, combos, goals, levels, scores) = pros(rate);
    int ans;
    vector < int > result_array;
    tie(ans, result_array) = leastScores(scores, target);

    if (ans == -1) {
        cout << "Impossible to reach the goal" << endl;
    } else {
        map < int, int > score_result;
        map < int, int > ::iterator iter;
        cout << "Times needed to play: " << ans << endl;
        vector < int > score_result_index;
        cout << "------------------" << endl;
        int index;
        while (target > 0) {
            index = find_index(scores, result_array[target]);
            iter = score_result.find(index);
            if (iter != score_result.end()) {
                iter -> second += 1;
            } else {
                score_result.insert(pair < int, int > (index, 1));
            }
            target = target - result_array[target];
        }
        for (iter = score_result.begin(); iter != score_result.end(); ++iter) {
            cout << "Magnification" << magnification.at(iter -> first) << " Combo " << combos.at(iter -> first) << " Score " << goals.at(iter -> first) << " Level " << levels.at(iter -> first) << " " << iter -> second << " times" << endl;

        }

    }
}