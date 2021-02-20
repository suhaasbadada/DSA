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

	void reverse_recurs();


};

void multiply(LinkedList l1,LinkedList l2){

	LinkedList res;
	Node* h1=l1.getHead();
	Node* h2=l2.getHead();
	int n1=0,n2=0;
	while(h1 || h2){
		if(h1){
			n1=n1*10+h1->data;
			h1=h1->next;
		}
		if(h2){
			n2=n2*10+h2->data;
			h2=h2->next;
		}
	}

	int m=n1*n2;
	int r;
	while(m){
		r=m%10;
		res.insertbeg(r);
		m=m/10;
	}
	res.print();

}



int main(){

	LinkedList l1,l2;
	l1.insertend(3);
	l1.insertend(4);
	l1.insertend(2);

	l2.insertend(9);
	l2.insertend(7);
	l2.insertend(6);
	l2.insertend(5);

	l1.print();
	l2.print();

	multiply(l1,l2);

	return 0;
}