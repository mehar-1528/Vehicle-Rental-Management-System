#include <iostream>
#include<time.h>
#include <cstdlib>
#include<vector>
using namespace std;

class UserLogin
{
    string username;
    string password;
public:
    void Login()
    {
        cout<<"Enter username:";
        cin>>username;
        cout<<"Enter Password:";
        cin>>password;
    }
    void DisplayLogin()
    {
        cout<<"UserName:"<<username<<endl;
    }
};

class Date
{
    int dd, mm, yyyy;
public:
    Date(){};
    void getDate(int dd, int mm, int yyyy)
    {
        this->dd = dd;
        this->mm = mm;
        this->yyyy = yyyy;
    }
    void putDate()
    {
        cout<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
    }
};

class dateAndTime
{
public:
    void getDateAndTime()
    {
        time_t my_time = time(NULL);
        cout << ctime(&my_time);
    }
};

class BookNow
{
protected:
    string source, destination;
    float dist, price;
    dateAndTime dateTime;
public:
    static int BookID;
    float calDist(string src, string dest)
    {
        source = src;
        destination = dest;
        dist = 2 + (rand() % (100 - 2 + 1));
        return dist;
    }
    float calPrice(string vehType)
    {
        if(vehType == "scooty")
        {
            price = dist*20;
        }
        else if(vehType == "sedan" || vehType == "suv")
        {
            price = dist*30;
        }
        else
        {
            price = dist*35;
        }
        return price;
    }
};
int BookNow::BookID=0;

class ageException: public exception
{
public:
    const char * what() const throw() {
        return "Sorry, we don't rent vehicles for customers below 18 years of age.\n";
    }
};

class selfDriveException: public exception
{
public:
    const char * what() const throw() {
        return "Sorry, you have to get a driver.\n";
    }
};

class Driver
{
    string DName;
    int age, yoe;
    long long int phno;
    Date DOJoin;
public:
    string status;
    Driver()
    {
        status = "available";
    }
    Driver(string name, int age, int yoe, long long int phno, int dd, int mm, int yyyy)
    {
        DName = name;
        this->age = age;
        this->yoe = yoe;
        this->phno = phno;
        DOJoin.getDate(dd, mm, yyyy);
        status = "available";
    }
    void putDriver()
    {
        cout<<"Name of the driver:"<<DName<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"Years of experience:"<<yoe<<endl;
        cout<<"Phone number:"<<phno<<endl;
        cout<<"Date of Joining:";
        DOJoin.putDate();
        status = "driving";
    }
};

class Customer
{
    string CName;
    long long int phno;
    vector<BookNow>bn;
    vector<UserLogin>login;
public:
    int age;
    void getCust()
    {
        cout<<"Enter your name:";
        cin>>CName;
        cout<<"Enter your age:";
        cin>>age;
        cout<<"Enter your phone number:";
        cin>>phno;
    }
    void putCust()
    {
        cout<<"Name of the customer:"<<CName<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"Phone number:"<<phno<<endl;
    }
    void book(BookNow b)
    {
        bn.push_back(b);
    }
    void allLogins(UserLogin ul)
    {
        login.push_back(ul);
    }
};

class Vehicle
{
protected:
    string VName, Model, Color, VehicleNo;
    int max_speed;
    float mileage;
    long long int insurance_no;
public:
    Vehicle() {}
    Vehicle(string VName, string Model, string Color, string VehicleNo, int max_speed, float mileage, long long int insurance_no)
    {
        this->VName=VName;
        this->Model=Model;
        this->Color=Color;
        this->VehicleNo=VehicleNo;
        this->max_speed=max_speed;
        this->mileage=mileage;
        this->insurance_no=insurance_no;
    }
    virtual void displayVehicle()=0;

};

class Car:public Vehicle
{
protected:
    string type;
public:
    Car(){}
    Car(string VName, string Model, string Color, string VehicleNo, int max_speed, float mileage, long long int insurance_no, string type):Vehicle(VName, Model, Color, VehicleNo, max_speed, mileage, insurance_no)
        {
        this->type = type;
        }
        void displayVehicle()
        {
            cout<<"Type:"<<type<<endl;
        }
};

