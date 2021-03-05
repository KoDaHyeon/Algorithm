#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long maxInversions(vector<int> arr) { //int 수 배열
  long result = 0;


  for(int i=0; i<=arr.size()-3; i++){
    if(arr[i] < 3) continue;
    for(int j=i+1; j<=arr.size()-2; j++){
      //if(j >= 2 && arr[j] == arr[j-1]) continue;
      if(arr[i] <= arr[j]) continue;
      if(arr[j] < 2) continue;
      for(int k=j+1; k<=arr.size()-1; k++){
        if(arr[j] <= arr[k]) continue;
        result++;
      }
    }
  }
  return result; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = maxInversions(arr);

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
