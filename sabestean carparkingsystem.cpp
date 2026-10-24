#include<iostream>
#include<cstring>     // for string
#include<ctime>       // for time
#include<vector>      // for dynamic array
#include<fstream>    // for file handling

using namespace std;
static int count = 0;  // --> fixed value

class Customer
{
	private:
    string name;
    string phone;
    
    public:
        Customer()
        {
        	ofstream file;
        	file.open("E:\\Superior\\2 semster\\OOP\\Theory\\Project\\Personinfo.txt");
        	
        	
            cin.ignore();
            cout<<"\n\t ---------- BASIC INFO ---------- "<<endl;
            cout<<"\n";
            cout<<"\tEnter Owner Name : ";
            getline(cin,name);
            file<<" Owner Name :" + name<<endl;
            
            cout<<"\n";
            cout<<"\tEnter Phone no   : ";
            getline(cin,phone);
            file<<" Phone no  :" + phone<<endl;
            
            file.close();
        }
        
        // using getter 
        
        string getName()
        {
            return name;
        }
        string getPhone()
        {
            return phone;
        }
};

class Vehicle:public Customer
{
	private:
    string car_name; 
    string carNo;
    string color;
    string model;
    string type;
    int slotNo; 
    int ticketNo;
    int billNo;
    int charges;
    
    time_t entryTime, exitTime;
    
    public:
        void getTicket(int slot)
        {
            slotNo=slot;
            
            ofstream onfile;
        	onfile.open("E:\\Superior\\2 semster\\OOP\\Theory\\Project\\Carinfo.txt");
            
            cout<<"\n";
            cout<<"\tEnter  Car Name  : ";
            getline(cin,car_name);
            onfile<<" Car Name   :" + car_name<<endl;
            
            cout<<"\n";
            cout<<"\tEnter Car Number : ";
            getline(cin,carNo);
            onfile<<" Car Number :" + carNo<<endl;
            
            cout<<"\n";
            cout<<"\tEnter Car Colour : ";
            getline(cin,color);
            onfile<<" Car Color  :" + color<<endl;
            
            cout<<"\n";
            cout<<"\tEnter Car Model no: ";
            getline(cin,model);
            onfile<<" Car Model :" + model<<endl;
            
            cout<<"\n";
            cout<<"\tEnter Car Type   : ";
            getline(cin,type);
            onfile<<" Car Type :" + type<<endl;
            
            
            onfile.close();
            
            entryTime = time(0);
            count++;
            string t = ctime(&entryTime);
            ticketNo = count;
            system("cls");
            displayTicket();
        }
        
        // using getter
        
        string getCar()
        {
            return car_name;
        }
        string getColor()
        {
            return color;
        }
        string getModel()
        {
            return model;
        }
        string getTypes()
        {
            return type;
        }
        
        //displaying parking ticket
        void displayTicket()    
        {
        	
        	ofstream up;
        	up.open("E:\\Superior\\2 semster\\OOP\\Theory\\Project\\unpaidticket.txt");
        	
        	cout<<"\n";
            cout<<"\t\t ---------- CAR PARKING TICKET ---------- "<<endl;
            
            cout<<"\n\t\t Owner Name   : "<<getName()<<endl;
            up<<" Owner Name :" + getName()<<endl;
            
            cout<<"\n\t\t Car Number   : "<<carNo<<endl;
            up<<" Car Number :" + carNo<<endl;
            
            cout<<"\n\t\t Car Model no : "<<getModel()<<endl;
            up<<" Car Model no :" + getModel()<<endl;
            
            cout<<"\n\t\t  Car Type    : "<<getTypes()<<endl;
            up<<" Car Type  :" + getTypes()<<endl;
            
            cout<<"\n\t\t Ticket Number: "<<ticketNo<<endl;
            up<<" Ticket Number:" << ticketNo<<endl;
            
            cout<<"\n\t\t Entry Time   : "<<ctime(&entryTime)<<endl;
            up<<" Entry Time :" << ctime(&entryTime)<<endl;
            
            cout<<"\n\t\t Parking Spot : "<<slotNo<<endl;
            
            cout<<"\n\t\t Current Status: UNPAID"<<endl;
            up<<" Current Status: UNPAID" <<endl;
            
            up.close();
            
            cout<<"\n";
            cout<<"\t\tEnter any key to go back to main menu..";
            char c = getchar();
            system("cls");
        }
        
        // using getter
        
        void getBill()
        {
            exitTime = time(0);
            billNo = ticketNo;
            calculateCharges();
        }
        
        int getTicketNo()
        {
            return ticketNo;
        }
        
        int getSlot()
        {
            return slotNo;
        }
        
