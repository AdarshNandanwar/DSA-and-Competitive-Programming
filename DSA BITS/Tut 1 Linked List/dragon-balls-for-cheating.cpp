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

SinglyLinkedListNode* pre(SinglyLinkedListNode* init, int n) {
	SinglyLinkedListNode* walker = init, *link;
  	
  	while(walker->next != NULL)
    {
        if(walker->data == n)
            link = walker;
      
        walker = walker->next;
    }
  
  	walker->next = link;
  	return init;
}

// ||START EDITING|| 

/*
 * Complete the 'grantWish' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
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

SinglyLinkedListNode* grantWish(SinglyLinkedListNode* head) {

    SinglyLinkedListNode * slow = head, * fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast);
    
    slow = head;
    int len = 0;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    SinglyLinkedListNode * start = slow, *newStart = slow;
    do{
        slow = slow->next;
        len++;
    }while(slow!=start);

    int offset;
    if(len%2){
        offset = (len/2)+1;
    } else {
        offset = len/2;
    }

    for (int i = 0; i < offset; i++)
    {
        newStart = newStart->next;
    }

    slow = head;
    bool first = true;
    while(true){
        if(slow->next == start){
            if(first){
                first = false;
            } else {
                slow->next = newStart;
                break;
            }
        }
        slow = slow->next;
    }


    // slow = fast = head;
    // do{
    //     slow = slow->next;
    //     fast = fast->next->next;
    //     cout<<slow->data<<" ";
    // } while(slow != fast);
    
    // slow = head;
    // len = 0;

    // while(slow != fast){
    //     slow = slow->next;
    //     fast = fast->next;
    // }

    // start = slow; newStart = slow;
    // do{
    //     slow = slow->next;
    //     len++;
    // }while(slow!=start);

    // cout<<"len"<<len<<endl;

    return head;

}

// ||END EDITING||


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* init = new SinglyLinkedList();

    string init_count_temp;
    getline(cin, init_count_temp);

    int init_count = stoi(ltrim(rtrim(init_count_temp)));

    for (int i = 0; i < init_count; i++) {
        string init_item_temp;
        getline(cin, init_item_temp);

        int init_item = stoi(ltrim(rtrim(init_item_temp)));

        init->insert_node(init_item);
    }

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    SinglyLinkedListNode* head2 = pre(init->head, n);

    SinglyLinkedListNode* answer = grantWish(head2);

    // while(answer != NULL){
    //     cout<<answer->data<<" ";
    // }cout<<endl;


    while(answer->data > 0)
    {
      	fout << answer->data << " ";
      	answer->data *= -1;
      	answer = answer->next;
    }
  	fout << -1*answer->data << " ";

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
