#include "tn0273Project2_header.h"


int main()
{
			//header
	cout<<"+-----------------------------------------------------------+"<<endl;
	cout<<"|               Computer Science and Engineering            |"<<endl;
	cout<<"|                CSCE 1030 - Computer Science I             |"<<endl;
	cout<<"|          TranAnhThu Nguyen tn0273 tn0273@my.unt.edu       |"<<endl;
	cout<<"+-----------------------------------------------------------+"<<endl;
		// end of header

	int type_menu=0;
	int rev;
	bool flag=false; 
	
	do {
	//display menu and ask user for choices
	cout<<"1. Add \n2. Remove \n3. Display \n4. Search \n5. Result\n6. Quit"<<endl;


	cout<<"Enter choice:";cin>>type_menu;
	Type my_choice=static_cast<Type>(type_menu); 	//cast for constant switching control

	//menu of choices
	switch(my_choice)
	{
		case Add:
			add_Student(); //call function for adding student
			flag=true; 

		break;

		case Remove:
			cout<<"Enter ID of student you want to remove:";cin>>rev;
			remove_Student(rev);
			flag=true;


		break;

		case Display:
			display_Student();
			cout<<endl;
			flag=true;

		break;


		case Search:
			search();
			cout<<endl;
			flag=true;

		break;

		case Result:
			cout<<"Results exported to file.";
			exportResults();
			cout<<endl;
			flag=true;

		break;

		case Quit:
			cout<<"Bye!!!"<<endl;
			exit(1);
			

		break;

		default: 
			cout<<"Incorrect choice. Please enter again."<<endl;
			flag=true;
		}
	}
	while(flag);
	


	return 0;

}