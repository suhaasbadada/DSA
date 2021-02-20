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

	void deletenode(int num){
		Node* temp=head;
		if(temp->data==num){
			head=temp->next;
		}
		else{
			while(temp->next->data!=num){
				temp=temp->next;
			}
			temp->next=temp->next->next;
		}
				
	}	

	void deleteIfRightGreater(){
		reverse_itr();
		Node* temp;
		Node* max=head;
		Node* curr=head;

		while(curr!=NULL && curr->next!=NULL){
			if(curr->next->data < max->data){
				//temp=curr->next;
				curr->next=curr->next->next;
				//free(temp);
			}else{
				curr=curr->next;
				max=curr;
			}
			//cout<<max->data<<" ";
		}

		reverse_itr();
	}
};




int main(){

	LinkedList l;
	l.insertend(12);
	l.insertend(15);
	l.insertend(10);
	l.insertend(11);
	l.insertend(5);
	l.insertend(6);
	l.insertend(2);
	l.insertend(3);
	
	l.print();
	

	l.deleteIfRightGreater();

	l.print();
	


	return 0;
}