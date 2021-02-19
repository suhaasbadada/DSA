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

	Node* getHead(){
		return head;
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

	void print(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}

	bool floyds(){
		Node* oneStep=head;
		Node* twoSteps=head;

		while(oneStep && twoSteps && twoSteps->next){
			oneStep=oneStep->next;
			twoSteps=twoSteps->next->next;

			if(oneStep==twoSteps){
				return true;
				break;
			}
		}

		return false;
	}

	void floydsloopstart(){
		Node* oneStep=head;
		Node* twoSteps=head;

		while(oneStep && twoSteps && twoSteps->next){
			oneStep=oneStep->next;
			twoSteps=twoSteps->next->next;

			if(oneStep==twoSteps){
				oneStep=head;
				break;
			}
		}

		while(oneStep && twoSteps){			

			if(oneStep==twoSteps){
				cout<<oneStep->data;
				break;
			}
			oneStep=oneStep->next;
			twoSteps=twoSteps->next;
		}

	}
	
};

int main(){

	LinkedList l;
	l.insertend(1);
	l.insertend(2);
	l.insertend(3);
	l.insertend(4);
	l.insertend(5);
	l.insertend(6);
	l.insertend(7);
	l.insertend(8);
	
	Node* head=l.getHead();
	
	head->next->next->next->next = head->next->next;
	


	(l.floyds())?(cout<<"Cycle Found"<<"\n"):(cout<<"Cycle not Found"<<"\n");
	l.floydsloopstart();

	return 0;
}