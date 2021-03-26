#include <bits/stdc++.h>

using namespace std;

struct node
{
    char info;
    node* next;
    node(char n, node* nextNode)
{
    info = n;
    next = nextNode;    
}

};

node* deleteHead(node* prevHead){
    node* head = prevHead->next;
    delete prevHead;
    return head;
}

void deleteAll(node* head){
    node *temp;
    while(head != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// Complete the isBalanced function below.
string isBalanced(const string &s){
    int size = s.size();
    if(size%2 == 0)
    {
        node* head = NULL;
        for(int i = 0; i < size; i++)
        {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                head = new node(s[i], head);
            }
            else
            {
                if(head != NULL)
                {
                    if(s[i] == '}' && head->info == '{')
                        head = deleteHead(head);
                    else if(s[i] == ')' && head->info == '(')
                        head = deleteHead(head);
                    else if(s[i] == ']' && head->info == '[')
                        head = deleteHead(head);
                    else
                    {
                        return "NO";
                    }
                }
                else
                {
                    return "NO";
                }

            }
        }
        if(head == NULL)
            return "YES";
        else
            return "NO";
    }
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
