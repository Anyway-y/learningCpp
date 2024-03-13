#include<iostream>
using namespace std;

struct node{
    int num;
    node *next;
    node* last;
};

node* makeAnewList(int m ){
    node* head = new(node);
    node* cur_node = head;
    for(int i = 1; i < m; i++){
        cur_node -> num = i;
        cur_node -> next = new(node);
        node* next_node = cur_node -> next;
        next_node -> last = cur_node;
        cur_node = next_node;
    }
    cur_node -> num = m;
    cur_node -> next = head;
    head -> last = cur_node;
    return head;
}

node* cutOffElements(node* cur_node, node* head){
    if(cur_node == head){
        node* last_node = head -> last;
        node* next_node = head -> next;
        last_node -> next = head -> next;
        next_node -> last = last_node;
        delete(head);
        
        return next_node;
    }else{
        node* last_node = cur_node -> last;
        node* next_node = cur_node -> next;
        if(last_node == next_node){
            delete(cur_node);
            return head;
        }
        last_node -> next = next_node;
        next_node -> last = last_node;
        delete(cur_node);
        return head;
    }

}



int main(){
    int n, m;
    cin >> n >> m;
    node* thead = makeAnewList(n);
    int remain = n;
    int count = 0;
    node* cur_node = thead;

    /*for(int i = 0; i < 2 * n; i++){
        cout << cur_node ->num << endl;
        
        cur_node = cur_node -> last;
    }*/

    while(remain > 1){
        count ++;
        if(count == m){
            count = 0;
            node* temp = cur_node ->next;
            thead = cutOffElements(cur_node, thead);
            cur_node = temp;
            remain --;
            
        }else{
            cur_node = cur_node -> next;
        }
    }
    cout << thead -> num << endl;
    delete(thead);
}
