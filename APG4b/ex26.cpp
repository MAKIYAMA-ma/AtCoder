#include <bits/stdc++.h>
#include <iostream>
#include <sstream>  // istringstream

using namespace std;

map<string, int> valinttable;
map<string, vector<int>> valvectable;

void print_val (vector<int> dt) {
    cout << "[ ";

    for(int i = 0; i < dt.size(); i++) {
        cout << dt.at(i) << " ";
    }

    cout << "]" << endl;
}

void print_val(int dt) {
    cout << dt << endl;
}

int parse_intval(string dt) {
    int val = 0;
    try {
        val = stoi(dt);
    } catch( const invalid_argument &e ) {
        val = valinttable[dt];
    }
    return val;
}

int parse_int(istringstream *iss) {
    int val = 0;
    string tmp;

    *iss >> tmp;
    val = parse_intval(tmp);
    while(*iss >> tmp) {
        if(tmp == ";") {
            break;
        } else {
            if(tmp == "+") {
                *iss >> tmp;
                val += parse_intval(tmp);
            } else if(tmp == "-") {
                *iss >> tmp;
                val -= parse_intval(tmp);
            }
        }
    }

    return val;
}

vector<int> parse_vec_unit(istringstream *iss) {
    vector<int> vec;

    string tmp;

    *iss >> tmp;
    if(tmp == "[") {
        *iss >> tmp;
        vec.push_back(parse_intval(tmp));
        while(*iss >> tmp) {
            if(tmp == ",") {
                *iss >> tmp;
                vec.push_back(parse_intval(tmp));
            } else if(tmp == "]") {
                break;
            }
        }
    } else {
        vec = valvectable[tmp];
    }

    return vec;
}

vector<int> parse_vec(istringstream *iss) {
    vector<int> vec;
    string tmp;

    vec = parse_vec_unit(iss);
    while(*iss >> tmp) {
        if(tmp == ";") {
            break;
        } else {
            vector<int> tmpvec = parse_vec_unit(iss);
            if(tmp == "+") {
                for(int i = 0; i < vec.size(); i++) {
                    vec.at(i) += tmpvec.at(i);
                }
            } else if(tmp == "-") {
                for(int i = 0; i < vec.size(); i++) {
                    vec.at(i) -= tmpvec.at(i);
                }
            }
        }
    }

    return vec;
}

int main() {
    int n;
    string line;
    const string INT_ORDER = "int";
    const string VEC_ORDER = "vec";
    const string PRINT_INT_ORDER = "print_int";
    const string PRINT_VEC_ORDER = "print_vec";

    cin >> n;
    getline(cin, line); // nの行終了させるダミー
    for(int i = 0; i < n; i++) {
        if(!getline(cin, line)) {
            // エラー
            return -1;
        }

        istringstream iss(line);
        string kou;
        iss >> kou;

        if(kou == INT_ORDER) {
            iss >> kou;

            string tmp;
            iss >> tmp;
            if(tmp == "=") {
                valinttable[kou] = parse_int(&iss);
            }
        } else if(kou == VEC_ORDER) {
            iss >> kou;

            string tmp;
            iss >> tmp;
            if(tmp == "=") {
                valvectable[kou] = parse_vec(&iss);
            }
        } else if(kou == PRINT_INT_ORDER) {
            print_val(parse_int(&iss));
        } else if(kou == PRINT_VEC_ORDER) {
            print_val(parse_vec(&iss));
        }
    }
}