class Scooty:public Vehicle
{
    string TyreType;
    string StartType;
public:
    Scooty(){}
    Scooty(string VName, string Model, string Color, string VehicleNo, int max_speed, float mileage, long long int insurance_no, string TyreType, string StartType):Vehicle(VName, Model, Color, VehicleNo, max_speed, mileage, insurance_no)
    {
        this->TyreType=TyreType;
        this->StartType=StartType;
    }
    void displayVehicle()
    {
        cout<<"Vehicle Name:"<<VName<<endl;
        cout<<"Model Name:"<<Model<<endl;
        cout<<"Color:"<<Color<<endl;
        cout<<"VehicleNo:"<<VehicleNo<<endl;
        cout<<"Max Speed:"<<max_speed<<endl;
        cout<<"Mileage:"<<mileage<<endl;
        cout<<"Insurance Number:"<<insurance_no<<endl;
        cout<<"Tyre Type:"<<TyreType<<endl;
        cout<<"Start Type:"<<StartType<<endl;
    }
};

class Minibus:public Vehicle
{
    int seat_num;
    string fuelType;
public:
    Minibus(){
    }
    Minibus(string VName, string Model, string Color, string VehicleNo, int max_speed, float mileage, long long int insurance_no, int seat_num, string fuelType)
    :Vehicle(VName, Model, Color, VehicleNo, max_speed, mileage, insurance_no)
    {
        this->seat_num = seat_num;
        this->fuelType = fuelType;
    }
    void displayVehicle()
    {
        cout<<"Vehicle Name:"<<VName<<endl;
        cout<<"Model Name:"<<Model<<endl;
        cout<<"Color:"<<Color<<endl;
        cout<<"VehicleNo:"<<VehicleNo<<endl;
        cout<<"Max Speed:"<<max_speed<<endl;
        cout<<"Mileage:"<<mileage<<endl;
        cout<<"Insurance Number:"<<insurance_no<<endl;
        cout<<"Number of seats:"<<seat_num<<endl;
        cout<<"Fuel type:"<<fuelType<<endl;
    }
};

class Sedan:public Car
{
    int no_of_seats;
public:
    Sedan(){
    }
    Sedan(string VName, string Model, string Color, string VehicleNo, int max_speed, float mileage, long long int insurance_no, int num_of_seats)
    :Car(VName, Model, Color, VehicleNo, max_speed, mileage, insurance_no, "sedan")
    {
        no_of_seats = num_of_seats;
    }
    void displayVehicle()
    {
        cout<<"Vehicle Name:"<<VName<<endl;
        cout<<"Model Name:"<<Model<<endl;
        cout<<"Color:"<<Color<<endl;
        cout<<"VehicleNo:"<<VehicleNo<<endl;
        cout<<"Max Speed:"<<max_speed<<endl;
        cout<<"Mileage:"<<mileage<<endl;
        cout<<"Insurance Number:"<<insurance_no<<endl;
        cout<<"Number of seats:"<<no_of_seats<<endl;

    }
};

class SUV:public Car
{
    int no_of_seats;
public:
    SUV(){}
    SUV(string VName, string Model, string Color, string VehicleNo, int max_speed, float mileage, long long int insurance_no, int num_of_seats)
    :Car(VName, Model, Color, VehicleNo, max_speed, mileage, insurance_no, "suv")
    {
        no_of_seats = num_of_seats;
    }
    void displayVehicle()
    {
        cout<<"Vehicle Name:"<<VName<<endl;
        cout<<"Model Name:"<<Model<<endl;
        cout<<"Color:"<<Color<<endl;
        cout<<"VehicleNo:"<<VehicleNo<<endl;
        cout<<"Max Speed:"<<max_speed<<endl;
        cout<<"Mileage:"<<mileage<<endl;
        cout<<"Insurance Number:"<<insurance_no<<endl;
        cout<<"Number of seats:"<<no_of_seats<<endl;
    }
};

class Payment
{
    string UPI_id;
public:
    void getCash()
    {
        cout << "You can pay the cash to the driver after reaching your destination.\n";
    }
    void getUPI(string UPI_id)
    {
        this->UPI_id = UPI_id;
        cout << "Payment Processed!\n";
    }
};

class RentalApp
{
public:
    Driver drivers[10];
    vector<Customer>customer;
    vector<BookNow>bookings;
    vector<Vehicle*>vehicles;

    void getDrivers(Driver dr[10]){
        for(int i = 0; i < 10; i++){
            drivers[i] = dr[i];
        }
    }

    void getCustomer(Customer c){
        customer.push_back(c);
    }

    void getRide(BookNow bn){
        bookings.push_back(bn);
    }

