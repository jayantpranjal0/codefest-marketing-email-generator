#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include<chrono>
using namespace __gnu_pbds;
using namespace std;
using namespace chrono;
using namespace tr1;

#define ll long long int
#define ld long double
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define tolower(a) ((char)tolower(a))
#define toupper(a) ((char)toupper(a))
#define yes cout<<"YES"
#define no cout<<"NO"
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define itn int
#define pb push_back
#define ceil(a) ((int)ceil(a))
#define mp make_pair
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


void insertTextAtPosition(const string& filename, int lineNumber, int charPosition, const string& text) {
    ifstream inFile(filename);
    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();
    if (lineNumber >= 1 && lineNumber <= static_cast<int>(lines.size()) + 1) {
        lines[lineNumber - 1].insert(charPosition - 1, text);
    } else {
        cout << "Invalid line number. Text not inserted." << endl;
        return;
    }

    ofstream outFile("output.html");
    for (const string& modifiedLine : lines) {
        outFile << modifiedLine << endl;
    }
    cout << "Text inserted successfully. Output written to output.html." << endl;
}


void solve() {
    int a;
    string s;
    cout << "Company Name: ";
    cin.ignore();
    getline(cin, s);
    cout << "Benefits Count(0 for standard): ";
    cin >> a;

    insertTextAtPosition("index2.html",303,26,s);
    string fappend = "";

    if (a == 0) {
        ifstream standardBenefitsFile("standard_benefits.txt");
        string standardLine;
        while (getline(standardBenefitsFile, standardLine)) {
            fappend+=standardLine;
            // fappend += "<li style=\"margin: 0; padding: 0; box-sizing: border-box; font-family: sans-serif; line-height: 160%; text-align: justify; font-size: 16px; margin-left: 36px; text-justify: inter-word;\">" + standardLine + "</li>";
        }
        standardBenefitsFile.close();
    } else {
        cin.ignore(); 
        rep(i, a){
            getline(cin, s);
            fappend += "<li style=\"margin: 0; padding: 0; box-sizing: border-box; font-family: sans-serif; line-height: 160%; text-align: justify; font-size: 16px; margin-left: 36px; text-justify: inter-word;\">" + s + "</li>";
        }
    }
    insertTextAtPosition("output.html", 481, 21, fappend);
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
