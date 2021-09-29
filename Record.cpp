#include "Record.h"

Record::Record(std::string licplate, std::string sta,
    std::string licType, std::string iDate,
    std::string vio, std::string fineA,
    std::string iAgency, std::string vioSta, 
    std::string payment) {

    licensePlate = licplate;
    state = sta;
    licenseType = licType;
    issueDate = iDate;
    violation = vio;
    fineAmount = fineA;
    issuingAgency = iAgency;
    violationStatus = vioSta;
    paymentAmount = payment;
}

Record::Record() {}
std::ostream& operator <<(std::ostream& output, const Record& rec) {
    output
        << "\n\nLicense Plate --> " << rec.licensePlate
        << "\nState --> " << rec.state
        << "\nLicense Type --> " << rec.licenseType
        << "\nIssue Date --> " << rec.issueDate
        << "\nViolation --> " << rec.violation
        << "\nFine Amount --> $" << rec.fineAmount
        << "\nPayment Amount --> $" << rec.paymentAmount
        << "\nIssuing Agency -->" << rec.issuingAgency
        << "\nViolation Status -->  " << rec.violationStatus << "\n\n";
    return output;
}
std::string Record::getLicensePlate() const{
    return licensePlate;
}
std::string Record::getPayments() const {
    return paymentAmount;
}
std::string Record::getState() const {
    return state;
}
