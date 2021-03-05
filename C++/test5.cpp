#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'numPaths' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY warehouse as parameter.
 */

int numPaths(vector<vector<int>> warehouse) {
  stack< pair<int,int> > s;
  long result = 0;
  if(warehouse[0][0] == 0 || warehouse[warehouse.size()-1][warehouse[0].size()-1] == 0){
    return 0;
  }
  else{
    s.push(make_pair(0,0));
    while(!s.empty()){
      int row = s.top().first;
      int col = s.top().second;
      s.pop();
      if(row == warehouse.size()-1 && col == warehouse[0].size()-1){
        result++;
        continue;
      }

      if(col+1 <= warehouse[0].size()-1){
        if(warehouse[row][col+1] == 1){
          s.push(make_pair(row,col+1));
        }
      }

      if(row+1 <= warehouse.size()-1){
        if(warehouse[row+1][col] == 1){
          s.push(make_pair(row+1,col));
        }
      }
    }
  }

  long modulo = pow(10,9)+7;

  return (int)(result % modulo);
  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string warehouse_rows_temp;
    getline(cin, warehouse_rows_temp);

    int warehouse_rows = stoi(ltrim(rtrim(warehouse_rows_temp)));

    string warehouse_columns_temp;
    getline(cin, warehouse_columns_temp);

    int warehouse_columns = stoi(ltrim(rtrim(warehouse_columns_temp)));

    vector<vector<int>> warehouse(warehouse_rows);

    for (int i = 0; i < warehouse_rows; i++) {
        warehouse[i].resize(warehouse_columns);

        string warehouse_row_temp_temp;
        getline(cin, warehouse_row_temp_temp);

        vector<string> warehouse_row_temp = split(rtrim(warehouse_row_temp_temp));

        for (int j = 0; j < warehouse_columns; j++) {
            int warehouse_row_item = stoi(warehouse_row_temp[j]);

            warehouse[i][j] = warehouse_row_item;
        }
    }

    int result = numPaths(warehouse);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
