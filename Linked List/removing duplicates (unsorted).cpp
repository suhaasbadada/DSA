#include <iostream>
#include <unordered_set>
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

		unordered_set<int> s;

		while(temp->next!=NULL){

			if(s.find(temp->data)==s.end()){	// not found condition
				s.insert(temp->data);
				temp=temp->next;
			}
			else{
				temp=temp->next;
			}
		}

		unordered_set<int> :: iterator itr;
		LinkedList ll; 
    	for (itr = s.begin(); itr != s.end(); itr++) 
        	ll.insertbeg(*itr);

        ll.print(); 
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

	l.insertend(10);
	l.insertend(12);
	l.insertend(11);
	l.insertend(11);
	l.insertend(12);
	l.insertend(11);
	l.insertend(10);

	l.print();

	l.removeDuplicates();
	
	//l.print();

	

	return 0;
}