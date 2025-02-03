#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<string>> getData();
string getHeader();
string getBody(vector<vector<string>> data);
string getFooter();
void writeHTMLfile(string outputString);

int main()
{
    vector<vector<string>> data = getData();

    string outputString = "";
    outputString += getHeader();
    outputString += getBody(data);
    outputString += getFooter();

    cout << outputString;
    writeHTMLfile(outputString);

    return 0;
}

vector<vector<string>> getData()
{
    int rows = 0,
        cols = 0;
    cout << "Enter Rows:";
    cin >> rows;
    cout << "Enter Columns:";
    cin >> cols;

    vector<vector<string>> data;
    data.resize(rows);

    for (int i = 0; i < rows; i++)
    {
        data[i].resize(cols);
        for (int j = 0; j < cols; j++)
        {
            string entryData = "";
            cout << "Enter Data for Table Entry " << i << j << " : ";
            cin >> entryData;
            data[i].push_back(entryData);
        }
    }

    return data;
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
            if (data[i][j] != "")
            {
                body += "<td>\n";
                body += data[i][j];
                body += "</td>\n";
            }
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

void writeHTMLfile(string outputString)
{
    ofstream file;
    file.open("/home/huzaifa/Desktop/table.html");
    file << outputString;
    file.close();
}