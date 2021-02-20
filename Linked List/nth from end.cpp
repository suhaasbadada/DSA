#include <iostream>
using namespace std;

struct Node{
	struct Node* next;
	int data;

	Node(int data){
		this->data=data;
		next=NULL;
	}
};

struct LinkedList{
	Node* head;
	LinkedList(){
		head=NULL;
	}

	void insertbeg(int data){
		Node* temp=new Node(data);
		temp->next=head;
		head=temp;
	}

	void insertend(int data){
		Node* nn=new Node(data);
		Node* temp=head;
		if(head==NULL){
			head=nn;
		}
		else{
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=nn;
		}
	}

	void insertafter(int num,int data){
		Node* nn=new Node(data);
		Node* temp=head;

		while(temp->data!=num){
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}

	Node* getHead(){
		return head;
	}

	Node* getTail(){
		Node* temp=head;

		while(temp->next!=NULL){
			temp=temp->next;
		}

		return temp;
	}

	void print(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}

	void reverse_itr(){
		Node* current=head;
		Node *prev=NULL;
		Node *next=NULL;

		while(current!=NULL){
			next=current->next;
			current->next=prev;

			prev=current;
			current=next;
		}
		head=prev;
	}

	Node* kthFromEnd(int k){
		Node* first=head;
		Node* second=head;
		int i;

		for(i=0;i<k;i++){
			if(first==NULL){
				return NULL;
			}
			first=first->next;
		}

		while(first!=NULL){
			first=first->next;
			second=second->next;
		}

		return second;
	}


};




int main(){

	LinkedList l;
	l.insertend(35);
	l.insertend(15);
	l.insertend(4);
	l.insertend(20);
	int n=4;

	cout<<l.kthFromEnd(5);

	return 0;
}