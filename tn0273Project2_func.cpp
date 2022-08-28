#include "tn0273Project2_header.h"

//Function to get the current number of students in the data file
int getNumber() 
{
	ifstream fin;
	int count=0;

	fin.open("student.dat");

	if(fin.fail())
	{
		cout<<"File error."<<endl;
		exit(1); //terminate program
	}

	string line;
	while (getline(fin,line))
	{		
		++count;
	}

	fin.close();
	return (count);


}

//FIND THE MINIMUM SCORE
int findMinimum(int arr[], int sz) 
{
	int min=arr[0];
	if (sz<5)
	{
		min=0;
	}
	if (sz==5)
	{
		for (int i=0;i<sz;++i)
		{
			if (*(arr+i)<min)
			{
				min=*(arr+i);
			}
		}
	}

    return min;

}

//Function for Adding Student
void add_Student() //DONE
{
	Student mySt;
	string fname, lname;

	mySt.numlist=new int[NUM_TEST]; //dynamic array memory allocation

	cout<<"Enter last name:";cin>>lname;
	cout<<"Enter first name:";cin>>fname;
	cout<<"Enter student ID:"; cin>>mySt.sID;
	cout<<"Enter number of tests this student take:"; cin>>mySt.numtest;

	cin.ignore();

	for (int i=0;i<mySt.numtest;++i) 
	{
		cout<<"Enter score #"<<i+1<<":";
		cin>>*(mySt.numlist+i); 	//mySt.numlist[i]=*(mySt.numlist+i)
		cout<<endl;
	}

	mySt.name=lname+","+fname; //combine name

	//open file and write data into that file
	ofstream fout;
	fout.open("student.dat", ios::app);

	if(fout.fail())
	{
		cout<<"File error."<<endl;
		exit(1); //terminate program
	}

	//write to file
	fout<<"\n";
	fout<<mySt.name<<","<<mySt.sID<<","<<mySt.numtest<<",";
	for(int i=0; i<mySt.numtest;++i)
	{
	    fout<<*(mySt.numlist+i)<<",";
	}
	

	fout.close();
	delete [] mySt.numlist;

}

//Function for Removing Student 
void remove_Student (int remove_ID) // DONE
{

	bool checkID=false;
	int count;
	count=getNumber();			 //calling function
	string fname, lname, ID, n_test, score[count];
	Student* my_rev=new Student[count];		 //allocate dynamic array with type Student
	my_rev->numlist=new int[NUM_TEST];
	

	//open the file
	ifstream fin;
	fin.open("student.dat");
	if(fin.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}

	int i=0;
	//read file and check
	while(!fin.eof())
    {
        //extract data from file
        getline(fin,lname,',');
        getline(fin,fname,',');
        getline(fin,ID,',');
        getline(fin,n_test,',');
        getline(fin,score[i]);

        //convert and store to array
        my_rev[i].name=lname+","+fname; 
        my_rev[i].numtest=stoi(n_test); 
        my_rev[i].sID=stoi(ID);
        ++i;
        
    }

    //check if ID matched
    for (int i=0;i<count;++i)
    {
    	if(my_rev[i].sID==remove_ID)
    	{
    		checkID=true;
    	}
    }


	fin.close();


	ifstream infile;
	ofstream outfile;
	infile.open("student.dat");
	outfile.open("student.dat");
	if (infile.fail() || outfile.fail())
		{
			cout<<"File error."<<endl;
			exit(1);
		}
	//indicate output whether ID matched or not
	if(checkID)
	{

		for (int i=0; i<count;++i)
		{
			if(remove_ID!=my_rev[i].sID)
			{
				outfile<<my_rev[i].name<<","<<my_rev[i].sID<<","<<my_rev[i].numtest<<",";
				//output score list
				string num;
				stringstream ss(score[i]);
				while(getline(ss,num,','))
				{
					*(my_rev->numlist+i)=stoi(num);
					outfile<<*(my_rev->numlist+i)<<",";
				}
				outfile<<endl;
			}
			

		}
		
	}

	if(!checkID)
	{
		cout<<"Student does not exist."<<endl;
	}
	

	infile.close();
	outfile.close();

	delete [] my_rev;
	delete [] my_rev->numlist;

}

