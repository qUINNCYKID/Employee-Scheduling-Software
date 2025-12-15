#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CruiseShip {

public:

    // All public functions needed for cruise ship class
    string credentials();
    void Pay();
    void ShiftExchange();
    void RequestOff();
    void SendMessage();
    void BroadcastMessage();
    bool input(const int[], const int, const int);

    void ViewMessages();

    string workername;
    string position;
    struct Message {
        string sender;
        string content;
    };
private:
    vector<Message> managerMessages;

};
/*****************************************************
*   This function prompts the user to enter his name
*   identification number, and work position, and returns
*   a string that holds the informations .
*****************************************************/
string CruiseShip::credentials() {


    int workerid;
    double workhours = 0.0;
    double payrate = 0.0;

    cout << "Enter your government name: ";
    cin >> workername;                          // Workers name

    cout << "Enter the identification number that placed on your Caribena cruises id: ";
    if (!(cin >> workerid)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input: identification number must be an integer");
    }

    cout << "Enter the employee work position: ";
    cin >> position;                                // What postion do you hold

    return "Credentials Name: " + workername + "\nPosition: " + position + "\nID: " + to_string(workerid); // Print stament for all worker credentials
}
/*****************************************************
*    Function to calculate workers' pay for cruise
*    ship management and floor staff while also taking
*    tax pay out for each worker.
*****************************************************/
void CruiseShip::Pay()
{
    // pay rates and tax rates
    int hoursworked;                            // Employee hours worked
    char employee_category;                     // Places holder for different position
    double net_wage{};
    const double HOURLY_RATE_CruiseManager = 34.11;
    const double HOURLY_RATE_DECKHAND = 22.30;
    const double TAX_RATE = 0.35;
    const double TIME_AND_HALF_M = 48.52;
    const double TIME_AND_HALF_c = 31.45;


    cout << "* WAGE CALCULATOR FOR CARBRAIN CRUISES *" << endl; //introduction
    cout << "****************************************" << endl;
    cout << endl;


    while (true) {
        cout << "ENTER CATEGORY: 'M' for Management 'C' for CrewMember:[M/C]: ";
        cin >> employee_category; // choice for different work positions

        if (employee_category == 'M' || employee_category == 'm' || employee_category == 'C' || employee_category == 'c') {
            break;
        }
        cout << "Invalid input, please enter either M or C." << endl;
    }

    while (true) {                                               // if the input is non-negative it will display this errir meddage
        cout << "How many hours did you work this week ? ";
        cin >> hoursworked;

        if (hoursworked >= 0) {  // if employee enters an input of less than zero.....
            break;
        }
        cout << "Invalid input, please enter a non-negative value." << endl;
    }

    // if then else for MANAGEMENT WORKES
    if (hoursworked <= 40)
    {
        if (employee_category == 'm' || employee_category == 'M')       // Equal for lower and higher and lower case letters
        {
            net_wage = (HOURLY_RATE_CruiseManager * hoursworked) - ((HOURLY_RATE_CruiseManager * hoursworked) * TAX_RATE);
        }
    }
    else
    {
        if (hoursworked > 40)
        {
            if (employee_category == 'm' || employee_category == 'M')   // Equal for lowerand higherand lower case letters
                net_wage = (((HOURLY_RATE_CruiseManager * 40) + ((hoursworked - 40) * TIME_AND_HALF_M)) - ((HOURLY_RATE_CruiseManager * 40) + ((hoursworked - 40) * TIME_AND_HALF_M)) * TAX_RATE);
        }
    }
    // if then else for FLOOR WORKERS

    if (hoursworked <= 40)
    {
        if (employee_category == 'c' || employee_category == 'C')     // Equal for lower and higher and lower case letters
        {
            net_wage = (HOURLY_RATE_DECKHAND * hoursworked) - ((HOURLY_RATE_DECKHAND * hoursworked) * TAX_RATE);
        }
    }
    {if (hoursworked > 40)
    {
        if (employee_category == 'c' || employee_category == 'C')    // Equal for lower and higher and lower case letters
            net_wage = (((HOURLY_RATE_DECKHAND * 40) + ((hoursworked - 40) * TIME_AND_HALF_c)) - ((HOURLY_RATE_DECKHAND * 40) + ((hoursworked - 40) * TIME_AND_HALF_c)) * TAX_RATE);
    }
    }

    cout << "\n Summary";                                // Print out for category pay and work hours.
    cout << "\n--------------";
    cout << "\nStaff Category: " << employee_category;   // The category you fall under
    cout << "\nHours Worked:" << hoursworked;          //
    cout << "\nNET WAGE: $" << net_wage;                 // Pay for the week including tax deduction


}
/*********************************************
*              * ShiftExchange *
*    This function will post a the users shift
*    for others to view and pickup the shift
*    if they so do choose too.
**********************************************/
void CruiseShip::ShiftExchange()
{

    string day;
    string start_time;
    string end_time;
    char choice;

    // Check if it's a valid day of the week
    cout << "Enter the day your shift is scheduled for (Monday, Tuesday, Wednesday, Thursday, Friday): ";
    cin >> day;
    if (day != "Monday" && day != "Tuesday" && day != "Wednesday" && day != "Thursday" && day != "Friday") {
        cout << "Invalid day of the week." << endl;
        return;
    }

    cout << "Enter the start time of your shift: ";    // Directions for employee to enter their shift start time..
    cin >> start_time;

    cout << "Enter the end time of your shift: ";      // Directions for employee to enter their shift end time..
    cin >> end_time;

    // Prompt for choice to drop or post the shift
    cout << "Do you want to drop this shift or post it to be picked up?" << endl;
    cout << "Enter D to drop, P to post: ";
    cin >> choice;


    if (choice == 'D' || choice == 'd') {   // Equal for lower and higher and lower case letters
        cout << "Your shift has been dropped but still needs to be approved by your shift leader.";
        cout << "other employees will be notified of this request if they denied it then you will have to show up to work..." << endl;
        cout << " A shift for " << start_time << " until " << end_time << "has been dropped  to the bord by " << workername;

        cout << "_____Avaiable shift that have been Droped____";
        cout << start_time << " until " << end_time << endl;
        cout << " Posted by " << workername;
        cout << " position: " << position;
    }
    else if (choice == 'P' || choice == 'p') {   // Equal for lower and higher and lower case letters
        cout << "Your shift has been posted for other employees to pick up." << endl;
        cout << "other employee will be notified of this request  if no one accept" << endl;
        cout << "them you will have to show up to work your shift ..." << endl;
        cout << "" << endl;
        cout << "_____Avaiable shift to be picked up ______" << endl;
        cout << "A Shift for " << start_time << " until " << end_time <<
            " has been Poseted to the board by " << workername;
        cout << endl;  cout << " postion: " << position;


    }

}
/***************************************************
*                 * Requestoff *
*  This function ask the user  to enter the number of
*  day they have requested  off and if this amount passes
*  the limit of 2 days the request will automatically
*  be denied...
****************************************************/
void CruiseShip::RequestOff() {
    int days;
    string reason;

    cout << "Enter the number of days requested off: ";
    cin >> days;

    if (days > 2) {  // if request passes limit of 2 days the request will automaticall be denied...
        cout << "Request denied. Cannot request more than 2 days at a time." << endl;
    }
    else {
        cout << "Enter the reason for the request (sick, personal): ";
        cin >> reason;

        if (reason == "sick" || "Sick" || reason == "personal" || "Persoanl") {
            cout << "\nRequest approved." << endl;
            cout << " Managment will be notified Enjoy yoru day off ";
        }
        else {
            cout << "\nRequest denied. Reasons not Validated ." << endl;
        }
    }
}
/***************************************************
*            * Send Messaheg function *
*  This function will allow the empyleee to comunicat
*   with their the shift manager back allowing them to
*
****************************************************/
void CruiseShip::SendMessage() {
    // Function to send message from employee to manager
    string employee_name;
    string message;

    cout << "Enter your name: ";
    cin >> employee_name;

    cout << "Please enter your message here: ";
    cin.ignore(); // To ignore the previous new line character
    getline(cin, message);

    // Create a new Message object with the employee name and message
    Message new_message = { employee_name, message };

    // Add the new message to the manager's list of messages
    managerMessages.push_back(new_message);

    cout << "Your message has been sent to the manager." << endl;
}




