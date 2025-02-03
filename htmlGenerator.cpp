#include <iostream>
#include <vector>
using namespace std;

string getHeader();
string getBody(vector<vector<string>> data);
string getFooter();

int main()
{
    int rows = 0,
        cols = 0;
    cout << "Enter Rows:";
    cin >> rows;
    cout << "Enter Columns:";
    cin >> cols;

    vector<vector<string>> data = {{0}};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            string entryData = "";
            cout << "Enter Data for Table Entry " << i << j << " : ";
            cin >> entryData;
            data[i].push_back(entryData);
        }
    }

    string outputString = "";
    outputString += getHeader();
    outputString += getBody(data);
    outputString += getFooter();

    return 0;
}

string getHeader()
{
    string header = "<!DOCTYPE html>\n";
    header += "<html>\n";
    header += "<head>\n";
    header += "<style>\n";
    header += "table {\n";
    header += "  font-family: arial, sans-serif;\n";
    header += "  border-collapse: collapse;\n";
    header += "  width: 100%;\n";
    header += "}\n";
    header += "\n";
    header += "td, th {\n";
    header += "  border: 1px solid #dddddd;\n";
    header += "  text-align: left;\n";
    header += "  padding: 8px;\n";
    header += "}\n";
    header += "\n";
    header += "tr:nth-child(even) {\n";
    header += "  background-color: #dddddd;\n";
    header += "}\n";
    header += "</style>\n";
    header += "</head>\n";
    header += "<h2> HTML Table</ h2>\n";

    return header;
}

string getBody(vector<vector<string>> data)
{
    string body = "<body>\n";
    body += "<table>\n";

    for (int i = 0; i < data.size(); i++)
    {
        body += "<tr>\n";
        for (int j = 0; j < data[i].size(); j++)
        {
            body += "<td>\n";
            body += data[i][j];
            body += "</td>\n";
        }
        body += "</tr>\n";
    }
    body += "</table>\n";
    body += "</body>\n";

    return body;
}

string getFooter()
{
    return "</html>\n";
}