//Function for Displaying
void display_Student()
{
	ifstream fin;
	fin.open("student.dat");
	if (fin.fail())
	{
		cout<<"File error."<<endl;
		exit(1); //terminate program

	}


	int count;
	count=getNumber();
	
	string fname, lname, ID, n_test, score[count];
	string dummy;
	int i=0;
	
	Student* my_dis=new Student[count];
	my_dis->numlist=new int[NUM_TEST];

	//read from files and store to array
    while(getline(fin,lname,','))
    {
        getline(fin,fname,',');
        getline(fin,ID,',');
        getline(fin,n_test,',');
        getline(fin,score[i]);        

        my_dis[i].name=lname+","+fname; //store data
        my_dis[i].sID=stoi(ID);
        ++i;
    }

    ///display out
    string num;
    for (int i=0;i<count;++i)
    {
    	cout<<setw(30)<<my_dis[i].name<<setw(15)<<my_dis[i].sID;
        
        
        stringstream ss(score[i]); ////input the score list with comma into stream
        while(getline(ss,num,',')) ///read only integer and output to array
        {
        	*(my_dis->numlist+i)=stoi(num);
        	cout<<setw(5)<<*(my_dis->numlist+i);
        }
        
        cout<<endl;
    }
   
	
	fin.close();
	delete [] my_dis;
	delete [] my_dis->numlist;
}

//Function for Searching
void search() //DONE
{
	ifstream fin;
	fin.open("student.dat");
	if (fin.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}
	string fname, lname, ID, n_test, score, input;
	Student* mySearch=new Student;
	mySearch->numlist=new int[NUM_TEST];
	bool trueID=false;

	int count;
	count=getNumber();

	int search_ID;
	cout<<"Enter the ID you want to search:";cin>>search_ID;
	while(getline(fin,lname,','))
	{
		
		getline(fin,fname,',');
		getline(fin,ID,',');
		getline(fin,n_test,',');
		getline(fin,score);

		mySearch->name=lname+","+fname;
		mySearch->sID=stoi(ID);

		//// CHECK IF THE ID MATCHED ////

		if (mySearch->sID==search_ID)
		{
			trueID=true;

		}

		/// OUTPUT THE RESULT ///
		if(trueID)
		{
			cout<<setw(30)<<mySearch->name<<setw(15)<<mySearch->sID;
			stringstream ss(score);
			while (getline(ss,input,','))
			{
				*(mySearch)->numlist=stoi(input);
				cout<<setw(5)<<*(mySearch)->numlist;
			}
			break;

		}

	}

	if(!trueID)
	{
		cout<<"Can't find the student.";
	}


	fin.close();

	delete mySearch;
	delete mySearch->numlist;

}


//Function for Exporting Result
void exportResults()
{
	ofstream fout;
	ifstream fin;
	fin.open("student.dat");
	fout.open("averages.dat");
	if (fin.fail() || fout.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}

	int count=getNumber();
	Student* myExport=new Student[count];
	myExport->numlist=new int[NUM_TEST];

	string lname,fname,ID,n_test,score[count],num;
    int sum=0, i=0;
    
	while(getline(fin,lname,','))
    {
        getline(fin,fname,',');
        getline(fin,ID,',');
        getline(fin,n_test,',');
        getline(fin,score[i]);
    
  
        myExport[i].name=lname+","+fname;
        myExport[i].sID=stoi(ID);

        stringstream ss(score[i]);
        for(int j=0;j<stoi(n_test);++j)
        {
        	getline(ss,num,',');
        	*(myExport->numlist+j)=stoi(num);
        	sum+=*(myExport->numlist+j);
        
        }

        if(stoi(n_test)<NUM_TEST)
        {
        	myExport[i].avg_score=static_cast<double>((sum-findMinimum(myExport->numlist,stoi(n_test))))/stoi(n_test);
        }
        else if (stoi(n_test)==NUM_TEST)
        {
        	myExport[i].avg_score=static_cast<double>((sum-findMinimum(myExport->numlist,stoi(n_test))))/4;    
        }
        sum=0;
        ++i;
        
    }

    for (int i=0;i<count;++i)
    {
    	fout<<myExport[i].sID<<setw(10)<<fixed<<setprecision(1)<<myExport[i].avg_score<<endl;
    }


	fin.close();
	fout.close();
	delete [] myExport;
	delete [] myExport->numlist;

}