/// ----------------------------------- Function for  all Managament fucntions to operate ------------------------------------------------------------------------------------------///

const int NumPasswords = 8;
string Passwords[NumPasswords] = { "456846", "48758", "12345", "65398", "j458757", "austin44", "b7845", "m12346" }; // Managamnent area of password to unlodk the BroadcastMessage & ViewMessages  channel

bool CheckPassword(const string& password)
{
    for (int i = 0; i < NumPasswords; ++i)
    {
        if (password == Passwords[i])
        {
            return true;
        }
    }
    return false;
}
/*************************************************
*               * Brodcast function *
*   function will ask to valiadate the user validte their
*   then the message will be retuned to all emplyees
*
*
****************************************************/
void CruiseShip::BroadcastMessage()
{
    cout << "Enter manager password to make a broadcast: ";
    string password;
    cin >> password;
    if (!CheckPassword(password))
    {
        std::cout << "Invalid password. Broadcast message failed." << endl;
        return;
    }
    cin.ignore(); // clear the input buffer

    cout << "Enter broadcast message: ";
    string message;
    getline(cin, message);

    cout << "Broadcasting message to all employees: " << message << endl; // Code to broadcast message to all employees
}

/*************************************************
*            *  viewMessages *
*   All messages will be sent a allocated vector quea
*   to hold messages from all emmployess
*
*
****************************************************/
void CruiseShip::ViewMessages() {
    cout << "Enter manager password to view messages: ";
    string password;
    cin >> password;

    if (!CheckPassword(password)) {
        cout << "Invalid password. Cannot view messages." << endl;
        return;
    }

    if (managerMessages.size() == 0) {
        cout << "No messages have been sent yet." << endl;
        return;
    }

    cout << "Messages:" << endl;

    for (int i = 0; i < managerMessages.size(); i++) {
        cout << "Message " << i + 1 << " from " << managerMessages[i].sender << ": " << managerMessages[i].content << endl;
    }
}


