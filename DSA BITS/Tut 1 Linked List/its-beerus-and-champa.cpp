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

// ||START EDITING||
/*
 * Complete the 'combineList' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST head1
 *  2. INTEGER_SINGLY_LINKED_LIST head2
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


SinglyLinkedListNode * reverseList(SinglyLinkedListNode * head){
    SinglyLinkedListNode * prev = NULL, * current = head, * temp;
    while(current != NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

SinglyLinkedListNode* combineList(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    head2 = reverseList(head2);
    SinglyLinkedListNode * current1 = head1, * current2 = head2, * head, * current;
    head = new SinglyLinkedListNode(head1->data);
    current1 = current1->next;
    current = head;

    int toggle = 0;
    while(current1 != NULL && current2 != NULL){
        if(toggle){
            current->next = new SinglyLinkedListNode(current1->data);
            current = current->next;
            current1 = current1->next;
        } else {
            current->next = new SinglyLinkedListNode(current2->data);
            current = current->next;
            current2 = current2->next;
        }
        toggle ^= 1;
    }
    if(current1 == NULL){
        current->next = current2;
    } else {
        current->next = current1;
    }

    return head;
}

// ||END EDITING||

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* head1 = new SinglyLinkedList();

    string head1_count_temp;
    getline(cin, head1_count_temp);

    int head1_count = stoi(ltrim(rtrim(head1_count_temp)));

    for (int i = 0; i < head1_count; i++) {
        string head1_item_temp;
        getline(cin, head1_item_temp);

        int head1_item = stoi(ltrim(rtrim(head1_item_temp)));

        head1->insert_node(head1_item);
    }

    SinglyLinkedList* head2 = new SinglyLinkedList();

    string head2_count_temp;
    getline(cin, head2_count_temp);

    int head2_count = stoi(ltrim(rtrim(head2_count_temp)));

    for (int i = 0; i < head2_count; i++) {
        string head2_item_temp;
        getline(cin, head2_item_temp);

        int head2_item = stoi(ltrim(rtrim(head2_item_temp)));

        head2->insert_node(head2_item);
    }

    SinglyLinkedListNode* answer = combineList(head1->head, head2->head);


    print_singly_linked_list(answer, " ", fout);
    fout << "\n";

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
