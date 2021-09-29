#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <string>
class Record {
        //add overload for non member friend function
    friend std::ostream& operator <<(std::ostream&, const Record&);
public:
    Record(std::string licPlate, std::string sta,
        std::string liceType, std::string issueD,
        std::string vio, std::string fineA,
        std::string issuingA, std::string vioStatus,
        std::string paymentAmount);

    Record();
    std::string getLicensePlate() const;
    std::string getPayments() const;
    std::string getState() const;
private:
    std::string licensePlate;
    std::string state;
    std::string licenseType;
    std::string issueDate;
    std::string violation;
    std::string fineAmount; //could be changed to type: double later on
    std::string paymentAmount; //could be changed to type: double later on
    std::string issuingAgency;
    std::string violationStatus;
    
};//end class
#endif