        void calculateCharges()
        {
            long long duration = exitTime-entryTime;
            
            int mins = duration/60;
            
            int hours = mins/60;
            
            int extra_min = mins%60;
            
            if(hours==0 && extra_min<=30)
                charges = 30;
                
            else if(hours<=2 && extra_min==0)
                charges = 55;
                
            else if(hours<=7)
                charges = 55 + (hours-2)*10;
                
            else
                charges = 165;
                
            displayBill();
        }
        
        void displayBill()
        {
        	
        	ofstream p;
        	p.open("E:\\Superior\\2 semster\\OOP\\Theory\\Project\\paidticket.txt");
        	
        	cout<<"\n\n";
            cout<<"\t\t ---------- CAR PARKING BILL ---------- ";
            
            cout<<"\n\n\t\t Bill Number : "<<billNo<<endl;
            p<<" Bill Number :" << billNo<<endl;
            
            cout<<"\n\t\t Owner Name  : "<<getName()<<endl;
            p<<" Owner Name  :" + getName()<<endl;
            
            cout<<"\n\t\t Car Number  : "<<carNo<<endl;
            p<<" Car Number   :" + carNo<<endl;
            
            cout<<"\n\t\t Car Model no: "<<getModel()<<endl;
            p<<" Car Model no :" + getModel()<<endl;
            
            cout<<"\n\t\t  Car Type   : "<<getTypes()<<endl;
            p<<" Car Type  :" + getTypes()<<endl;
            
            cout<<"\n\t\t Parking Spot: "<<slotNo;
            p<<" Parking Spot :" + slotNo<<endl;
            
            cout<<"\n\t\t Entry Time  : "<<ctime(&entryTime);
            p<<" Entry Time  :"<< ctime(&entryTime)<<endl;
            
            cout<<"\n\t\t Exit Time   : "<<ctime(&exitTime);
            p<<" Exit Time :" <<ctime(&exitTime)<<endl;
            
            cout<<"\n\t\t Total Charges: Rs."<<charges<<"/-";
            p<<" Total Charges: Rs."<<charges<<"/-"<<endl;
            
            cout<<"\n\t\t Current Status: PAID";
            p<<" Current Status: PAID"<<endl;
            
            p.close();
            
            cout<<"\n\t\t Enter any key to go back to main menu..";
            char c = getchar();
        }

};

class ParkingLot
{
	private:
    int capacity;
    int totalFilled;
    vector<bool> parkingSpaces;
    vector<Vehicle> v;
    public:
        ParkingLot()
        {
            capacity = 125;
            totalFilled = 0;
            for(int i=0;i<capacity;++i)
                parkingSpaces.push_back(false);
        }
        
        bool ifSlotAvailable()
        {
            if(totalFilled==capacity)
                return false;
            else
                return true;
        }
        
        int getFreeSlot()
        {
            for(int i=0;i<capacity;++i)
            {
            	
                if(parkingSpaces[i]==false)
                {
                    parkingSpaces[i]=true;
                    totalFilled++;
                    return i+1;
                }
                
            }
            return -1;
        }
        
        void newVehicle(Vehicle& x)
        {
            v.push_back(x);
        }
        
        void deleteVehicle(int slot)
        {
            parkingSpaces[slot-1] = false;
            totalFilled--;
        }
        
        //Take input of ticket number
        
        Vehicle findDepartingCar(int t) 
        {
            for(int i=0;i<v.size();++i)
            {
                int s = v[i].getTicketNo();
                if(t == s)
                    return v[i];
            }
            return v[0];
        }
        
        int getCapacity()
        {
            return capacity;
        }
        
        int getTotalFilled()
        {
            return totalFilled;
        }
        
        void emptyParkingSpotsList()
        {
            for(int i=0;i<parkingSpaces.size();++i)
            {
                if(parkingSpaces[i]==false)
                    cout<<i+1<<", ";
            }
        }
        
        void occupiedParkingSpotsList()
        {
            for(int i=0;i<parkingSpaces.size();++i)
            
            {
                if(parkingSpaces[i]==true)
                    cout<<i+1<<", ";
            }
            
        }
};

   // car entrance

void carArrival(ParkingLot& pl) 
{
    if(pl.ifSlotAvailable())
    {
        int slot = pl.getFreeSlot();
        Vehicle obj;
        obj.getTicket(slot);
        pl.newVehicle(obj);
    }
    
    else
    {
        cout<<"Sorry no empty parking space available!";
    }
    
}

void carDeparture(ParkingLot& pl)
{
	if(pl.getTotalFilled() == 0)
	{
		cout<<"\n\n\t\t No Car Available in your Parking Lot";
		cout<<"\n\n\t\t Enter any key to go back to main menu..";
		cin.ignore();
		cin.ignore();
		return;
	}
    int ticketno;
    
    // enter the parking slot no
    
    cout<<"\n\n\t\tEnter ticket number : ";
    cin>>ticketno;
    cin.ignore();
    
    Vehicle curr = pl.findDepartingCar(ticketno);
    pl.deleteVehicle(curr.getSlot());
    system("cls");
    curr.getBill();
}

    // Info

