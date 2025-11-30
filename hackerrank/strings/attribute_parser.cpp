#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    vector<string> tagPath;        // stack of current tag path
    vector<string> keys;           // keys like "tag1.tag2~name"
    vector<string> vals;           // associated values

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        // Remove leading '<' and trailing '>'
        line = line.substr(1, line.size() - 2);

        // Closing tag: </tag>
        if (line[0] == '/') {
            string closingTag = line.substr(1);
            tagPath.pop_back();
            continue;
        }

        // Opening tag: tag attr1 = "value1"
        string tagName;
        int pos = line.find(' ');

        if (pos == string::npos) {
            tagName = line;
        } else {
            tagName = line.substr(0, pos);
        }

        string fullPath;
        if (tagPath.empty())
            fullPath = tagName;
        else
            fullPath = tagPath.back() + "." + tagName;

        tagPath.push_back(fullPath);

        if (pos != string::npos) {
            int i = pos + 1;
            while (i < line.size()) {
                
                int eq = line.find('=', i);
                if (eq == string::npos) break;

                string attrName = line.substr(i, eq - i - 1);

                int firstQuote = line.find('"', eq);
                int secondQuote = line.find('"', firstQuote + 1);

                string attrValue = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);

                keys.push_back(fullPath + "~" + attrName);
                vals.push_back(attrValue);

                i = secondQuote + 2;
            }
        }
    }

    // Answer queries
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);

        bool found = false;
        for (int j = 0; j < keys.size(); j++) {
            if (keys[j] == query) {
                cout << vals[j] << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Not Found!\n";
        }
    }

    return 0;
}
