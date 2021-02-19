#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;

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

	void insertafter(int num,int data){
		Node* temp=head;
		Node* nn=new Node(data);

		while(temp->data!=num){
			temp=temp->next;
		}
		nn->next=temp->next;	
		temp->next=nn;
	}

	void insertend(int data){
		Node* nn=new Node(data);
		Node* temp=head;
		
		if(temp==NULL){
			head=nn;
		}
		else{
			while(temp->next!=NULL){
				temp=temp->next;				
			}
			temp->next=nn;			
		}
		//free(temp);
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

	void removeDuplicates(){
		Node* temp=head;
		Node* next_next;

		while(temp->next!=NULL){
			if(temp->data==temp->next->data){
				next_next=temp->next->next;
				free(temp->next);
				temp->next=next_next;
			}else{
				temp=temp->next;
			}

		}
	}

	void print(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}


};



int main(){

	LinkedList l;

	l.insertbeg(20);
	l.insertbeg(13);
	l.insertbeg(13);
	l.insertbeg(11);
	l.insertbeg(11);
	l.insertbeg(11);
	l.insertbeg(11);

	l.print();

	l.removeDuplicates();
	
	l.print();

	

	return 0;
}