void displayDetails(ParkingLot& pl)
{
	cout<<"\n\n\t\t   ------------------ DETAILS --------------------";
	cout<<"\n";
	cout<<"\n\n\t\t   = = = = = = = = = = = = = = = = = = = = = = = =";
    cout<<"\n\n\t\t    1. Get the Total Capacity of Parking Lot      ";
    cout<<"\n\n\t\t    2. Get Total Number of Occupied Parking Spots ";
    cout<<"\n\n\t\t    3. Get Total Number of Empty Parking Spots    ";
    cout<<"\n\n\t\t    4. Get List of Empty Parking Spots            ";
    cout<<"\n\n\t\t    5. Get List of Occupied Parking Spots         ";
    cout<<"\n\n\t\t    6. Get the Total Number of Parkings           ";
    cout<<"\n\n\t\t    7. Exit Program                               "; 
	cout<<"\n\n\t\t   = = = = = = = = = = = = = = = = = = = = = = = ="; 
	 
    int choice;
    
    do
    {
        cout<<"\n\n\t\t  Enter your option :: ";
        cin>>choice;
        if(choice<1 || choice>8)
            cout<<"\n\n\t\t Invalid Input";
        else
            break;
    } 
	
	while(true);
	
	// cls for new screen
	
    system("cls");
    int c;
    switch(choice)
    {
    	// pl is stand for parkinglot
    	
        case 1:
            c = pl.getCapacity();                        
            cout<<"\n\n\t\tThe capacity of parking lot is "<<c;
            break;
            
        case 2:
            c = pl.getTotalFilled();
            cout<<"\n\n\t\tThe number of occupied parking spots is "<<c;
            break;
            
        case 3:
            c = pl.getCapacity()-pl.getTotalFilled();
            cout<<"\n\n\t\tThe number of empty parking spots is "<<c;
            break;
            
        case 4:
            cout<<"\n\n\t\tList of empty parking spots: ";
            pl.emptyParkingSpotsList();
            break;
            
        case 5:
            cout<<"\n\n\t\tList of occupied parking spots: ";
            pl.occupiedParkingSpotsList();
            break;
            
        case 6:
            cout<<"\n\n\t\tThe total number of parkings: "<<count;
            break;
            
        case 7:
            break;
    }
    
    cin.ignore();
    cout<<"\n\n\t\t Enter any key to return to main menu..";
    char ch = getchar();
}

int main()
{
    ParkingLot p;
    int choice;
    int pass ;  
    
    cout<<"\n\n\n\n\n\t\t\tLogin"<<endl;
    cout<<"\n\n\t\tEnter Your Password :: ";
    cin>>pass;
    
    if(pass==0000)   
    {
    do
    {
        system("cls");
        cout<<"\n\n\n\t\t\t ======= CAR PARKING MANAGEMENT SYSTEM =======";
        cout<<"\n\n                                                      ";
        cout<<"\n\n\t\t\t -----------------------------------------------";
        cout<<"\n\n\t\t\t 1. Arrival of a Car  ";
        cout<<"\n\n\t\t\t 2. Departure of a Car";
        cout<<"\n\n\t\t\t 3. Display Details   ";
        cout<<"\n\n\t\t\t 4. Exit Program      ";
        cout<<"\n\n                                                      ";
        cout<<"\n\t\t\t ----------------------------------------------";
        cout<<"\n\n\t\t\t Select an option :: ";
        cin>>choice;
        while(choice<0 || choice>4)
		{
        	system("cls");
        	cout<<"\n\n\n\t\t\t\t  YOUR OPTION IS INVALID !! ";
        	cout<<"\n\n                                       ";
        	cout<<"\n\n\t\t\t\t ---------------------------   ";
		    cout<<"\n\n\t\t\t\t 1. Arrival of a Car  ";
		    cout<<"\n\n\t\t\t\t 2. Departure of a Car";
		    cout<<"\n\n\t\t\t\t 3. Display Details   ";
		    cout<<"\n\n\t\t\t\t 4. Exit Program      ";
		    cout<<"\n\n\t\t\t\t ---------------------------   ";
		    cout<<"\n\n\t\t\t\t Select another option :: ";
		    cin>>choice;
		}
        system("cls");
        switch(choice)
        {
            case 1:
                carArrival(p);
                break;
                
            case 2:
                carDeparture(p);
                break;
                
            case 3:
                displayDetails(p);
                break;
                
            case 4:
                exit(0);
                
            default:
                cout<<"Invalid Choice!";
                break;
        }
    } 
	while(true);
	cout<<" ";
    }
    
    else
	{
	cout<<"\n\n\t\t  Invalid Password !"<<endl;
    }
	
	return 0;
}