    void getVehicle(Vehicle* veh){
        vehicles.push_back(veh);
    }
};

int main()
{
    Vehicle *vh;
    RentalApp app;
    UserLogin u;
    u.Login();
    u.DisplayLogin();
    cout << "------Welcome to the Vehicle Rental Management System!-------\n\n";
    cout << "Enter 1 to book a ride and 0 to exit:\n";
    int choice;
    cin >> choice;

    int valid = 1;

    Scooty scootyArray[5];
    scootyArray[0] = Scooty("Pleasure", "Platinum", "Blue", "KA25U4567", 77, 63.5, 8976578546, "Tubeless", "SelfStart");
    scootyArray[1] = Scooty("Pept", "BSVI", "Pink", "KA25T743", 70, 65.5, 8937475332, "Tubeless", "SelfStart");
    scootyArray[2] = Scooty("Vespa", "VXL150", "Yellow", "KA25Y789", 80, 45.6, 548356830, "Tubeless", "KickStart");
    scootyArray[3] = Scooty("Dio", "BS4", "Blue", "KA56R896", 83, 55.4, 6387878833, "Tubeless", "SelfStart");
    scootyArray[4] = Scooty("Aviator", "6GS", "Blue", "KA67B483", 82, 60.0, 7824683292, "Tubeless", "KickStart");

    for(int i = 0; i < 5; i++)
        app.getVehicle(&scootyArray[i]);

    long long int license;

    Driver driverArray[10];
    driverArray[0] = Driver("Ron", 25, 3, 4589658956, 22, 6, 2019);
    driverArray[1] = Driver("Jack", 29, 5, 4879858956, 22, 8, 2019);
    driverArray[2] = Driver("Dyer", 35, 7, 22125558956, 26, 6, 2018);
    driverArray[3] = Driver("Shane", 20, 0, 4559658956, 22, 6, 2019);
    driverArray[4] = Driver("Sam", 27, 3, 999958956, 12, 6, 2019);
    driverArray[5] = Driver("Jordan", 25, 3, 8889658956, 22, 7, 2019);
    driverArray[6] = Driver("Fred", 50, 12, 522658956, 11, 6, 2001);
    driverArray[7] = Driver("Rick", 48, 10, 1002658956, 2, 6, 2008);
    driverArray[8] = Driver("Thomson", 37, 5, 129658956, 28, 12, 2010);
    driverArray[9] = Driver("Shine", 35, 6, 778558956, 20, 8, 2019);

    app.getDrivers(driverArray);

    Sedan sedanArray[3];
    sedanArray[0] = Sedan("Honda City", "ZX MT", "Grey", "KA25RS28", 195, 18.5, 458453853, 4);
    sedanArray[1] = Sedan("Swift", "LXI", "Red", "KA25TS45", 165, 23.2, 4543345432, 5);
    sedanArray[2] = Sedan("Verna", "CRDiAT", "Black", "KA28GF45", 240, 17.5, 654355654, 5);

    for(int i = 0; i < 3; i++)
        app.getVehicle(&sedanArray[i]);

    SUV suvArray[2];
    suvArray[0] = SUV("Creta", "SX(O)", "Black", "KA65FC43", 190, 17.1, 759494322, 7);
    suvArray[1] = SUV("Kia", "Seltos", "Red", "KA43FC34", 170, 18.5, 4533345553, 6);

    for(int i = 0; i < 2; i++)
        app.getVehicle(&suvArray[i]);

    Minibus minibusArray[2];
    minibusArray[0] = Minibus("Coach", "EIR", "White", "KA28HD42", 75, 9.1, 4378292929, 12, "diesel");
    minibusArray[1] = Minibus("Jitney", "TAX", "Yellow", "KA84F53", 80, 11.6, 65737832, 12, "diesel");

    for(int i = 0; i < 2; i++)
        app.getVehicle(&minibusArray[i]);

    while(choice)
    {
        Customer c;
        c.getCust();
        c.allLogins(u);
        app.getCustomer(c);
        int numOfPass;
        cout << "Enter the number of passengers: ";
        cin >> numOfPass;
        cout << "Choose vehicle:\n";
        int vehChoice;
        string vehType;
        if(numOfPass > 0 && numOfPass <= 2)
            {
            cout<<"1->Scooter\t2->Sedan\n"<<endl;
            cin >> vehChoice;
            cout << "\n";
            if(vehChoice == 1)
            {
                vehType = "scooty";
                Scooty s = scootyArray[rand()%5];
                vh=&s;
                vh->displayVehicle();
            }
            else if(vehChoice == 2)
            {
                vehType = "sedan";
                Sedan sed = sedanArray[rand()%3];
                vh=&sed;
                vh->displayVehicle();
            }
            else
            {
                cout << "Enter from the above mentioned options.\n";
                valid = 0;
            }
        }
        else if(numOfPass > 2 && numOfPass <= 5)
        {
            cout<<"1->Sedan\t2->SUV\n"<<endl;
            cin >> vehChoice;
            if(vehChoice == 1)
            {
                vehType = "sedan";
                Sedan sed = sedanArray[rand()%3];
                vh=&sed;
                vh->displayVehicle();
            }
            else if(vehChoice == 2)
            {
                vehType = "suv";
                SUV suv = suvArray[rand()%2];
                vh=&suv;
                vh->displayVehicle();
            }
            else
            {
                cout << "Enter from the above mentioned options.\n";
                valid = 0;
            }
        }
        else if(numOfPass >= 6 && numOfPass <= 12)
        {
            cout<<"1->Minibus\n"<<endl;
            cin >> vehChoice;
            if(vehChoice == 1)
            {
                vehType = "Minibus";
                Minibus bus = minibusArray[rand()%2];
                vh=&bus;
                vh->displayVehicle();
            }
            else
            {
                cout << "Enter from the above mentioned options.\n";
                valid = 0;
            }
        }
        else
        {
            cout << "Can't book ride. Try adding another vehicle if passengers are more than 12\n";
            valid = 0;
        }

        if(valid)
        {
        cout << "Choose:\n1->Self Drive\t2->Driver\n";
        int driveChoice;
        cin >> driveChoice;
        if(driveChoice == 1)
        {
            if(c.age < 18)
            {
                ageException ae;
                cout << ae.what()<<endl;
            }

            if(c.age < 18){
                driveChoice = 2;
            }
            else if(numOfPass >= 6 && numOfPass <= 12)
            {
                selfDriveException se;
                //throw se;
                cout<<se.what()<<endl;
                driveChoice = 2;
            }
            else
            {
                cout<<"Enter your license number: ";
                cin>>license;
            }
        }
        cout <<"\n";
        if(driveChoice == 2)
        {
            //Assigning an available driver from an array of drivers.
            Driver d;
            d = driverArray[rand()%10];
            while(d.status == "driving")
            {
                d = driverArray[ (rand() % 10)];
            }
            d.putDriver();
        }
        else if(driveChoice != 1)
        {
            cout << "Enter valid data\n";
            valid = 0;
        }
        if(valid)
        {
            string src, dest;
            cout << "Enter Source: ";
            cin >> src;
            cout << "Enter Destination: ";
            cin >> dest;
            if(src == dest)
            {
                cout << "Enter valid data\n";
                valid = 0;
            }
            if(valid)
            {
                BookNow bn;
                bn.BookID++;
                cout<<"Booking ID="<<bn.BookID<<endl;
                cout << "Calculating distance.....\n";
                cout << "Distance is " << bn.calDist(src, dest) << " km" << endl;
                cout << "Cost of Journey: Rs. " << bn.calPrice(vehType) << endl;
                cout << "Please complete the payment.\n1->Cash\t2->UPI\n";
                Payment pay;
                int payChoice;
                cin >> payChoice;
                if(payChoice == 1)
                {
                    if(driveChoice == 1)
                    {
                        cout << "There is no option for COD in self drive\n";
                        payChoice = 2;
                    }
                    else
                    {
                        pay.getCash();
                    }
                }
                if(payChoice == 2)
                {
                    string upi;
                    cout << "Enter UPI: ";
                    cin >> upi;
                    pay.getUPI(upi);
                }
                else if(payChoice != 1 && payChoice != 2)
                {
                    cout << "Enter valid data\n";
                    valid = 0;
                }
                if(valid)
                {
                    app.getRide(bn);
                    c.book(bn);
                    cout << "\nBooking completed!\n\n";
                    dateAndTime t;
                    cout << "At: ";
                    t.getDateAndTime();
                    cout <<  "\n\nThank You.\n";
                }
            }
        }
        }
        cout << "Enter 1 to book a ride and 0 to exit\n";
        cin >> choice;
    }
    return 0;
}
