#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}


/*
 * Complete the 'getNumber' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_SINGLY_LINKED_LIST binary as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

long getNumber(SinglyLinkedListNode* binary) {
  long decimal = 0;
  int binaryArray[65];
  int idx = 0;
  for(int i=0; i<65; i++){
    binaryArray[i] = 0;
  }
  while(true){
    SinglyLinkedListNode* nextNode = binary->next;
    if(nextNode == nullptr) break;
    binaryArray[idx++] = nextNode->data;
    binary = nextNode;
  }
  idx--;
  for(int i=idx; i>=0; i--){
    decimal += (long)binaryArray[i] * pow((long)2,(long)idx-i);
  }

  return decimal;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* binary = new SinglyLinkedList(); //binary는 리스트

    string binary_count_temp;
    getline(cin, binary_count_temp);

    int binary_count = stoi(ltrim(rtrim(binary_count_temp)));

    for (int i = 0; i < binary_count; i++) {
        string binary_item_temp;
        getline(cin, binary_item_temp);

        int binary_item = stoi(ltrim(rtrim(binary_item_temp)));

        binary->insert_node(binary_item); //리스트에 노드 추가
    }

    long result = getNumber(binary->head); //result는 변환된 십진수. binary->head(리스트 binary의 헤드노드의 포인터)를 인수로 받음

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
