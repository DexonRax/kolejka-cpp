#include<iostream>

class Queue{

private:
	double *tab;
	double *temp_tab;
	int length;

public:

	Queue(){
		length = 0;
		tab = new double[length];
	}

	void enqueue(double liczba){
		temp_tab = new double[length];
		for(int i = 0; i<length; i++){
			temp_tab[i] = tab[i];
		}
		delete[] tab;
		tab = new double[length+1];
		for(int i = 0; i<length; i++){
			tab[i] = temp_tab[i];
		}
		delete[] temp_tab;
		length+=1;
		tab[length-1] = liczba;
	}

	void dequeue(){
		temp_tab = new double[length];
		for(int i = 0; i<length; i++){
			temp_tab[i] = tab[i];
		}
		delete[] tab;
		length-=1;
		tab = new double[length];
		for(int i = 0; i<length; i++){
			tab[i] = temp_tab[i+1];
		}
		delete[] temp_tab;
	}

	bool isEmpty(){
		return length == 0;
	}

	int size(){
		return length;
	}

	double front(){
		return tab[0];
	}

	void printQueue(){
		for(int i = 0; i<length; i++){
			std::cout<<"["<<i<<"] "<<tab[i]<<"\n";
		}
	}

};

int main(){
	
	Queue kolejka;
	kolejka.printQueue();
	std::cout<<kolejka.isEmpty()<<"\n";
	kolejka.enqueue(4.2);
	kolejka.enqueue(2.2);
	kolejka.enqueue(2.1);
	std::cout<<kolejka.front()<<"\n";
	kolejka.dequeue();
	kolejka.printQueue();
	std::cout<<kolejka.isEmpty()<<"\n";
	kolejka.dequeue();
	kolejka.dequeue();
	std::cout<<kolejka.isEmpty()<<"\n";
	kolejka.printQueue();

	return 0;
}