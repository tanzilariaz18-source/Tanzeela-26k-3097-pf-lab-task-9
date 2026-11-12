#include<stdio.h>

int calculateTotal(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += *(arr + i);   // *(arr + i) is the value at position i
    }
    return total;
}

int deposit(int Balance, int amount) {
    return Balance + amount;
}

int withdraw(int Balance, int amount) {
    return Balance - amount;
}

int processTransaction(int Balance, int amount, int (*operation)(int, int)) {
    return operation(Balance, amount);
}
int main()
{
	// task 1
	printf("====task 1====\n");
	int balance[] = {15000,25000,18000,32000,12000};
	 int *p;
	p=&balance[1];
	printf("balance of customer 2 is %d\n",*p);
	printf("address of customer 2 is %x\n",p);
	//update pointer 1 value
	*p+=4000;
	printf("updated value of customer 2 is %d\n",*p);
	
	
	// task 2
	printf("\n====task 2====\n");
		int transactions[2][3] =
		 {{120000,150000,180000},
		{200000,170000,220000}};
		int (*ptr)[3]= transactions;
		
		 for(int i=0;i<2;i++)
		 {
		 	int total=0;
		 	printf("\n[branch %d transaction]",i+1);
		 	
		 	for(int j=0;j<3;j++)
		 	{
		 		printf("\ncustomer %d transaction %d",j+1,(*(ptr+i))[j]);
		 		total+=(*(ptr+i))[j];
		 		 printf("\nrow address %x",&(*(ptr))[j]);
		 		
			 }
			  printf("\ntotal transaction %d",total);
		 }
		 
		 
		 //task 3
		 printf("\n  ===task 3====\n");
		 int branch1[]={15000,23000,32000};
		 int branch2[]={12000,21000,27000,35000};
		 int total=0;
		 int Total=0;
		 
		 
		 printf("balance and address of branch 1\n");
		 for(int i=0;i<3;i++)
		 {
		 	
		 	printf("\n %d\t",*(branch1+i));
		 	printf("%p",&branch1+i);
		 	total+=*(branch1+i);
		 }
		 printf("\n total balance of branch 1 is %d",total);
		 
		  printf("\nbalance and address of branch 2\n");
		 for(int i=0;i<4;i++)
		 {
		 	printf("\n %d\t",*(branch2+i));
		 		printf("%p",&branch2+i);
		 			Total+=*(branch2+i);
		 }
		 printf("\n total balance of branch 2 is %d",Total);
		 
		 
		 
		 //task4
		 printf("\n====task4====\n");

    int total1 = calculateTotal(branch1, 3);
    int total2 = calculateTotal(branch2, 4);

    printf("\ntotal balance of branch 1 is %d\n", total1);
    printf("total balance of branch 2 is %d\n", total2);
    
    printf("====task 5====\n");

    int Balance = 15000;
    int amount = 5000;

    // function pointer: a variable that can hold the address of a function
    int (*operation)(int, int);

    operation = deposit;                  // point it at deposit()
    Balance = operation(Balance, amount); // calls deposit(15000, 5000)
    printf("balance after deposit is %d\n", Balance);

    operation = withdraw;                 // point it at withdraw()
    Balance = operation(Balance, 2000);   // calls withdraw(20000, 2000)
    printf("balance after withdraw is %d\n", Balance);
    
    printf("====task 6====\n");


    // send deposit() into processTransaction()
    Balance = processTransaction(Balance, 5000, deposit);
    printf("balance after deposit is %d\n", Balance);

    // send withdraw() into processTransaction()
    Balance = processTransaction(Balance, 2000, withdraw);
    printf("balance after withdraw is %d\n", Balance);
    
		
}