/***************************************
 *             * Input *
 * bool function to testing each input
 * is identical to account number array that
 * that has already been initialized
 ****************************************/
bool input(const int array[], const int SIZE, const int input)     // Bool loop to test the paramaters of all passwords..
{
    int i = 0;
    bool found = false; // bool for false

    while (i < SIZE) {
        if (array[i] == input)
            found = true;  // bool for ture
        i++;               // count continuation

    }
    return  found; // return for true or false
}
//  Main function
int main() {
    CruiseShip ship;

    const int Size = 20;
    const int Password[Size] = { 788542, 647128, 452318, 948563, 214536, 978564,
        8080152, 4562555, 789456, 546230, 21546, 4685759,
        1005231, 6545231, 352085, 11, 351463, 458100,
        795684, 465813 };

    int maager_account_number{};
    cout << "\n\nCaribena cruises Employee Login " << endl;
    cout << "_____________________________________" << endl;
    cout << "Please Enter Your Employee Password to be validated " << endl;
    cin >> maager_account_number; // input for employee password  

    int tries = 0;
    bool Useraccountnumber = input(Password, Size, maager_account_number);
    while (!Useraccountnumber && tries < 3) {
        cout << "Wrong password. Please try again." << endl;
        cin >> maager_account_number;
        Useraccountnumber = input(Password, Size, maager_account_number);
        tries++;
    }

    if (Useraccountnumber) {
        int choice = 0;
        do {
            cout << "\n\nCaribena cruises Employee Framework" << endl;
            cout << "_____________________________________" << endl;

            cout << "  1. Entrance of employee credentials." << endl;

            cout << "  2. Calculate Pay." << endl;

            cout << "  3. Manage shift." << endl;

            cout << "  4. Request time off." << endl;

            cout << "  5. Send management a message." << endl;

            cout << "  6. Management Broadcast * only Managers granted access *." << endl;

            cout << "  7. To view Message * only Managers granted access * " << endl;

            cout << "  8. To exit menu  " << endl;

            cin >> choice;

            switch (choice) {
            case 1:
                ship.credentials();
                break;
            case 2:

                ship.Pay();
                break;
            case 3:

                ship.ShiftExchange();
                break;
            case 4:

                ship.RequestOff();
                break;
            case 5:

                ship.SendMessage();
                break;
            case 6:

                ship.BroadcastMessage();
            case 7:

                ship.ViewMessages();
            case 8:
                cout << "Exiting menu...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choice != 8);
    }
    else {
        cout << "Wrong password entered three times Program has been  terminated." << endl;
    }
    return 0;
}